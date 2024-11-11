#include <bits/stdc++.h>
int n, t, f[21][4][21], ans;
int main() {
  scanf("%d %d", &n, &t);
  f[1][0][0] = 1;
  f[1][1][0] = 1;
  f[1][2][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = 0; k < 2 * t; k++) {
        for (int l = 1; l <= 4; l++) {
          if (i == 2 && j > l || i > 2 && j != l) {
            if (k % 2 == 0) {
              if (j < l)
                f[i][j][k + 1] += f[i - 1][l][k];
              else
                f[i][j][k] += f[i - 1][l][k];
            } else {
              if (j < l)
                f[i][j][k] += f[i - 1][l][k];
              else
                f[i][j][k + 1] += f[i - 1][l][k];
            }
          }
        }
      }
    }
  }
  ans = 0;
  for (int i = 1; i <= 4; i++) {
    ans += f[n][i][t * 2 - 1];
  }
  printf("%d\n", ans);
  return 0;
}
