#include <bits/stdc++.h>
using namespace std;
int V, E, N, K, dis[610][610];
int in[610];
namespace Dinic {
struct node {
  int f, t, c, nxt;
} e[800010 * 2];
int head[1210], cur[1210], depth[1210], S, T, ei = 1;
long long maxflow = 0;
void add_edge(int f, int t, int c) {
  e[++ei] = {f, t, c, head[f]};
  head[f] = ei;
  e[++ei] = {t, f, 0, head[t]};
  head[t] = ei;
}
struct bfs {
  int num, dep;
};
bool BFS() {
  memset(depth, 0, sizeof(depth));
  memcpy(cur, head, sizeof(cur));
  depth[S] = 1;
  queue<bfs> test;
  test.push({S, 1});
  while (!test.empty()) {
    bfs sub = test.front();
    test.pop();
    for (int i = head[sub.num]; i; i = e[i].nxt) {
      if (e[i].c && (!depth[e[i].t] || depth[e[i].t] > sub.dep + 1)) {
        depth[e[i].t] = sub.dep + 1;
        test.push({e[i].t, sub.dep + 1});
      }
    }
  }
  return depth[T];
}
int DFS(int x, int flw) {
  if (x == T) {
    maxflow += flw;
    return flw;
  }
  for (int i = cur[x]; i; i = e[i].nxt) {
    cur[x] = i;
    if (depth[e[i].t] - depth[x] == 1 && e[i].c) {
      int minflow = DFS(e[i].t, min(flw, e[i].c));
      if (minflow) {
        e[i].c -= minflow;
        e[i ^ 1].c += minflow;
        return minflow;
      }
    }
  }
  return 0;
}
long long work(int s, int t) {
  S = s, T = t;
  maxflow = 0;
  while (BFS())
    while (1)
      if (!DFS(S, 1691691691)) break;
  return maxflow;
}
void init() {
  memset(head, 0, sizeof(head));
  for (int i = 1; i <= ei; i++) e[i].c = e[i].f = e[i].nxt = e[i].t = 0;
  ei = 1;
}
void rebuild(int t) {
  init();
  int ss = V * 2 + 1, tt = V * 2 + 2;
  for (int i = 1; i <= V; i++) {
    add_edge(ss, i, in[i]);
    add_edge(V + i, tt, 1);
  }
  for (int i = 1; i <= V; i++)
    for (int j = 1; j <= V; j++) {
      if (dis[i][j] <= t) add_edge(i, j + V, 1);
    }
}
}  // namespace Dinic
int main() {
  scanf("%d %d %d %d", &V, &E, &N, &K);
  memset(dis, 127, sizeof(dis));
  for (int i = 1; i <= N; i++) {
    int id;
    scanf("%d", &id);
    ++in[id];
  }
  for (int i = 1; i <= V; i++) dis[i][i] = 0;
  for (int i = 1; i <= E; i++) {
    int u, v, val;
    scanf("%d %d %d", &u, &v, &val);
    dis[u][v] = min(dis[u][v], val);
    dis[v][u] = min(dis[v][u], val);
  }
  for (int k = 1; k <= V; k++)
    for (int i = 1; i <= V; i++)
      for (int j = 1; j <= V; j++)
        if (dis[i][k] <= 1691691691 && dis[k][j] <= 1691691691)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  int l = 0, r = 1731312, mid, ans = 1731312;
  while (l <= r) {
    mid = (l + r) >> 1;
    Dinic::rebuild(mid);
    if (Dinic::work(V * 2 + 1, V * 2 + 2) >= K) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (ans > 1731311)
    puts("-1");
  else
    cout << ans << endl;
  return 0;
}
