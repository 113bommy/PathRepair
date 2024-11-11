#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  ++m;
  int ans = 0;
  for (int i = 30; i >= 0 && n < m; ++i) {
    if ((n >> i & 1) == (m >> i & 1)) continue;
    if (m >> i & 1) ans ^= 1 << i, n ^= 1 << i;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
