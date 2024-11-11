#include <bits/stdc++.h>
const int N = 10005;
const int inf = 1 << 28;
const int mod = 1e9 + 7;
const int zero = 10000;
const double pi = acos(-1.0);
const double eps = 1e-8;
using namespace std;
int n, L, R;
struct seg {
  int x, y, a;
} p[21];
double dp[(1 << 20) + 5];
double DP() {
  double l = L;
  double res = 0.0;
  for (int i = 0; i < (1 << n); i++) dp[i] = -1.0;
  dp[0] = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (dp[i] < 0) continue;
    res = max(res, dp[i]);
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) continue;
      double x = l + dp[i], len;
      double a = pi * p[j].a / 180;
      if (fabs(x - p[j].x) < eps) {
        if (p[j].a == 90)
          len = 1e8;
        else
          len = p[j].y * atan(1.0 * a);
      } else if (x > p[j].x) {
        double ang = atan((x - p[j].x) / p[j].y);
        if (ang + a > 0.5 * pi || (fabs(ang + a - 0.5 * pi) < eps))
          len = 1e8;
        else
          len = p[j].y * tan(ang + a) - (x - p[j].x);
      } else {
        double ang = atan((p[j].x - x) / p[j].y);
        if (ang < a)
          len = p[j].y * tan(a - ang) + (p[j].x - x);
        else {
          len = p[j].x - x - p[j].y * tan(ang - a);
        }
      }
      int k = i | (1 << j);
      dp[k] = max(dp[k], dp[i] + len);
    }
  }
  res = min(res, 1.0 * R - L);
  return res;
}
int main() {
  while (cin >> n >> L >> R) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].a);
    }
    double res = DP();
    printf("%.8f\n", res);
  }
  return 0;
}
