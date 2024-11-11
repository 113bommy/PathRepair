#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
const int maxm = 3000;
char maze[maxn][maxn];
int g[maxn * maxn][maxn * maxn];
int n, m, N, M;
int src, sink;
long long ans;
struct Node {
  int r, c, t;
  Node() {}
  Node(int r, int c, int t) : r(r), c(c), t(t) {}
};
vector<Node> males, fmales;
struct Edge {
  int u, v, c;
  Edge() {}
  Edge(int u, int v, int c) : u(u), v(v), c(c) {}
};
struct MaxFlow {
  int n, m;
  int Now[maxm], Dfn[maxm];
  vector<Edge> edges;
  vector<int> G[maxm];
  void init(int n) {
    this->n = n;
    for (auto &x : G) x.clear();
    edges.clear();
  }
  void add(int u, int v, int c) {
    edges.push_back(Edge(u, v, c));
    edges.push_back(Edge(v, u, 0));
    m = ((int)((edges).size()));
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
  }
  int ISAP(int s, int flow) {
    if (s == sink) return flow;
    int v, tab = n, now = 0, vary;
    for (int i = 0; i < ((int)((G[s]).size())); i++) {
      Edge &e = edges[G[s][i]];
      if (e.c > 0) {
        if (Dfn[s] == Dfn[v = e.v] + 1)
          vary = ISAP(v, min(flow - now, e.c)), now += vary, e.c -= vary,
          edges[G[s][i] ^ 1].c += vary;
        if (Dfn[src] == n) return now;
        if (e.c > 0) tab = min(tab, Dfn[v]);
        if (now == flow) break;
      }
    }
    if (now == 0) {
      if (--Now[Dfn[s]] == 0) Dfn[src] = n;
      ++Now[Dfn[s] = tab + 1];
    }
    return now;
  }
  int getAns() {
    int flow = 0;
    memset(Dfn, 0, sizeof Dfn);
    memset(Now, 0, sizeof Now);
    Now[0] = n;
    while (Dfn[src] < n) flow += ISAP(src, 0x0f0f0f0f);
    return flow;
  }
} solver;
int idx(char x, int y) { return x * m + y; }
bool cango(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
void calDist() {
  memset(g, 0x0f, sizeof g);
  for (int i = 0; i < n * m; i++) g[i][i] = 0;
  for (int x = 0; x < n; x++)
    for (int y = 0; y < m; y++) {
      if (maze[x][y] != '.') continue;
      int u = idx(x, y);
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (!cango(nx, ny) || maze[nx][ny] == '#') continue;
        int v = idx(nx, ny);
        g[u][v] = 1;
      }
    }
  for (int k = 0; k < n * m; k++)
    for (int i = 0; i < n * m; i++)
      for (int j = 0; j < n * m; j++) {
        if (g[i][k] == 0x0f0f0f0f || g[k][j] == 0x0f0f0f0f) continue;
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
}
bool check(long long mid) {
  src = 2 * N + 2 * n * m;
  sink = src + 1;
  solver.init(sink + 1);
  for (int j = 0; j < n; j++)
    for (int k = 0; k < m; k++) {
      if (maze[j][k] == '#') continue;
      int v = idx(j, k);
      int id1 = 2 * N + v * 2;
      int id2 = id1 + 1;
      solver.add(id1, id2, 1);
    }
  for (int i = 0; i < N; i++) {
    int x = males[i].r, y = males[i].c, t = males[i].t;
    int u = idx(x, y);
    solver.add(src, i, 1);
    for (int j = 0; j < n; j++)
      for (int k = 0; k < m; k++) {
        if (maze[j][k] == '#') continue;
        int v = idx(j, k);
        int id1 = 2 * N + v * 2;
        int id2 = id1 + 1;
        if (g[u][v] != 0x0f0f0f0f && 1.0 * g[u][v] * t <= mid)
          solver.add(i, id1, 1);
      }
    x = fmales[i].r, y = fmales[i].c, t = fmales[i].t;
    u = idx(x, y);
    solver.add(i + N, sink, 1);
    for (int j = 0; j < n; j++)
      for (int k = 0; k < m; k++) {
        if (maze[j][k] == '#') continue;
        int v = idx(j, k);
        int id1 = 2 * N + v * 2;
        int id2 = id1 + 1;
        if (g[u][v] != 0x0f0f0f0f && 1.0 * g[u][v] * t <= mid)
          solver.add(id2, i + N, 1);
      }
  }
  return solver.getAns() == N;
}
int main() {
  cin >> n >> m >> N >> M;
  for (int i = 0; i < n; i++) scanf("%s", maze[i]);
  int ok = 1;
  int r, c, t;
  scanf("%d%d%d", &r, &c, &t);
  r--, c--;
  if (N - M == 1) {
    fmales.push_back(Node(r, c, t));
  } else if (M - N == 1) {
    males.push_back(Node(r, c, t));
  } else {
    ok = 0;
  }
  for (int i = 0; i < N; i++) {
    scanf("%d%d%d", &r, &c, &t);
    r--, c--;
    males.push_back(Node(r, c, t));
  }
  for (int i = 0; i < M; i++) {
    int r, c, t;
    scanf("%d%d%d", &r, &c, &t);
    r--, c--;
    fmales.push_back(Node(r, c, t));
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  N = max(N, M);
  calDist();
  long long L = 0, R = (long long)1e15;
  while (R - L > 0) {
    long long mid = (L + R) >> 1;
    if (check(mid))
      R = mid;
    else
      L = mid + 1;
  }
  if (R != (long long)1e15) {
    printf("%lld\n", R);
  } else
    puts("-1");
  return 0;
}
