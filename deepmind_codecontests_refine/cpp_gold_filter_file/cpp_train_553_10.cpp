#include <bits/stdc++.h>
using namespace std;
const int N = 62, inf = 1e8;
int n, m, r;
int matrix[N][N][N], dp[N][N][N];
int main() {
  cin >> n >> m >> r;
  for (int x = 0; x < m; x++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cin >> matrix[x][i][j];
  for (int x = 0; x < m; x++)
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          matrix[x][i][j] =
              min(matrix[x][i][j], matrix[x][i][k] + matrix[x][k][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int y = 0; y <= n; y++) dp[i][j][y] = inf;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int x = 0; x < m; x++)
        dp[i][j][0] = min(dp[i][j][0], matrix[x][i][j]);
  for (int y = 1; y <= n; y++)
    for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          dp[i][j][y] = min(dp[i][j][y], dp[i][k][y - 1] + dp[k][j][0]);
  for (int i = 0; i < r; i++) {
    int s, t, k;
    cin >> s >> t >> k;
    s--, t--;
    cout << dp[s][t][min(k, n)] << endl;
  }
  return 0;
}
