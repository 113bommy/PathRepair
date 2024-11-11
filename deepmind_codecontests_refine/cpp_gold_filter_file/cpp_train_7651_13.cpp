#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int maxn = 35, maxx = 55;
int dp[maxn][maxn][maxn * maxn];
int main() {
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++)
      for (int o = 0; o < maxx; o++) dp[i][j][o] = 1000000000;
  }
  for (int i = 0; i < maxn; i++) {
    for (int j = 0; j < maxn; j++) {
      dp[i][j][0] = 0;
      dp[i][j][i * j] = 0;
    }
  }
  for (int i = 1; i < maxn; i++) {
    for (int j = 1; j < maxn; j++) {
      int mxx = min(i * j, 50);
      for (int k = 1; k <= mxx; k++) {
        for (int h = 1; h < i; h++) {
          for (int a = 1; a <= k; a++) {
            dp[i][j][k] =
                min(dp[i][j][k], dp[h][j][a] + j * j + dp[i - h][j][k - a]);
          }
        }
        for (int z = 1; z < j; z++) {
          for (int a = 1; a <= k; a++) {
            dp[i][j][k] =
                min(dp[i][j][k], dp[i][z][a] + i * i + dp[i][j - z][k - a]);
          }
        }
      }
    }
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", dp[a][b][c]);
  }
  return 0;
}
