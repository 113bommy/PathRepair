#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long l, r;
  cin >> l >> r;
  cout << (l * 2 <= r ? "YES\n" : "NO\n");
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
