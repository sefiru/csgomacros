#include <Mouse.h>

boolean isPressed = false;
long tick = 0;
unsigned long timer = 0;
byte _delay = 100;
byte _map[12] = {10, 10, 20, 15, 15, 15, 15, 15, 15, 15, 10, 10
};
//byte _map[12] = {20, 20, 20, 40, 40, 20, 20, 20, 20, 20, 20, 20
//};

void setup() {
  pinMode(4, INPUT);
  Mouse.begin();
  Serial.begin(9600);
}

void loop() {
  if ( isPressed ) {
    if ( digitalRead(4) ) {
      isPressed = false;
      tick = 0;
      return;
    }
    if ( millis() > timer + _delay ) {
      if ( tick > 29 )
        return;
      timer = millis();
      Mouse.move(0, _map[tick], 0);
      tick++;
    }
  } else {
    if ( !digitalRead(4) ) {
      timer = millis();
      isPressed = true;
    }
  }

}
