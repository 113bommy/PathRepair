#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[11] = {"ten",   "twenty",  "thirty", "forty", "fifty",
                  "sixty", "seventy", "eighty", "ninety"};
  string c[11] = {"zero", "one", "two",   "three", "four",
                  "five", "six", "seven", "eight", "nine"};
  string d[11] = {"eleven",  "twelve",    "thirteen", "fourteen", "fifteen",
                  "sixteen", "seventeen", "eighteen", "nineteen"};
  int n, k;
  cin >> n;
  if (n < 10) {
    cout << c[n];
  } else if (n > 10 && n < 20) {
    int z = n % 10;
    cout << d[z - 1];
  } else {
    k = n % 10;
    if (k == 0) {
      cout << s[(n / 10) - 1];
    } else {
      cout << s[(n / 10) - 1] << '-' << c[k];
    }
  }
}
