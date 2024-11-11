#include <bits/stdc++.h>
using namespace std;
struct dsu_save {
  long long v, u;
  pair<long long, long long> rnkv, rnku;
  dsu_save() {}
  dsu_save(long long _v, pair<long long, long long> _rnkv, long long _u,
           pair<long long, long long> _rnku)
      : v(_v), rnkv(_rnkv), u(_u), rnku(_rnku) {}
};
struct dsu_with_rollbacks {
  vector<long long> p;
  vector<pair<long long, long long>> rnk;
  long long comps;
  stack<dsu_save> op;
  dsu_with_rollbacks() {}
  dsu_with_rollbacks(long long n) {
    p.resize(2 * n + 1);
    rnk.resize(2 * n + 1);
    for (long long i = 1; i <= 2 * n; i++) {
      p[i] = i;
      rnk[i] = make_pair(i <= n / 2, !(i <= n / 2));
    }
    comps = 0;
  }
  long long find_set(long long v) { return (v == p[v]) ? v : find_set(p[v]); }
  bool unite(long long v, long long u) {
    v = find_set(v);
    u = find_set(u);
    if (v == u) return false;
    comps -= rnk[u].first * rnk[u].second + rnk[v].first * rnk[v].second;
    if (rnk[v].first + rnk[v].second > rnk[u].first + rnk[u].second) swap(v, u);
    op.push(dsu_save(v, rnk[v], u, rnk[u]));
    p[v] = u;
    rnk[u].first += rnk[v].first;
    rnk[u].second += rnk[v].second;
    comps += rnk[u].first * rnk[u].second;
    return true;
  }
  void rollback() {
    if (op.empty()) return;
    dsu_save x = op.top();
    op.pop();
    long long u = x.u, v = x.v;
    long long a = max(rnk[u].first, rnk[v].first);
    long long b = max(rnk[u].second, rnk[v].second);
    comps -= a * b;
    p[x.v] = x.v;
    rnk[x.v] = x.rnkv;
    p[x.u] = x.u;
    rnk[x.u] = x.rnku;
    comps += rnk[u].first * rnk[u].second + rnk[v].first * rnk[v].second;
  }
};
struct query {
  long long v, u;
  bool united;
  query(long long _v, long long _u) : v(_v), u(_u) {}
};
struct QueryTree {
  vector<vector<query>> t;
  dsu_with_rollbacks dsu;
  long long T;
  QueryTree() {}
  QueryTree(long long _T, long long n) : T(_T) {
    dsu = dsu_with_rollbacks(n);
    t.resize(4 * T + 555);
  }
  void add_to_tree(long long v, long long l, long long r, long long ul,
                   long long ur, query& q) {
    if (r < ul || l > ur) return;
    if (ul <= l && r <= ur) {
      t[v].push_back(q);
      return;
    }
    long long mid = (l + r) / 2;
    add_to_tree(2 * v, l, mid, ul, ur, q);
    add_to_tree(2 * v + 1, mid + 1, r, ul, ur, q);
  }
  void add_query(query q, long long l, long long r) {
    add_to_tree(1, 0, T - 1, l, r, q);
  }
  void dfs(long long v, long long l, long long r, vector<long long>& ans) {
    for (query& q : t[v]) {
      q.united = dsu.unite(q.v, q.u);
    }
    if (l == r)
      ans[l] = dsu.comps;
    else {
      long long mid = (l + r) / 2;
      dfs(2 * v, l, mid, ans);
      dfs(2 * v + 1, mid + 1, r, ans);
    }
    for (query q : t[v]) {
      if (q.united) dsu.rollback();
    }
  }
  vector<long long> solve() {
    vector<long long> ans(T);
    dfs(1, 0, T - 1, ans);
    return ans;
  }
};
long long t, n, m;
vector<long long> qq;
vector<long long> ans;
vector<pair<pair<long long, long long>, query>> qr;
map<pair<long long, long long>, long long> mr;
signed main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    t++;
    char ch;
    long long x, y;
    cin >> x >> y;
    y += 300005;
    if (mr.find(make_pair(x, y)) == mr.end()) {
      mr[make_pair(x, y)] = t;
    } else {
      long long beg = mr[make_pair(x, y)], end = t - 1;
      qr.push_back(make_pair(make_pair(beg, end), query(x, y)));
      assert(mr.find(make_pair(x, y)) != mr.end());
      mr.erase(make_pair(x, y));
    }
  }
  t++;
  for (auto x : mr) {
    long long beg = x.second, end = t;
    qr.push_back(
        make_pair(make_pair(beg, end), query(x.first.first, x.first.second)));
  }
  QueryTree q(300005, 300005);
  for (long long i = 0; i < qr.size(); i++) {
    q.add_query(qr[i].second, qr[i].first.first, qr[i].first.second);
  }
  ans = q.solve();
  for (long long i = 1; i < n + 1; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
