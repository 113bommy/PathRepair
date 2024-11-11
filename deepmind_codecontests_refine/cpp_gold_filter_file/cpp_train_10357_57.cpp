#include <bits/stdc++.h>
using namespace std;
int n;
string s[] = {"zero",    "one",     "two",       "three",    "four",
              "five",    "six",     "seven",     "eight",    "nine",
              "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
              "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
       a[] = {"twenty", "thirty",  "forty",  "fifty",
              "sixty",  "seventy", "eighty", "ninety"};
int main() {
  cin >> n;
  if (n < 20) {
    cout << s[n];
  }
  if (n > 19 && n % 10 == 0) {
    cout << a[n / 10 - 2];
    return 0;
  }
  if (n >= 20) {
    cout << a[n / 10 - 2] << "-" << s[n % 10];
  }
}
