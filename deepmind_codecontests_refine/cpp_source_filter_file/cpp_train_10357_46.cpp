#include <bits/stdc++.h>
using namespace std;
string find(int a) {
  string s = "\n";
  if (a == 0) return s;
  if (a == 1) cout << "-one";
  if (a == 2) cout << "-two";
  if (a == 3) cout << "-three";
  if (a == 4) cout << "-four";
  if (a == 5) cout << "-five";
  if (a == 6) cout << "-six";
  if (a == 7) cout << "-seven";
  if (a == 8) cout << "-eight";
  if (a == 9) cout << "-nine";
}
int main() {
  int s;
  cin >> s;
  if (s == 0) {
    cout << "zero" << endl;
  } else {
    int a = s % 10;
    int b = s / 10;
    if (b == 0) {
      if (a == 1) cout << "one" << endl;
      if (a == 2) cout << "two" << endl;
      if (a == 3) cout << "three" << endl;
      if (a == 4) cout << "four" << endl;
      if (a == 5) cout << "five" << endl;
      if (a == 6) cout << "six" << endl;
      if (a == 7) cout << "seven" << endl;
      if (a == 8) cout << "eight" << endl;
      if (a == 9) cout << "nine" << endl;
    } else if (b == 1) {
      if (a == 0) cout << "ten" << endl;
      if (a == 1) cout << "eleven" << endl;
      if (a == 2) cout << "twenlve" << endl;
      if (a == 3) cout << "thirteen" << endl;
      if (a == 4) cout << "fourteen" << endl;
      if (a == 5) cout << "fifteen" << endl;
      if (a == 6) cout << "sixteen" << endl;
      if (a == 7) cout << "seventeen" << endl;
      if (a == 8) cout << "eighteen" << endl;
      if (a == 9) cout << "nineteen" << endl;
    } else if (b > 1) {
      if (b == 2) cout << "twenty";
      if (b == 3) cout << "thirty";
      if (b == 4) cout << "forty";
      if (b == 5) cout << "fifty";
      if (b == 6) cout << "sixty";
      if (b == 7) cout << "seventy";
      if (b == 8) cout << "eighty";
      if (b == 9) cout << "ninety";
      cout << find(a);
    }
  }
}
