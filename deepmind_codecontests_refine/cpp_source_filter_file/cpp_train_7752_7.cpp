#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
const double INF = 1e12, EPS = 1e-9;
int n, k, e, d[100];
double dp[101][101], p[100];
bool ok(double r) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  r *= r;
  for (int i = 0; i < n; i++) {
    if (d[i] < r + EPS)
      p[i] = 1;
    else
      p[i] = exp(1 - d[i] / r);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i + 1; j++) {
      dp[i + 1][j + 1] += dp[i][j] * p[i];
      dp[i + 1][j] += dp[i][j] * (1 - p[i]);
    }
  double prob = 0;
  for (int i = 0; i < k; i++) prob += dp[n][i];
  return prob * 1000 - EPS < e;
}
void run() {
  int x0, y0;
  cin >> n >> k >> e >> x0 >> y0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    d[i] = (x - x0) * (x - x0) + (y - y0) * (y - y0);
  }
  double l = 0, r = 2500, mid;
  for (int i = 0; i < 100; i++) {
    mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.9f\n", l);
}
int main() { run(); }
