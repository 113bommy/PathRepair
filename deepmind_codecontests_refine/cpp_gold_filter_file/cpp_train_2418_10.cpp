#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1},
          dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T &a, U b) {
  return a < b ? (a = b, true) : false;
}
template <typename T, typename U>
inline bool chmin(T &a, U b) {
  return a > b ? (a = b, true) : false;
}
template <typename T>
void unique(vector<T> &a) {
  a.erase(unique((a).begin(), (a).end()), a.end());
}
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;
using CostType = ll;
struct Edge {
  int src, dst;
  CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &rhs) const {
    return cost != rhs.cost ? cost < rhs.cost
           : dst != rhs.dst ? dst < rhs.dst
                            : src < rhs.src;
  }
  inline bool operator<=(const Edge &rhs) const { return !(rhs < *this); }
  inline bool operator>(const Edge &rhs) const { return rhs < *this; }
  inline bool operator>=(const Edge &rhs) const { return !(*this < rhs); }
};
struct CentroidDecomposition {
  int root;
  vector<vector<int> > comp;
  vector<int> par;
  CentroidDecomposition(const vector<vector<Edge> > &graph) : graph(graph) {
    int n = graph.size();
    alive.assign(n, true);
    subtree.resize(n);
    comp.resize(n);
    par.assign(n, -1);
    root = build(0);
  }

 private:
  const vector<vector<Edge> > graph;
  vector<bool> alive;
  vector<int> subtree;
  int build(int s) {
    int centroid = search_centroid(-1, s, calc_subtree(-1, s) / 2);
    alive[centroid] = false;
    for (const Edge &e : graph[centroid]) {
      if (alive[e.dst]) {
        comp[centroid].emplace_back(build(e.dst));
        par[e.dst] = centroid;
      }
    }
    alive[centroid] = true;
    return centroid;
  }
  int calc_subtree(int par, int ver) {
    subtree[ver] = 1;
    for (const Edge &e : graph[ver]) {
      if (e.dst != par && alive[e.dst])
        subtree[ver] += calc_subtree(ver, e.dst);
    }
    return subtree[ver];
  }
  int search_centroid(int par, int ver, int half) {
    for (const Edge &e : graph[ver]) {
      if (e.dst != par && alive[e.dst]) {
        if (subtree[e.dst] > half) return search_centroid(ver, e.dst, half);
      }
    }
    return ver;
  }
};
template <typename T>
struct LiChaoTree {
  struct Line {
    T a, b;
    Line(T a, T b) : a(a), b(b) {}
    inline T get(T x) const { return a * x + b; }
    inline bool over(const Line &b, const T &x) const {
      return get(x) < b.get(x);
    }
  };
  vector<T> xs;
  vector<Line> seg;
  int sz;
  LiChaoTree(const vector<T> &x, T INF) : xs(x) {
    sz = 1;
    while (sz < xs.size()) sz <<= 1;
    while (xs.size() < sz) xs.push_back(xs.back() + 1);
    seg.assign(2 * sz - 1, Line(0, INF));
  }
  void update(Line &x, int k, int l, int r) {
    int mid = (l + r) >> 1;
    auto latte = x.over(seg[k], xs[l]), malta = x.over(seg[k], xs[mid]);
    if (malta) swap(seg[k], x);
    if (l + 1 >= r)
      return;
    else if (latte != malta)
      update(x, 2 * k + 1, l, mid);
    else
      update(x, 2 * k + 2, mid, r);
  }
  void update(T a, T b) {
    Line l(a, b);
    update(l, 0, 0, sz);
  }
  T query(int k) {
    const T x = xs[k];
    k += sz - 1;
    T ret = seg[k].get(x);
    while (k > 0) {
      k = (k - 1) >> 1;
      ret = min(ret, seg[k].get(x));
    }
    return ret;
  }
};
int main() {
  int n;
  cin >> n;
  vector<vector<Edge> > graph(n);
  for (int _ = (0); _ < (n - 1); ++_) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    graph[u].emplace_back(u, v);
    graph[v].emplace_back(v, u);
  }
  vector<int> a(n);
  for (int i = (0); i < (n); ++i) cin >> a[i];
  CentroidDecomposition cent(graph);
  vector<bool> visited(n, false);
  ll ans = 0;
  function<void(int)> dfs = [&](int root) {
    visited[root] = true;
    chmax(ans, a[root]);
    vector<vector<ll> > sum_a, psum_a;
    vector<vector<pair<ll, int> > > psum_b;
    function<void(int, int, int, ll, ll, ll, int)> dfs2 =
        [&](int par, int ver, int idx, ll sum, ll A, ll B, int len) {
          sum += a[ver];
          A += 1LL * a[ver] * len;
          B += sum - a[root];
          bool leaf = true;
          for (const Edge &e : graph[ver]) {
            if (e.dst == par || visited[e.dst]) continue;
            dfs2(ver, e.dst, idx, sum, A, B, len + 1);
            leaf = false;
          }
          if (leaf) {
            sum_a[idx].emplace_back(sum);
            psum_a[idx].emplace_back(A);
            psum_b[idx].emplace_back(B, len - 1);
          }
        };
    for (const Edge &e : graph[root]) {
      if (visited[e.dst]) continue;
      int sz = sum_a.size();
      sum_a.emplace_back();
      psum_a.emplace_back();
      psum_b.emplace_back();
      dfs2(-1, e.dst, sz, a[root], a[root], 0, 2);
    }
    int m = sum_a.size();
    vector<ll> xs;
    for (int i = (0); i < (m); ++i) {
      for (ll e : sum_a[i]) xs.emplace_back(e);
      for (ll e : psum_a[i]) chmax(ans, e);
      for (auto pr : psum_b[i])
        chmax(ans, pr.first + 1LL * a[root] * (pr.second + 1));
    }
    if (!xs.empty()) {
      sort((xs).begin(), (xs).end());
      unique(xs);
      LiChaoTree<ll> lct1(xs, LINF);
      for (int i = (0); i < (m); ++i) {
        int sz = sum_a[i].size();
        for (int j = (0); j < (sz); ++j) {
          chmax(ans,
                -lct1.query(lower_bound((xs).begin(), (xs).end(), sum_a[i][j]) -
                            xs.begin()) +
                    psum_a[i][j]);
        }
        for (int j = (0); j < (sz); ++j) {
          lct1.update(-psum_b[i][j].second, -psum_b[i][j].first);
        }
      }
      LiChaoTree<ll> lct2(xs, LINF);
      for (int i = m - 1; i >= 0; --i) {
        int sz = sum_a[i].size();
        for (int j = (0); j < (sz); ++j)
          chmax(ans,
                -lct2.query(lower_bound((xs).begin(), (xs).end(), sum_a[i][j]) -
                            xs.begin()) +
                    psum_a[i][j]);
        for (int j = (0); j < (sz); ++j)
          lct2.update(-psum_b[i][j].second, -psum_b[i][j].first);
      }
    }
    for (int e : cent.comp[root]) dfs(e);
  };
  dfs(cent.root);
  cout << ans << '\n';
  return 0;
}
