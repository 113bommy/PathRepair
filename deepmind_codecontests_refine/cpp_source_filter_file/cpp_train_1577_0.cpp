#include <bits/stdc++.h>
using namespace std;
long long n, a[100001], tot, m, b[100001], mn[100001], cnt[100001];
long long dist(long long x, long long y) {
  return (x <= y) ? (y - x) : (n - x + y);
}
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    long long dis = dist(a[i], b[i]);
    if (!cnt[a[i]])
      mn[a[i]] = dis;
    else
      mn[a[i]] = min(mn[a[i]], dis);
    ++cnt[a[i]];
  }
  for (long long i = 1; i <= n; i++) {
    long long ans = 0;
    for (long long j = 1; j <= n; j++)
      if (cnt[j]) ans = max(ans, dist(i, j) + n * (cnt[j] - 1) + mn[j]);
    cout << ans;
  }
}
