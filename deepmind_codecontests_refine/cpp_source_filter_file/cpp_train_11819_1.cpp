#include <bits/stdc++.h>
using namespace std;
int n, b, q;
int sum[700005];
int nd = 7, src = 6, dest = 5, nedge = 0;
int head[700005], point[700005], nt[700005], flow[700005], capa[700005];
int dist[700005], Q[700005], work[700005];
vector<int> check;
void fin(bool state) {
  cout << (state ? "fair" : "unfair");
  exit(0);
}
void add(int u, int v, int c) {
  point[nedge] = v, capa[nedge] = c, flow[nedge] = 0, nt[nedge] = head[u],
  head[u] = (nedge++);
  point[nedge] = u, capa[nedge] = 0, flow[nedge] = 0, nt[nedge] = head[v],
  head[v] = (nedge++);
}
void build_graph() {
  int cnt[5];
  memset((cnt), 0, sizeof((cnt)));
  int ls = 0;
  for (int i = 1; i <= b; ++i) {
    ++cnt[i % 5];
    if (sum[i] != -1 && i > 1) {
      if (sum[i] < sum[ls]) fin(false);
      check.push_back(nedge);
      add(src, nd, sum[i] - sum[ls]);
      for (int rm = 0; rm < 5; ++rm) {
        add(nd, rm, cnt[rm]);
      }
      memset((cnt), 0, sizeof((cnt)));
      ls = i;
      ++nd;
    }
  }
  for (int rm = 0; rm < 5; ++rm) {
    check.push_back(nedge);
    add(rm, dest, n / 5);
  }
}
bool dinic_bfs() {
  memset(dist, 255, sizeof(dist));
  dist[src] = 0;
  int sizeQ = 0;
  Q[sizeQ++] = src;
  for (int cl = 0; cl < sizeQ; cl++)
    for (int k = Q[cl], i = head[k]; i >= 0; i = nt[i])
      if (flow[i] < capa[i] && dist[point[i]] < 0) {
        dist[point[i]] = dist[k] + 1;
        Q[sizeQ++] = point[i];
      }
  return dist[dest] >= 0;
}
int dinic_dfs(int x, int exp) {
  if (x == dest) return exp;
  for (int &i = work[x]; i >= 0; i = nt[i]) {
    int v = point[i], tmp;
    if (flow[i] < capa[i] && dist[v] == dist[x] + 1 &&
        (tmp = dinic_dfs(v, min(exp, capa[i] - flow[i]))) > 0) {
      flow[i] += tmp;
      flow[i ^ 1] -= tmp;
      return tmp;
    }
  }
  return 0;
}
int max_flow() {
  int result = 0;
  while (dinic_bfs()) {
    for (int i = 0; i < nd; i++) work[i] = head[i];
    while (1) {
      int delta = dinic_dfs(src, INT_MAX);
      if (delta == 0) break;
      result += delta;
    }
  }
  return result;
}
int main() {
  ios::sync_with_stdio(false);
  scanf("%d%d%d", &n, &b, &q);
  memset((sum), -1, sizeof((sum)));
  for (int i = 0; i < q; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    sum[x] = y;
  }
  sum[b] = n;
  sum[0] = 0;
  memset((head), -1, sizeof((head)));
  build_graph();
  max_flow();
  for (int edg : check) {
    if (flow[edg] != capa[edg]) fin(false);
  }
  fin(true);
}
