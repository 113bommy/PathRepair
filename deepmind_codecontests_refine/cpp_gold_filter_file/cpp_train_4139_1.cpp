#include <bits/stdc++.h>
using namespace std;
const int N = 2.5e5 + 10;
int b[N], mx[N][20], mn[N][20], tg[N * 4], Mn[N * 4], sz[N], tp[N], son[N],
    dfn[N], nu[N], a[N], d[N], dfsc, n, Q, fa[N];
int t1, t2, tt, s1[N], s2[N], s[N], id[N], cnt, L[N], R[N], o[N], f[N], rt;
vector<int> G[N];
long long g[N], C[N], D[N], cl[N], cr[N], zl[N], zr[N];
inline bool ck(int l, int r) {
  int t = b[r - l + 1];
  return max(mx[l][t], mx[r - (1 << t) + 1][t]) -
             min(mn[l][t], mn[r - (1 << t) + 1][t]) ==
         r - l;
}
inline void pd(int o) {
  tg[o << 1] += tg[o];
  tg[o << 1 | 1] += tg[o];
  Mn[o << 1] += tg[o];
  Mn[o << 1 | 1] += tg[o];
  tg[o] = 0;
}
void upd(int l, int r, int o, int ql, int qr, int x) {
  if (ql <= l && r <= qr) {
    tg[o] += x;
    Mn[o] += x;
    return;
  }
  if (ql > r || qr < l) return;
  int mid = (l + r) >> 1;
  pd(o);
  upd(l, mid, o << 1, ql, qr, x);
  upd(mid + 1, r, o << 1 | 1, ql, qr, x);
  Mn[o] = min(Mn[o << 1], Mn[o << 1 | 1]);
}
int que(int o, int l, int r) {
  if (l == r) return l;
  int mid = (l + r) >> 1;
  pd(o);
  if (Mn[o << 1])
    return que(o << 1 | 1, mid + 1, r);
  else
    return que(o << 1, l, mid);
}
void dfs(int u) {
  sz[u] = 1;
  g[u] = o[u] ? 1ll * G[u].size() * (G[u].size() - 1) / 2 : 1;
  for (int &v : G[u]) {
    d[v] = d[u] + 1, dfs(v);
    sz[u] += sz[v];
    son[u] = sz[v] > sz[son[u]] ? v : son[u];
    g[u] += g[v];
  }
  if (L[u] == R[u]) return;
  long long lst = 0, c = (int)G[u].size() - 1;
  C[G[u][0]] = g[G[u][0]];
  for (int i = (1); i <= ((int)G[u].size() - 1); ++i)
    lst = cl[G[u][i]] = lst + g[G[u][i - 1]] + (o[u] ? i - 1 : 0);
  lst = 0;
  for (int i = ((int)G[u].size() - 2); i >= (0); --i)
    lst = cr[G[u][i]] = lst + g[G[u][i + 1]] + (o[u] ? c - i - 1 : 0);
  lst = C[G[u][0]];
  for (int i = (1); i <= ((int)G[u].size() - 1); ++i)
    lst = C[G[u][i]] = lst + g[G[u][i]], D[G[u][i]] = i;
}
void dfs2(int u, int t) {
  dfn[u] = ++dfsc;
  tp[u] = t;
  nu[dfsc] = u;
  if (son[u]) cl[son[u]] += cl[u], cr[son[u]] += cr[u], dfs2(son[u], t);
  for (int &v : G[u])
    if (v ^ son[u]) cl[v] += cl[u], cr[v] += cr[u], dfs2(v, v);
}
int lca(int u, int v) {
  while (tp[u] ^ tp[v]) d[tp[u]] > d[tp[v]] ? u = fa[tp[u]] : v = fa[tp[v]];
  return d[u] < d[v] ? u : v;
}
int kth(int u, int k) {
  while (d[u] - d[tp[u]] < k) k -= d[u] - d[tp[u]] + 1, u = fa[tp[u]];
  return nu[dfn[u] - k];
}
void out(int l, int r, int o) {
  if (l == r) {
    printf("%d ", Mn[o]);
    return;
  }
  int mid = (l + r) >> 1;
  pd(o);
  out(l, mid, o << 1);
  out(mid + 1, r, o << 1 | 1);
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) scanf("%d", a + i);
  b[0] = -1;
  for (int i = (1); i <= (n); ++i)
    mx[i][0] = mn[i][0] = a[i], b[i] = b[i >> 1] + 1;
  for (int i = (1); i <= (19); ++i)
    for (int j = (1); j <= (n - (1 << i) + 1); ++j)
      mx[j][i] = max(mx[j][i - 1], mx[j + (1 << i - 1)][i - 1]),
      mn[j][i] = min(mn[j][i - 1], mn[j + (1 << i - 1)][i - 1]);
  for (int i = (1); i <= (n); ++i) {
    while (t1 && a[i] > a[s1[t1]])
      upd(1, n, 1, s1[t1 - 1] + 1, s1[t1], -a[s1[t1]]), --t1;
    while (t2 && a[i] < a[s2[t2]])
      upd(1, n, 1, s2[t2 - 1] + 1, s2[t2], a[s2[t2]]), --t2;
    upd(1, n, 1, s1[t1] + 1, i, a[i]);
    upd(1, n, 1, s2[t2] + 1, i, -a[i]);
    s1[++t1] = i;
    s2[++t2] = i;
    id[i] = ++cnt;
    L[cnt] = R[cnt] = i;
    int ps = que(1, 1, n), x = cnt;
    upd(1, n, 1, 1, i, -1);
    while (tt && L[s[tt]] >= ps)
      if (o[s[tt]] && ck(f[s[tt]], i))
        fa[x] = s[tt], R[s[tt]] = i, x = s[tt--];
      else if (ck(L[s[tt]], i))
        o[++cnt] = 1, fa[x] = fa[s[tt]] = cnt, L[cnt] = L[s[tt]], R[cnt] = i,
        f[cnt] = L[x], x = cnt, --tt;
      else {
        fa[x] = ++cnt;
        while (tt && !ck(L[s[tt]], i)) fa[s[tt--]] = cnt;
        L[cnt] = L[s[tt]];
        R[cnt] = i;
        fa[s[tt--]] = cnt;
        x = cnt;
      }
    s[++tt] = x;
  }
  for (int i = (1); i <= (cnt); ++i)
    if (fa[i]) G[fa[i]].push_back(i);
  dfs(rt = s[1]);
  dfs2(s[1], s[1]);
  scanf("%d", &Q);
  while (Q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    ++r;
    if (!l && r > n) {
      printf("%lld\n", g[rt]);
      continue;
    }
    if (!l) {
      int y = id[r], ly = kth(y, d[y] - 1);
      long long ans = cl[y] - cl[ly], p = D[ly];
      ans += C[ly] - g[ly] + (o[rt] ? p * (p - 1) / 2 : 0);
      printf("%lld\n", ans);
      continue;
    }
    if (r > n) {
      int x = id[l], lx = kth(x, d[x] - 1);
      long long ans = cr[x] - cr[lx], p = G[rt].size() - D[lx] - 1;
      ans += C[G[rt].back()] - C[lx] + (o[rt] ? p * (p - 1) / 2 : 0);
      printf("%lld\n", ans);
      continue;
    }
    int x = id[l], y = id[r], c = lca(x, y), lx = kth(x, d[x] - d[c] - 1),
        ly = kth(y, d[y] - d[c] - 1);
    long long ans = cr[x] + cl[y] - cr[lx] - cl[ly], p = D[ly] - D[lx] - 1;
    ans += C[ly] - C[lx] - g[ly] + (o[c] ? p * (p - 1) / 2 : 0);
    printf("%lld\n", ans);
  }
  return 0;
}
