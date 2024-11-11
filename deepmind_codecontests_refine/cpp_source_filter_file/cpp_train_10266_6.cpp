#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const int MAX_N = 2e5 + 10;
const long long mod = 998244353;
const double PI = acos(-1);
struct E {
  int u, v, w;
} edge[MAX_N << 1];
vector<pair<int, int> > son[MAX_N];
int per[MAX_N][20], deep[MAX_N], tin[MAX_N], tout[MAX_N], t, to[MAX_N];
long long f[MAX_N], g[MAX_N];
void dfs(int o, int fa, int d) {
  tin[o] = ++t;
  to[t] = o;
  deep[o] = d;
  per[o][0] = fa;
  for (int i = 1; i < 20; ++i) {
    if (per[o][i - 1] == 1)
      per[o][i] = 1;
    else
      per[o][i] = per[per[o][i - 1]][i - 1];
  }
  for (auto it : son[o]) {
    f[it.first] = it.second + f[o];
    dfs(it.first, o, d + 1);
  }
  tout[o] = t;
}
int lca(int x, int y) {
  if (deep[x] < deep[y]) swap(x, y);
  int u = deep[x] - deep[y];
  for (int i = 0; i < 20; ++i)
    if ((u >> i) & 1) x = per[x][i];
  if (x == y) return x;
  for (int i = 19; i >= 0; --i)
    if (per[x][i] != per[y][i]) x = per[x][i], y = per[y][i];
  return per[x][0];
}
pair<long long, long long> node[MAX_N << 2];
void push_up(int o) {
  node[o].first = min(node[o << 1].first, node[o << 1 | 1].first);
}
void push_down(int o) {
  node[o << 1].first += node[o].second;
  node[o << 1 | 1].first += node[o].second;
  node[o << 1].second += node[o].second;
  node[o << 1 | 1].second += node[o].second;
  node[o].second = 0;
}
void build(int l, int r, int o) {
  node[o].second = 0;
  if (l == r) {
    node[o].first = f[to[l]] + g[to[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, o << 1);
  build(mid + 1, r, o << 1 | 1);
  push_up(o);
}
void update(int ll, int rr, int x, int l, int r, int o) {
  if (ll <= l && r <= rr) {
    node[o].first += x;
    node[o].second += x;
    return;
  }
  if (node[o].second) push_up(o);
  int mid = (l + r) >> 1;
  if (ll <= mid) update(ll, rr, x, l, mid, o << 1);
  if (rr > mid) update(ll, rr, x, mid + 1, r, o << 1 | 1);
  push_up(o);
}
long long query(int ll, int rr, int l, int r, int o) {
  if (ll <= l && r <= rr) return node[o].first;
  long long res = 1e15;
  if (node[o].second) push_up(o);
  int mid = (l + r) >> 1;
  if (ll <= mid) res = min(res, query(ll, rr, l, mid, o << 1));
  if (rr > mid) res = min(res, query(ll, rr, mid + 1, r, o << 1 | 1));
  return res;
}
int main() {
  int n, q, u, v, w, op, id;
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    edge[i] = {u, v, w};
    son[u].push_back({v, w});
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    edge[i + n - 1] = {u, v, w};
    g[u] = w;
  }
  dfs(1, 1, 1);
  build(1, n, 1);
  while (q--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &id, &w);
      if (id >= n) {
        u = edge[id].u;
        update(tin[u], tin[u], w - g[u], 1, n, 1);
        edge[id].w = g[u] = w;
      } else {
        v = edge[id].v;
        update(tin[v], tout[v], w - edge[id].w, 1, n, 1);
        edge[id].w = w;
      }
    } else {
      scanf("%d%d", &u, &v);
      int p = lca(u, v);
      if (p == u) {
        long long ans = query(tin[v], tin[v], 1, n, 1) - g[v] -
                        (query(tin[u], tin[u], 1, n, 1) - g[u]);
        printf("%I64d\n", ans);
      } else {
        long long ans = query(tin[v], tin[v], 1, n, 1) - g[v] +
                        query(tin[u], tout[u], 1, n, 1) -
                        (query(tin[u], tin[u], 1, n, 1) - g[u]);
        printf("%I64d\n", ans);
      }
    }
  }
  return 0;
}
