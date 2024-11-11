#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, m;
  cin >> n >> m;
  int64_t a[n];
  int64_t b[m];
  int64_t mi = 0;
  int64_t ma = 0;
  for (int64_t i = 0; i < n; i++) cin >> a[i];
  for (int64_t i = 0; i < m; i++) cin >> b[i];
  int64_t mii = 1e18;
  for (int64_t i = 0; i < min(n, m); i++) {
    ma = max(ma, a[i]);
  }
  for (int64_t i = 0; i < m; i++) mii = min(mii, b[i]);
  if (ma > mii) return cout << -1, 0;
  int64_t ans = 0;
  for (int64_t i = 0; i < n; i++) ans += m * a[i];
  for (int64_t i = 0; i < m; i++) ans += b[i];
  sort(a, a + n);
  for (int64_t i = 0; i < m; i++) {
    if (a[n - 1] == b[i]) {
      mi = 1;
      break;
    }
  }
  ans -= (m - 1) * a[n - 1];
  if (mi != 1)
    ans -= a[n - 2];
  else
    ans -= a[n - 1];
  cout << ans << "\n";
  return 0;
}
