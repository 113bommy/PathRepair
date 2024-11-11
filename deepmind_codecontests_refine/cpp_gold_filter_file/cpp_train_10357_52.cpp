#include <bits/stdc++.h>
using namespace std;
int main() {
  string ones[] = {"zero", "one", "two",   "three", "four",
                   "five", "six", "seven", "eight", "nine"};
  string tens[] = {"ten",   "twenty",  "thirty", "forty", "fifty",
                   "sixty", "seventy", "eighty", "ninety"};
  string teens[] = {"eleven",  "twelve",    "thirteen", "fourteen", "fifteen",
                    "sixteen", "seventeen", "eighteen", "nineteen"};
  int n;
  cin >> n;
  if (n < 10) {
    cout << ones[n] << endl;
  } else {
    if (n % 10 == 0) {
      cout << tens[(n / 10) - 1] << endl;
    } else if (n > 10 && n < 20) {
      cout << teens[n - 10 - 1] << endl;
    } else {
      int x = n / 10;
      n = n % 10;
      cout << tens[x - 1] << "-" << ones[n] << endl;
    }
  }
  return 0;
}
