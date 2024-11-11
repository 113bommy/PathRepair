#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);
int matrix[60][60][60];
int dp[60][60][65];
int main() {
  int N, M, R;
  cin >> N >> M >> R;
  for (int k = 0; k < M; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) cin >> matrix[j][i][k];
  for (int i = 0; i < M; i++)
    for (int k = 0; k < N; k++)
      for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++) {
          int d = matrix[x][k][i] + matrix[k][y][i];
          if (d < matrix[x][y][i]) matrix[x][y][i] = d;
        }
  for (int i = 0; i <= 60; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++) dp[i][j][k] = INF;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      int mn = INF;
      for (int k = 0; k < M; k++) mn = min(mn, matrix[i][j][k]);
      dp[i][j][0] = mn;
    }
  for (int l = 0; l < 60; l++)
    for (int k = 0; k < N; k++)
      for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++) {
          dp[x][y][l + 1] = min(dp[x][y][l + 1], dp[x][k][l] + dp[k][y][0]);
          dp[x][y][l + 1] = min(dp[x][y][l + 1], dp[x][y][l]);
        }
  for (int i = 0; i < R; i++) {
    int s, t, k;
    cin >> s >> t >> k;
    if (k > 60) k = 60;
    cout << dp[t - 1][s - 1][k] << endl;
  }
}
