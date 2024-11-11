#include <bits/stdc++.h>
using namespace std;
int dp[301][301][4];
int graph[301][301];
const int inf = 0x3f3f3f3f;
int read() {
  int num = 0;
  int c = getchar();
  for (; c > 47 && c < 58; c = getchar()) num = num * 10 + c - 48;
  return num;
}
int main() {
  int n = read();
  int m = read();
  int t = read();
  int tp = read();
  int tu = read();
  int td = read();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      graph[i][j] = read();
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      dp[i][j][0] = dp[i][j - 1][0];
      dp[i][j][0] += graph[i][j] > graph[i][j - 1]
                         ? tu
                         : (graph[i][j] < graph[i][j - 1] ? td : tp);
    }
    for (int j = m - 2; j >= 0; j--) {
      dp[i][j][1] = dp[i][j + 1][1];
      dp[i][j][1] += graph[i][j] > graph[i][j + 1]
                         ? tu
                         : (graph[i][j] < graph[i][j + 1] ? td : tp);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[j][i][2] = dp[j - 1][i][2];
      dp[j][i][2] += graph[j][i] > graph[j - 1][i]
                         ? tu
                         : (graph[j][i] < graph[j - 1][i] ? td : tp);
    }
    for (int j = n - 2; j >= 0; j--) {
      dp[j][i][3] = dp[j + 1][i][3];
      dp[j][i][3] += graph[j][i] > graph[j + 1][i]
                         ? tu
                         : (graph[j][i] < graph[j + 1][i] ? td : tp);
    }
  }
  int res1 = 0, res3 = 0, res2 = 2, res4 = 2;
  int curr = inf;
  for (int i = 0; i < n; i++) {
    for (int j = i + 2; j < n; j++) {
      for (int k = 0; k < m; k++) {
        for (int r = k + 2; r < m; r++) {
          int tmp = dp[i][r][0] - dp[i][k][0] + dp[j][k][1] - dp[j][r][1] +
                    dp[j][r][2] - dp[i][r][2] + dp[i][k][3] - dp[j][k][3];
          if (abs(tmp - t) < curr) {
            curr = abs(tmp - t);
            res1 = i, res2 = j;
            res3 = k, res4 = r;
            if (curr == 0) break;
          }
        }
      }
    }
  }
  cout << res1 + 1 << " " << res3 + 1 << " " << res2 + 1 << " " << res4 + 1;
}
