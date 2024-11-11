#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[] = {"zero",    "one",     "two",       "three",    "four",
                "five",    "six",     "seven",     "eight",    "nine",
                "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  string c[] = {"",      "",      "twenty",  "thirty", "fourty",
                "fifty", "sixty", "seventy", "eighty", "ninety"};
  int n;
  cin >> n;
  if (n < 20) {
    cout << s[n];
  } else {
    if (n % 10 == 0)
      cout << c[n / 10];
    else
      cout << c[n / 10] << "-" << s[n % 10];
  }
  return 0;
}
