#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s1, s2;
  vector<string> d(10);
  vector<string> d1(10);
  vector<string> d2(10);
  d[0] = "zero";
  d[1] = "one";
  d[2] = "two";
  d[3] = "three";
  d[4] = "four";
  d[5] = "five";
  d[6] = "six";
  d[7] = "seven";
  d[8] = "eight";
  d[9] = "nine";
  d1[0] = "ten";
  d1[1] = "eleven";
  d1[2] = "twelve";
  d1[3] = "thirteen";
  d1[4] = "fourteen";
  d1[5] = "fifteen";
  d1[6] = "sixteen";
  d1[7] = "seventeen";
  d1[8] = "eighteen";
  d1[9] = "nineteen";
  d2[2] = "twenty";
  d2[3] = "thirty";
  d2[4] = "forty";
  d2[5] = "fifty";
  d2[6] = "sixty";
  d2[7] = "seventy";
  d2[8] = "eighty";
  d2[9] = "ninety";
  cin >> n;
  if (n < 10) {
    cout << d[n] << "\n";
  } else if (n < 20) {
    cout << d1[n - 10] << "\n";
  } else if (n % 10 == 0) {
    n /= 10;
    cout << d2[n % 10] << "\n";
  } else {
    s1 = d[(n % 10)];
    n /= 10;
    s2 = d2[n % 10];
    cout << s2 << "-" << s1 << "\n";
  }
  return 0;
}
