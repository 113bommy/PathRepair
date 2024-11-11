#include <bits/stdc++.h>
using namespace std;
int main() {
  const string tenToNineteen[] = {"ten",      "eleven",  "twelve",  "thirteen",
                                  "fourteen", "fifteen", "sixteen", "seventeen",
                                  "eighteen", "nineteen"};
  const string tenFromTen[] = {"twenty", "thirty",  "forty",  "fifty",
                               "sixty",  "seventy", "eighty", "ninety"};
  const string firstTen[] = {"zero", "one", "two",   "three", "four",
                             "five", "six", "seven", "eight", "nine"};
  int n;
  cin >> n;
  int support = n % 10;
  int firstDigit = n / 10;
  if (n < 10) {
    cout << firstTen[n] << endl;
  } else if (n >= 10 && n <= 19) {
    cout << tenToNineteen[n - 10] << endl;
  } else if (n >= 20 && n <= 99 && support == 0) {
    cout << tenFromTen[firstDigit - 2] << endl;
  } else if (n >= 20 && n <= 99 && support != 0) {
    cout << tenFromTen[firstDigit - 2] << "-" << firstTen[support] << endl;
  }
}
