#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long n, i, k;
  cin >> n;
  string str[] = {"January",   "February", "March",    "April",
                  "May",       "June",     "July",     "August",
                  "September", "October",  "November", "December"};
  for (i = 0; i < 12; i++)
    if (s == str[i]) {
      k = i + 1;
      break;
    }
  n %= 12;
  k = (k + n) % 12;
  cout << str[k - 1] << endl;
  return 0;
}
