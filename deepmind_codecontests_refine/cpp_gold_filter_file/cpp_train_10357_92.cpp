#include <bits/stdc++.h>
using namespace std;
int main() {
  string num[100] = {"zero",    "one",     "two",       "three",    "four",
                     "five",    "six",     "seven",     "eight",    "nine",
                     "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  num[20] = {"twenty"};
  num[30] = {"thirty"};
  num[40] = {"forty"};
  num[50] = {"fifty"};
  num[60] = {"sixty"};
  num[70] = {"seventy"};
  num[80] = {"eighty"};
  num[90] = {"ninety"};
  int n, exd;
  cin >> n;
  if (n < 20)
    cout << num[n];
  else {
    if ((n % 10) == 0) {
      cout << num[n];
    } else {
      exd = n % 10;
      n = n / 10;
      n = n * 10;
      cout << num[n] << "-" << num[exd];
    }
  }
  return 0;
}
