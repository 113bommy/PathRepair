#include <bits/stdc++.h>
using namespace std;
double dp[55][55][55];
long long C[55][55];
int a[55];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  cout.precision(15);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= n; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  for (int i = 1; i <= m; ++i) cin >> a[i];
  for (int i = 0; i <= n; ++i) dp[0][0][i] = i;
  for (int i = 0; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int k = 0; k <= n; ++k)
        for (int c = 0; c <= i; ++c)
          dp[i][j][k] += pow(1.0 / j, c) * pow(1.0 - 1.0 / j, i - c) * C[i][c] *
                         dp[i - c][j - 1][max(k, (c + a[j] - 1) / a[j])];
  cout << dp[n][m][0] << endl;
  return 0;
}
