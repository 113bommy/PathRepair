#include <bits/stdc++.h>
using namespace std;
const long long MXN = 200 + 10;
long long n, m, k;
long long A[MXN], B[MXN], C[MXN], dp[MXN][MXN][MXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k, memset(dp, -63, sizeof dp);
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= m; i++) cin >> B[i];
  for (int i = 1; i <= k; i++) cin >> C[i];
  sort(A + 1, A + n + 1);
  sort(B + 1, B + m + 1);
  sort(C + 1, C + k + 1);
  dp[0][0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int h = 0; h <= k; h++) {
        if (i) dp[i][j][h] = max(dp[i][j][h], dp[i - 1][j][h]);
        if (j) dp[i][j][h] = max(dp[i][j][h], dp[i][j - 1][h]);
        if (h) dp[i][j][h] = max(dp[i][j][h], dp[i][j][h - 1]);
        if (i && j)
          dp[i][j][h] = max(dp[i][j][h], dp[i - 1][j - 1][h] + A[i] * B[j]);
        if (i && h)
          dp[i][j][h] = max(dp[i][j][h], dp[i - 1][j][h - 1] + A[i] * C[h]);
        if (j && h)
          dp[i][j][h] = max(dp[i][j][h], dp[i][j - 1][h - 1] + B[j] * C[h]);
      }
    }
  }
  cout << dp[n][m][k] << '\n';
  return 0;
}
