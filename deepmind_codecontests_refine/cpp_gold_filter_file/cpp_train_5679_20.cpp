#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005, MAXM = 200005;
int n, m, q, f[MAXN][MAXN], head[MAXM], nxt[MAXM], x[MAXM], y[MAXM];
struct Q {
  int l, r, s, t;
} s[MAXM];
bool ans[MAXM];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (register int i = 1; i <= m; ++i) scanf("%d%d", x + i, y + i);
  for (register int i = 1; i <= q; ++i) {
    scanf("%d%d%d%d", &s[i].l, &s[i].r, &s[i].s, &s[i].t);
    nxt[i] = head[s[i].r];
    head[s[i].r] = i;
  }
  for (register int u, v, k = 1; k <= m; ++k) {
    u = x[k];
    v = y[k];
    f[u][v] = f[v][u] = k;
    for (register int i = 1; i <= n; ++i)
      f[u][i] = f[v][i] = max(f[u][i], f[v][i]);
    for (register int i = head[k]; i; i = nxt[i])
      ans[i] = s[i].l <= f[s[i].t][s[i].s];
  }
  for (register int i = 1; i <= q; ++i) puts(ans[i] ? "Yes" : "No");
}
