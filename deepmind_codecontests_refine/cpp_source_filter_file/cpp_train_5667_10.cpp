#include <bits/stdc++.h>
using namespace std;
long long n, i, j, d, m, x, y, p, k, max1, a[5000], b[5000], rez, rows, cols;
double dp[2200][2200];
string s;
int main() {
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> x >> y;
    if (a[x] == 0) rows++;
    if (a[y] == 0) cols++;
    a[x] = 1;
    a[y] = 1;
  }
  for (i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + (double)n / i;
  for (j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] + (double)n / j;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) {
      double x = 0;
      x = (dp[i - 1][j] * (double)(i * (n - j)) +
           dp[i][j - 1] * (double)((n - i) * j) +
           dp[i - 1][j - 1] * (double)(i * j)) /
          (double)(n * n);
      dp[i][j] = x + 1.;
      dp[i][j] /= (1. - (double)((n - i) * (n - j)) / (n * n));
    }
  printf("%.10f\n", dp[n - rows][n - cols]);
  return 0;
}
