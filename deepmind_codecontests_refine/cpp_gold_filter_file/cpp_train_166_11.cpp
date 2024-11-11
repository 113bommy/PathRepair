#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 1, -1, 0}, dy[4] = {-1, 0, 0, 1};
const char D[4] = {'L', 'D', 'U', 'R'};
char p[5010][5010];
int x[5010], y[5010], mk[5010][5010], d[5010], w[5010][4], u[5010][4], a, b, i,
    j, k, t, s, tx, ty, n, m, cnt;
int main() {
  scanf("%d%d", &n, &m);
  getchar();
  cnt = 0;
  for (i = 0; i < (n); ++i) {
    gets(p[i]);
    for (j = 0; j < (m); ++j)
      if (p[i][j] != '.') {
        x[cnt] = i;
        y[cnt] = j;
        for (k = 0; k < (4); ++k)
          if (p[i][j] == D[k]) d[cnt] = k;
        mk[i][j] = cnt++;
      }
  }
  for (i = 0; i < (cnt); ++i)
    for (k = 0; k < (4); ++k) {
      tx = x[i] + dx[k];
      ty = y[i] + dy[k];
      w[i][k] = -1;
      while (tx >= 0 && tx < n && ty >= 0 && ty < m) {
        if (p[tx][ty] != '.') {
          w[i][k] = mk[tx][ty];
          break;
        }
        tx += dx[k];
        ty += dy[k];
      }
    }
  a = -1;
  for (i = 0; i < (cnt); ++i) {
    t = i;
    s = 0;
    for (j = 0; j < (cnt); ++j)
      for (k = 0; k < (4); ++k) u[j][k] = w[j][k];
    do {
      ++s;
      for (k = 0; k < (4); ++k)
        if (u[t][k] >= 0) u[u[t][k]][3 - k] = u[t][3 - k];
      t = u[t][d[t]];
    } while (t != -1);
    if (s > a) {
      a = s;
      b = 1;
    } else
      b += a == s ? 1 : 0;
  }
  printf("%d %d\n", a, b);
  return 0;
}
