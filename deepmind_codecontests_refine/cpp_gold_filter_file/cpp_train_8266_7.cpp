#include <bits/stdc++.h>
using namespace std;
struct point {
  double x;
  double y;
  double a;
} p[25];
double dp[2000000];
double toRad(double a) { return (a / 180.0) * M_PI; }
int main() {
  int n, l, r;
  scanf("%d%d%d", &n, &l, &r);
  for (int i = 0; i < n; i++) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].a);
  dp[0] = l;
  for (int i = 1; i < (1 << n); i++) {
    double w, best = -1000000007;
    for (int j = 0; j < n; j++) {
      if (!(i & (1 << j))) continue;
      int prev = i ^ (1 << j);
      double b = p[j].y;
      if (dp[prev] < p[j].x) {
        double d = p[j].x - dp[prev];
        double angle = atan(d / b) - toRad(p[j].a);
        w = (angle < M_PI / 2.0) ? d - b * tan(angle) : 1000000007;
      } else {
        double d = dp[prev] - p[j].x;
        double angle = atan(d / b) + toRad(p[j].a);
        w = (angle < M_PI / 2.0) ? b * tan(angle) - d : 1000000007;
      }
      w = (dp[prev] + w <= r) ? dp[prev] + w : r;
      best = max(w, best);
    }
    dp[i] = best;
  }
  printf("%.9lf\n", dp[(1 << n) - 1] - l);
  return 0;
}
