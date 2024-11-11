#include <bits/stdc++.h>
using namespace std;
namespace mcmf {
const int MAX = 1000010;
const int INF = 1 << 25;
int cap[MAX], flow[MAX], cost[MAX], dis[MAX];
int n, m, s, t, Q[10000010], adj[MAX], link[MAX], last[MAX], from[MAX],
    visited[MAX];
void init(int nodes, int source, int sink) {
  m = 0, n = nodes, s = source, t = sink;
  for (int i = 0; i <= n; i++) last[i] = -1;
}
void addEdge(int u, int v, int c, int w) {
  adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u],
  last[u] = m++;
  adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v],
  last[v] = m++;
}
bool spfa() {
  int i, j, x, f = 0, l = 0;
  for (i = 0; i <= n; i++) visited[i] = 0, dis[i] = INF;
  dis[s] = 0, Q[l++] = s;
  while (f < l) {
    i = Q[f++];
    for (j = last[i]; j != -1; j = link[j]) {
      if (flow[j] < cap[j]) {
        x = adj[j];
        if (dis[x] > dis[i] + cost[j]) {
          dis[x] = dis[i] + cost[j], from[x] = j;
          if (!visited[x]) {
            visited[x] = 1;
            if (f && rand() & 7)
              Q[--f] = x;
            else
              Q[l++] = x;
          }
        }
      }
    }
    visited[i] = 0;
  }
  return (dis[t] != INF);
}
pair<int, int> solve() {
  int i, j;
  int mincost = 0, maxflow = 0;
  while (spfa()) {
    int aug = INF;
    for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]) {
      aug = min(aug, cap[j] - flow[j]);
    }
    for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i]) {
      flow[j] += aug, flow[j ^ 1] -= aug;
    }
    maxflow += aug, mincost += aug * dis[t];
  }
  return make_pair(mincost, maxflow);
}
}  // namespace mcmf
int n, ar[5010];
char counter[100010];
inline int get_in(int x) { return 2 * x; }
inline int get_out(int x) { return 2 * x + 1; }
int main() {
  int i, j, w, s, t;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i < n; i++) scanf("%d", &ar[i]);
    s = n * 2, t = s + 1, w = t + 1;
    mcmf::init(n * 2 + 3, s, t);
    mcmf::addEdge(s, w, 2, 0);
    for (i = 0; i < n; i++) mcmf::addEdge(get_in(i), get_out(i), 1, -1);
    for (i = 0; i < n; i++) mcmf::addEdge(w, get_in(i), 1, 0);
    for (i = 0; i < n; i++) mcmf::addEdge(get_out(i), t, 1, 0);
    for (i = 0; i < n; i++) {
      memset(counter, 0, sizeof(counter));
      for (j = i + 1; j < n; j++) {
        if (abs(ar[j] - ar[i]) == 1) {
          if (counter[ar[j]] < 2) {
            counter[ar[j]]++;
            mcmf::addEdge(get_out(i), get_in(j), 1, 0);
          }
        }
      }
    }
    for (i = 0; i < n; i++) ar[i] %= 7;
    for (i = 0; i < n; i++) {
      memset(counter, 0, sizeof(counter));
      for (j = i + 1; j < n; j++) {
        if (ar[i] == ar[j]) {
          if (counter[ar[j]] < 2) {
            counter[ar[j]]++;
            mcmf::addEdge(get_out(i), get_in(j), 1, 0);
          }
        }
      }
    }
    pair<int, int> res = mcmf::solve();
    printf("%d\n", -res.first);
  }
  return 0;
}
