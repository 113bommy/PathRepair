#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, an;
int a[4][4];
bool f[50][50][50][4][4][4];
void dfs(int x, int y, int z, int A, int B, int C) {
  int b[4] = {0, x, y, z}, c[4] = {0, A, B, C}, i, j, g[50] = {};
  if (f[x][y][z][A][B][C]) return;
  f[x][y][z][A][B][C] = 1;
  for (i = 1; i <= 3; i++) g[b[i]] = i;
  for (i = 1; i <= 3; i++) {
    int t = b[i];
    if (t <= 45) {
      an = max(an, t);
      if (!(c[i] & 1) && !g[45 + i]) {
        for (j = t - a[i][2]; j <= t + a[i][2]; j++)
          if (j > 0 && !g[j]) {
            b[i] = j, c[i] ^= 1;
            dfs(b[1], b[2], b[3], c[1], c[2], c[3]);
            b[i] = t;
            c[i] ^= 1;
          }
      }
      if (!(c[i] & 2) && !g[45 + i]) {
        for (j = 1; j <= 3; j++) {
          int v = b[j];
          if (abs(t - v) != 1) continue;
          b[j] = 45 + i;
          c[i] ^= 2;
          dfs(b[1], b[2], b[3], c[1], c[2], c[3]);
          b[j] = v;
          c[i] ^= 2;
        }
      }
      if (g[45 + i]) {
        int A = g[45 + i];
        for (j = t - a[i][3]; j <= t + a[i][3]; j++)
          if (j > 0 && !g[j]) {
            b[A] = j;
            dfs(b[1], b[2], b[3], c[1], c[2], c[3]);
            b[A] = 45 + i;
          }
      }
    }
  }
}
int main() {
  for (i = 1; i <= 3; i++)
    for (j = 1; j <= 3; j++) scanf("%d", &a[i][j]);
  dfs(a[1][1], a[2][1], a[3][1], 0, 0, 0);
  printf("%d\n", an);
  return 0;
}
