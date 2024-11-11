#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string units[] = {"zero",    "one",     "two",       "three",    "four",
                    "five",    "six",     "seven",     "eight",    "nine",
                    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  string tenth[] = {"twenty", "thirty",  "forty",  "fifty",
                    "sixty",  "seventy", "eighty", "ninety"};
  if (n < 20)
    cout << units[n];
  else {
    int last = n % 10;
    int first = n / 10;
    if (last == 0)
      cout << tenth[first - 2];
    else
      cout << tenth[first - 2] << "-" << units[last - 1];
  }
  return 0;
}
