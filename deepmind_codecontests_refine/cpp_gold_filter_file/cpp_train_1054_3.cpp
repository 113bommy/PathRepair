#include <bits/stdc++.h>
using namespace std;
const int OO = 1e9;
const double EPS = 1e-9;
template <class T>
void _db(const char* dbStr, T e) {
  cout << dbStr << " = " << e << endl;
}
template <class T, class... L>
void _db(const char* dbStr, T e, L... r) {
  while (*dbStr != ',') cout << *dbStr++;
  cout << " = " << e << ',';
  _db(dbStr + 1, r...);
}
template <class S, class T>
ostream& operator<<(ostream& o, const map<S, T>& v) {
  o << "[";
  int i = 0;
  for (const pair<S, T>& pr : v)
    o << (!i++ ? "" : ", ") << "{" << pr.first << " : " << pr.second << "}";
  return o << "]";
}
template <template <class, class...> class S, class T, class... L>
ostream& operator<<(ostream& o, const S<T, L...>& v) {
  o << "[";
  int i = 0;
  for (const auto& e : v) o << (!i++ ? "" : ", ") << e;
  return o << "]";
}
template <class S, class T>
ostream& operator<<(ostream& o, const pair<S, T>& pr) {
  return o << "(" << pr.first << ", " << pr.second << ")";
}
ostream& operator<<(ostream& o, const string& s) {
  for (const char& c : s) o << c;
  return o;
}
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T>
using VVV = VV<V<T>>;
using ll = long long;
using pii = pair<int, int>;
using vi = V<int>;
using vii = V<pii>;
using vvi = VV<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using si = set<int>;
using usi = unordered_set<int>;
struct SegmentTree {
  V<ll> t, lazy;
  int n;
  void push(int v) {
    t[v << 1] += lazy[v];
    t[v << 1 | 1] += lazy[v];
    lazy[v << 1] += lazy[v];
    lazy[v << 1 | 1] += lazy[v];
    lazy[v] = 0;
  }
  ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) return 1e18;
    if (l == tl && r == tr) return t[v];
    push(v);
    int tm = (tl + tr) >> 1;
    ll valL = query(v << 1, tl, tm, l, min(r, tm));
    ll valR = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
    return min(valL, valR);
  }
  void lazyUpdate(int v, int tl, int tr, int l, int r, ll newVal) {
    if (l > r) return;
    if (l == tl && tr == r) {
      t[v] += newVal;
      lazy[v] += newVal;
    } else {
      push(v);
      int tm = (tl + tr) >> 1;
      lazyUpdate(v << 1, tl, tm, l, min(r, tm), newVal);
      lazyUpdate(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, newVal);
      ll valL = t[v << 1], valR = t[v << 1 | 1];
      t[v] = min(valL, valR);
    }
  }
  void init(int _n) {
    n = _n;
    t.assign(n << 2, 0);
    lazy.assign(n << 2, 0);
  }
  SegmentTree(int _n) { init(_n); }
  SegmentTree() {}
  ll query(int i, int j) { return query(1, 0, n - 1, i, j); }
  void lazyUpdate(int l, int r, ll newVal) {
    lazyUpdate(1, 0, n - 1, l, r, newVal);
  }
};
struct Query {
  int v, l, r;
};
int n, q;
VV<pii> adj;
V<pair<int, ll>> leaves;
vii range;
V<Query> queries;
vi Next, Prev;
V<ll> ans;
vvi queriesOnNode;
SegmentTree ST;
void dfs(int u, int p = -1, ll totW = 0) {
  for (auto& pr : adj[u]) {
    int v = pr.first, w = pr.second;
    if (v != p) {
      dfs(v, u, totW + w);
      range[u].first = min(range[u].first, range[v].first);
      range[u].second = max(range[u].second, range[v].second);
    }
  }
  if (int(adj[u].size()) == 1) {
    range[u] = make_pair(int(leaves.size()), int(leaves.size()));
    Next[u] = Prev[u] = int(leaves.size());
    leaves.push_back(make_pair(u, totW));
  }
}
void dfs2(int u, int p = -1) {
  for (auto& i : queriesOnNode[u]) {
    int l = Next[queries[i].l], r = Prev[queries[i].r];
    ans[i] = ST.query(l, r);
  }
  for (auto& pr : adj[u]) {
    int v = pr.first, w = pr.second;
    if (v != p) {
      ST.lazyUpdate(0, int(leaves.size()) - 1, w);
      ST.lazyUpdate(range[v].first, range[v].second, -2 * w);
      dfs2(v, u);
      ST.lazyUpdate(0, int(leaves.size()) - 1, -w);
      ST.lazyUpdate(range[v].first, range[v].second, 2 * w);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cin.tie(0);
  cin >> n >> q;
  adj.assign(n + 1, vii());
  for (int i = 2; i <= n; ++i) {
    int pi, wi;
    cin >> pi >> wi;
    adj[i].push_back(make_pair(pi, wi));
    adj[pi].push_back(make_pair(i, wi));
  }
  for (int i = 1; i <= n; ++i) sort(adj[i].begin(), adj[i].end());
  true;
  Next.assign(n + 1, -1);
  Prev.assign(n + 1, -1);
  range.assign(n + 1, make_pair(OO, -1));
  dfs(1);
  for (int i = n - 1; i >= 1; --i) {
    if (Next[i] == -1) Next[i] = Next[i + 1];
  }
  for (int i = 2; i <= n; ++i) {
    if (Prev[i] == -1) Prev[i] = Prev[i - 1];
  }
  ST = SegmentTree(int(leaves.size()));
  true;
  true;
  for (int i = 0; i < int(leaves.size()); ++i)
    ST.lazyUpdate(i, i, leaves[i].second);
  queries.assign(q, Query());
  queriesOnNode.assign(n + 1, vi());
  for (int i = 0; i < q; ++i) {
    cin >> queries[i].v >> queries[i].l >> queries[i].r;
    queriesOnNode[queries[i].v].push_back(i);
  }
  ans.assign(q, 0);
  dfs2(1);
  for (auto& elem : ans) cout << elem << '\n';
  return 0;
}
