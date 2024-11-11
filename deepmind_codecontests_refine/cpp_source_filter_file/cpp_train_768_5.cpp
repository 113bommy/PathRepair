#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
int h[N], to[M], nexp[M], W[M], p = 1;
inline void ins(int a, int b, int w) {
  nexp[p] = h[a], h[a] = p, to[p] = b, W[p] = w, p++;
}
char bla[N];
int f[N], l[N], f2[N], l2[N];
int dfn[N], siz[N], dep[N], son[N], top[N], fa[N], faw[N], idx;
void _dfs1(int x, int k) {
  dep[x] = k, siz[x] = 1;
  for (int u = h[x]; u; u = nexp[u])
    if (!dep[to[u]]) {
      _dfs1(to[u], k + 1), siz[x] += siz[to[u]], fa[to[u]] = x,
                                                 faw[to[u]] = W[u];
      if (siz[son[x]] < siz[to[u]]) son[x] = to[u];
    }
}
void _dfs2(int x, int t) {
  top[x] = t, dfn[x] = ++idx;
  if (son[x]) _dfs2(son[x], t);
  for (int u = h[x]; u; u = nexp[u])
    if (!dfn[to[u]]) _dfs2(to[u], to[u]);
}
int lca(int s, int t) {
  while (top[s] != top[t]) {
    if (dep[top[s]] < dep[top[t]]) swap(s, t);
    s = fa[top[s]];
  }
  return dep[s] < dep[t] ? s : t;
}
void dfs(int x, int fr) {
  f[x] = -0x3f3f3f3f;
  if (bla[x]) f[x] = 0, l[x] = x;
  for (int u = h[x]; u; u = nexp[u])
    if (to[u] != fr) {
      dfs(to[u], x);
      if (f[to[u]] + W[u] > f[x])
        l[x] = l[to[u]], f[x] = f[to[u]] + W[u];
      else if (f[to[u]] + W[u] == f[x])
        l[x] = x;
    }
}
map<int, int> mp;
map<int, vector<int> > vp;
void dfs2(int x, int fr) {
  if (bla[x]) f2[x] = max(f2[x], 0);
  mp.clear(), vp.clear();
  for (int u = h[x]; u; u = nexp[u])
    if (to[u] != fr)
      mp[f[to[u]] + W[u]]++, vp[f[to[u]] + W[u]].push_back(to[u]);
  int rna;
  for (int u = h[x]; u; u = nexp[u])
    if (to[u] != fr) {
      rna = f[to[u]] + W[u];
      f2[to[u]] = f2[x] + W[u], l2[to[u]] = l2[x];
      mp[rna]--;
      for (auto it = mp.rbegin(); it != mp.rend(); it++)
        if (it->second) {
          if (it->first + W[u] > f2[to[u]]) {
            f2[to[u]] = it->first + W[u];
            if (it->second > 1)
              l2[to[u]] = x;
            else {
              for (auto x : vp[it->first])
                if (x != to[u]) {
                  l2[to[u]] = l[x];
                }
            }
          } else if (it->first + W[u] == f[to[u]]) {
            l2[to[u]] = x;
            break;
          }
          break;
        }
      mp[rna]++;
    }
  for (int u = h[x]; u; u = nexp[u])
    if (to[u] != fr) dfs2(to[u], x);
}
void dfs4(int x, int fr) {
  if (f[x] == f2[x])
    l2[x] = x;
  else if (f[x] > f2[x])
    f2[x] = f[x], l2[x] = l[x];
  for (int u = h[x]; u; u = nexp[u])
    if (to[u] != fr) dfs4(to[u], x);
}
int c[N];
int ans, ansb;
void dfs3(int x) {
  for (int u = h[x]; u; u = nexp[u])
    if (to[u] != fa[x]) dfs3(to[u]), c[x] += c[to[u]];
  if (!bla[x]) {
    if (c[x] > ans) ans = c[x], ansb = 0;
    ansb += ans == c[x];
  }
}
int main() {
  memset(f2, -0x3f, sizeof(f2));
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m, u, v, w;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> u, bla[u] = 1;
  for (int i = 0; i < n - 1; i++)
    cin >> u >> v >> w, ins(u, v, w), ins(v, u, w);
  _dfs1(1, 1), _dfs2(1, 1);
  dfs(1, 0), dfs2(1, 0), dfs4(1, 0);
  int lc;
  for (int i = 1; i <= n; i++) {
    if (bla[i]) {
      lc = lca(i, l2[i]);
      c[i]++, c[l2[i]]++, c[lc]--, c[fa[lc]]--;
    }
  }
  dfs3(1);
  cout << ans << ' ' << ansb << endl;
  return 0;
}
