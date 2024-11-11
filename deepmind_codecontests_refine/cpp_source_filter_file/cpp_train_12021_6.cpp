#include <bits/stdc++.h>
using namespace std;
int n;
double l, x[1009], b[1009], dp[1009][1009];
int pre[1009][1009];
double check(double m, bool flag) {
  memset(pre, 0, sizeof(pre));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = 1e19;
  dp[1][1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++) {
      dp[i][j] = dp[i - 1][j];
      if (dp[i][i] > sqrt(fabs(x[i] - x[j] - l)) - m * b[i] + dp[i - 1][j]) {
        dp[i][i] = sqrt(fabs(x[i] - x[j] - l)) - m * b[i] + dp[i - 1][j];
        pre[i][i] = j;
      }
    }
  }
  return dp[n][n];
}
void output(int x) {
  if (x == 0) return;
  output(pre[x][x]);
  printf("%d ", x);
}
int main() {
  scanf("%d%lf", &n, &l);
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &x[i], &b[i]);
  double L = 0, R = 2e9;
  while (R - L > 1e-10) {
    double M = (L + R) / 2;
    if (check(M, 0) < 0)
      R = M;
    else
      L = M;
  }
  check(L, 1);
  output(n);
  return 0;
}
