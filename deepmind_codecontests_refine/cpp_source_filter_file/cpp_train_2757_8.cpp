#include <bits/stdc++.h>
using namespace std;
void task();
int main() {
  task();
  return 0;
}
const int INF = 0x3f3f3f3f;
const int N = 203;
struct Rib {
  int to;
  int cap;
  int flow;
  int back;
};
int n, m;
int a[101];
int b[101];
vector<Rib> g[N];
int S = 201, T = 202;
int ans[101][101];
int dist[N];
int pt[N];
void add_rib(int a, int b, int cap) {
  g[a].push_back(Rib{b, cap, 0, ((int)((g[b]).size()))});
  g[b].push_back(Rib{a, 0, 0, ((int)((g[a]).size())) - 1});
}
int bfs() {
  memset(dist, 0x3f, sizeof(dist));
  dist[S] = 0;
  queue<int> q;
  q.push(S);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (Rib& r : g[v])
      if (r.cap - r.flow && dist[r.to] == INF) {
        dist[r.to] = dist[v] + 1;
        q.push(r.to);
      }
  }
  return dist[T] != INF;
}
int dfs(int v, int flow) {
  if (v == T) return flow;
  for (; pt[v] < ((int)((g[v]).size())); ++pt[v]) {
    Rib& r = g[v][pt[v]];
    if (dist[r.to] != dist[v] + 1 || r.cap - r.flow == 0) continue;
    if (int f = dfs(r.to, min(flow, r.cap - r.flow))) {
      r.flow += f;
      g[r.to][r.back].flow -= f;
      return f;
    }
  }
  return 0;
}
int dinic() {
  int res = 0;
  while (bfs()) {
    memset(pt, 0, sizeof(pt));
    while (int f = dfs(S, INF)) res += f;
  }
  return res;
}
void task() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < n; ++i) sum1 += a[i], sum2 += b[i];
  if (sum1 != sum2) {
    printf("NO");
    return;
  }
  for (int i = 0; i < n; ++i) {
    add_rib(S, i, a[i]);
    add_rib(n + i, T, b[i]);
  }
  for (int i = 0; i < n; ++i) add_rib(i, n + i, INF);
  for (int i = 0; i < m; ++i) {
    int f, t;
    scanf("%d %d", &f, &t);
    --f, --t;
    add_rib(f, n + t, INF);
    add_rib(t, n + f, INF);
  }
  int max_flow = dinic();
  if (max_flow != sum2) {
    printf("NO");
    return;
  }
  printf("YES\n");
  for (int i = 0; i < n; ++i)
    for (Rib& r : g[i]) ans[i][r.to - n] += abs(r.flow);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) printf("%d ", ans[i][j]);
    printf("\n");
  }
}
