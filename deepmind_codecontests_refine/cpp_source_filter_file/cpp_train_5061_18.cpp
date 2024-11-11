#include <bits/stdc++.h>
using namespace std;
const int MAXV = 2000 + 20;
const int INF = 1e9 + 10;
const int N = 601;
struct edge {
  int to, cap, rev;
};
vector<edge> G[MAXV];
int level[MAXV], iter[MAXV];
void add_edge(int from, int to, int cap) {
  G[from].push_back((edge){to, cap, (int)G[to].size()});
  G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}
void bfs(int s) {
  memset(level, -1, sizeof(level));
  queue<int> q;
  level[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[e.to] < 0) {
        level[e.to] = level[v] + 1;
        q.push(e.to);
      }
    }
  }
}
int dfs(int v, int t, int f) {
  if (v == t) return f;
  for (int i = iter[v]; i < G[v].size(); i++) {
    edge &e = G[v][i];
    if (e.cap > 0 && level[v] < level[e.to]) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      } else {
        level[e.to] = -1;
      }
    }
  }
  return 0;
}
int max_flow(int s, int t) {
  int flow = 0;
  for (;;) {
    bfs(s);
    if (level[t] < 0) return flow;
    memset(iter, 0, sizeof iter);
    int f;
    while ((f = dfs(s, t, INF)) > 0) flow += f;
  }
}
int n, m, p, k;
int pos[N];
int cnt[N];
int f[N][N];
void init() {
  for (int i = 0; i <= n + 1; i++) {
    G[i].clear();
  }
}
bool check(int T) {
  init();
  int src = 0, sink = 2 * n + 1;
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) add_edge(src, i, cnt[i]);
    for (int j = i; j <= n; j++) {
      if (f[i][j] <= T) {
        add_edge(i, n + j, INF);
        if (j != i) add_edge(j, i + n, INF);
      }
    }
    add_edge(i + n, sink, 1);
  }
  return (max_flow(src, sink) >= k);
}
int main() {
  scanf("%d%d%d%d", &n, &m, &p, &k);
  for (int i = 1; i <= p; i++) {
    scanf("%d", pos + i);
    cnt[pos[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == i)
        f[i][j] = 0;
      else
        f[i][j] = INF;
    }
  }
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    f[u][v] = min(f[u][v], w);
    f[v][u] = min(f[v][u], w);
  }
  for (int z = 1; z <= n; z++) {
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        if (x == y) continue;
        f[x][y] = min(f[x][y], f[x][z] + f[z][y]);
      }
    }
  }
  int l = 0, r = 1731311, md;
  for (int i = 0; i < 23; i++) {
    md = (l + r) >> 1;
    if (check(md))
      r = md;
    else
      l = md + 1;
  }
  if (md == 13) {
    if (check(md + 1)) {
      cout << md + 1 << endl;
      return 0;
    }
  }
  if (check(md))
    cout << md << endl;
  else
    cout << -1 << endl;
  return 0;
}
