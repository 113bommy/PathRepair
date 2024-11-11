#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int INF = INT32_MAX;
constexpr int MAXN = 2e6 + 10;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using Vec = vector<int>;
template <class T>
void Min(T &a, T &b) {
  if (b < a) a = b;
}
template <class T>
void Max(T &a, T &b) {
  if (b > a) a = b;
}
ll N, M, K, T;
Vec A;
namespace DinicAlgo {
const int N = 1e4 + 10, M = 1e5 + 10;
int s, t, edge_cnt;
struct Edge {
  int to, nxt;
  ll w;
} edges[M << 1];
int head[N], lvl[N], cur[N];
void AddEdge(int u, int v, ll w) {
  edges[++edge_cnt] = Edge{v, head[u], w};
  head[u] = edge_cnt;
}
void Link(int u, int v, ll w) {
  AddEdge(u, v, w);
  AddEdge(v, u, 0);
}
void SetST(int _s, int _t) { s = _s, t = _t; }
void Init() {
  memset(head, 0, sizeof(head));
  edge_cnt = 0;
}
bool bfs() {
  memset(lvl, -1, sizeof(lvl));
  lvl[s] = 0;
  queue<int> q;
  q.emplace(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int e = head[u]; e; e = edges[e].nxt) {
      int v = edges[e].to;
      if (lvl[v] == -1 && edges[e].w) {
        lvl[v] = lvl[u] + 1;
        q.emplace(v);
      }
    }
  }
  return lvl[t] != -1;
}
ll dfs(int u, ll flow) {
  if (u == t) return flow;
  ll su = 0, f = 0;
  for (int &e = cur[u]; e; e = edges[e].nxt) {
    int v = edges[e].to;
    if (edges[e].w && lvl[v] == lvl[u] + 1) {
      f = dfs(v, min(flow, edges[e].w));
      su += f;
      flow -= f;
      edges[e].w -= f;
      edges[e ^ 1].w += f;
      if (!flow) break;
    }
  }
  return su;
}
ll MaxFlow() {
  ll max_flow = 0;
  while (bfs()) {
    memcpy(cur, head, sizeof(cur));
    max_flow += dfs(s, INF);
  }
  return max_flow;
}
}  // namespace DinicAlgo
int cnt_x, cnt_y;
int dx[MAXN], dy[MAXN], sx[MAXN], sy[MAXN], tx[MAXN], ty[MAXN];
bool vis[105][105];
ll Solution() {
  for (int i = (int)(1); i < (int)(M + 1); ++i) {
    dx[++cnt_x] = sx[i];
    dx[++cnt_x] = tx[i] + 1;
    dy[++cnt_y] = sy[i];
    dy[++cnt_y] = ty[i] + 1;
  }
  sort(dx + 1, dx + 1 + cnt_x);
  sort(dy + 1, dy + 1 + cnt_y);
  cnt_x = unique(dx + 1, dx + 1 + cnt_x) - dx - 1;
  cnt_y = unique(dy + 1, dy + 1 + cnt_y) - dy - 1;
  DinicAlgo::Init();
  DinicAlgo::SetST(cnt_x + cnt_y - 1, cnt_x + cnt_y);
  for (int i = (int)(1); i < (int)(M + 1); ++i) {
    int lx, ly, rx, ry;
    lx = lower_bound(dx + 1, dx + 1 + cnt_x, sx[i]) - dx;
    rx = upper_bound(dx + 1, dx + 1 + cnt_x, tx[i]) - 1 - dx;
    ly = lower_bound(dy + 1, dy + 1 + cnt_y, sy[i]) - dy;
    ry = upper_bound(dy + 1, dy + 1 + cnt_y, ty[i]) - 1 - dy;
    for (int x = (int)(lx); x < (int)(rx + 1); ++x)
      for (int y = (int)(ly); y < (int)(ry + 1); ++y) vis[x][y] = 1;
  }
  for (int i = (int)(1); i < (int)(cnt_x); ++i)
    for (int j = (int)(1); j < (int)(cnt_y); ++j)
      if (vis[i][j]) DinicAlgo::Link(i, cnt_x + j - 1, INF);
  for (int i = (int)(1); i < (int)(cnt_x); ++i)
    DinicAlgo::Link(cnt_x + cnt_y - 1, i, dx[i + 1] - dx[i]);
  for (int i = (int)(1); i < (int)(cnt_y); ++i)
    DinicAlgo::Link(cnt_x + i - 1, cnt_x + cnt_y, dy[i + 1] - dy[i]);
  return DinicAlgo::MaxFlow();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> N >> M) {
    for (int i = (int)(1); i < (int)(M + 1); ++i) {
      cin >> sx[i] >> sy[i] >> tx[i] >> ty[i];
    }
    cout << Solution() << '\n';
  }
  return 0;
}
