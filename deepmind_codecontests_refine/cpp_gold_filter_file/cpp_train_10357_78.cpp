#include <bits/stdc++.h>
using namespace std;
const long long AMZ = 1e16;
const long long BST = 1e9 + 7;
const long long MGC = 1e9 + 1;
const long long WOW = 1e6 + 1;
const long long SPR = 1e4 + 1;
int main() {
  string num3[15] = {"ten",   "twenty",  "thirty", "forty", "fifty",
                     "sixty", "seventy", "eighty", "ninety"};
  string num[15] = {"zero", "one", "two",   "three", "four",
                    "five", "six", "seven", "eight", "nine"};
  string num2[15] = {"ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  long long n;
  cin >> n;
  if (n < 10) {
    cout << num[n];
  } else if (n < 20) {
    cout << num2[n - 10];
  } else {
    long long x = n % 10;
    n = n / 10;
    if (x == 0) {
      cout << num3[n - 1];
    } else {
      cout << num3[n - 1] << "-" << num[x];
    }
  }
  return 0;
}
