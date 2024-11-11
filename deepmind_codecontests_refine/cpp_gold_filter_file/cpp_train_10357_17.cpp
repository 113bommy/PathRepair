#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  string one[10] = {"zero", "one", "two",   "three", "four",
                    "five", "six", "seven", "eight", "nine"};
  string second[10] = {"ten",      "eleven",  "twelve",  "thirteen",
                       "fourteen", "fifteen", "sixteen", "seventeen",
                       "eighteen", "nineteen"};
  string zeros[8] = {"twenty", "thirty",  "forty",  "fifty",
                     "sixty",  "seventy", "eighty", "ninety"};
  if (x / 10 == 0) {
    cout << one[x];
  } else if (x / 20 == 0) {
    cout << second[x - 10];
  } else {
    if (x % 10 == 0) {
      cout << zeros[x / 10 - 2];
    } else {
      cout << zeros[x / 10 - 2] << "-" << one[x % 10];
    }
  }
  return 0;
}
