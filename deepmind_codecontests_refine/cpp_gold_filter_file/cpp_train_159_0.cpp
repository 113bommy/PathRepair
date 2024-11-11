#include <bits/stdc++.h>
using namespace std;
const long long N = 1000005;
long long s, t, n, c[N], v[N], k, g[N];
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> s >> t;
  for (long long i = 1; i <= n; i++) cin >> c[i] >> v[i];
  for (long long i = 1; i <= k; i++) cin >> g[i];
  sort(g + 1, g + k + 1);
  g[k + 1] = s;
  long long l = 1, r = 2e9;
  while (l < r) {
    long long mid = (l + r) / 2;
    long long sum = 0;
    long long flag = 1;
    for (long long i = 1; i <= k + 1; i++) {
      long long len = g[i] - g[i - 1];
      long long x = 2 * len - mid;
      if (x > len) {
        flag = 0;
        break;
      }
      x = max(x, 0ll);
      sum += x + len;
    }
    if (sum > t) flag = 0;
    if (flag)
      r = mid;
    else
      l = mid + 1;
  }
  long long ans = 1e18;
  for (long long i = 1; i <= n; i++)
    if (v[i] >= r) ans = min(ans, c[i]);
  if (ans == 1e18)
    cout << -1;
  else
    cout << ans;
}
