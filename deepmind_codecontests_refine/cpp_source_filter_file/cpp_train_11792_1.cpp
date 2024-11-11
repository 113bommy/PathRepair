#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n, k, l1, r1, l2, r2, inter = 0, dist = 0;
    cin >> n >> k;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l2 < l1 || (l2 == l1 && r2 < r1)) swap(l1, l2), swap(r2, r1);
    if (r1 < l2) dist = l2 - r1;
    if (dist == 0) inter = min(r1, r2) - l1;
    if (1ll * n * inter >= k) {
      cout << "0\n";
      continue;
    }
    long long ans = 1e18, last = max(r1, r2) - l1;
    for (long long i = 1; i <= n; i++) {
      long long cost = dist * i, left = k - inter * i, rem = (last - inter) * i;
      if (left <= rem)
        cost += left;
      else
        cost += rem + 2 * (left - rem);
      ans = min(ans, cost);
    }
    cout << ans << "\n";
  }
}
