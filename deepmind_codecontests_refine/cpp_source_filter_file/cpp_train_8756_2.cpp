#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
const int M = 14;
const long long mod = 1e9 + 7;
const double eps = 1e-14;
const double PI = acos(-1.0);
bool debug = false;
int fa[20][N], deep[N], id[N], p[N];
vector<int> vc[N];
void dfs(int o, int f) {
  deep[o] = deep[f] + 1, fa[0][o] = f;
  for (int i = 1; i < 20; ++i) fa[i][o] = fa[i - 1][fa[i - 1][o]];
  for (auto it : vc[o])
    if (it != f) dfs(it, o);
}
int lca(int u, int v) {
  if (deep[u] < deep[v]) swap(u, v);
  int d = deep[u] - deep[v];
  for (int i = 19; i >= 0; --i)
    if ((d >> i) & 1) u = fa[i][u];
  if (u == v) return u;
  for (int i = 19; i >= 0; --i)
    if (fa[i][u] != fa[i][v]) u = fa[i][u], v = fa[i][v];
  return fa[0][u];
}
struct Node {
  int tmp, l, r, _lca;
  void pri(int id) {
    printf("id = %d tmp = %d, l = %d, r = %d, _lca = %d\n", id, tmp, l, r,
           _lca);
  }
} node[N << 2];
void mer(Node ls, Node rs, Node &o) {
  if (ls.tmp < rs.tmp) swap(ls, rs);
  if (ls.tmp == 2) {
    o.tmp = 2;
    return;
  }
  o.tmp = 1, o._lca = ls._lca;
  if (rs.tmp) {
    if (ls._lca != rs._lca) {
      o.tmp = 2;
      return;
    }
    int x = lca(ls.l, rs.l), y;
    if (x == ls.l || x == rs.l) {
      y = lca(ls.r, rs.r);
      if (y == ls.r || y == rs.r) {
        o.l = x == ls.l ? rs.l : ls.l;
        o.r = y == ls.r ? rs.r : ls.r;
      } else
        o.tmp = 2;
    } else {
      x = lca(ls.l, rs.r), y = lca(ls.r, rs.l);
      if ((y == ls.r || y == rs.l) && (x == ls.l || x == rs.r)) {
        o.l = x == ls.l ? rs.r : ls.l;
        o.r = y == ls.r ? rs.l : ls.r;
      } else
        o.tmp = 2;
    }
  } else if (ls.tmp) {
    if (deep[ls._lca] > deep[rs.l]) {
      o.tmp = 2;
      return;
    }
    int y = lca(ls.l, rs.r);
    if (y == ls.l)
      o.l = rs.r, o.r = ls.r;
    else if (y == rs.r)
      o.l = ls.l, o.r = ls.r;
    else {
      y = lca(ls.r, rs.r);
      if (y == ls.r)
        o.l = ls.l, o.r = rs.r;
      else if (y == ls.r)
        o.l = ls.l, o.r = ls.r;
      else
        o.tmp = 2;
    }
  } else {
    if (deep[ls.l] > deep[rs.l]) swap(ls, rs);
    int x = lca(ls.l, rs.l);
    if (deep[x] < deep[ls.l])
      o._lca = x, o.l = ls.r, o.r = rs.r;
    else {
      x = lca(ls.r, rs.r);
      if (x == rs.r)
        o.tmp = 0, o.l = ls.l, o.r = ls.r;
      else if (x == ls.r)
        o.tmp = 0, o.l = ls.l, o.r = rs.r;
      else if (x == ls.l)
        o.tmp = 1, o._lca = ls.l, o.l = ls.r, o.r = rs.r;
      else
        o.tmp = 2;
    }
  }
}
void build(int l, int r, int o) {
  if (l == r) {
    node[o].l = node[o].r = id[l];
    node[o].tmp = 0;
    if (debug) {
      printf("l = %d, r = %d, o = %d\n", l, r, o);
      node[o].pri(o);
    }
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, o << 1);
  build(mid + 1, r, o << 1 | 1);
  mer(node[o << 1], node[o << 1 | 1], node[o]);
  if (debug) {
    printf("l = %d, r = %d, o = %d\n", l, r, o);
    node[o].pri(o);
  }
}
void update(int x, int v, int l, int r, int o) {
  if (l == r) {
    node[o].l = node[o].r = v;
    node[o].tmp = 0;
    if (debug) {
      printf("l = %d, r = %d, o = %d\n", l, r, o);
      node[o].pri(o);
    }
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    update(x, v, l, mid, o << 1);
  else
    update(x, v, mid + 1, r, o << 1 | 1);
  mer(node[o << 1], node[o << 1 | 1], node[o]);
  if (debug) {
    printf("l = %d, r = %d, o = %d\n", l, r, o);
    node[o].pri(o);
  }
}
int querty(int l, int r, int o) {
  if (node[o].tmp < 2) return r - l + 1;
  int ret = 0, mid;
  Node ans, now;
  ans.tmp = -1;
  while (l != r) {
    if (debug) {
      printf("----- query ----\n");
      printf("l = %d, r = %d, o = %d\n", l, r, o);
    }
    now.tmp = 2;
    if (node[o << 1].tmp <= 1) {
      if (ans.tmp == -1)
        now = node[o << 1];
      else
        mer(ans, node[o << 1], now);
    }
    if (debug) {
      ans.pri(-1);
      node[o << 1].pri(o << 1);
      now.pri(-2);
    }
    mid = l + r >> 1;
    if (now.tmp < 2) {
      ans = now, ret += mid - l + 1;
      l = mid + 1;
      o = o << 1 | 1;
    } else {
      r = mid;
      o = o << 1;
    }
  }
  return ret;
}
int main() {
  int n, q, x, y, op;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &p[i]), id[p[i] + 1] = i;
  for (int i = 2; i <= n; ++i) {
    scanf("%d", &x);
    vc[x].push_back(i);
  }
  dfs(1, 0);
  build(1, n, 1);
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &x, &y);
      update(p[x] + 1, y, 1, n, 1);
      update(p[y] + 1, x, 1, n, 1);
      swap(p[x], p[y]);
    } else {
      printf("%d\n", querty(1, n, 1));
    }
  }
  return 0;
}
