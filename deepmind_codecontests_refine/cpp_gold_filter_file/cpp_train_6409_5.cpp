#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;
int main() {
  long long mid, l, r, ans = INF, n, m, k, x, s;
  vector<long long> a, b, c, d;
  cin >> n >> m >> k >> x >> s;
  a.resize(m);
  b.resize(m);
  c.resize(k);
  d.resize(k);
  for (int i = 0; i < m; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  for (int i = 0; i < k; ++i) cin >> c[i];
  for (int i = 0; i < k; ++i) cin >> d[i];
  ans = n * x;
  for (int i = 0; i < k; ++i) {
    if (s >= d[i]) ans = min(ans, (n - c[i]) * x);
  }
  for (int i = 0; i < m; ++i) {
    l = 0;
    r = k;
    if (s - b[i] > 0)
      while (r - l > 1) {
        mid = (l + r) / 2;
        if (d[mid] > s - b[i])
          r = mid;
        else
          l = mid;
      }
    if (d[l] <= s - b[i])
      ans = min(ans, (n - c[l]) * a[i]);
    else if (s >= b[i])
      ans = min(ans, n * a[i]);
  }
  cout << ans;
}
