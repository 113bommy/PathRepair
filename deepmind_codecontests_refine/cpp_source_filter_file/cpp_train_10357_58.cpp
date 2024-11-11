#include <bits/stdc++.h>
using namespace std;
int n, x, y;
string s[1000];
int main() {
  s[0] = "zero";
  s[1] = "one";
  s[2] = "two";
  s[3] = "three";
  s[4] = "four";
  s[5] = "five";
  s[6] = "six";
  s[7] = "seven";
  s[8] = "eight";
  s[9] = "nine";
  s[10] = "ten";
  s[11] = "eleven";
  s[12] = "twelve";
  s[13] = "thirteen";
  s[14] = "fourteen";
  s[15] = "fifteen";
  s[16] = "sixteen";
  s[17] = "seventeen";
  s[18] = "eighteen";
  s[19] = "nineteen";
  s[20] = "twenty";
  s[30] = "thirty";
  s[40] = "forty";
  s[50] = "fifty";
  s[60] = "sixty";
  s[70] = "seventy";
  s[80] = "eighty";
  s[90] = "ninety";
  cin >> n;
  x = n / 10;
  y = n % 10;
  if (x == 0 || y == 0)
    cout << s[n];
  else
    cout << s[n - y] << "-" << s[y];
}
