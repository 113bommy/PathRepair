#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e3 + 4;
const int maxm = 1e3 + 4;
struct Edge {
  int to, cab, rev, cost;
  Edge(int _to, int _cap, int _cost, int _rev)
      : to(_to), cab(_cap), cost(_cost), rev(_rev) {}
};
vector<Edge> G[maxn];
int dist[maxn], H[maxn], preve[maxn], prevv[maxn], V;
inline void add(int u, int v, int cost, int cap) {
  G[u].push_back(Edge(v, cap, cost, G[v].size()));
  G[v].push_back(Edge(u, 0, -cost, G[u].size() - 1));
  return;
}
int min_cost_flow(int s, int t, int f) {
  int res = 0;
  memset(H, 0, sizeof H);
  while (f > 0) {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   greater<pair<int, int> > >
        que;
    que.push(pair<int, int>(0, s));
    while (que.size()) {
      pair<int, int> top = que.top();
      que.pop();
      int u = top.second, dis = top.first;
      if (dist[u] != dis) continue;
      for (int i = 0; i < G[u].size(); ++i) {
        int to = G[u][i].to;
        if (G[u][i].cab > 0 && dist[to] > dis + H[u] - H[to] + G[u][i].cost) {
          dist[to] = dis + H[u] - H[to] + G[u][i].cost;
          prevv[to] = u;
          preve[to] = i;
          que.push(pair<int, int>(dist[to], to));
        }
      }
    }
    if (dist[t] == inf) return -1;
    for (int i = 0; i <= V; ++i) H[i] += dist[i];
    int d = f;
    for (int i = t; i != s; i = prevv[i]) d = min(d, G[prevv[i]][preve[i]].cab);
    for (int i = t; i != s; i = prevv[i]) {
      Edge &e = G[prevv[i]][preve[i]];
      e.cab -= d;
      G[e.to][e.rev].cab += d;
    }
    res += d * H[t];
    f -= d;
  }
  return res;
}
int u, v, cost, n, m, limit, K;
char s[maxn], p[maxn];
void match() {
  int len = strlen(p + 1);
  for (int i = len; i <= n; ++i) {
    int j = 0;
    while (j < len && p[len - j] == s[i - j]) j++;
    if (j == len) add(i - len, i + m, -cost, 1);
  }
  return;
}
int main() {
  int ik = 1, i, j, k, kase;
  scanf("%d%s", &n, s + 1);
  m = n + 1;
  V = m * 2;
  int M;
  scanf("%d", &M);
  for (i = 0; i < M; ++i) {
    scanf("%s%d", p + 1, &cost);
    match();
  }
  scanf("%d", &K);
  for (i = 0; i <= n; ++i) add(i, i + m, 0, K);
  for (i = 0; i < n; ++i) add(i + m, i + 1, 0, inf);
  printf("%d\n", -min_cost_flow(0, V - 1, K));
  return 0;
}
