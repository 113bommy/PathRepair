#include <bits/stdc++.h>
using namespace std;
string calendar[] = {"January",   "February", "March",    "April",
                     "May",       "June",     "July",     "August",
                     "September", "October",  "November", "December"};
int main() {
  string m;
  cin >> m;
  int n;
  cin >> n;
  int c;
  for (int i = 0; i < 12; i++) {
    if (calendar[i] == m) {
      c = i;
    }
  }
  int mod = n % 12;
  c += mod;
  c %= 12;
  cout << calendar[c] << endl;
  return 0;
}
