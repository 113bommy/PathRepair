#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int g[505][505];
char s[505][505];
int total_step;
int n, m;
bool isok(int x1, int y1, int x2, int y2) {
  if (x1 <= 0 || x1 > n || y1 <= 0 || y1 > m) return false;
  if (x2 <= 0 || x2 > n || y2 <= 0 || y2 > m) return false;
  if (x1 > x2 || y1 > y2) return false;
  if (s[x1][y1] != s[x2][y2]) return false;
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  total_step = n + m - 1;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int k = (total_step + 1) / 2; k >= 1; k--) {
    memset(g, 0, sizeof g);
    for (int i = 1; i <= min(n, k); i++) {
      int x1 = i, y1 = k + 1 - x1;
      for (int j = max(x1, n + 1 - k); j <= n; j++) {
        int x2 = j, y2 = (total_step + 1 - k) + 1 - x2;
        if (isok(x1, y1, x2, y2)) {
          if (s[x1][y1] != s[x2][y2]) {
            g[x1][x2] = 0;
            continue;
          }
          if (x1 == x2 && y1 == y2) {
            g[x1][x2] = 1;
            continue;
          }
          if (total_step - 2 * k + 1 == 1) {
            if (s[x1][y1] == s[x2][y2]) {
              g[x1][x2] = 1;
            }
            continue;
          }
          if (isok(x1 + 1, y1, x2 - 1, y2)) {
            g[x1][x2] += dp[x1 + 1][x2 - 1];
            if (g[x1][x2] > 1000000007) g[x1][x2] -= 1000000007;
          }
          if (isok(x1 + 1, y1, x2, y2 - 1)) {
            g[x1][x2] += dp[x1 + 1][x2];
            if (g[x1][x2] > 1000000007) g[x1][x2] -= 1000000007;
          }
          if (isok(x1, y1 + 1, x2 - 1, y2)) {
            g[x1][x2] += dp[x1][x2 - 1];
            if (g[x1][x2] > 1000000007) g[x1][x2] -= 1000000007;
          }
          if (isok(x1, y1 + 1, x2, y2 - 1)) {
            g[x1][x2] += dp[x1][x2];
            if (g[x1][x2] > 1000000007) g[x1][x2] -= 1000000007;
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] = g[i][j];
      }
    }
  }
  printf("%d\n", dp[1][n]);
}
