#include <bits/stdc++.h>
using namespace std;
int solve(int n, int m, int k) {
  if (n > m) return 0;
  if (n == 0) return min(m + 1, (1 << (k + 1)));
  if ((1 << k) & n) {
    int c = solve(n - (1 << k), m - (1 << k), k - 1);
    if (c == (1 << k))
      return (1 << (k + 1));
    else
      return c;
  } else {
    int z = solve(n, m - (1 << k), k - 1);
    if (z == (1 << k))
      return 2 * z;
    else {
      int c = solve(n, m, k - 1);
      if (c == (1 << k))
        return (1 << k) + z;
      else
        return c;
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  cout << solve(n, m, 30) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
