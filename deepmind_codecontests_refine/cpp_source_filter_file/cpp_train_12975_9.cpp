#include <bits/stdc++.h>
using namespace std;
inline void cmax(int &a, int b) { a = max(a, b); }
inline void cmin(int &a, int b) { a = min(a, b); }
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct edge {
  int to, cap, rev;
  edge(int x, int y, int z) { to = x, cap = y, rev = z; }
};
struct Max_flow {
  int Siz;
  int src, snk;
  vector<vector<edge> > G;
  vector<int> dist, seen;
  Max_flow() {
    Siz = 0;
    src = -1;
    snk = -1;
    G.clear();
    dist.clear();
    seen.clear();
  }
  void Set(int x, int y) { src = x, snk = y; }
  void resize(int s) {
    Siz = s;
    G.resize(s + 1);
    dist.resize(s + 1);
    seen.resize(s + 1);
  }
  void add_edge(int u, int v, int c) {
    edge t1(v, c, G[v].size()), t2(u, 0, G[u].size());
    G[u].push_back(t1);
    G[v].push_back(t2);
  }
  void bfs(int s) {
    for (int i = 0; i < dist.size(); i++) dist[i] = -1;
    queue<int> Q;
    dist[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();
      for (int i = 0; i < G[x].size(); i++) {
        int v = G[x][i].to;
        if (G[x][i].cap && dist[v] == -1) {
          dist[v] = dist[x] + 1;
          Q.push(v);
        }
      }
    }
  }
  int dfs(int x, int dest, int flow) {
    if (x == dest) return flow;
    for (int &i = seen[x]; i < G[x].size(); i++) {
      edge &e = G[x][i];
      if (e.cap && dist[e.to] == dist[x] + 1) {
        int ff = dfs(e.to, dest, min(flow, e.cap));
        if (ff) {
          e.cap -= ff;
          G[e.to][e.rev].cap += ff;
          return ff;
        }
      }
    }
    return 0;
  }
  int dinic(int u, int v) {
    int ans = 0;
    while (1) {
      for (int i = 0; i < seen.size(); i++) seen[i] = 0;
      bfs(u);
      if (dist[v] == -1) break;
      int f;
      while (f = dfs(u, v, 2147483647)) {
        ans += f;
      }
    }
    return ans;
  }
  int Maxflow() { return dinic(src, snk); }
};
const int Maxn = 1005;
int x[Maxn];
double y[Maxn];
int main() {
  int n, r;
  scanf("%d %d", &n, &r);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
    double My = -1.0;
    for (int j = 1; j < i; j++) {
      if (abs(x[j] - x[i]) <= 2 * x[i]) {
        My = max(My, y[j] + (double)sqrt(4.0 * r * r - (double)(x[j] - x[i]) *
                                                           (x[j] - x[i])));
      }
    }
    if (My < r) {
      My = r;
    }
    printf("%.10lf\n", y[i] = My);
  }
  return 0;
}
