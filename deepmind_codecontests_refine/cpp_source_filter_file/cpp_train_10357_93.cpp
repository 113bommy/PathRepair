#include <bits/stdc++.h>
using namespace std;
string num(int a) {
  if (a == 1) return "one";
  if (a == 2) return "two";
  if (a == 3) return "three";
  if (a == 4) return "four";
  if (a == 5) return "five";
  if (a == 6) return "six";
  if (a == 7) return "seven";
  if (a == 8) return "eight";
  if (a == 9) return "nine";
}
int main() {
  int n1;
  cin >> n1;
  int n = n1 / 10;
  int n2 = n1 % 10;
  if (n1 == 0) cout << "zero";
  if (n1 == 10) cout << "ten";
  if (n == 2) cout << "twenty";
  if (n == 3) cout << "thirty";
  if (n == 4) cout << "forty";
  if (n == 5) cout << "fifty";
  if (n == 6) cout << "sixty";
  if (n == 7) cout << "seventy";
  if (n == 8) cout << "eighty";
  if (n == 9) cout << "ninety";
  if (n2 != 0 && n > 1) cout << "-";
  if (n > 1 && n2 > 0) cout << num(n2) << endl;
  if (n == 1) {
    if (n2 == 1) cout << "eleven" << endl;
    if (n2 == 2) cout << "twelve" << endl;
    if (n2 == 3) cout << "thirteen" << endl;
    if (n2 == 4) cout << "fourteen" << endl;
    if (n2 == 5) cout << "fifteen" << endl;
    if (n2 == 6) cout << "sixteen" << endl;
    if (n2 == 7) cout << "seventeen" << endl;
    if (n2 == 8) cout << "eighteen" << endl;
    if (n2 == 9) cout << "nineteen" << endl;
  }
}
