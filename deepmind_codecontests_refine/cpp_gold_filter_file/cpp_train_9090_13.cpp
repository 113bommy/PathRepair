#include <bits/stdc++.h>
using namespace std;
int main() {
  int max = 0;
  int counter = 0;
  string line;
  int q;
  cin >> q;
  string number;
  string format;
  int num1;
  int num2;
  int num3;
  int num4;
  int preNum1 = 9;
  int preNum2 = 9;
  int preNum3 = 9;
  int preNum4 = 9;
  char letter;
  cin.ignore();
  while (q--) {
    getline(cin, line);
    stringstream ss(line);
    ss >> number;
    num1 = number[1] - '0';
    num2 = number[2] - '0';
    num3 = number[4] - '0';
    num4 = number[5] - '0';
    ss >> format;
    letter = format[0];
    if (letter == 'p') {
      if (!(num1 == 1 && num2 == 2)) {
        num2 += 2;
        if (num2 > 9) {
          num2 -= 10;
          num1 += 1;
        }
        num1 += 1;
      }
    }
    if ((letter == 'a' && num1 == 1 && num2 == 2)) {
      num1 -= 1;
      num2 -= 2;
    }
    if (num1 < preNum1) {
      counter++;
    } else if (num1 == preNum1 && num2 < preNum2) {
      counter++;
    } else if (num1 == preNum1 && num2 == preNum2 && num3 < preNum3) {
      counter++;
    } else if (num1 == preNum1 && num2 == preNum2 && num3 == preNum3 &&
               num4 < preNum4) {
      counter++;
    }
    if (num1 == preNum1 && num2 == preNum2 && num3 == preNum3 &&
        num4 == preNum4) {
      max++;
    } else {
      max = 0;
    }
    if (max == 10) {
      counter++;
      max = 0;
    }
    preNum1 = num1;
    preNum2 = num2;
    preNum3 = num3;
    preNum4 = num4;
  }
  cout << counter << endl;
  return 0;
}
