#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int N, K, f[30005][205][2], g[30005][205][2];
int main() {
  scanf("%d%d", &N, &K);
  for (int _r = K, i = 1; i <= _r; ++i)
    for (int _r = 2, j = 0; j < _r; ++j) f[0][i][j] = g[0][i][j] = -inf;
  for (int _r = N, i = 1; i <= _r; ++i) {
    int x;
    scanf("%d", &x);
    for (int _r = K, j = 1; j <= _r; ++j) {
      int mp = 2 - (j == 1 || j == K);
      f[i][j][0] = max(f[i - 1][j][0] + mp * x, g[i - 1][j - 1][1] + mp * x);
      f[i][j][1] = max(f[i - 1][j][1] - mp * x, g[i - 1][j - 1][0] - mp * x);
      g[i][j][0] = max(f[i][j][0], g[i - 1][j][0]);
      g[i][j][1] = max(f[i][j][1], g[i - 1][j][1]);
      if (j > 1 && j < K) {
        g[i][j][0] = max(g[i][j][0], f[i - 1][j - 1][0]);
        g[i][j][1] = max(g[i][j][1], f[i - 1][j - 1][1]);
      }
    }
  }
  printf("%d\n", max(g[N][K][0], g[N][K][1]));
}
