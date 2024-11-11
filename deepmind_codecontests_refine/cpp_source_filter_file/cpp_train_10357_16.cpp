#include <bits/stdc++.h>
using namespace std;
long long n;
string d[10] = {"",      "ten",   "twenty",  "thirty", "forty",
                "fifty", "sixty", "seventy", "eighty", "ninety"};
string e[10] = {"",     "one", "two",   "three", "four",
                "five", "six", "seven", "eight", "nine"};
string m[10] = {"",        "eleven",  "twelve",    "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  if (n > 10 && n < 20) {
    cout << m[n % 10];
    return 0;
  }
  if (n % 10 != 0 && n > 10) {
    cout << d[n / 10];
    cout << '-';
    cout << e[n % 10];
    return 0;
  }
  if (n < 10) {
    cout << e[n];
    return 0;
  }
  cout << d[n / 10];
  return 0;
}
