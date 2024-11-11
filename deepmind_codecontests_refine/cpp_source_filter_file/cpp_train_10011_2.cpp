#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T maxs(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T mins(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long N = 2e5 + 5;
auto eval = [](pair<long long, long long> p) { return p.first * p.second; };
struct node {
  long long wait = 0;
  pair<long long, long long> p;
  void merge(node &n1, node &n2) {
    this->wait = min(n1.wait, n2.wait);
    pair<long long, long long> p1 = n1.p;
    pair<long long, long long> p2 = n2.p;
    if (eval(p1) < eval(p2)) swap(p1, p2);
    p = p1;
    if (p2.second > p1.second) {
      mins(this->wait, (eval(p1) - eval(p2)) / (p2.second - p1.second));
    }
  }
};
struct update {
  long long val = 0;
  update(long long t = 0) { val = t; }
  void combine(update &par, long long tl, long long tr) { val += par.val; }
  void apply(node &node) {
    node.p.first += val;
    node.wait -= val;
    val = 0;
  }
};
template <typename node, typename update>
struct segtree {
  node t[4 * N];
  bool lazy[4 * N];
  update zaker[4 * N];
  long long tl[4 * N];
  long long tr[4 * N];
  node nul;
  inline void pushdown(long long v) {
    if (lazy[v]) {
      apply(zaker[v], v);
      lazy[v] = 0;
      zaker[v].apply(t[v]);
    }
  }
  inline void apply(update &u, long long v) {
    if (tl[v] != tr[v]) {
      lazy[2 * v] = lazy[2 * v + 1] = 1;
      zaker[2 * v].combine(u, tl[2 * v], tr[2 * v]);
      zaker[2 * v + 1].combine(u, tl[2 * v + 1], tr[2 * v + 1]);
    }
  }
  void build(long long v, long long start, long long end,
             vector<pair<long long, long long> > &arr) {
    tl[v] = start;
    tr[v] = end;
    if (start == end) {
      t[v].p = arr[start];
      t[v].wait = 1e18;
    } else {
      long long m = (start + end) / 2;
      build(2 * v, start, m, arr);
      build(2 * v + 1, m + 1, end, arr);
      t[v].merge(t[2 * v], t[2 * v + 1]);
    }
  }
  void zeno(long long v, long long l, long long r, update val) {
    pushdown(v);
    if (tr[v] < l || tl[v] > r) return;
    if (l <= tl[v] && tr[v] <= r && t[v].wait >= val.val) {
      t[v].p.first += val.val;
      t[v].wait - val.val;
      apply(val, v);
      return;
    }
    zeno(2 * v, l, r, val);
    zeno(2 * v + 1, l, r, val);
    t[v].merge(t[2 * v], t[2 * v + 1]);
  }
  long long query(long long v, long long l, long long r) {
    if (tr[v] < l || tl[v] > r) return 0;
    pushdown(v);
    if (l <= tl[v] && tr[v] <= r) {
      return eval(t[v].p);
    }
    long long a = query(2 * v, l, r);
    long long b = query(2 * v + 1, l, r);
    return max(a, b);
  }

 public:
  long long query(long long l, long long r) { return query(1, l, r); }
  void upd(long long l, long long r, update val) { return zeno(1, l, r, val); }
};
segtree<node, update> seg1, seg2;
vector<long long> g[N];
long long solve() {
  long long n, m;
  cin >> n >> m;
  for (long long i = 2; i < n + 1; i++) {
    long long p;
    cin >> p;
    g[p].push_back(i);
  }
  vector<long long> a(n + 1), b(n + 1);
  vector<long long> eu(n + 1), in(n + 1), out(n + 1);
  vector<pair<long long, long long> > vec(n + 1);
  for (long long i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i < n + 1; i++) {
    cin >> b[i];
  }
  long long t = 0;
  function<void(long long, long long)> dfs = [&](long long u, long long p) {
    in[u] = ++t;
    eu[t] = u;
    for (auto i : g[u]) {
      a[i] += a[u];
      b[i] += b[u];
      dfs(i, u);
    }
    out[u] = t;
  };
  dfs(1, 1);
  for (long long i = 1; i < n + 1; i++) {
    vec[i].first = a[eu[i]];
    vec[i].second = b[eu[i]];
  }
  seg1.build(1, 1, n, vec);
  for (long long i = 1; i < n + 1; i++) {
    vec[i].second *= -1;
  }
  seg2.build(1, 1, n, vec);
  for (long long i = 0; i < m; i++) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long v, first;
      cin >> v >> first;
      seg1.upd(in[v], out[v], first);
      seg2.upd(in[v], out[v], first);
    } else {
      long long v;
      cin >> v;
      cout << max(seg1.query(in[v], out[v]), seg2.query(in[v], out[v])) << "\n";
    }
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
