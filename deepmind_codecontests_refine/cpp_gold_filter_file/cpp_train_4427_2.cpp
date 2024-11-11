#include <bits/stdc++.h>
using namespace std;
struct edge {
  int from, to, c, i;
};
const int N = 2e5;
int n;
vector<vector<edge> > g;
vector<edge> edges;
class DSU {
 public:
  int *p, n, numSets;
  DSU(const int N) {
    p = new int[N];
    srand(time(0));
  }
  ~DSU() { delete[] p; }
  void init(const int _n);
  int findSet(const int v);
  bool unite(int a, int b);
  void finalize();
  int getNumSets() const { return numSets; }

 private:
  DSU();
};
void DSU::init(const int _n) {
  n = _n;
  for (int i = 0; i < n; ++i) p[i] = i;
  numSets = n;
}
int DSU::findSet(const int v) {
  if (v == p[v]) return v;
  return p[v] = findSet(p[v]);
}
bool DSU::unite(int a, int b) {
  a = findSet(a), b = findSet(b);
  if (a == b) return false;
  if (rand() & 1) swap(a, b);
  p[a] = b;
  --numSets;
  return true;
}
void DSU::finalize() {
  for (int i = 0; i < n; ++i) p[i] = findSet(p[i]);
}
struct SegmentTree {
  int* t;
  int n;
  void init(int sz) {
    t = new int[2 * N];
    memset(t, -2e9, 2 * sz * sizeof(int));
    n = sz;
  }
  void build() {
    for (int i = n - 1; i > 0; --i) t[i] = max(t[i << 1], t[i << 1 | 1]);
  }
  void set(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = max(t[p], t[p ^ 1]);
  }
  int query(int l, int r) {
    int res = -2e9;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = max(res, t[l++]);
      if (r & 1) res = max(res, t[--r]);
    }
    return res;
  }
};
template <class T, int V>
class HeavyLight {
  int parent[V], heavy[V], depth[V];
  int root[V], treePos[V];
  SegmentTree tree;
  int dfs(vector<vector<edge> >& graph, int v) {
    int size = 1, maxSubtree = 0;
    for (auto e : graph[v]) {
      int u = e.to;
      if (u != parent[v]) {
        cost[u] = e.c;
        parent[u] = v;
        depth[u] = depth[v] + 1;
        int subtree = dfs(graph, u);
        if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
        size += subtree;
      }
    }
    return size;
  }
  template <class BinaryOperation>
  void processPath(int u, int v, BinaryOperation op) {
    for (; root[u] != root[v]; v = parent[root[v]]) {
      if (depth[root[u]] > depth[root[v]]) swap(u, v);
      op(treePos[root[v]], treePos[v] + 1);
    }
    if (depth[u] > depth[v]) swap(u, v);
    op(treePos[u] + 1, treePos[v] + 1);
  }

 public:
  int cost[V];
  void init(vector<vector<edge> >& graph) {
    int n = graph.size();
    fill_n(heavy, n, -1);
    fill_n(cost, n, 0);
    parent[0] = -1;
    depth[0] = 0;
    dfs(graph, 0);
    for (int i = 0, currentPos = 0; i < n; ++i)
      if (parent[i] == -1 || heavy[parent[i]] != i)
        for (int j = i; j != -1; j = heavy[j]) {
          root[j] = i;
          treePos[j] = currentPos++;
        }
    tree.init(n);
  }
  void set(int v, const T& value) { tree.set(treePos[v], value); }
  void build() { tree.build(); }
  T queryPath(int u, int v) {
    T res = T();
    processPath(
        u, v, [this, &res](int l, int r) { res = max(res, tree.query(l, r)); });
    return res;
  }
};
bool cmp(edge a, edge b) { return (a.c < b.c); }
int main() {
  int m;
  cin >> n >> m;
  vector<edge> ttmp;
  g.assign(n, ttmp);
  for (int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    edge tmp;
    tmp.from = x;
    tmp.to = y;
    tmp.c = c;
    tmp.i = i;
    edges.emplace_back(tmp);
  }
  sort(edges.begin(), edges.end(), &cmp);
  DSU dsu(n);
  dsu.init(n);
  vector<long long> ans(m, -1);
  vector<int> ind(m, -1);
  vector<bool> mst(m, false);
  long long mstcost = 0;
  for (int i = 0; i < edges.size(); i++) {
    if (dsu.findSet(edges[i].from) != dsu.findSet(edges[i].to)) {
      dsu.unite(edges[i].from, edges[i].to);
      edge tmp = edges[i];
      g[edges[i].from].emplace_back(tmp);
      tmp.from = edges[i].to;
      tmp.to = edges[i].from;
      g[edges[i].to].emplace_back(tmp);
      mstcost += edges[i].c;
      mst[edges[i].i] = true;
    }
    ind[edges[i].i] = i;
  }
  HeavyLight<int, N> hld;
  hld.init(g);
  for (int i = 0; i < n; i++) hld.set(i, hld.cost[i]);
  hld.build();
  for (int i = 0; i < m; i++) {
    if (mst[i])
      ans[i] = mstcost;
    else {
      edge q = edges[ind[i]];
      int maxedge = hld.queryPath(q.from, q.to);
      ans[i] = mstcost + q.c - maxedge;
    }
    cout << ans[i] << endl;
  }
  return 0;
}
