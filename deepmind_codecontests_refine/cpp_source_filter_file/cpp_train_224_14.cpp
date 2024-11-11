#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, l, r;
  cin >> n;
  long long dl, dr;
  dl = 0, dr = 1e5;
  for (long long i = 0; i < n; i++) {
    cin >> l >> r;
    dl = max(dl, l), dr = min(dr, r);
  }
  cout << max(0ll, dl - dr) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
