#include <bits/stdc++.h>
using namespace std;
long long n, k, res;
pair<long long, long long> p[200005];
long long d[200005], f[200005];
long long bs(long long x) {
  long long l, r, mid, ans = -1;
  l = 1, r = n;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (p[mid].first <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}
void solve() {
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) cin >> p[i].first;
  for (long long i = 1; i <= n; ++i) cin >> p[i].second;
  sort(p + 1, p + n + 1);
  res = f[n + 1] = 0;
  for (long long i = 1; i <= n; ++i) d[i] = bs(p[i].first + k) - i + 1;
  for (long long i = n; i >= 1; --i) f[i] = max(d[i], f[i + 1]);
  for (long long i = 1; i <= n; ++i) res = max(res, f[i] + f[i + f[i]]);
  cout << res << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  if (1) {
    long long t;
    cin >> t;
    while (t--) solve();
  } else {
    solve();
  }
}
