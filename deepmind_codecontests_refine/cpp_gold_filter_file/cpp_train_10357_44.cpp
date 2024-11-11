#include <bits/stdc++.h>
using namespace std;
int main() {
  string one[] = {"zero", "one", "two",   "three", "four",
                  "five", "six", "seven", "eight", "nine"};
  string tens[] = {"ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                   "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  string mult[] = {"twenty", "thirty",  "forty",  "fifty",
                   "sixty",  "seventy", "eighty", "ninety"};
  int input;
  string result;
  cin >> input;
  if (input < 10) {
    result = one[input];
  } else if (input >= 10 && input < 20) {
    result = tens[input - 10];
  } else if (input >= 20 && input < 30) {
    if (input == 20) {
      result = mult[0];
    } else {
      result = mult[0];
      result += "-";
      result += one[input - 20];
    }
  } else if (input >= 30 && input < 40) {
    if (input == 30) {
      result = mult[1];
    } else {
      result = mult[1];
      result += "-";
      result += one[input - 30];
    }
  } else if (input >= 40 && input < 50) {
    if (input == 40) {
      result = mult[2];
    } else {
      result = mult[2];
      result += "-";
      result += one[input - 40];
    }
  } else if (input >= 50 && input < 60) {
    if (input == 50) {
      result = mult[3];
    } else {
      result = mult[3];
      result += "-";
      result += one[input - 50];
    }
  } else if (input >= 60 && input < 70) {
    if (input == 60) {
      result = mult[4];
    } else {
      result = mult[4];
      result += "-";
      result += one[input - 60];
    }
  } else if (input >= 70 && input < 80) {
    if (input == 70) {
      result = mult[5];
    } else {
      result = mult[5];
      result += "-";
      result += one[input - 70];
    }
  } else if (input >= 80 && input < 90) {
    if (input == 80) {
      result = mult[6];
    } else {
      result = mult[6];
      result += "-";
      result += one[input - 80];
    }
  } else {
    if (input == 90) {
      result = mult[7];
    } else {
      result = mult[7];
      result += "-";
      result += one[input - 90];
    }
  }
  cout << result;
}
