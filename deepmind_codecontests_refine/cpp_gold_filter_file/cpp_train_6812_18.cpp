#include <bits/stdc++.h>
using namespace std;
int n, m, k, x;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
int mat[MAXN][MAXN];
int dp[MAXN][MAXN][11];
struct e {
  int lr, mod;
} ans[MAXN][MAXN][11];
void print(int x, int y, int q) {
  if (x == 0)
    printf("%d\n", y + 1);
  else {
    print(x - 1, y + ans[x][y][q].lr, ans[x][y][q].mod);
    if (ans[x][y][q].lr == 1)
      putchar('L');
    else
      putchar('R');
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  k++;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int q = 0; q < k; q++) dp[i][j][q] = -INF;
    }
  }
  getchar();
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      mat[i][j] = getchar() - '0';
    }
    getchar();
  }
  for (int j = 0; j < m; j++) {
    for (int q = 0; q < k; q++) {
      if (mat[0][j] % k == q) {
        dp[0][j][q] = mat[0][j];
      }
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j != 0) {
        for (int q = 0; q < k; q++) {
          if (dp[i - 1][j - 1][q] != -INF) {
            int s = dp[i - 1][j - 1][q] + mat[i][j];
            dp[i][j][s % k] = max(dp[i][j][s % k], s);
            if (dp[i][j][s % k] == s) {
              ans[i][j][s % k] = {-1, q};
            }
          }
        }
      }
      if (j != m - 1) {
        for (int q = 0; q < k; q++) {
          if (dp[i - 1][j + 1][q] != -INF) {
            int s = dp[i - 1][j + 1][q] + mat[i][j];
            dp[i][j][s % k] = max(dp[i][j][s % k], s);
            if (dp[i][j][s % k] == s) {
              ans[i][j][s % k] = {1, q};
            }
          }
        }
      }
    }
  }
  int w = 0;
  for (int j = 0; j < m; j++)
    if (dp[n - 1][j][0] > dp[n - 1][w][0]) w = j;
  if (w == 0 && dp[n - 1][w][0] == -INF) {
    puts("-1");
    return 0;
  }
  printf("%d\n", dp[n - 1][w][0]);
  print(n - 1, w, 0);
}
