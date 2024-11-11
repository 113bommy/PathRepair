#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t p;
  cin >> p;
  cout << "2 " << p - (p % 2) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t test = 1;
  cin >> test;
  while (test--) solve();
  return 0;
}
