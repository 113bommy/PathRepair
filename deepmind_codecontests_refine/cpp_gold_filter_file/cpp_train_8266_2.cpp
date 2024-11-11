#include <bits/stdc++.h>
using namespace std;
int n;
const double PI = acos(-1.0);
double dp[1 << 21];
double a[22], x[22], y[22];
double solve(double l, int c) {
  double d1 = sqrt((x[c] - l) * (x[c] - l) + y[c] * y[c]);
  if (x[c] <= l) {
    double a1 = PI - asin(y[c] / d1);
    if (a[c] + a1 >= PI) return 100000;
    double a2 = PI - a[c] - a1;
    return l + d1 * sin(a[c]) / sin(a2);
  } else {
    double a1 = asin(y[c] / d1);
    if (a[c] + a1 >= PI) return 100000;
    double a2 = PI - a[c] - a1;
    return l + d1 * sin(a[c]) / sin(a2);
  }
}
int main() {
  double l, r;
  scanf("%d%lf%lf", &n, &l, &r);
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf%lf", &x[i], &y[i], &a[i]);
    a[i] = a[i] / 180 * PI;
  }
  int full = (1 << n) - 1;
  for (int i = 0; i <= full; i++) dp[i] = l;
  for (int i = 0; i < full; i++) {
    for (int j = 0; j < n; j++)
      if (!(i & (1 << j))) {
        double cur = solve(dp[i], j);
        if (cur >= r) {
          printf("%.10lf\n", r - l);
          return 0;
        }
        dp[i | (1 << j)] = max(dp[i | (1 << j)], cur);
      }
  }
  printf("%.10lf\n", dp[full] - l);
  return 0;
}
