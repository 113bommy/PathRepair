#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using bs = basic_string<int>;
int n, k, c[1 << 17], fa[1 << 17][17], Q, dep[1 << 17], vt[1 << 17];
int dfn[1 << 17], vte[1 << 17], _, vl[1 << 17][2], sta[1 << 17], up[1 << 17];
char cl[1536 + 10][100010];
bs v[1 << 17], s, vls[1 << 17], v1[1 << 17];
struct qr {
  int p, k, t;
};
basic_string<qr> q;
void dfs(int p, int f = 0) {
  *fa[p] = f;
  dep[p] = dep[f] + 1;
  dfn[p] = ++_;
  for (int i : v[p])
    if (i != f) dfs(i, p);
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = 16, d = dep[u] - dep[v]; ~k; k--)
    if (d >> k & 1) u = fa[u][k];
  if (u == v) return u;
  for (int k = 16; ~k; k--)
    if (fa[u][k] != fa[v][k]) u = fa[u][k], v = fa[v][k];
  return *fa[u];
}
void clc(bs& s, int& v) {
  sort(s.begin(), s.end());
  int l = -n - 10, r = n + 10, mid;
  while (l < r) {
    mid = l + r >> 1;
    int cb = 0, cr = 0;
    for (int i : s)
      if (i < mid)
        cr++;
      else
        cb++;
    if (cb - cr >= mid)
      l = mid + 1;
    else
      r = mid;
  }
  v = l - 1;
}
void dfs1(int p) {
  if (vt[p]) vl[p][0] = -1e9, vl[p][1] = 1e9;
  if (~c[p]) {
    if (!vt[p]) vl[p][0] = vl[p][1] = c[p] ? 1e9 : -1e9;
    return;
  }
  bs s0, s1;
  for (int i : v[p])
    if (i != *fa[p]) {
      dfs1(i);
      if (!vte[i]) vls[p] += vl[i][0];
      s0 += vl[i][0], s1 += vl[i][1];
    }
  if (vt[p]) return;
  clc(s0, vl[p][0]);
  clc(s1, vl[p][1]);
  sort(vls[p].begin(), vls[p].end());
}
int qry(int p, int k, int t) {
  if (~c[p]) return cl[t][p];
  int cb = 0, cr = 0;
  for (int i : v1[p])
    if (vl[up[i]][qry(i, k, t)] >= k)
      cb++;
    else
      cr++;
  int r = lower_bound(vls[p].begin(), vls[p].end(), k) - vls[p].begin(),
      b = vls[p].size() - r;
  return b + cb - r - cr >= k;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x] += y, v[y] += x;
  }
  for (int i = 1; i <= n; i++) scanf("%d", c + i);
  dfs(1);
  for (int i = 1; i < 17; i++)
    for (int j = 1; j <= n; j++) fa[j][i] = fa[fa[j][i - 1]][i - 1];
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i += 1536) {
    for (int j = 1; j <= n; j++) cl[0][j] = c[j];
    q = {};
    s = {};
    for (int j = 1; j <= min(1536, Q - i + 1); j++) {
      int op, x, y;
      scanf("%d%d", &op, &x);
      memcpy(cl[j], cl[j - 1], sizeof *cl);
      if (op == 1) q += {x, k, j}, s += x;
      if (op == 3) k = x;
      if (op == 2) scanf("%d", &y), cl[j][x] = y, c[x] = y, s += x;
    }
    if (!s.size()) continue;
    sort(s.begin(), s.end(), [&](int a, int b) { return dfn[a] < dfn[b]; });
    s.erase(unique(s.begin(), s.end()), s.end());
    for (int j = 1; j <= n; j++) v1[j] = vls[j] = {};
    memset(vt, 0, sizeof vt);
    memset(vte, 0, sizeof vte);
    int tp = 1;
    sta[1] = s[0];
    vt[s[0]] = 1;
    for (int j : s.substr(1)) {
      int p = lca(j, sta[tp]);
      while (tp > 1 && dep[sta[tp - 1]] >= dep[p])
        v1[sta[tp - 1]] += sta[tp], --tp;
      if (sta[tp] != p) v1[p] += sta[tp], sta[tp] = p, vt[p] = 1;
      sta[++tp] = j, vt[j] = 1;
    }
    while (tp > 1) v1[sta[tp - 1]] += sta[tp], --tp;
    for (int j : s)
      for (; j && !vte[j]; j = *fa[j]) vte[j] = 1;
    for (int j = 1; j <= n; j++)
      if (vt[j])
        for (up[j] = j; up[j] && !vt[*fa[up[j]]]; up[j] = *fa[up[j]])
          ;
    dfs1(1);
    for (qr& x : q) printf("%d\n", qry(x.p, x.k, x.t));
  }
  return 0;
}
