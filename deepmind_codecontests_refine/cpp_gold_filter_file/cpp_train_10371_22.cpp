#include <bits/stdc++.h>
using namespace std;
int sc[150];
int p[75][75];
double q[150][75];
int l[150], r[150];
double dp[150][75];
double sum[150];
int main() {
  int i, j, k, n, N, pnt;
  cin >> N;
  n = 1 << N;
  for (i = 1; i <= n; i++) {
    q[0][i] = 1;
    for (j = 1; j <= n; j++) {
      scanf("%d", &p[i][j]);
    }
  }
  for (pnt = 1; pnt < n; pnt <<= 1)
    ;
  for (i = 1; i <= n; i++) {
    l[pnt + i - 1] = i;
    r[pnt + i - 1] = i;
    sc[pnt + i - 1] = 100000;
    q[pnt + i - 1][i] = 1;
  }
  for (i = pnt; --i;) {
    sc[i] = sc[2 * i];
    int l1 = l[2 * i], l2 = l[2 * i + 1];
    int r1 = r[2 * i], r2 = r[2 * i + 1];
    for (j = l1; j <= r1; j++) {
      for (q[i][j] = 0, k = l2; k <= r2; k++)
        q[i][j] += 0.01 * p[j][k] * q[2 * i + 1][k];
      q[i][j] *= q[2 * i][j];
      dp[i][j] =
          max(dp[i][j], dp[2 * i][j] + dp[2 * i + 1][0] + sc[i] * q[i][j]);
    }
    for (k = l2; k <= r2; k++) {
      for (q[i][k] = 0, j = l1; j <= r1; j++)
        q[i][k] += 0.01 * p[k][j] * q[2 * i][j];
      q[i][k] *= q[2 * i + 1][k];
      dp[i][k] =
          max(dp[i][k], dp[2 * i + 1][k] + dp[2 * i][0] + sc[i] * q[i][k]);
    }
    l[i] = min(l1, l2), r[i] = max(r1, r2), sc[i] = 2 * sc[2 * i];
    for (dp[i][0] = 0, j = l[i]; j <= r[i]; j++)
      dp[i][0] = max(dp[i][0], dp[i][j]);
  }
  printf("%.10lf\n", dp[1][0] / 100000);
}
