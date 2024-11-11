#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int i, n, m, s[2200][2200], a[2200][2200], j, numC, numS, num, Lx, Ly, k, Rx,
    Ry, dis, q[120000][2], D, U, L, R, tot;
void read(int &x) {
  char c;
  while ((c = getchar()) == ' ' || c == '\n' || c == '\r')
    ;
  x = c - 48;
}
bool dfs(int x, int y) {
  if (!a[x][y]) return 1;
  if (a[x][y] == -1) return 0;
  a[x][y] = -1;
  bool f = dfs(x - 1, y) | dfs(x + 1, y) | dfs(x, y - 1) | dfs(x, y + 1);
  L = min(L, x);
  R = max(R, x);
  U = min(U, y);
  D = max(D, y);
  num++;
  if (f) q[++tot][0] = x, q[tot][1] = y;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      read(a[i][j]);
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  int M = 6;
  for (i = M; i <= n - M; ++i)
    for (j = M; j <= n - M; ++j) {
      int num =
          s[i + M][j + M] - s[i + M][j - M] - s[i - M][j + M] + s[i - M][j - M];
      if (num >= (M + M) * (M + M) * 0.3)
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  for (i = M + 5; i <= n - M - 5; ++i)
    for (j = M + 5; j <= n - M - 5; ++j)
      if (a[i][j] == 1) {
        num = tot = 0;
        L = R = i;
        U = D = j;
        dfs(i, j);
        if (num <= 50) continue;
        double sx = (L + R) / 2.0, sy = (U + D) / 2.0, near = 1e8, far = 0;
        for (k = 1; k <= tot; ++k) {
          double D =
              (q[k][0] - sx) * (q[k][0] - sx) + (q[k][1] - sy) * (q[k][1] - sy);
          if (D < near) near = D;
          if (D > far) far = D;
        }
        if (far / near > 1.6)
          numS++;
        else
          numC++;
      }
  printf("%d %d\n", numC, numS);
}
