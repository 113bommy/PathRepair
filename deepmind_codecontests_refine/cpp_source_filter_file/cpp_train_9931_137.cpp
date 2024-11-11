#include <bits/stdc++.h>
using namespace std;
const int a1[4] = {1, -1, 0, 0}, a2[4] = {0, 0, 1, -1};
struct ww {
  int a, b;
} g[1610 * 1610], h[1610 * 1610];
int i, j, k, n, m, s, l, r;
int a[1610][1610], f[1610][1610], d[1610][1610], F[1610][1610],
    ans[1610 * 1610];
inline void bfs(int x, int y) {
  int i;
  g[l = r = 1].a = x, g[1].b = y;
  f[x][y] = 1;
  for (; l <= r; l++) {
    int X = g[l].a, Y = g[l].b;
    for (i = 0; i <= 3; i++) {
      int A = X + a1[i], B = Y + a2[i];
      if (a[A][B] && !f[A][B]) {
        f[A][B] = 1;
        g[++r].a = A, g[r].b = B;
      }
    }
  }
}
inline int cal(int x, int y) {
  int l, r, i;
  h[l = r = 1].a = x, h[1].b = y, d[x][y] = 0, F[x][y] = 1;
  for (; l <= r; l++) {
    int X = h[l].a, Y = h[l].b;
    if (d[X][Y] == d[h[r].a][h[r].b] && l + 4 - 1 <= r) break;
    for (i = 0; i <= 3; i++) {
      int A = X + a1[i], B = Y + a2[i];
      if (a[A][B] && !F[A][B]) {
        F[A][B] = 1;
        h[++r].a = A, h[r].b = B;
        d[A][B] = d[X][Y] + 1;
      }
    }
  }
  int D = d[h[r].a][h[r].b];
  if (D <= 10)
    for (i = 1; i <= r; i++) F[h[i].a][h[i].b] = 0;
  return D > 10;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (a[i][j] && !f[i][j]) {
        bfs(i, j);
        s = cal(i, j);
        for (k = r; k > 1; k--) {
          int A = g[k].a, B = g[k].b;
          if (!F[A][B]) s += cal(A, B);
        }
        ans[++*ans] = s;
      }
  sort(ans + 1, ans + *ans + 1);
  printf("%d\n", *ans);
  for (i = 1; i <= *ans; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
