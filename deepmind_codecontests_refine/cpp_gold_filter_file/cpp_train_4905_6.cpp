#include <bits/stdc++.h>
using namespace std;
int n, h[52], cnt = 0, siz[52];
struct Edge {
  int to, next;
} e[52 << 1];
inline void AddEdge(int x, int y) {
  e[++cnt] = (Edge){y, h[x]};
  h[x] = cnt;
}
double fac[52], f[52][52], g[52], w[52], C[52][52];
void dfs(int x, int prt) {
  int i, j, k, y;
  double su;
  siz[x] = 1;
  memset(f[x], 0, sizeof(f[x]));
  f[x][0] = 1.0;
  for (i = h[x]; i; i = e[i].next)
    if ((y = e[i].to) != prt) {
      dfs(y, x);
      su = 0;
      for (j = 0; j <= siz[y]; j++) {
        w[j] += su + (siz[y] - j) * f[y][j];
        su += 0.5 * f[y][j];
      }
      for (j = 0; j < siz[x]; j++)
        for (k = 0; k <= siz[y]; k++)
          g[j + k] += C[j + k][k] * C[siz[x] - 1 - j + siz[y] - k][siz[y] - k] *
                      f[x][j] * w[k];
      siz[x] += siz[y];
      for (j = 0; j < siz[x]; j++) f[x][j] = g[j], g[j] = w[j] = 0;
    }
}
int main() {
  for (int i = 0; i < 52; i++) {
    C[i][0] = 1.0;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  fac[0] = 1.0;
  for (int i = 1; i < 52; i++) fac[i] = fac[i - 1] * i;
  scanf("%d", &n);
  int i, x, y;
  for (i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    AddEdge(x, y);
    AddEdge(y, x);
  }
  for (i = 1; i <= n; i++) {
    dfs(i, 0);
    printf("%.9lf\n", f[i][n - 1] / fac[n - 1]);
  }
  return 0;
}
