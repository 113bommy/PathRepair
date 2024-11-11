#include <bits/stdc++.h>
using namespace std;
template <typename T, class F = function<T(const T &, const T &)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;
  SparseTable(){};
  SparseTable(const vector<T> &a, const F &f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};
class tree {
 public:
  ;
  int n;
  vector<vector<int>> gr;
  vector<int> in, out, tour, dep, par, sub;
  SparseTable<int> st;
  tree(){};
  tree(int _n) {
    n = _n;
    gr.resize(n);
    in.resize(n);
    out.resize(n);
    dep.resize(n);
    par.resize(n);
    sub.resize(n, 1);
  }
  void add(int u, int v) {
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  void dfs(int v, int p) {
    in[v] = tour.size();
    tour.push_back(v);
    if (~p) dep[v] = dep[p] + 1;
    par[v] = p;
    for (int i : gr[v]) {
      if (i == p) continue;
      sub[v] += sub[i];
      dfs(i, v);
      tour.push_back(v);
    }
    out[v] = tour.size() - 1;
  }
  void prep() {
    dfs(0, -1);
    st = SparseTable<int>(tour, [&](int x, int y) {
      return (dep[x] == dep[y] ? min(x, y) : (dep[x] > dep[y] ? y : x));
    });
  }
  int parent(int u, int v) {
    return st.get(min(in[u], in[v]), max(out[u], out[v]));
  }
  pair<map<int, int>, vector<int>> to_tree(vector<int> id) {
    sort(id.begin(), id.end(), [&](int x, int y) { return in[x] < in[y]; });
    int sz = id.size();
    for (int i = 0; i < sz - 1; i++) {
      id.push_back(parent(id[i], id[i + 1]));
    }
    sort(id.begin(), id.end(), [&](int x, int y) { return in[x] < in[y]; });
    id.resize(unique(id.begin(), id.end()) - id.begin());
    sz = id.size();
    vector<int> p(sz);
    map<int, int> to;
    for (int i = 0; i < sz; i++) to[id[i]] = i;
    vector<int> que;
    for (int i = 0; i < sz; i++) {
      while (!que.empty() && out[id[que.back()]] < in[id[i]]) que.pop_back();
      if (que.empty())
        p[i] = -1;
      else
        p[i] = que.back();
      que.push_back(i);
    }
    return make_pair(to, p);
  }
};
class HLD_tree {
 public:
  ;
  int n;
  vector<vector<int>> gr;
  vector<int> sub;
  vector<int> path;
  vector<int> to;
  vector<int> pos;
  vector<int> par;
  HLD_tree(){};
  HLD_tree(int _n) : n(_n) {
    gr.resize(n);
    sub.resize(n, 1);
    to.resize(n);
    pos.resize(n);
    par.resize(n);
  }
  void add(int u, int v) {
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  void dfs1(int v, int p) {
    par[v] = p;
    for (int i : gr[v]) {
      if (i == p) continue;
      dfs1(i, v);
      sub[v] += sub[i];
    }
  }
  void dfs2(int v, int p, int t) {
    pos[v] = path.size();
    to[v] = t;
    path.push_back(v);
    if ((gr[v].size() == 1 && ~p) || gr[v].empty()) return;
    int nxt = gr[v][0];
    for (int i : gr[v]) {
      if (i == p) continue;
      dfs2(i, v, (i == nxt ? t : i));
    }
  }
  void prep() {
    dfs1(0, -1);
    for (int i = 0; i < n; i++) {
      int nxt = -1;
      for (int j = 0; j < (int)gr[i].size(); j++) {
        int v = gr[i][j];
        if (v == par[i]) continue;
        if (nxt == -1 || sub[v] > sub[gr[i][nxt]]) nxt = j;
      }
      if (~nxt) swap(gr[i][0], gr[i][nxt]);
    }
    dfs2(0, -1, 0);
  }
  vector<pair<int, int>> make_path(int v) {
    vector<pair<int, int>> res;
    while (~v) {
      res.emplace_back(pos[to[v]], pos[v]);
      v = par[to[v]];
    }
    return res;
  }
};
class segtree {
 public:
  struct node {
    long long sum = 0;
    long long mul = 0;
    long long ad = 0;
    void apply(int l, int r, long long v, int t = -1) {
      if (t != -1) {
        sum = v * t;
        mul = t;
      } else {
        sum += v * mul;
        ad += v;
      }
    }
  };
  node unite(const node &a, const node &b) const {
    node res;
    res.sum = a.sum + b.sum;
    res.mul = a.mul + b.mul;
    return res;
  }
  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    if (tree[x].ad != 0) {
      tree[x + 1].apply(l, y, tree[x].ad);
      tree[z].apply(y + 1, r, tree[x].ad);
      tree[x].ad = 0;
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
  void build(int x, int l, int r, const vector<pair<int, int>> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l].first, v[r].second);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
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
  int find_first_knowingly(int x, int l, int r,
                           const function<bool(const node &)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }
  int find_first(int x, int l, int r, int ll, int rr,
                 const function<bool(const node &)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
  int find_first(int ll, int rr, const function<bool(const node &)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }
  int find_last_knowingly(int x, int l, int r,
                          const function<bool(const node &)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }
  int find_last(int x, int l, int r, int ll, int rr,
                const function<bool(const node &)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
  int find_last(int ll, int rr, const function<bool(const node &)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};
template <typename T>
void debug_out(T t) {
  cerr << t;
}
template <typename A, typename B>
void debug_out(pair<A, B> u) {
  cerr << "(" << u.first << " " << u.second << ")";
}
template <typename T>
void debug_out(vector<T> t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << ", ";
  }
}
template <typename T>
void debug_out(vector<vector<T>> t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << endl;
  }
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  debug_out(H);
  cerr << " ";
  debug_out(T...);
}
template <typename T>
void debug_out(set<T> a) {
  vector<T> _a;
  for (T t : a) _a.push_back(t);
  debug_out(_a);
}
int n, m, q;
long long C;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
  cin >> n >> m >> q >> C;
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    f[i]--;
  }
  tree g(n);
  for (int i = 1; i < n; i++) {
    int u;
    cin >> u;
    u--;
    g.add(u, i);
  }
  vector<int> c(m);
  for (int i = 0; i < m; i++) {
    cin >> c[i];
  }
  g.prep();
  vector<vector<int>> id(m, vector<int>(1, 0));
  for (int i = 0; i < n; i++) id[f[i]].push_back(i);
  vector<vector<int>> que;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, w;
      cin >> x >> w;
      w--;
      x--;
      id[w].push_back(x);
      que.push_back({t, x, w});
    } else {
      int w;
      cin >> w;
      w--;
      que.push_back({t, w});
    }
  }
  vector<long long> res(m);
  vector<long long> total(m);
  vector<segtree> st(m);
  vector<HLD_tree> cur(m);
  vector<map<int, int>> to(m);
  vector<vector<int>> ps(m);
  for (int i = 0; i < m; i++) {
    if (id[i].empty()) continue;
    pair<map<int, int>, vector<int>> foo = g.to_tree(id[i]);
    vector<int> par = foo.second;
    to[i] = foo.first;
    int sz = par.size();
    vector<int> sp(sz);
    for (auto j : to[i]) sp[j.second] = j.first;
    ps[i] = sp;
    vector<pair<int, int>> now;
    cur[i] = HLD_tree(sz);
    for (int j = 1; j < sz; j++) {
      cur[i].add(j, par[j]);
    }
    cur[i].prep();
    vector<int> cnt(sz);
    for (int j = sz - 1; j > -1; j--) {
      if (f[sp[j]] == i) cnt[j] = 1;
      for (int t : cur[i].gr[j]) {
        if (t == par[j]) continue;
        cnt[j] += cnt[t];
      }
      int mu = g.dep[ps[i][j]] -
               (cur[i].par[j] == -1 ? -1 : g.dep[ps[i][cur[i].par[j]]]);
      total[i] += 1LL * mu * cnt[j];
      res[i] += 1LL * mu * cnt[j] * cnt[j];
    }
    for (int j : cur[i].path) {
      int v = sp[j];
      now.emplace_back(cnt[j],
                       g.dep[v] - (par[j] == -1 ? -1 : g.dep[sp[par[j]]]));
    }
    st[i] = segtree(now);
  }
  for (int i = 0; i < q; i++) {
    int t = que[i][0];
    if (t == 1) {
      int x = que[i][1], w = que[i][2];
      res[f[x]] += g.dep[x] + 1;
      total[f[x]] -= g.dep[x] + 1;
      vector<pair<int, int>> seg = cur[f[x]].make_path(to[f[x]][x]);
      for (auto i : seg) {
        res[f[x]] -= st[f[x]].get(i.first, i.second).sum * 2;
        st[f[x]].modify(i.first, i.second, -1);
      }
      f[x] = w;
      res[f[x]] += g.dep[x] + 1;
      total[f[x]] += g.dep[x] + 1;
      seg = cur[f[x]].make_path(to[f[x]][x]);
      for (auto i : seg) {
        res[f[x]] += st[f[x]].get(i.first, i.second).sum * 2;
        st[f[x]].modify(i.first, i.second, 1);
      }
    } else {
      int w = que[i][1];
      double ans = res[w] * c[w] * c[w] - 2LL * c[w] * total[w] * C + n * C * C;
      ans /= n;
      cout << ans << "\n";
    }
  }
  return 0;
}
