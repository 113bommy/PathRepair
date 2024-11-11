#include <bits/stdc++.h>
using namespace std;
const long long INF = 20000000000000ll;
struct dat {
  int to, id;
  long long w;
  dat(int _t = 0, long long _w = 0, int _i = 0) : to(_t), w(_w), id(_i) {}
  bool operator<(const dat &p) const { return w > p.w; }
};
const int N = 200000 + 7;
vector<dat> g[N];
long long dis[N][2];
int parn[N][2], pare[N][2];
int eno[N];
bool main_path[N];
bool in_node[N];
int range[N][2];
bool vis[N][2];
int edg[N][3];
int n, m, q;
void dijkstra(int src = 1, int f = 0) {
  for (int i = 0; i < N; ++i) {
    dis[i][f] = INF;
    parn[i][f] = 0;
    pare[i][f] = 0;
  }
  dis[src][f] = 0;
  priority_queue<dat> pq;
  pq.push(dat(src, dis[src][f]));
  while (!pq.empty()) {
    dat top = pq.top();
    pq.pop();
    int u = top.to;
    long long w = top.w;
    if (dis[u][f] < w) continue;
    for (auto &qq : g[u]) {
      int v = qq.to;
      if (dis[v][f] > w + qq.w) {
        dis[v][f] = w + qq.w;
        parn[v][f] = u;
        pare[v][f] = qq.id;
        pq.push(dat(v, dis[v][f]));
      }
    }
  }
}
void dfs(int u, int f) {
  vis[u][f] = true;
  for (auto &qq : g[u]) {
    int v = qq.to;
    if (!vis[v][f] and dis[v][f] == qq.w + dis[u][f]) {
      if (!in_node[v]) range[v][f] = range[u][f];
      dfs(v, f);
    }
  }
}
struct SegmentTree {
  long long Tree[4 * 200007], Lazy[4 * 200007];
  SegmentTree() {}
  void pushdown(int at) {
    Lazy[(at << 1)] = min(Lazy[(at << 1)], Lazy[at]);
    Lazy[((at << 1) | 1)] = min(Lazy[((at << 1) | 1)], Lazy[at]);
    Tree[(at << 1)] = min(Tree[(at << 1)], Lazy[at]);
    Tree[((at << 1) | 1)] = min(Tree[((at << 1) | 1)], Lazy[at]);
  }
  void build(int at, int l, int r) {
    Lazy[at] = INF;
    if (l == r) {
      Tree[at] = INF;
      return;
    }
    int mid = (l + r) / 2;
    build((at << 1), l, mid);
    build(((at << 1) | 1), mid + 1, r);
    Tree[at] = min(Tree[(at << 1)], Tree[((at << 1) | 1)]);
  }
  void update(int at, int l, int r, int x, int y, long long val) {
    if (x > r || y < l) return;
    if (x <= l && r <= y) {
      Tree[at] = min(Tree[at], val);
      Lazy[at] = min(Lazy[at], val);
      return;
    }
    if (l != r) pushdown(at);
    int mid = (l + r) / 2;
    update((at << 1), l, mid, x, y, val);
    update(((at << 1) | 1), mid + 1, r, x, y, val);
    Tree[at] = min(Tree[(at << 1)], Tree[((at << 1) | 1)]);
  }
  long long query(int at, int l, int r, int x, int y) {
    if (x > r || y < l) return INF;
    if (x <= l && r <= y) return Tree[at];
    if (l != r) pushdown(at);
    int mid = (l + r) / 2;
    return min(query((at << 1), l, mid, x, y),
               query(((at << 1) | 1), mid + 1, r, x, y));
  }
} seg;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(dat(v, w, i));
    g[v].push_back(dat(u, w, i));
    edg[i][0] = u;
    edg[i][1] = v;
    edg[i][2] = w;
  }
  dijkstra(1, 0);
  dijkstra(n, 1);
  long long shortest = dis[n][0];
  memset(range, -1, sizeof range);
  int cur = 1, cnt = 0;
  while (cur) {
    int e = pare[cur][1];
    eno[e] = ++cnt;
    main_path[e] = true;
    in_node[cur] = true;
    range[cur][0] = cnt;
    range[cur][1] = cnt - 1;
    cur = parn[cur][1];
  }
  dfs(1, 0);
  dfs(n, 1);
  seg.build(1, 1, m);
  for (int u = 1; u <= n; ++u) {
    for (auto &qq : g[u]) {
      int idx = qq.id;
      if (main_path[idx]) continue;
      int v = qq.to;
      long long cost = dis[u][0] + qq.w + dis[v][1];
      seg.update(1, 1, m, range[u][0], range[v][1], cost);
    }
  }
  while (q--) {
    int idx;
    long long val;
    cin >> idx >> val;
    int u = edg[idx][0], v = edg[idx][1];
    long long w = edg[idx][2];
    if (!main_path[idx]) {
      long long cost = min(dis[u][0] + dis[v][1], dis[v][0] + dis[u][1]) + val;
      cout << min(cost, shortest) << "\n";
    } else {
      if (val <= w) {
        cout << (shortest - w + val) << "\n";
      } else {
        long long op1 = shortest - w + val;
        int e = eno[idx];
        long long op2 = seg.query(1, 1, m, e, e);
        cout << min(op1, op2) << "\n";
      }
    }
  }
  return 0;
}
