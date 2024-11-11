#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  if (abs(a - b) % 2 == 1) {
    cout << -1 << '\n';
  } else if (a == b && a == 0) {
    cout << 0 << '\n';
  } else if (a == b) {
    cout << 1 << '\n';
  } else {
    cout << 2 << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
