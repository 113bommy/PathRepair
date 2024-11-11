#include <bits/stdc++.h>
using namespace std;
double p[210], dp[210][410][210];
int n, l, a[210];
double solve(int idx, int left, int won) {
  int i, j, k;
  double ans = 0.0;
  if (idx == n) return (double)(won >= l && left >= 0);
  if (dp[idx][left + 200][won] == -1.0) {
    ans = (1 - p[idx]) * solve(idx + 1, left, won);
    ans = ans + (p[idx]) * solve(idx + 1, min(left + a[idx], 200), won + 1);
    dp[idx][left + 200][won] = ans;
  }
  return dp[idx][left + 200][won];
}
int main() {
  int i, j, m, k;
  double ans = 0.0;
  scanf("%d%d%d", &n, &l, &k);
  for (i = 0; i <= 200; i++)
    for (j = 0; j <= 200; j++)
      for (m = 0; m <= 200; m++) dp[i][j][m] = -1.0;
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    p[i] = (double)j / 100;
  }
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  printf("%.6lf\n", solve(0, k, 0));
  return 0;
}
