#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, d, a[N], m;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> d;
  for (int i = 1; i <= n; i++) cin >> a[i], ++a[i];
  a[0] = INT_MIN >> 2;
  a[n + 1] = INT_MAX >> 2;
  cin >> m;
  while (m--) {
    double ans = 0;
    int x;
    cin >> x;
    int pos = lower_bound(a + 1, a + n + 1, x + 1) - a - 1;
    ans = max(ans, atan(1.0 / (x - a[pos])));
    if (pos != n) ans = max(ans, atan(1.0 / (a[pos + 1] - 1 - x)));
    int l = pos, r = pos + 1;
    while (x - a[l] <= d && a[r] - 1 - x <= d &&
           abs(a[r] - 1 - x - x - a[l]) > 1)
      if (x - a[l] <= a[r] - 1 - x)
        --l;
      else
        ++r;
    if (abs(a[r] - 1 - x - (x - a[l])) <= 1) {
      int kk = max(a[r] - 1 - x, x - a[l]);
      ans = max(ans, 2 * atan(1.0 / kk));
    }
    printf("%.10lf\n", ans);
  }
  return 0;
}
