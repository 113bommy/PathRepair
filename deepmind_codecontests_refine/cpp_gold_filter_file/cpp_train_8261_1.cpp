#include <bits/stdc++.h>
using namespace std;
int dp[2][31][31][31][31], n, H;
inline void updata(int h, int i, int j, int p, int q, int c, int key, int num) {
  int w[4] = {i, j, p, q};
  for (int t = 0; t < num; t++) {
    if (t == c) w[t] = w[t] == H ? H : 0;
    if (t != c) w[t] = min(w[t] + 1, H);
  }
  sort(w, w + num);
  dp[h][w[0]][w[1]][w[2]][w[3]] += key;
  dp[h][w[0]][w[1]][w[2]][w[3]] %= 1000000009;
}
int solve(int num) {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0][0] = 1;
  int ret = 0;
  for (int t = 0, g = 1, h = 0; t <= n; t++) {
    swap(g, h);
    for (int i = 0; i < H; i++)
      for (int j = i; j <= H; j++) {
        for (int p = j; p <= H; p++) {
          for (int q = p; q <= H; q++) {
            if (dp[g][i][j][p][q] == 0) continue;
            if (t == n) {
              ret += dp[g][i][j][p][q];
              ret %= 1000000009;
              continue;
            }
            for (int c = 0; c < num; c++)
              updata(h, i, j, p, q, c, dp[g][i][j][p][q], num);
            dp[g][i][j][p][q] = 0;
          }
        }
      }
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &H);
  printf("%d\n", solve(4));
  return 0;
}
