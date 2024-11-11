#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 2010;
const int INF = 1000000000;
struct Edge {
  int from, to, cap, flow;
};
bool operator<(const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}
struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool vis[maxn];
  int d[maxn];
  int cur[maxn];
  void init(int n) {
    for (int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }
  void ClearFlow() {
    for (int i = 0; i < edges.size(); i++) edges[i].flow = 0;
  }
  void AddEdge(int from, int to, int cap) {
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }
  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }
  int DFS(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }
  int Maxflow(int s, int t) {
    this->s = s;
    this->t = t;
    int flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
  vector<int> Mincut() {
    vector<int> ans;
    for (int i = 0; i < edges.size(); i++) {
      Edge& e = edges[i];
      if (vis[e.from] && !vis[e.to] && e.cap > 0) ans.push_back(i);
    }
    return ans;
  }
  void Reduce() {
    for (int i = 0; i < edges.size(); i++) edges[i].cap -= edges[i].flow;
  }
};
int n, m, x;
double ans;
int a, b, c;
struct e {
  int f, t, w;
} ee[550];
Dinic so;
bool check(double c) {
  so.init(n + 1);
  for (int t = (0); t < (m); ++t) {
    so.AddEdge(ee[t].f, ee[t].t, ee[t].w / c);
  }
  return so.Maxflow(1, n) == x;
}
int main() {
  cin >> n >> m >> x;
  double mw = INF;
  for (int t = (0); t < (m); ++t) {
    scanf("%d%d%d", &ee[t].f, &ee[t].t, &ee[t].w);
    mw = min(mw, (double)ee[t].w);
  }
  double l = mw / x, r = INF;
  while (r - l > eps) {
    double mid = (r + l) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.9lf\n", l * x);
}
