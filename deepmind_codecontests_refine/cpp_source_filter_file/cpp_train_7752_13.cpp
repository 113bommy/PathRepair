#include <bits/stdc++.h>
using namespace std;
int X, Y, x[101], y[101];
int n, K;
double ep;
double e(double d, double r) { return exp(1 - (d * d) / (r * r)); }
double dist(int i) {
  return sqrt((X - x[i]) * (X - x[i]) + (Y - y[i]) * (Y - y[i]));
}
double dp[101][101];
double solve(double r) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    double p, d = dist(i);
    if (d <= r)
      p = 1;
    else
      p = e(d, r);
    for (int j = 0; j <= i; j++) {
      dp[i][j] += dp[i - 1][j] * (1.0 - p);
      dp[i][j + 1] += dp[i - 1][j] * p;
    }
  }
  double ret = 0;
  for (int i = K; i <= n; i++) ret += dp[n][i];
  return ret;
}
int main() {
  cin >> n;
  cin >> K >> ep;
  ep /= 1000.0;
  ep = 1.0 - ep;
  cin >> X >> Y;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  double lo = 0, hi = 1024;
  for (int i = 0; i < 100; i++) {
    double mi = lo + (hi - lo) / 2.0;
    if (solve(mi) >= ep)
      hi = mi;
    else
      lo = mi;
  }
  printf("%.12lf\n", hi);
  return 0;
}
