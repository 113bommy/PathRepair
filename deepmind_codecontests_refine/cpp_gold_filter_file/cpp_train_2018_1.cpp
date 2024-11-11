#include <bits/stdc++.h>
using namespace std;
int a[55];
long long int C[55][55];
double dp[55][55][55];
void precompute(int N) {
  for (int i = 0; i <= N; ++i) C[i][0] = 1;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
}
double func(int n, int m, int q) {
  if (dp[n][m][q] >= 0.0) return dp[n][m][q];
  dp[n][m][q] = 0;
  for (int t = 0; t <= n; t++) {
    dp[n][m][q] += (pow(1.0 / m, t) * pow(1.0 - 1.0 / m, n - t) * C[n][t] *
                    func(n - t, m - 1, max(q, (t + (a[m] - 1)) / a[m])));
  }
  return dp[n][m][q];
}
int main() {
  int j, k, i, n, m;
  cin >> n >> m;
  precompute(n);
  for (i = 1; i <= m; i++) cin >> a[i];
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      for (int k = 0; k <= n; ++k) dp[i][j][k] = -1;
  for (j = 0; j <= m; j++) {
    for (k = 0; k <= n; k++) dp[0][j][k] = k;
  }
  for (i = 1; i <= n; i++)
    for (k = 0; k <= n; k++) dp[i][0][k] = 0;
  printf("%.15lf\n", func(n, m, 0));
}
