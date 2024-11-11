#include <bits/stdc++.h>
using namespace std;
string single_digit(int s) {
  if (s == 0) return "zero";
  if (s == 1) return "one";
  if (s == 2) return "two";
  if (s == 3) return "three";
  if (s == 4) return "four";
  if (s == 5) return "five";
  if (s == 6) return "six";
  if (s == 7) return "seven";
  if (s == 8) return "eight";
  if (s == 9) return "nine";
  if (s == 10) return "ten";
  if (s == 11) return "eleven";
  if (s == 12) return "twelve";
  if (s == 13) return "thirteen";
  if (s == 14) return "fourteen";
  if (s == 15) return "fifteen";
  if (s == 16) return "sixteen";
  if (s == 17) return "seventeen";
  if (s == 18) return "eighteen";
  if (s == 19) return "nineteen";
}
int s;
int main() {
  cin >> s;
  if (s < 20) {
    cout << single_digit(s);
    return 0;
  }
  int tens = s / 10;
  int ones = s % 10;
  if (tens == 2) cout << "twenty";
  if (tens == 3) cout << "thirty";
  if (tens == 4) cout << "forty";
  if (tens == 5) cout << "fifty";
  if (tens == 6) cout << "sixty";
  if (tens == 7) cout << "seventy";
  if (tens == 8) cout << "eighty";
  if (tens == 9) cout << "ninety";
  if (ones != 0) {
    cout << "-" << single_digit(ones);
  }
  return 0;
}
