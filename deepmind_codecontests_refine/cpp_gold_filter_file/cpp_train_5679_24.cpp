#include <bits/stdc++.h>
using namespace std;
const int M = 200000 + 10, N = 1000 + 10;
int n, m, q;
int g[N][N], ans[M];
struct edge {
  int s, t;
} d[M];
struct node {
  int l, r, s, t, id;
} f[M];
bool operator<(const node a, const node b) { return a.l > b.l; }
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= m; i++) scanf("%d%d", &d[i].s, &d[i].t);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d%d", &f[i].l, &f[i].r, &f[i].s, &f[i].t);
    f[i].id = i;
  }
  sort(f + 1, f + 1 + q);
  memset(g, 0x3f, sizeof g);
  for (int i = 1; i <= n; i++) g[i][i] = 0;
  int cnt = 1;
  for (int i = m; i; i--) {
    g[d[i].s][d[i].t] = g[d[i].t][d[i].s] = i;
    for (int j = 1; j <= n; j++) {
      if (j != d[i].t) g[d[i].s][j] = min(g[d[i].s][j], g[d[i].t][j]);
      if (j != d[i].s) g[d[i].t][j] = min(g[d[i].t][j], g[d[i].s][j]);
    }
    while (cnt <= q && f[cnt].l >= i) {
      ans[f[cnt].id] = g[f[cnt].s][f[cnt].t] <= f[cnt].r;
      cnt++;
    }
  }
  for (int i = 1; i <= q; i++) printf("%s\n", ans[i] ? "Yes" : "No");
  return 0;
}
