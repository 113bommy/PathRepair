#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int N = 2010;
long double dp[N][N], p[N], u[N], pab[N];
int n, a, b, opt[N][N];
double x;
int solve(long double C) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= a; j++) {
      long double &ret = dp[i][j] = dp[i - 1][j];
      int &tot = opt[i][j] = opt[i - 1][j];
      if (j && p[i] + dp[i - 1][j - 1] > ret) {
        ret = p[i] + dp[i - 1][j - 1];
        tot = opt[i - 1][j - 1];
      }
      if (u[i] + dp[i - 1][j] - C > ret) {
        ret = u[i] + dp[i - 1][j] - C;
        tot = opt[i - 1][j] + 1;
      }
      if (j && pab[i] + dp[i - 1][j - 1] - C > ret) {
        ret = pab[i] + dp[i - 1][j - 1] - C;
        tot = opt[i - 1][j - 1] + 1;
      }
    }
  }
  return opt[n][a];
}
int main(int argc, char const *argv[]) {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 1; i <= n; ++i) scanf("%lf", &x), p[i] = x;
  for (int i = 1; i <= n; ++i) scanf("%lf", &x), u[i] = x;
  for (int i = 1; i <= n; ++i) pab[i] = p[i] + u[i] - p[i] * u[i];
  long double lo = 0, hi = 1;
  long double eps = 1.0 / b * 1e-4;
  while (fabs(hi - lo) > eps) {
    long double mid = (lo + hi) / 2;
    if (solve(mid) <= b)
      hi = mid;
    else
      lo = mid;
  }
  solve(hi);
  double ans = dp[n][a] + hi * b;
  printf("%.6f\n", ans);
}
