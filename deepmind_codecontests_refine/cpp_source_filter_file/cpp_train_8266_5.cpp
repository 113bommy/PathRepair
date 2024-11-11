#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.);
int n;
double l, r;
double x[22], y[22], a[22];
double dp[(1 << 20) | 5];
int main() {
  cin >> n >> l >> r;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> a[i];
    a[i] *= PI / 180.;
  }
  for (int i = 0; i < (1 << n); ++i) dp[i] = i == 0 ? l : -1e8;
  for (int i = 0; i < (1 << n); ++i)
    for (int j = 0; j < n; ++j)
      if (!(i & (1 << j))) {
        double ang = atan2(-y[j], -x[j] + dp[i]);
        ang += a[j];
        if (ang + 1e-8 > 0.) {
          printf("%.10lf\n", r - l);
          return 0;
        }
        dp[i | (1 << j)] = max(dp[i | (1 << j)], x[j] - y[j] / tan(ang));
      }
  printf("%.10lf\n", min(r - l, dp[(1 << n) - 1]) - l);
}
