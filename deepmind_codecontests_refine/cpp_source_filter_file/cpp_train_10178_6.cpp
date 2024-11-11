#include <bits/stdc++.h>
using namespace std;
double dp[5005][5005];
double dfs(int n, int m) {
  if (m == 0) return 1;
  if (n == 0) return 1.0 / (m + 1);
  if (dp[n][m] > 0) return dp[n][m];
  double A = (double)m / (m + 1) * (1 - dfs(m - 1, n));
  double C = 1.0 / (m + 1) + (double)m / (m + 1) * (1 - dfs(m - 1, n));
  double D = (1.0 - dfs(m, n - 1));
  double p = (D - 1) / (A - 1 - C + D);
  dp[n][m] = p * A + (1 - p);
  return dp[n][m];
}
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) dp[i][j] = -1.0;
  printf("%lf %lf\n", dfs(n, m), 1 - dfs(n, m));
  return 0;
}
