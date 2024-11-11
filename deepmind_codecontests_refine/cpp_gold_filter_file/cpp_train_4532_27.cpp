#include <bits/stdc++.h>
using namespace std;
int dp[20][20];
set<pair<pair<int, int>, pair<int, int>>> st;
int main() {
  int r, c, n, w;
  cin >> r >> c >> n >> w;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    dp[x][y]++;
  }
  int por = 0;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++)
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i][j] - dp[i - 1][j - 1];
  }
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++)
      for (int k = i; k <= r; k++)
        for (int l = j; l <= c; l++)
          if (dp[i - 1][j - 1] + dp[k][l] - dp[i - 1][l] - dp[k][j - 1] >= w) {
            por++;
          }
  cout << por;
}
