#include <bits/stdc++.h>
using namespace std;
string st[13] = {"January",   "February", "March",    "April",
                 "May",       "June",     "July",     "August",
                 "September", "October",  "November", "December"};
void solve() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  int y = 0;
  for (int i = 0; i < 12; i++) {
    if (st[i] == s) {
      y = i + n;
      break;
    }
  }
  while (y > 12) {
    y = y - 12;
  }
  cout << st[y] << '\n';
}
int main() {
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
