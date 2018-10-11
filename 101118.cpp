#include "robot-config.h"

int main() {
    Brain.Screen.print("Program Started");
    while(true) {
        int a2 = Control.Axis2.position(vex::percentUnits::pct);
        if (a2 < 0) {
            RightMotor.spin(vex::directionType::rev, abs(Control.Axis2.value()), vex::velocityUnits::pct);
        } else if (a2 > 0) {
           RightMotor.spin(vex::directionType::fwd, Control.Axis2.value(), vex::velocityUnits::pct);
        } else {
           RightMotor.stop(vex::brakeType::brake);
        }

        int a3 = Control.Axis3.position(vex::percentUnits::pct);
        if (a3 < 0) {
            LeftMotor.spin(vex::directionType::rev, abs(Control.Axis3.value()), vex::velocityUnits::pct);
        } else if (a3 > 0) {
            LeftMotor.spin(vex::directionType::fwd, Control.Axis3.value(), vex::velocityUnits::pct);
        } else {
            LeftMotor.stop(vex::brakeType::brake);
        }
        
        if(Control.ButtonL2.pressed()) {
            Flipper.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
        } 
        if (Control.ButtonR2.pressed()) {
            Flipper.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
        }
        vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.
    }

}