#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a[] = {" ",     " ",     "twenty",  "thirty", "fourty",
                "fifty", "sixty", "seventy", "eighty", "ninety"};
  string b[] = {"zero",    "one",     "two",       "three",    "four",
                "five",    "six",     "seven",     "eight",    "nine",
                "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  if (n < 20) {
    cout << b[n] << endl;
  } else {
    int r = n % 10;
    int q = n / 10;
    cout << a[q];
    if (r != 0) {
      cout << "-" << b[r];
    }
  }
  return 0;
}
