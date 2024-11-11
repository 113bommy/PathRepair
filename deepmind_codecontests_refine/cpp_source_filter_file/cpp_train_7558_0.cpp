#include <bits/stdc++.h>
const int N = 200005, W = 4;
int b[N], col[N], t[N], nn, n, x, y, in[N], out[N], block, c[2][N], f[N][W + 1],
    to[N << 1], edge, last[N], Next[N << 1];
int deep[N], eu[N], cnt, vis[N], Q;
long long Ans[N], ans;
struct qry {
  int l, r, id, lca;
} q[N];
bool cmp(qry x, qry y) {
  return x.l / block == y.l / block ? x.r < y.r : x.l / block < y.l / block;
}
void add(int x, int y) {
  to[++edge] = y;
  Next[edge] = last[x];
  last[x] = edge;
}
void dfs(int x, int y) {
  f[x][0] = y, deep[x] = deep[y] + 1;
  eu[++cnt] = x, in[x] = cnt;
  for (int i = last[x]; i; i = Next[i]) {
    int u = to[i];
    if (u == y) continue;
    dfs(u, x);
  }
  eu[++cnt] = x, out[x] = cnt;
}
int lca(int x, int y) {
  if (deep[x] < deep[y]) std::swap(x, y);
  for (int i = W; i >= 0; i--)
    if (deep[f[x][i]] >= deep[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = W; i >= 0; i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
void upd(int x) {
  int tt = col[x];
  ans = ans - 1ll * c[0][tt] * c[1][tt];
  c[b[x]][tt] += vis[x];
  ans = ans + 1ll * c[0][tt] * c[1][tt];
  vis[x] *= -1;
}
int main() {
  scanf("%d", &n);
  block = (int)sqrt(2 * n);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &col[i]), t[i] = col[i];
  std::sort(t + 1, t + n + 1);
  nn = std::unique(t + 1, t + n + 1) - t - 1;
  for (int i = 1; i <= n; i++)
    col[i] = std::lower_bound(t + 1, t + nn + 1, col[i]) - t;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  for (int i = 1; i <= W; i++)
    for (int j = 1; j <= n; j++) f[j][i] = f[f[j][i - 1]][i - 1];
  scanf("%d", &Q);
  for (int i = 1; i <= n; i++) vis[i] = 1;
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d", &x, &y);
    if (in[x] > in[y]) std::swap(x, y);
    int LCA = lca(x, y);
    if (LCA == x)
      q[i] = {in[x], in[y], i, 0};
    else
      q[i] = {out[x], in[y], i, LCA};
  }
  std::sort(q + 1, q + Q + 1, cmp);
  int pl = 0, pr = 0;
  for (int i = 1; i <= Q; i++) {
    while (pl > q[i].l) upd(eu[--pl]);
    while (pl < q[i].l) upd(eu[pl++]);
    while (pr > q[i].r) upd(eu[pr--]);
    while (pr < q[i].r) upd(eu[++pr]);
    if (q[i].lca) upd(q[i].lca);
    Ans[q[i].id] = ans;
    if (q[i].lca) upd(q[i].lca);
  }
  for (int i = 1; i <= Q; i++) printf("%lld\n", Ans[i]);
}
