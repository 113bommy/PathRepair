#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
const long long inf = numeric_limits<long long>::max() / 2;
const long double eps = 1e-9;
const long double pi = acos(-1);
inline void solve(), read();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  solve();
  return 0;
}
struct graph {
  long long n;
  vector<vector<long long> > adj;
  graph() {}
  graph(long long n_) {
    n = n_;
    adj.resize(n);
  }
  inline void insert(long long v, long long u) {
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
};
struct vertex {
  long long val = 0, push = 0;
};
struct segment {
  long long n;
  vector<vertex> t;
  segment() {}
  segment(vector<long long>& a) {
    long long l = log2((long long)((a).size())) + 1;
    n = 1ll << l;
    t.resize(4 * n);
    build(a);
  }
  inline void build(vector<long long>& a) {
    for (long long i = 0; i < (long long)((a).size()); i++) {
      t[i + n].val = a[i];
    }
    for (long long i = n - 1; i >= 0; i--) {
      t[i].val = t[2 * i].val + t[2 * i + 1].val;
    }
  }
  inline void push(long long v, long long tl, long long tr) {
    if (t[v].push == 0) {
      return;
    }
    t[2 * v].push += t[v].push;
    t[2 * v + 1].push += t[v].push;
    t[v].val += t[v].push * (tr - tl + 1);
    t[v].push = 0;
  }
  void upd(long long v, long long tl, long long tr, long long l, long long r,
           long long d) {
    push(v, tl, tr);
    if (tl > r || tr < l) {
      return;
    }
    if (l <= tl && tr <= r) {
      t[v].push += d;
      push(v, tl, tr);
      return;
    }
    long long tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, d);
    upd(2 * v + 1, tm + 1, tr, l, r, d);
    t[v].val = t[2 * v].val + t[2 * v + 1].val;
  }
  long long sum(long long v, long long tl, long long tr, long long l,
                long long r) {
    push(v, tl, tr);
    if (tl > r || tr < l) {
      return 0;
    }
    if (l <= tl && tr <= r) {
      return t[v].val;
    }
    long long tm = (tl + tr) / 2;
    long long v1 = sum(2 * v, tl, tm, l, r);
    long long v2 = sum(2 * v + 1, tm + 1, tr, l, r);
    return v1 + v2;
  }
};
long long n, m;
vector<long long> a, d, ord1, ord2, f1, f2, s1, s2;
graph g;
segment st1, st2;
void dfs(long long v, long long p) {
  d[v] = d[p] + 1;
  if (d[v] % 2 == 0) {
    ord1.push_back(a[v]);
    f1[v] = (long long)((ord1).size()) - 1;
    if (f1[p] == -1) {
      f1[p] = (long long)((ord1).size()) - 1;
    }
  } else {
    ord2.push_back(a[v]);
    f2[v] = (long long)((ord2).size()) - 1;
    if (f2[p] == -1) {
      f2[p] = (long long)((ord2).size()) - 1;
    }
  }
  for (long long u : g.adj[v]) {
    if (u == p) {
      continue;
    }
    dfs(u, v);
  }
  s1[v] = (long long)((ord1).size()) - 1;
  s2[v] = (long long)((ord2).size()) - 1;
}
inline void precalc() {
  d.resize(n, 0);
  f1.resize(n, -1);
  f2.resize(n, -1);
  s1.resize(n, -1);
  s2.resize(n, -1);
  d[0] = -1;
  dfs(0, 0);
  for (long long i = 0; i < n; i++) {
    if (f1[i] == -1) {
      s1[i] = -1;
    }
    if (f2[i] == -1) {
      s2[i] = -1;
    }
  }
  st1 = segment(ord1);
  st2 = segment(ord2);
}
inline void solve() {
  precalc();
  for (long long i = 0; i < m; i++) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x, val;
      cin >> x >> val;
      --x;
      if (d[x] % 2 == 1) {
        val = -val;
      }
      st1.upd(1, 0, st1.n - 1, f1[x], s1[x], val);
      st2.upd(1, 0, st2.n - 1, f2[x], s2[x], -val);
    } else if (t == 2) {
      long long x;
      cin >> x;
      --x;
      long long ans = 0;
      if (d[x] % 2 == 0) {
        ans = st1.sum(1, 0, st1.n - 1, f1[x], f1[x]);
      } else {
        ans = st2.sum(1, 0, st2.n - 1, f2[x], f2[x]);
      }
      cout << ans << "\n";
    }
  }
}
inline void read() {
  cin >> n >> m;
  a.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  g = graph(n);
  for (long long i = 0; i < n - 1; i++) {
    long long v, u;
    cin >> v >> u;
    --v, --u;
    g.insert(v, u);
  }
}
