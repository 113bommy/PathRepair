#include <bits/stdc++.h>
using namespace std;
string last_dig[] = {"zero", "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};
string first_dig[] = {"twenty", "thirty",  "forty",  "fifty",
                      "sixty",  "seventy", "eighty", "ninety"};
int n, last, first;
int main() {
  scanf("%d", &n);
  last = n % 10;
  if (n < 10) {
    cout << last_dig[last];
  } else {
    n /= 10;
    first = n;
    if (first == 1) {
      if (last == 0) cout << "ten";
      if (last == 1) cout << "eleven";
      if (last == 2) cout << "twelve";
      if (last == 3) cout << "thirteen";
      if (last == 4) cout << "forteen";
      if (last == 5) cout << "fifteen";
      if (last == 6) cout << "sixteen";
      if (last == 7) cout << "seventeen";
      if (last == 8) cout << "eighteen";
      if (last == 9) cout << "nineteen";
    } else {
      if (last == 0)
        cout << first_dig[first - 2];
      else
        cout << first_dig[first - 2] << "-" << last_dig[last];
    }
  }
}
