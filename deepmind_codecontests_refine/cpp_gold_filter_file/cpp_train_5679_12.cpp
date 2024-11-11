#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int maxm = 200000 + 10;
int f[maxn][maxn], n, m, Q, ans[maxm];
struct edge {
  int u, v;
} e[maxm];
struct query {
  int l, r, s, t;
  int id;
} q[maxm];
int cmp(query a, query b) { return a.l > b.l; }
int main() {
  memset(f, 127 / 2, sizeof(f));
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 1; i <= m; i++) scanf("%d%d", &e[i].u, &e[i].v);
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d%d%d", &q[i].l, &q[i].r, &q[i].s, &q[i].t);
    q[i].id = i;
  }
  sort(q + 1, q + Q + 1, cmp);
  int po = 1;
  for (int i = m; i; i--) {
    int u = e[i].u, v = e[i].v;
    f[u][v] = f[v][u] = i;
    for (int j = 1; j <= n; j++) {
      int hm = min(f[u][j], f[v][j]);
      f[u][j] = hm;
      f[v][j] = hm;
    }
    while (q[po].l == i && po <= Q) {
      if (f[q[po].s][q[po].t] <= q[po].r)
        ans[q[po].id] = 1;
      else
        ans[q[po].id] = 0;
      po++;
    }
  }
  for (int i = 1; i <= Q; i++)
    if (ans[i])
      puts("Yes");
    else
      puts("No");
  return 0;
}
