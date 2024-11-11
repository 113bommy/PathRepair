#include <bits/stdc++.h>
using namespace std;
const long long MX = (long long)1e18;
struct Node {
  long long val;
  bool big;
  Node(bool pos) : val(1), big(pos) {}
  Node(long long v) : val(v), big(false) {}
  Node(int v) : val(v), big(false) {}
  inline Node operator+(Node o) const {
    if (big || o.big || (MX / val < o.val)) return Node(true);
    return Node(val * o.val);
  }
};
struct SegmentTree {
  int size;
  vector<Node> tree;
  SegmentTree() {}
  SegmentTree(int _) {
    size = 1;
    while (size < _) size *= 2;
    tree = vector<Node>(2 * size, Node(false));
    size = _;
  }
  void update(int p, int id, int v, int lx, int rx) {
    if (lx == rx) {
      tree[p].val = v;
      return;
    }
    int mid = (lx + rx) / 2;
    if (id <= mid)
      update(p << 1, id, v, lx, mid);
    else
      update(p << 1 | 1, id, v, mid + 1, rx);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
  }
  inline void update(int id, long long v) { update(1, id, v, 1, size); }
  Node query(int p, int l, int r, int lx, int rx) {
    if (l <= lx && rx <= r) return tree[p];
    if (rx < l || r < lx) return Node(1);
    int mid = (lx + rx) / 2;
    return query(p << 1, l, r, lx, mid) + query(p << 1 | 1, l, r, mid + 1, rx);
  }
  inline long long query(int l, int r) {
    auto res = query(1, l, r, 1, size);
    return (res.big ? LONG_LONG_MAX : res.val);
  }
};
const int B = 18, N = (int)2e5, M = (int)2e5;
int n, m, cnt, pos[N], par[N], head[N], level[N], sz[N], up[B][N];
vector<pair<int, long long>> adj[N];
SegmentTree seg;
void dfsSize(int x, int pr, int lvl) {
  sz[x] = 1;
  level[x] = lvl;
  up[0][x] = pr;
  par[x] = pr;
  for (int i = 1; i < B; i++)
    up[i][x] = (up[i - 1][x] == -1 ? -1 : up[i - 1][up[i - 1][x]]);
  for (auto e : adj[x]) {
    if (e.first != pr) {
      dfsSize(e.first, x, lvl + 1);
      sz[x] += sz[e.first];
    }
  }
}
void decompose(int x, int pr, bool is_head) {
  pos[x] = cnt++;
  if (is_head)
    head[x] = x;
  else
    head[x] = head[pr];
  int mx = 0, mxi = -1;
  long long w = -1;
  for (auto e : adj[x]) {
    if (e.first != pr && sz[e.first] > mx) {
      mx = sz[e.first];
      mxi = e.first;
      w = e.second;
    }
  }
  if (mxi != -1) {
    seg.update(cnt + 1, w);
    decompose(mxi, x, false);
  }
  for (auto e : adj[x]) {
    if (e.first != pr && e.first != mxi) {
      seg.update(cnt + 1, e.second);
      decompose(e.first, x, true);
    }
  }
}
inline int jmp(int x, int d) {
  for (int i = 0; i < B; i++)
    if ((d >> i) & 1) x = up[i][x];
  return x;
}
inline int LCA(int x, int y) {
  if (level[x] < level[y]) swap(x, y);
  x = jmp(x, level[x] - level[y]);
  if (x == y) return x;
  for (int i = B - 1; i >= 0; i--) {
    if (up[i][x] != up[i][y]) {
      x = up[i][x], y = up[i][y];
    }
  }
  return up[0][x];
}
inline Node query_up(int x, int y) {
  Node res(1);
  while (head[x] != head[y]) {
    res = res + seg.query(pos[head[x]] + 1, pos[x] + 1);
    x = par[head[x]];
  }
  if (x != y) {
    res = res + seg.query(pos[y] + 2, pos[x] + 1);
  }
  return res;
}
inline long long query(int x, int y) {
  int lca = LCA(x, y);
  Node res = query_up(x, lca) + query_up(y, lca);
  return (res.big ? LONG_LONG_MAX : res.val);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  vector<pair<int, int>> edges;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    long long v;
    cin >> x >> y >> v;
    x--, y--;
    adj[x].emplace_back(y, v);
    adj[y].emplace_back(x, v);
    edges.emplace_back(x, y);
  }
  seg = SegmentTree(n);
  dfsSize(0, -1, 0);
  decompose(0, -1, true);
  for (auto& e : edges)
    if (level[e.second] > level[e.first]) swap(e.first, e.second);
  for (int rep = 0; rep < m; rep++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      long long v;
      cin >> x >> y >> v;
      x--, y--;
      cout << v / query(x, y) << '\n';
    } else {
      int p;
      long long c;
      cin >> p >> c;
      p--;
      seg.update(pos[edges[p].first] + 1, c);
    }
  }
  return 0;
}
