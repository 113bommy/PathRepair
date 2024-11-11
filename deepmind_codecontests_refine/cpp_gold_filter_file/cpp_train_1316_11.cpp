#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, e, l, v;
  cin >> n >> m >> l >> e >> v;
  long long a[l], b[e];
  for (int i = (0), _ = (l); i < _; ++i) cin >> a[i];
  for (int i = (0), _ = (e); i < _; ++i) cin >> b[i];
  int q;
  cin >> q;
  while (q--) {
    long long ans = 1e18;
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
      cout << abs(y2 - y1) << endl;
    else {
      long long i = lower_bound(a, a + l, y1) - a;
      if (i < l) ans = min(ans, abs(y1 - a[i]) + abs(y2 - a[i]) + abs(x1 - x2));
      if (i > 0)
        ans = min(ans, abs(a[i - 1] - y1) + abs(a[i - 1] - y2) + abs(x1 - x2));
      i = lower_bound(b, b + e, y1) - b;
      if (i < e)
        ans = min(ans,
                  abs(b[i] - y1) + abs(b[i] - y2) + (abs(x1 - x2) + v - 1) / v);
      if (i > 0)
        ans = min(ans, abs(b[i - 1] - y1) + abs(b[i - 1] - y2) +
                           (abs(x2 - x1) + v - 1) / v);
      cout << ans << endl;
    }
  }
  return 0;
}
