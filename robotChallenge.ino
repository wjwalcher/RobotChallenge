#include <Servo.h>
Servo servo1;
int motorPin = 3;
void setup() {
  // put your setup code here, to run once:
 pinMode(1, OUTPUT);
 pinMode(motorPin, OUTPUT);
 servo1.attach(14);
 Serial.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int launchSpeed;
  int motorSpeed;
  int slidePot = analogRead(A0);
  int launchBtn = analogRead(A1);
  switch(slidePot){
    case '1'...'170':
      launchSpeed = 1;
      break;
    case '171'...'340':
      launchSpeed = 2;
      break;
    case '341'...'511':
      launchSpeed = 3;
      break;
    case '512'...'652':
      launchSpeed = 4;
      break;
    case '653'...'823':
      launchSpeed = 5;
      break;
    case '824'...'1024':
      launchSpeed = 6;
      break;
  }

  switch(launchSpeed){
    case 1:
      motorSpeed = 90;
      break;
    case 2:
      motorSpeed = 108;
      break;
    case 3:
      motorSpeed = 126;
      break;
    case 4:
      motorSpeed = 144;
      break;
    case 5:
      motorSpeed = 162;
      break;
    case 6:
      motorSpeed = 180;
      break;
  }
  
  if(launchBtn == LOW){
      analogWrite(motorPin, motorSpeed);  
  }
  else{
    delay(10);
  }
}