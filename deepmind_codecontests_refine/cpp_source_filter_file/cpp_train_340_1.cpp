#include <bits/stdc++.h>
using namespace std;
const int N = 302, inf = 1000000000;
int n, m, res;
int c[10][N][N], curr[N][N], pre[N][N];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      c[0][i][j] = (i == j ? 0 : -inf);
      pre[i][j] = c[0][i][j];
    }
  for (int i = 1; i <= m; i++) {
    int u, v, c1, c2;
    scanf("%d %d %d %d", &u, &v, &c1, &c2);
    c[0][u][v] = c1;
    c[0][v][u] = c2;
  }
  for (int step = 0; step < 8; step++) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) c[step + 1][i][j] = c[step][i][j];
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          c[step + 1][i][j] =
              max(c[step + 1][i][j], c[step][i][k] + c[step][k][j]);
  }
  bool found = false;
  for (int i = 1; i <= n && !found; i++)
    if (c[8][i][i] > 0) found = true;
  if (!found) {
    printf("%d\n", 0);
    return 0;
  }
  for (int x = 8; x >= 0; x--) {
    if (found)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) curr[i][j] = pre[i][j];
    found = false;
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          curr[i][j] = max(curr[i][j], pre[i][k] + c[x][k][j]);
    for (int i = 1; i <= n && !found; i++)
      if (curr[i][i] > 0) found = true;
    if (!found) {
      res += (1 << x);
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) pre[i][j] = curr[i][j];
    }
  }
  printf("%d\n", res + 1);
  return 0;
}
