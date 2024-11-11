#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
double dis(long long x1, long long y1, long long x2, long long y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void solve() {
  int a[2], b[2], t[2];
  cin >> a[0] >> a[1];
  cin >> b[0] >> b[1];
  cin >> t[0] >> t[1];
  int n;
  cin >> n;
  double sum = 0;
  pair<long long, long long> x[n];
  vector<double> da, db;
  vector<double> pre(n), suf(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i].first >> x[i].second;
    double tmp = dis(x[i].first, x[i].second, t[0], t[1]);
    sum += (tmp * 2);
    da.push_back(dis(a[0], a[1], x[i].first, x[i].second) - tmp);
    db.push_back(dis(b[0], b[1], x[i].first, x[i].second) - tmp);
  }
  for (int i = 0; i < n; i++) {
    if (i == 0)
      pre[i] = da[i];
    else
      pre[i] = min(pre[i - 1], da[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1)
      suf[i] = da[i];
    else
      suf[i] = min(suf[i + 1], da[i]);
  }
  double ans = sum + pre[n - 1];
  for (int i = 1; i <= n - 2; i++) {
    ans = (double)min(
        ans, sum +
                 (double)min((double)0.0, (double)min(pre[i - 1], suf[i + 1])) +
                 db[i]);
  }
  ans = min(ans, sum + db[n - 1] +
                     ((n - 2 >= 0) ? min((double)0.0, pre[n - 2]) : 0.0));
  ans = min(ans,
            db[0] + sum + ((1 < n) ? min((double)0.0, pre[1]) : (double)0.0));
  cout << fixed << setprecision(12) << ans << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
