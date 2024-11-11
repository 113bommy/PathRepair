#include <bits/stdc++.h>
using namespace std;
int p[70], m, f[70][33][2010], ans[70][70], a[70], as;
struct ha {
  int w, n;
} b[70];
void work(int n) {
  memset(f, 0, sizeof(f));
  f[0][0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= min(i, m); j++)
      for (int k = max(p[j], i * (i - 1) / 2); k <= 1800; k++)
        f[i][j][k] |= (f[i - 1][j - 1][k - p[j]]) | f[i - 1][j][k - p[j]];
}
void dfs(int x, int y, int z) {
  if (x == 0) return;
  a[++as] = p[y];
  if (f[x - 1][y - 1][z - p[y]]) {
    dfs(x - 1, y - 1, z - p[y]);
    return;
  }
  dfs(x - 1, y, z - p[y]);
}
bool cmp(ha x, ha y) { return x.n > y.n; }
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
  sort(p + 1, p + 1 + m);
  for (int i = 1; i <= 65; i++) {
    work(i);
    if (f[i][m][i * (i - 1) / 2] == 1) {
      printf("%d\n", i);
      dfs(i, m, i * (i - 1) / 2);
      for (int j = 1; j <= as; j++) b[j].w = j, b[j].n = a[j];
      for (int j = 1; j <= as; j++) {
        sort(b + j, b + 1 + as, cmp);
        for (int k = as - b[j].n + 1; k <= as; k++) ans[b[j].w][b[k].w] = 1;
        for (int k = j + 1; k <= as - b[j].n; k++)
          ans[b[k].w][b[j].w] = 1, b[k].n--;
      }
      for (int i = 1; i <= as; i++) {
        for (int j = 1; j <= as; j++) printf("%d", ans[i][j]);
        printf("\n");
      }
      return 0;
    }
  }
  printf("=(\n");
  return 0;
}
