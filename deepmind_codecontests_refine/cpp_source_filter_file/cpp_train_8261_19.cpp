#include <bits/stdc++.h>
int n, h, dp[1010][2][33][33][33];
int c(int x) { return x ? ((x + 1) % h) : 0; }
void upd(int &x, int y) { x = (x + y) % 1000000007; }
int main() {
  scanf("%d%d", &n, &h);
  dp[1][1][0][0][0] = 4;
  for (int i = 1; i < n; i++) {
    for (int p = 0; p < h; p++) {
      for (int q = 0; q < h; q++) {
        for (int r = 0; r < h; r++) {
          for (int ty = 0; ty < 2; ty++) {
            int P = c(p), Q = c(q), R = c(r);
            upd(dp[i + 1][ty][P][Q][R], dp[i][ty][p][q][r]);
            upd(dp[i + 1][p > 0 || i < h][ty][Q][R], dp[i][ty][p][q][r]);
            upd(dp[i + 1][q > 0 || i < h][P][ty][R], dp[i][ty][p][q][r]);
            upd(dp[i + 1][r > 0 || i < h][P][Q][ty], dp[i][ty][p][q][r]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int p = 0; p < h; p++) {
    for (int q = 0; q < h; q++) {
      for (int r = 0; r < h; r++) {
        upd(ans, dp[n][1][p][q][r]);
        if (p + q + r != 0) upd(ans, dp[n][0][p][q][r]);
      }
    }
  }
  printf("%d\n", ans);
}
