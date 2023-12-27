const int TrigPin = 9;
const int EchoPin = 8;
const int Data = 7;
float cm;
void setup()
{
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(Data, OUTPUT);
}
void loop()
{
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  cm = pulseIn(EchoPin, HIGH) / 58.0; //The echo time is converted into cm
  cm = (int(cm * 100.0)) / 100.0;     //Keep two decimal places
  Serial.println();
  if(cm>30){ //if you are puting the sensor behind the door use ">" sysmbole insted of ">" p.s. make sure tat the door nob is less than 30cm away
    digitalWrite(Data, HIGH);
    delay(200);
    Serial.write(0xAA);
    Serial.write(0x02);
    Serial.write(0x00);
    Serial.write(0xAC);
    delay(100);
    Serial.write(0xAA);
    Serial.write(0x18);
    Serial.write(0x01);
    Serial.write(0x01);
    Serial.write(0xC4);
    delay(100);
    Serial.end ();

  }
  else
  {
    Serial.begin(9600);
    digitalWrite(Data, LOW);
    delay(200);
    Serial.write(0xAA);
    Serial.write(0x04);
    Serial.write(0x00);
    Serial.write(0xAE);

  }
  delay(200);
}
