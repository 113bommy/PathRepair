#include <bits/stdc++.h>
using namespace std;
int n;
int le[100010], pe[100010 << 1], ev[100010 << 1], ecnt;
void addEdge(int u, int v) {
  ecnt++;
  pe[ecnt] = le[u];
  le[u] = ecnt;
  ev[ecnt] = v;
}
int fa[100010], sz[100010], hson[100010], dep[100010];
void dfs1(int u) {
  sz[u] = 1;
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (v == fa[u]) continue;
    fa[v] = u;
    dep[v] = dep[u] + 1;
    dfs1(v);
    sz[u] += sz[v];
    if (sz[v] > sz[hson[u]]) hson[u] = v;
  }
}
int dfs_clock, top[100010], id[100010], L[100010], R[100010];
void dfs2(int u) {
  id[u] = ++dfs_clock;
  L[u] = id[u];
  if (hson[u]) {
    top[hson[u]] = top[u];
    dfs2(hson[u]);
  }
  for (int i = le[u]; i; i = pe[i]) {
    int &v = ev[i];
    if (v == fa[u] || v == hson[u]) continue;
    top[v] = v;
    dfs2(v);
  }
  R[u] = dfs_clock;
}
priority_queue<int, vector<int>, greater<int> > pq[100010];
pair<long long, pair<int, int> > minv[100010 << 2];
int addv[100010 << 2];
void add(int o, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) {
    addv[o] += v;
    minv[o].first += v;
    return;
  }
  if (L <= ((l + r) >> 1)) add((o << 1), l, ((l + r) >> 1), L, R, v);
  if (R > ((l + r) >> 1)) add((o << 1 | 1), ((l + r) >> 1) + 1, r, L, R, v);
  minv[o] = min(minv[(o << 1)], minv[(o << 1 | 1)]);
  minv[o].first += addv[o];
}
void erase(int o, int l, int r, int p) {
  if (l == r) {
    pq[l].pop();
    if (pq[l].empty())
      minv[o] = make_pair((1ll << 60), make_pair(100010, l));
    else
      minv[o] = make_pair(pq[l].top(), make_pair(pq[l].top(), l));
    minv[o].first += addv[o];
    return;
  }
  if (p <= ((l + r) >> 1))
    erase((o << 1), l, ((l + r) >> 1), p);
  else
    erase((o << 1 | 1), ((l + r) >> 1) + 1, r, p);
  minv[o] = min(minv[(o << 1)], minv[(o << 1 | 1)]);
  minv[o].first += addv[o];
}
pair<long long, pair<int, int> > query(int o, int l, int r, int L, int R) {
  if (L > r || R < l) return make_pair((1ll << 60), make_pair(100010, 0));
  if (L <= l && r <= R) return minv[o];
  pair<long long, pair<int, int> > ret =
      min(query((o << 1), l, ((l + r) >> 1), L, R),
          query((o << 1 | 1), ((l + r) >> 1) + 1, r, L, R));
  ret.first += addv[o];
  return ret;
}
void build(int o, int l, int r) {
  if (l == r) {
    addv[o] = 0;
    if (pq[l].empty())
      minv[o] = make_pair((1ll << 60), make_pair(100010, l));
    else
      minv[o] = make_pair((long long)pq[l].top(), make_pair(pq[l].top(), l));
    return;
  }
  build((o << 1), l, ((l + r) >> 1));
  build((o << 1 | 1), ((l + r) >> 1) + 1, r);
  minv[o] = min(minv[(o << 1)], minv[(o << 1 | 1)]);
}
int Query(int u, int v) {
  int L, R;
  pair<long long, pair<int, int> > ret =
      make_pair((1ll << 60), make_pair(100010, 0));
  while (top[u] != top[v]) {
    if (dep[top[u]] > dep[top[v]]) {
      L = id[top[u]], R = id[u];
      ret = min(ret, query(1, 1, n, L, R));
      u = fa[top[u]];
    } else {
      L = id[top[v]], R = id[v];
      ret = min(ret, query(1, 1, n, L, R));
      v = fa[top[v]];
    }
  }
  if (dep[u] > dep[v]) {
    L = id[v], R = id[u];
    ret = min(ret, query(1, 1, n, L, R));
  } else {
    L = id[u], R = id[v];
    ret = min(ret, query(1, 1, n, L, R));
  }
  if (ret.second.first >= 100010) {
    return 0;
  } else {
    erase(1, 1, n, ret.second.second);
    return ret.second.first;
  }
}
void Modify(int u, int val) { add(1, 1, n, L[u], R[u], val); }
int main() {
  int m, Q;
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 1, ed_i = n - 1; i <= ed_i; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addEdge(u, v);
    addEdge(v, u);
  }
  dfs1(1);
  dfs2(1);
  for (int i = 1, ed_i = m; i <= ed_i; i++) {
    int u;
    scanf("%d", &u);
    pq[id[u]].push(i);
  }
  build(1, 1, n);
  while (Q--) {
    int op, u, v, k;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", &u, &v, &k);
      vector<int> ans;
      int tmp;
      while (k && (tmp = Query(u, v))) {
        ans.push_back(tmp);
        k--;
      }
      printf("%d", (int)ans.size());
      for (int i = 0, ed_i = ans.size(); i < ed_i; i++) {
        printf(" %d", ans[i]);
      }
      putchar('\n');
    } else {
      scanf("%d%d", &u, &k);
      Modify(u, k);
    }
  }
  return 0;
}
