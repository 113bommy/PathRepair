#include <bits/stdc++.h>
using namespace std;
using LL = long long;
class LCA {
 public:
  LCA(int _n) : n(_n) {
    logn = log2(_n) + 1;
    x = vector<vector<pair<int, int>>>(_n);
    p = pt = vector<vector<int>>(_n, vector<int>(logn, -1));
    d = vector<int>(_n);
    v = vector<int>(_n);
  }
  void AddEdge(int a, int b, int c) {
    x[a].push_back({b, c});
    x[b].push_back({a, c});
  }
  void Dfs(int a, int fa, int depth, int tol) {
    d[a] = depth;
    p[a][0] = fa;
    pt[a][0] = tol;
    for (auto [i, cost] : x[a]) {
      if (i == fa) continue;
      Dfs(i, a, depth + 1, cost);
    }
  }
  void Build(int r) {
    root = r;
    Dfs(r, -1, 0, 0);
    for (int j = 1; j < logn; ++j) {
      for (int i = 0; i < n; ++i) {
        if (p[i][j - 1] != -1) {
          p[i][j] = p[p[i][j - 1]][j - 1];
          pt[i][j] = max(pt[i][j - 1], pt[p[i][j - 1]][j - 1]);
        }
      }
    }
  }
  int Cost(int a, int b) {
    if (a == b) return 0;
    if (d[a] < d[b]) swap(a, b);
    int log = 1;
    while ((1 << log) <= d[a]) ++log;
    --log;
    int ans = 0;
    for (int i = log; i >= 0; --i) {
      if (d[a] - (1 << i) >= d[b]) {
        ans = max(ans, pt[a][i]);
        a = p[a][i];
      }
    }
    if (a == b) return ans;
    for (int i = log; i >= 0; --i) {
      if (p[a][i] != -1 && p[a][i] != p[b][i]) {
        ans = max(ans, pt[a][i]);
        ans = max(ans, pt[b][i]);
        a = p[a][i];
        b = p[b][i];
      }
    }
    ans = max(ans, pt[a][0]);
    ans = max(ans, pt[b][0]);
    return ans;
  }
  int n, logn;
  int root;
  vector<vector<pair<int, int>>> x;
  vector<vector<int>> p;
  vector<vector<int>> pt;
  vector<int> d;
  vector<int> v;
};
namespace atcoder {
struct dsu {
 public:
  dsu() : _n(0) {}
  dsu(int n, LCA& lca) : _n(n), parent_or_size(n, -1) {
    e = ei = cost = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      e[i] = lca.v[i];
      ei[i] = i;
      cost[i] = 0;
    }
  }
  int merge(int a, int b, LCA& lca) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    if (e[x] == e[y]) {
      cost[x] = max(cost[x], cost[y]);
      cost[x] = max(cost[x], lca.Cost(x, y));
    } else {
      if (e[x] < e[y]) {
        e[x] = e[y];
        ei[x] = ei[y];
        cost[x] = cost[y];
      }
    }
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }
  pair<int, int> getcost(int a) {
    a = leader(a);
    return {e[a], cost[a]};
  }
  int geti(int a) { return ei[leader(a)]; }
  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }
  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }
  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

 private:
  int _n;
  vector<int> parent_or_size;
  vector<int> e;
  vector<int> ei;
  vector<int> cost;
};
}  // namespace atcoder
struct Edge {
  int a, b, c;
  bool operator<(const Edge& rhs) const { return c > rhs.c; }
};
struct Query {
  int v, s;
  int i;
  int ans1, ans2;
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  LCA lca(n);
  vector<Edge> x;
  for (int i = 0; i < n; ++i) cin >> lca.v[i];
  for (int i = 1; i < n; ++i) {
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    --a;
    --b;
    x.push_back({a, b, c});
    lca.AddEdge(a, b, t);
  }
  sort(x.begin(), x.end());
  lca.Build(0);
  vector<Query> y(m);
  for (int i = 0; i < m; ++i) {
    cin >> y[i].v >> y[i].s;
    --y[i].s;
    y[i].i = i;
  }
  sort(y.begin(), y.end(),
       [](const Query& a, const Query& b) { return a.v > b.v; });
  atcoder::dsu dsu(n, lca);
  int j = 0;
  for (int i = 0; i < m; ++i) {
    while (j < n - 1 && x[j].c >= y[i].v) {
      dsu.merge(x[j].a, x[j].b, lca);
      ++j;
    }
    auto pi = dsu.getcost(y[i].s);
    y[i].ans1 = pi.first;
    y[i].ans2 = pi.second;
    y[i].ans2 = max(y[i].ans2, lca.Cost(y[i].s, dsu.geti(y[i].s)));
  }
  sort(y.begin(), y.end(),
       [](const Query& a, const Query& b) { return a.i < b.i; });
  for (int i = 0; i < m; ++i) {
    cout << y[i].ans1 << " " << y[i].ans2 << "\n";
  }
  return 0;
}
