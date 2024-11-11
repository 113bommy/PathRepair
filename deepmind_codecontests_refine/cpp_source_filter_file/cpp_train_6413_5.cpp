#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
template <class T>
int getbit(T x, int pos) {
  return (x >> (pos - 1)) & 1;
}
template <class T>
void turn_on(T &x, int pos) {
  x = x | ((T)1 << (pos - 1));
}
template <class T>
void turn_off(T &x, int pos) {
  x = x & ~((T)1 << (pos - 1));
}
template <class T>
T sqr(T a) {
  return a * a;
}
struct edge {
  int u, v, w, id;
  bool selected;
  edge() { selected = false; }
} e[200002];
struct node {
  int val, lazy;
} st[200002 * 4];
int n, m, lab[200002], nChild[200002], l[200002], p[200002][20],
    chainHead[200002], nChain = 1;
int chainIn[200002], posInBase[200002], nBase, res[200002];
vector<pair<int, int> > a[200002];
int findset(int u) { return lab[u] <= 0 ? u : lab[u] = findset(lab[u]); }
void uni(int s, int t) {
  if (lab[s] < lab[t])
    lab[t] = s;
  else if (lab[s] > lab[t])
    lab[s] = t;
  else {
    lab[s] = t;
    lab[t]--;
  }
}
int buildTree(int u) {
  nChild[u] = 1;
  for (int i = 0; i < (int)a[u].size(); ++i) {
    int v = a[u][i].first;
    if (v == p[u][0]) continue;
    p[v][0] = u;
    nChild[u] += buildTree(v);
  }
  return nChild[u];
}
int level(int u) { return l[u] > 0 ? u : l[u] = level(p[u][0]) + 1; }
bool cmp(edge a, edge b) { return a.w < b.w; }
void initHLD(int u) {
  if (chainHead[nChain] == 0) chainHead[nChain] = u;
  chainIn[u] = nChain;
  posInBase[u] = ++nBase;
  int hv = -1;
  for (int i = 0; i < (int)a[u].size(); ++i) {
    int v = a[u][i].first;
    if (v != p[u][0] && (hv == -1 || nChild[hv] < nChild[v])) hv = v;
  }
  if (hv != -1) initHLD(hv);
  for (int i = 0; i < (int)a[u].size(); ++i) {
    int v = a[u][i].first;
    if (v != p[u][0] && v != hv) {
      ++nChain;
      initHLD(v);
    }
  }
}
void down(int id, int type) {
  int tmp = st[id].lazy;
  st[id].lazy = inf;
  if (type == -1) st[id].lazy = 0;
  st[id * 2].lazy = abs(min(st[id * 2].lazy * type, tmp * type));
  st[id * 2].val = abs(min(st[id * 2].val * type, tmp * type));
  st[id * 2 + 1].lazy = abs(min(st[id * 2 + 1].lazy * type, tmp * type));
  st[id * 2 + 1].val = abs(min(st[id * 2 + 1].val * type, tmp * type));
}
void update(int u, int v, int newVal, int type, int l = 1, int r = n,
            int id = 1) {
  if (v < l || r < u) return;
  if (u <= l && r <= v) {
    st[id].val = abs(min(type * st[id].val, type * newVal));
    st[id].lazy = abs(min(type * st[id].lazy, type * newVal));
    return;
  }
  down(id, type);
  int mid = (l + r) / 2;
  update(u, v, newVal, type, l, mid, id * 2);
  update(u, v, newVal, type, mid + 1, r, id * 2 + 1);
  st[id].val = abs(min(type * st[id * 2].val, type * st[id * 2 + 1].val));
}
int get(int u, int v, int type, int l = 1, int r = n, int id = 1) {
  if (v < l || r < u) return type == 1 ? inf : 0;
  if (u <= l && r <= v) return st[id].val;
  down(id, type);
  int mid = (l + r) / 2;
  int res = abs(min(type * get(u, v, type, l, mid, id * 2),
                    type * get(u, v, type, mid + 1, r, id * 2 + 1)));
  st[id].val = abs(min(type * st[id * 2].val, type * st[id * 2 + 1].val));
  return res;
}
void update_hld(int u, int par, int newVal, int type) {
  if (chainIn[u] == chainIn[par]) {
    return update(posInBase[par] + 1, posInBase[u], newVal, type);
  }
  update(posInBase[chainHead[chainIn[u]]], posInBase[u], newVal, type);
  update_hld(p[chainHead[chainIn[u]]][0], par, newVal, type);
}
int get_hld(int u, int par, int type) {
  if (chainIn[u] == chainIn[par]) {
    return get(posInBase[par] + 1, posInBase[u], type);
  }
  return abs(
      min(get(posInBase[chainHead[chainIn[u]]], posInBase[u], type) * type,
          get_hld(p[chainHead[chainIn[u]]][0], par, type) * type));
}
int lca(int x, int y) {
  for (int k = 19; k >= 0; --k) {
    if (l[p[x][k]] >= l[y]) x = p[x][k];
  }
  for (int k = 19; k >= 0; --k) {
    if (l[p[y][k]] >= l[x]) y = p[y][k];
  }
  for (int k = 19; k >= 0; --k) {
    if (p[x][k] != p[y][k]) {
      x = p[x][k];
      y = p[y][k];
    }
  }
  while (x != y) {
    x = p[x][0];
    y = p[y][0];
  }
  return x;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    e[i].id = i;
  }
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1; i <= m; ++i) {
    int s = findset(e[i].u), t = findset(e[i].v);
    if (s != t) {
      uni(s, t);
      e[i].selected = true;
      a[e[i].u].push_back(pair<int, int>(e[i].v, e[i].w));
      a[e[i].v].push_back(pair<int, int>(e[i].u, e[i].w));
    }
  }
  buildTree(1);
  initHLD(1);
  l[1] = 1;
  for (int i = 1; i <= n; ++i) level(i);
  for (int i = 1; i <= 19; ++i)
    for (int j = 1; j <= n; ++j) p[j][i] = p[p[j][i - 1]][i - 1];
  for (int i = 1; i <= 4 * n; ++i) st[i].lazy = st[i].val = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < (int)a[i].size(); ++j) {
      int v = a[i][j].first;
      if (v == p[i][0]) update_hld(i, v, a[i][j].second, -1);
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (!e[i].selected) {
      int u = e[i].u, v = e[i].v, x = lca(u, v);
      res[e[i].id] = max(get_hld(u, x, -1), get_hld(v, x, -1)) - 1;
    }
  }
  for (int i = 1; i <= 4 * n; ++i) st[i].val = st[i].lazy = inf;
  for (int i = 1; i <= m; ++i) {
    int u = e[i].u, v = e[i].v, x = lca(u, v);
    if (e[i].selected) continue;
    update_hld(u, x, e[i].w, 1);
    update_hld(v, x, e[i].w, 1);
  }
  for (int i = 1; i <= m; ++i) {
    if (!e[i].selected) continue;
    int u = e[i].u, v = e[i].v;
    if (u == p[v][0]) swap(u, v);
    int tmp = get_hld(u, v, 1);
    if (tmp == inf)
      res[e[i].id] = -1;
    else
      res[e[i].id] = tmp - 1;
  }
  for (int i = 1; i <= m; ++i) printf("%d ", res[i]);
}
