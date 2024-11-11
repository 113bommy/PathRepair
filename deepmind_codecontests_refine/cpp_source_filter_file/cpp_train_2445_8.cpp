#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
void solve() {
  long long a, b, n;
  cin >> a >> b >> n;
  long long l, t, m;
  for (long long i = 0; i < n; i += 1) {
    cin >> l >> t >> m;
    long long vl = a + (l - 1) * b;
    if (vl > t) {
      cout << -1 << '\n';
      continue;
    }
    long long lo = l, hi = 1e15;
    long long ans = -1;
    while (lo <= hi) {
      long long mid = (hi + lo) / 2;
      long long f = abs(l - mid);
      long long val = vl * (f + 1) + (f * (f + 1)) / 2 * b;
      if (val > m * t || a + (mid - 1) * b > t) {
        hi = mid - 1;
      } else {
        ans = max(ans, mid);
        lo = mid + 1;
      }
    }
    cout << ans << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tin = 1;
  while (tin--) {
    solve();
  }
  return 0;
}
