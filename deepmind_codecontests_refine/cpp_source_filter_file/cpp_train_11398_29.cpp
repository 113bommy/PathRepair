#include <bits/stdc++.h>
using namespace std;
int dp[1020][102][2][2];
int n, k, m;
int xp[1020];
void up(int &x, int y) {
  x += y;
  if (x >= m) x -= m;
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  xp[0] = 1 % m;
  for (int i = 1; i <= n; i++) xp[i] = xp[i - 1] * 10 % m;
  dp[0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      for (int p = 0; p < 2; p++) {
        for (int q = 0; q < 2; q++) {
          if (!dp[i][j][p][q]) continue;
          for (int t = 0; t < 10; t++) {
            if (i == n - 1 && t == 0) continue;
            int nq = t ? 1 : q;
            int nj = (t * xp[i] + j) % k, np = p;
            if (nj == 0 && nq) np = 1;
            up(dp[i + 1][nj][np][nq], dp[i][j][p][q]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < k; i++) up(ans, dp[n][i][1][1]);
  printf("%d\n", ans);
}
