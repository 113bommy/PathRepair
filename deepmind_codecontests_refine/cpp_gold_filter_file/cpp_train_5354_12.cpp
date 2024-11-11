#include <bits/stdc++.h>
using namespace std;
int n, m;
int row[2005], col[2005];
double dp[2005][2005];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int r, c;
    cin >> r >> c;
    row[r] = col[c] = 1;
  }
  int cr = 0, cc = 0;
  for (int i = 1; i <= n; ++i) cr += (row[i]), cc += (col[i]);
  dp[n][n] = 0;
  for (int i = n; i >= 0; --i)
    for (int j = n; j >= 0; --j) {
      if (i == n && j == n) continue;
      if (i != n)
        dp[i][j] += (double)(n - i) * j / (double)(n * n) * dp[i + 1][j];
      if (j != n)
        dp[i][j] += (double)i * (n - j) / (double)(n * n) * dp[i][j + 1];
      if (i != n && j != n)
        dp[i][j] +=
            (double)(n - i) * (n - j) / (double)(n * n) * dp[i + 1][j + 1];
      dp[i][j] += 1;
      dp[i][j] = dp[i][j] * (double)(n * n) / (double)(n * n - i * j);
    }
  cout << fixed << setprecision(8) << dp[cr][cc] << '\n';
  return 0;
}
