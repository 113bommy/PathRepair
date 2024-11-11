#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[1005][1005];
int dp2[1005][1005];
int dp3[1005][1005];
int dp4[1005][1005];
int arr[1005][1005];
int main() {
  cin >> n >> m;
  for (int i = 0; i < 1005; i++)
    for (int j = 0; j < 1005; j++) {
      dp[i][j] = -1;
      dp2[i][j] = -1;
      dp3[i][j] = -1;
      dp4[i][j] = -1;
    }
  dp[0][1] = 0;
  dp[1][0] = 0;
  dp2[n + 1][0] = 0;
  dp2[n][0] = 0;
  dp3[0][m] = 0;
  dp3[1][m + 1] = 0;
  dp4[n + 1][m] = 0;
  dp4[n][m + 1] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> arr[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
    }
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++) {
      dp2[i][j] = max(dp2[i + 1][j], dp2[i][j - 1]) + arr[i][j];
    }
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--) {
      dp3[i][j] = max(dp3[i - 1][j], dp3[i][j + 1]) + arr[i][j];
    }
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--) {
      dp4[i][j] = max(dp4[i + 1][j], dp4[i][j + 1]) + arr[i][j];
    }
  int beta = -1e9;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i == 1 || i == n || j == 1 || j == m) continue;
      beta = max(dp[i - 1][j] + dp2[i][j - 1] + dp3[i][j + 1] + dp4[i + 1][j],
                 beta);
      beta = max(dp[i][j - 1] + dp2[i + 1][j] + dp3[i - 1][j] + dp4[i][j + 1],
                 beta);
    }
  cout << beta << endl;
}
