#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x, m;
  cin >> n >> x >> m;
  int mn = x, mx = x;
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    if (mn <= r && r <= mx) {
      mn = min(mn, l);
      mx = max(mx, r);
    }
    if (mn <= l && l <= mx) {
      mn = min(mn, l);
      mx = max(mx, r);
    }
    if (l <= mn && l <= mx) {
      mn = min(mn, l);
      mx = max(mx, r);
    }
    if (r <= mn && r <= mx) {
      mn = min(mn, l);
      mx = max(mx, r);
    }
  }
  cout << (mx - mn + 1) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
