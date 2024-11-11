#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans = 0, x, y, z, MAX, MIN;
string str, str1, str2;
char C;
bool flag = false;
int main() {
  string a[20] = {"Zero",    "one",    "two",       "three",    "four",
                  "five",    "six",    "seven",     "eight",    "nine",
                  "ten",     "eleven", "twelve",    "thirteen", "fourteen",
                  "fifteen", "sixten", "seventeen", "eighteen", "nineteen"};
  string b[8] = {"twenty", "thirty",  "forty",  "fifty",
                 "sixty",  "seventy", "eighty", "ninety"};
  cin >> n;
  if (n < 20) {
    cout << a[n] << endl;
  } else if (n % 10 == 0) {
    cout << b[n / 10 - 2] << endl;
  } else {
    cout << b[n / 10 - 2] << "-" << a[n % 10] << endl;
  }
  return 0;
}
