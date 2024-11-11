#include <bits/stdc++.h>
using namespace std;
int dp[1 << 19][20];
int maze[22][22];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    maze[x][y] = maze[y][x] = 1;
  }
  for (int i = 0; i < n; i++) {
    dp[1 << i][i] = 1;
  }
  long long ans = 0;
  for (int i = 1; i < (1 << n); i++) {
    int mi = log2(i & -i);
    for (int j = mi; j < n; j++) {
      if (!dp[i][j]) continue;
      for (int k = mi; k < n; k++) {
        if (!maze[j][k]) {
          continue;
        }
        if (i & (1 << k)) {
          if (k == mi) ans += dp[i][j];
        } else {
          dp[i | (1 << k)][k] += dp[i][j];
        }
      }
    }
  }
  printf("%lld\n", (ans - m) / 2);
  return 0;
}
