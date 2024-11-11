#include <bits/stdc++.h>
using namespace std;
class segtree {
 public:
  struct node {
    int black = INT_MIN;
    int white = INT_MIN;
    bool exchange = false;
    void apply(int l, int r, int v) {
      if (v >= 0) {
        int t = v & 1;
        v >>= 1;
        t ? black : white = v;
      } else {
        swap(black, white);
        exchange = true;
      }
    }
  };
  node unite(const node &a, const node &b) const {
    node res;
    res.black = max(a.black, b.black);
    res.white = max(a.white, b.white);
    return res;
  }
  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].exchange) {
      tree[x + 1].apply(l, y, -1);
      tree[z].apply(y + 1, r, -1);
      tree[x].exchange = false;
    }
  }
  inline void pull(int x, int z) { tree[x] = unite(tree[x + 1], tree[z]); }
  int n;
  vector<node> tree;
  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }
  template <typename M, typename... T>
  void build(int x, int l, int r, const vector<M> &v, const T &...t) {
    if (l == r) {
      tree[x].apply(l, r, v[l], t...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v, t...);
    build(z, y + 1, r, v, t...);
    pull(x, z);
  }
  template <typename M, typename... T>
  segtree(const vector<M> &v, const T &...t) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v, t...);
  }
  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }
  segtree(){};
  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }
  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }
  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }
  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M &...v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }
  template <typename... M>
  void modify(int ll, int rr, const M &...v) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }
};
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> from(n - 1);
  vector<int> to(n - 1);
  vector<int> d(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    u--;
    v--;
    g[u].push_back(i);
    g[v].push_back(i);
    from[i] = u;
    to[i] = v;
    d[i] = t;
  }
  vector<int> dep(n);
  function<void(int, int)> dfs0 = [&](int v, int p) {
    if (~p)
      dep[v] = dep[p] + 1;
    else
      dep[v] = 0;
    for (int i : g[v]) {
      int id = from[i] ^ to[i] ^ v;
      if (id == p) continue;
      dfs0(id, v);
    }
  };
  dfs0(0, -1);
  int left_root = max_element(dep.begin(), dep.end()) - dep.begin();
  dfs0(left_root, -1);
  int right_root = max_element(dep.begin(), dep.end()) - dep.begin();
  vector<int> order;
  vector<int> din(n);
  vector<int> dout(n);
  vector<int> par(n);
  function<void(int, int)> dfs = [&](int v, int p) {
    par[v] = p;
    if (~p)
      dep[v] = dep[p] + 1;
    else
      dep[v] = 0;
    din[v] = order.size();
    order.push_back(v);
    for (int i : g[v]) {
      int id = from[i] ^ to[i] ^ v;
      if (id == p) continue;
      dfs(id, v);
    }
    dout[v] = order.size() - 1;
  };
  vector<int> R_order, R_in, R_out, R_dep, R_par, L_order, L_in, L_out, L_dep,
      L_par;
  dfs(right_root, -1);
  R_order = order;
  R_in = din;
  R_out = dout;
  R_dep = dep;
  R_par = par;
  order.clear();
  dfs(left_root, -1);
  L_order = order;
  L_in = din;
  L_out = dout;
  L_dep = dep;
  L_par = par;
  vector<int> pos(n);
  function<void(int, int, int)> dfs1 = [&](int v, int p, int t) {
    pos[v] = t;
    for (int i : g[v]) {
      int id = from[i] ^ to[i] ^ v;
      if (id == p) continue;
      dfs1(id, v, t ^ d[i]);
    }
  };
  dfs1(0, -1, 0);
  for (int i = 0; i < n; i++) {
    L_dep[i] = L_dep[i] * 2 + pos[i];
    R_dep[i] = R_dep[i] * 2 + pos[i];
  }
  for (int i = 0; i < n; i++) {
    L_order[i] = L_dep[L_order[i]];
    R_order[i] = R_dep[R_order[i]];
  }
  segtree Lst(L_order);
  segtree Rst(R_order);
  int q;
  cin >> q;
  while (q--) {
    int id;
    cin >> id;
    id--;
    int u = from[id];
    int v = to[id];
    int ret = 0;
    {
      if (L_par[v] == u) swap(u, v);
      Lst.modify(L_in[u], L_out[u], -1);
      segtree::node x = Lst.get(L_in[left_root], L_out[left_root]);
      segtree::node y = Lst.get(L_in[left_root], L_in[left_root]);
      int v = (y.black > INT_MIN ? x.black : x.white);
      ret = max(ret, v);
    }
    {
      if (R_par[v] == u) swap(u, v);
      Rst.modify(R_in[u], R_out[u], -1);
      segtree::node x = Rst.get(R_in[right_root], R_out[right_root]);
      segtree::node y = Rst.get(R_in[right_root], R_in[right_root]);
      int v = (y.black > INT_MIN ? x.black : x.white);
      ret = max(ret, v);
    }
    cout << ret << "\n";
  }
  return 0;
}
