#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 9;
const int mxn = 2e5 + 5;
int n, m, q, dis[mxn], ext;
vector<int> G1[mxn], G2[mxn];
multiset<int> S[mxn];
int minn[mxn << 2];
int pos, dfn[mxn], low[mxn], topp, sta[mxn];
int dep[mxn], f[mxn], size[mxn], id[mxn], cnt, h[mxn], top[mxn], loc[mxn];
void build_tree(int o, int l, int r) {
  if (l == r) {
    minn[o] = dis[loc[l]];
    return;
  }
  int md = l + r >> 1;
  build_tree(o << 1, l, md);
  build_tree(o << 1 | 1, md + 1, r);
  minn[o] = min(minn[o << 1], minn[o << 1 | 1]);
}
void update(int o, int l, int r, int x, int k) {
  if (l == r) {
    minn[o] = k;
    return;
  }
  int md = l + r >> 1;
  if (o <= md)
    update(o << 1, l, md, x, k);
  else
    update(o << 1 | 1, md + 1, r, x, k);
  minn[o] = min(minn[o << 1], minn[o << 1 | 1]);
}
int query(int o, int l, int r, int x, int y) {
  if (x <= l and r <= y) return minn[o];
  int md = l + r >> 1, ret = INF;
  if (x <= md) ret = min(ret, query(o << 1, l, md, x, y));
  if (md < y) ret = min(ret, query(o << 1 | 1, md + 1, r, x, y));
  return ret;
}
void dfs1(int x, int fa) {
  f[x] = fa;
  dep[x] = dep[fa] + 1;
  size[x] = 1;
  int tmp = -1;
  for (int i = 0; i < G2[x].size(); ++i) {
    int v = G2[x][i];
    if (v == fa) continue;
    dfs1(v, x);
    size[x] += size[v];
    if (size[v] > tmp) {
      tmp = size[v];
      h[x] = v;
    }
  }
}
void dfs2(int x, int fa) {
  top[x] = fa;
  id[x] = ++cnt;
  loc[cnt] = x;
  if (!h[x]) return;
  dfs2(h[x], fa);
  for (int i = 0; i < G2[x].size(); ++i) {
    int v = G2[x][i];
    if (v == f[x] or v == h[x]) continue;
    dfs2(v, v);
  }
}
void tarjan(int x) {
  dfn[x] = low[x] = ++pos;
  sta[++topp] = x;
  for (int i = 0; i < G1[x].size(); ++i) {
    int v = G1[x][i];
    if (!dfn[v]) {
      tarjan(v);
      low[x] = min(low[x], low[v]);
      if (low[v] == dfn[x]) {
        ++ext;
        for (int j = 0; j != v; topp--) {
          j = sta[topp];
          G2[ext].push_back(j);
          G2[j].push_back(ext);
        }
        G2[ext].push_back(x);
        G2[x].push_back(ext);
      }
    } else
      low[x] = min(low[x], dfn[v]);
  }
}
inline int querypath(int x, int y) {
  int ret = INF;
  for (; top[x] != top[y];) {
    if (dep[top[x]] < dep[top[y]]) swap(x, y);
    ret = min(ret, query(1, 1, ext, id[top[x]], id[x]));
    x = f[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ret = min(ret, query(1, 1, ext, id[x], id[y]));
  if (x > n) ret = min(ret, dis[f[x]]);
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  ext = n;
  for (int i = 1; i <= n; ++i) scanf("%d", &dis[i]);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    G1[u].push_back(v);
    G1[v].push_back(u);
  }
  tarjan(1);
  dfs1(1, 0);
  dfs2(1, 1);
  for (int i = 1; i <= n; ++i)
    if (f[i]) S[f[i]].insert(dis[i]);
  for (int i = n + 1; i <= ext; ++i) dis[i] = *S[i].begin();
  build_tree(1, 1, ext);
  for (; q--;) {
    char s[5];
    scanf("%s", s);
    if (s[0] == 'C') {
      int x, y;
      scanf("%d%d", &x, &y);
      update(1, 1, ext, id[x], y);
      if (f[x]) {
        S[f[x]].erase(S[f[x]].lower_bound(dis[x]));
        S[f[x]].insert(y);
        if (dis[f[x]] != *S[f[x]].begin()) {
          dis[f[x]] = *S[f[x]].begin();
          update(1, 1, ext, id[f[x]], dis[f[x]]);
        }
      }
      dis[x] = y;
    } else if (s[0] == 'A') {
      int x, y;
      scanf("%d%d", &x, &y);
      printf("%d\n", querypath(x, y));
    }
  }
  return 0;
}
