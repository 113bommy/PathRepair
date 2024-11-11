#include <bits/stdc++.h>
using namespace std;
int main() {
  string a[] = {"zero", "one", "two",   "three", "four",
                "five", "six", "seven", "eight", "nine"};
  string b[] = {",",     ",",     "twenty",  "thirty", "forty",
                "fifty", "sixty", "seventy", "eighty", "ninety"};
  string c[] = {"ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  int n;
  cin >> n;
  int x = n / 10;
  int y = n % 10;
  if (n >= 0 && n <= 9) {
    cout << a[n] << endl;
  } else if (n >= 10 && n <= 19) {
    cout << c[y] << endl;
  } else if (y == 0) {
    cout << b[x] << endl;
  } else {
    cout << b[x] << " " << a[y] << endl;
  }
  return 0;
}
