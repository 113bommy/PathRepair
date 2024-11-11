#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string digit[10] = {"",     "one", "two",   "three", "four",
                      "five", "six", "seven", "eight", "nine"};
  string tenth[10] = {"",      "ten",   "twenty",  "thrity", "forty",
                      "fifty", "sixty", "seventy", "eighty", "ninety"};
  string tenx[10] = {"ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  cin >> n;
  switch (n / 10) {
    case 0:
      cout << digit[n % 10] << endl;
      break;
    case 1:
      cout << tenx[n % 10] << endl;
      break;
    default:
      if (digit[n % 10] == "")
        cout << tenth[n / 10] << endl;
      else
        cout << tenth[n / 10] << "-" << digit[n % 10] << endl;
      break;
  }
  if (n == 0) printf("zero");
  return (0);
}
