#include <bits/stdc++.h>
using namespace std;
int n, po[22][3], l, r;
double dp[1 << 20];
const double pi = acos(-1);
const double eps = 1e-7;
double cal(double l, double x, double y, double a) {
  double afa = a * 1.0 / 180 * pi;
  if (l - x > eps) {
    double theta = atan((l - x) / y);
    if ((theta + afa - pi / 2) > eps) return r;
    double res = y * tan(theta + afa) + x;
    if (res - r > eps)
      return r;
    else
      return res;
  } else {
    double theta = atan((x - l) / y);
    double res = x + y * tan(afa - theta);
    if (res - r > eps)
      return r;
    else
      return res;
  }
}
int main() {
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) cin >> po[i][0] >> po[i][1] >> po[i][2];
  dp[0] = l;
  double ans = l;
  int lim = 1 << n;
  for (int i = 1; i < lim; i++) {
    dp[i] = l;
    for (int j = 0; j < n; j++)
      if (i & (1 << j)) {
        double rr = cal(dp[i ^ (1 << j)], po[j][0], po[j][1], po[j][2]);
        if (dp[i] <= rr) dp[i] = rr;
      }
    if (ans < dp[i]) ans = dp[i];
  }
  printf("%.8lf\n", ans - l);
  return 0;
}
