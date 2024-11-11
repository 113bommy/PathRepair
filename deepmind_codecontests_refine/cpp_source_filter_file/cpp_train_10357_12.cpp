#include <bits/stdc++.h>
using namespace std;
int main() {
  string a[10] = {"zero", "one", "two",   "three", "four",
                  "five", "six", "seven", "eight", "nine"};
  string b[10] = {"ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                  "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
  string c[10] = {"tmp",   "ten",   "twenty",  "thirty", "fourty",
                  "fifty", "sixty", "seventy", "eighty", "ninety"};
  long long n;
  cin >> n;
  if (n < 10)
    cout << a[n];
  else if (n < 20)
    cout << b[n % 10];
  else {
    cout << c[n / 10];
    if (n % 10) cout << '-' << a[n % 10];
  }
}
