#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
const int LIM = 4e5 + 5, MOD = 1e9 + 7;
int t, n, m, k, x, y, w;
struct segtree {
  long long lazy[4 * LIM] = {0};
  long long sum[4 * LIM] = {0};
  int N;
  void clear(int n) { N = n; }
  inline void push(int v) {
    int lf = v << 1, rt = lf ^ 1;
    if (lazy[v] != 0) lazy[lf] = sum[lf] = sum[rt] = lazy[rt] = lazy[v];
    lazy[v] = 0;
  }
  void update(int v, int tl, int tr, int l, int r, long long val) {
    if (l > r or tl > r or tr < l) return;
    if (l == tl && tr == r) {
      sum[v] = lazy[v] = val;
    } else {
      push(v);
      int tm = (tl + tr) >> 1, lf = v << 1, rt = lf ^ 1;
      ;
      update(lf, tl, tm, l, min(r, tm), val);
      update(rt, tm + 1, tr, max(l, tm + 1), r, val);
      sum[v] = (sum[lf] | sum[rt]);
    }
  }
  long long query(int v, int tl, int tr, int l, int r) {
    if (l > r or tl > r or tr < l) {
      return 0LL;
    }
    if (l <= tl && tr <= r) {
      return sum[v];
    }
    push(v);
    int tm = (tl + tr) >> 1, lf = v << 1, rt = lf ^ 1;
    return query(lf, tl, tm, l, min(r, tm)) |
           query(rt, tm + 1, tr, max(l, tm + 1), r);
  }
  int q(int l, int r) { return __builtin_popcountll(query(1, 0, N - 1, l, r)); }
  void u(int l, int r, int val) { update(1, 0, N - 1, l, r, (1 << val)); }
} st;
int c[LIM];
vector<vector<int> > g;
struct hld {
  int n, t;
  vector<int> in, out;
  void dfs_hld(int v = 0, int p = 0) {
    in[v] = t++;
    for (auto u : g[v]) {
      if (u == p) continue;
      dfs_hld(u, v);
    }
    out[v] = t;
  }
  void pre(int N) {
    n = N;
    t = 0;
    in.assign(n, 0);
    out.assign(n, 0);
    dfs_hld();
    st.clear(n);
    for (int i = 0; i < n; ++i) st.u(in[i], in[i], c[i]);
  }
  void modifySubtree(int u, const int& value) {
    st.u(in[u], out[u] - 1, value);
  }
  int querySubtree(int u) { return st.q(in[u], out[u] - 1); }
};
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> c[i];
  g.assign(n, vector<int>(0));
  for (int i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  hld h;
  h.pre(n);
  for (int i = 0; i < m; ++i) {
    cin >> t >> x;
    --x;
    if (t & 1) {
      cin >> w;
      h.modifySubtree(x, w);
    } else
      cout << h.querySubtree(x) << '\n';
  }
  return 0;
}
