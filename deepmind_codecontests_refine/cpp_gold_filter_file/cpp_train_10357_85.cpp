#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> ones = {"one",       "two",      "three",   "four",
                         "five",      "six",      "seven",   "eight",
                         "nine",      "ten",      "eleven",  "twelve",
                         "thirteen",  "fourteen", "fifteen", "sixteen",
                         "seventeen", "eighteen", "nineteen"};
  vector<string> tens = {"ten",   "twenty",  "thirty", "forty", "fifty",
                         "sixty", "seventy", "eighty", "ninety"};
  int s;
  cin >> s;
  string res;
  if (s == 0)
    res = "zero";
  else if (s / 10 > 0) {
    int u = s / 10;
    int o = s % 10;
    if (u == 1) {
      res += ones[s - 1];
    } else {
      res += tens[u - 1];
      if (o > 0) res += '-' + ones[o - 1];
    }
  } else
    res += ones[s % 10 - 1];
  cout << res << "\n";
  return 0;
}
