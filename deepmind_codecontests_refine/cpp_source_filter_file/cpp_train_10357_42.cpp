#include <bits/stdc++.h>
using namespace std;
string st[101] = {"zeor",    "one",     "two",       "three",    "four",
                  "five",    "six",     "seven",     "eight",    "nine",
                  "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                  "twenty",  "thirty",  "forty",     "fifty",    "sixty",
                  "seventy", "eighty",  "ninety"};
int main() {
  int n;
  while (cin >> n) {
    if (n <= 20)
      cout << st[n];
    else if (n % 10 == 0)
      cout << st[20 + n / 10 - 2];
    else if (n < 30)
      cout << st[20] + '-' + st[n % 10];
    else if (n < 40)
      cout << st[21] + '-' + st[n % 10];
    else if (n < 50)
      cout << st[22] + '-' + st[n % 10];
    else if (n < 60)
      cout << st[23] + '-' + st[n % 10];
    else
      cout << st[20 + n / 10 - 2] + '-' + st[n % 10];
    cout << endl;
  }
  return 0;
}
