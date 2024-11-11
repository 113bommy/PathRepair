#include <bits/stdc++.h>
using namespace std;
char digit[][10] = {"zero",    "one",     "two",       "three",    "four",
                    "five",    "six",     "seven",     "eight",    "nine",
                    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char post[][10] = {" ",     " ",     "twenty",  "thirty", "fourty",
                   "fifty", "sixty", "seventy", "eighty", "ninety"};
int main() {
  int n, i;
  cin >> n;
  if (n < 20) {
    cout << digit[n] << "\n";
  } else if (n % 10 == 0) {
    cout << post[n % 10] << "\n";
  } else {
    cout << post[n / 10] << "-" << digit[n % 10] << "\n";
  }
  return 0;
}
