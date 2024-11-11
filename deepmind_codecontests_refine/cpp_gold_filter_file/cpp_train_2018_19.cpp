#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int n, m, a[N];
double dp[N][N][N], C[N][N];
double ans;
double Pow(double x, int b) {
  double res = 1.0;
  for (; b; b >>= 1, x = x * x)
    if (b & 1) res = res * x;
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) scanf("%d", a + i);
  C[0][0] = 1;
  for (int i = 1; i <= 50; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  dp[0][0][0] = 1;
  for (int i = 0; i <= n; i++)
    for (int k = 1; k <= m; k++)
      for (int hi = 0; hi <= n; hi++) {
        for (int j = 0; j <= i; j++) {
          int high = (j + a[k] - 1) / a[k];
          if (high <= hi)
            dp[i][k][hi] += C[i][j] * dp[i - j][k - 1][hi];
          else
            dp[i][k][high] += C[i][j] * dp[i - j][k - 1][hi];
        }
      }
  for (int i = 0; i <= n; i++) ans += 1.0 * i * dp[n][m][i] * Pow(1.0 / m, n);
  printf("%.15lf\n", ans);
  return 0;
}
