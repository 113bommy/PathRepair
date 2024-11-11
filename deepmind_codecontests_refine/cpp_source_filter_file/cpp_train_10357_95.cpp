#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string a[] = {"zero",    "one",     "two",       "three",     "four",
                "five",    "six",     "seven",     "eight",     "nine",
                "ten",     "eleven",  "twelve",    "thirteen",  "fourteen",
                "fifteen", "sixteen", "seventeen", "eightteen", "nineteen"};
  string b[] = {"",      "",        "twenty", "thirty", "forty",  "fifty",
                "sixty", "seventy", "eighty", "ninety", "hundred"};
  cin >> n;
  int c = n % 10;
  if (n < 20) {
    cout << a[n] << endl;
  } else {
    if (c == 0) {
      cout << b[n / 10] << endl;
    } else
      cout << b[n / 10] << "-" << a[n % 10] << endl;
  }
  return 0;
}
