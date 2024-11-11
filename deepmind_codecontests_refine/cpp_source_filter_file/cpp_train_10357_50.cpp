#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[15] = {"zero",  "one",   "two",  "three", "four",   "five",  "six",
                  "seven", "eight", "nine", "ten",   "eleven", "twelve"};
  string ss[11] = {"thirteen",  "fourteen", "fifteen", "sixteen",
                   "seventeen", "eighteen", "nineteen"};
  string s1[11] = {"twenty", "thirty",  "forty",  "fivty",
                   "sixty",  "seventy", "eighty", "ninety"};
  int a;
  cin >> a;
  if (a < 13) {
    cout << s[a];
    cout << endl;
    return 0;
  }
  if (a < 20) {
    cout << ss[a - 13];
    cout << endl;
    return 0;
  }
  int b = a / 10;
  cout << s1[b - 2];
  if (a % 10 != 0) cout << "-" << s[a % 10];
  cout << endl;
  return 0;
}
