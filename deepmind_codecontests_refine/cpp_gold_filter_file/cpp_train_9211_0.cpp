#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int H[N], to[N * 2], nxt[N * 2], e = 1;
void addedge(int t, int v) {
  e++, to[e] = v, nxt[e] = H[t], H[t] = e;
  e++, to[e] = t, nxt[e] = H[v], H[v] = e;
}
int dfn[N], low[N], cnt;
void dfs(int u, int j) {
  dfn[u] = low[u] = ++cnt;
  for (int i = H[u], v = to[i]; i; i = nxt[i], v = to[i])
    if (i != j) {
      if (!dfn[v]) dfs(v, i ^ 1);
      low[u] = min(low[u], low[v]);
    }
}
vector<int> ch[N];
int fa[N], dep[N], son[N], size[N];
void init_(int u, int f) {
  fa[u] = f;
  size[u] = 1;
  dep[u] = dep[f] + 1;
  for (int i = 0; i <= (int)ch[u].size() - 1; i++) {
    int v = ch[u][i];
    if (v != f) {
      init_(v, u);
      size[u] += size[v];
      if (size[v] > size[son[u]]) son[u] = v;
    }
  }
}
int idx[N], top[N], tot;
void Build(int u, int f, int tp) {
  top[u] = tp;
  idx[u] = ++tot;
  if (son[u]) Build(son[u], u, tp);
  for (int i = 0; i <= (int)ch[u].size() - 1; i++) {
    int v = ch[u][i];
    if (v != f && v != son[u]) Build(v, u, v);
  }
}
void update(int* tree, int k, int val) {
  for (; k <= tot; k += k & -k) tree[k] += val;
}
void modify(int* tree, int l, int r) {
  update(tree, l + 0, +1);
  update(tree, r + 1, -1);
}
int tree[2][N];
void modify(int u, int v) {
  int w = 1;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v), w ^= 1;
    modify(tree[w], idx[top[u]], idx[u]);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v), w ^= 1;
  modify(tree[w], idx[v] + 1, idx[u]);
}
int f[N];
int F(int k) { return f[k] == k ? k : f[k] = F(f[k]); }
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    int t, v;
    scanf("%d%d", &t, &v);
    addedge(t, v);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) {
      ch[0].push_back(cnt + 1);
      dfs(i, 0);
    }
  for (int i = 1; i <= n; i++) f[dfn[i]] = low[i];
  vector<pair<int, int> > vec;
  for (int i = 2; i <= e; i++) {
    int t = F(dfn[to[i]]);
    int v = F(dfn[to[i ^ 1]]);
    if (t < v) vec.push_back(pair<int, int>(t, v));
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 0; i <= (int)vec.size() - 1; i++) {
    int t = vec[i].first, v = vec[i].second;
    ch[t].push_back(v);
    ch[v].push_back(t);
  }
  init_(0, 0);
  Build(0, 0, 0);
  for (int i = 1; i <= q; i++) {
    int t, v;
    scanf("%d%d", &t, &v);
    modify(F(low[t]), F(low[v]));
  }
  for (int i = 1; i <= tot; i++) tree[0][i] += tree[0][i - (i & -i)];
  for (int i = 1; i <= tot; i++) tree[1][i] += tree[1][i - (i & -i)];
  for (int i = 1; i <= tot; i++)
    if (tree[0][i] && tree[1][i]) {
      puts("No");
      return 0;
    }
  for (int i = 1; i <= tot; i++)
    if (fa[i] == 0 && (tree[0][idx[i]] || tree[1][idx[i]])) {
      puts("No");
      return 0;
    }
  puts("Yes");
  return 0;
}
