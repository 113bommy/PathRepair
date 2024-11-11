#include <bits/stdc++.h>
using namespace std;
const int max_n = 200;
const int max_m = 1000;
const int inf = 0x3f3f3f3f;
struct edge {
  int u, v, cap, cost, next;
} G[max_m * 2];
int head[max_n], tot;
int dis[max_n];
int pv[max_n], pe[max_n];
void init(int n) {
  tot = 0;
  for (int i = 0; i <= n; i++) head[i] = -1;
}
void add_edge(int u, int v, int cap, int cost) {
  G[tot] = {u, v, cap, cost, head[u]};
  head[u] = tot++;
}
int min_cost_flow(int s, int t, int n, int f, int &flow) {
  int res = 0;
  while (f) {
    for (int i = 0; i <= n; i++) dis[i] = inf;
    dis[s] = 0;
    static bool inq[max_n];
    for (int i = 0; i <= n; i++) inq[i] = false;
    queue<int> que;
    que.push(s);
    inq[s] = true;
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      inq[u] = false;
      for (int i = head[u]; ~i; i = G[i].next) {
        int v = G[i].v, cap = G[i].cap, cost = G[i].cost;
        if (cap > 0 && dis[v] > dis[u] + cost) {
          dis[v] = dis[u] + cost;
          pv[v] = u, pe[v] = i;
          if (!inq[v]) {
            inq[v] = true;
            que.push(v);
          }
        }
      }
    }
    if (dis[t] == inf) break;
    int d = f;
    for (int u = t; u != s; u = pv[u]) d = min(d, G[pe[u]].cap);
    f -= d, flow += d;
    res += d * dis[t];
    for (int u = t; u != s; u = pv[u]) {
      G[pe[u]].cap -= d;
      G[pe[u] ^ 1].cap += d;
    }
  }
  return res;
}
int n, m;
int d[max_n];
bool vis[max_n][max_n];
int ans[max_n][max_n];
vector<pair<int, int> > E;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    ans[u][v] = 1;
    d[u]++;
    if (u < v) swap(u, v);
    vis[u][v] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (!vis[i][j]) E.push_back(pair<int, int>(i, j));
    }
  }
  m = n * (n - 1) / 2 - m;
  int N = n + m + 2;
  int src = 0, trg = N - 1;
  init(N);
  for (int i = 1; i <= m; i++) add_edge(src, i, 1, 0), add_edge(i, src, 0, 0);
  for (int i = 1; i <= m; i++) {
    int u = E[i - 1].first, v = E[i - 1].second;
    add_edge(i, u + m, 1, 0);
    add_edge(u + m, i, 0, 0);
    add_edge(i, v + m, 1, 0);
    add_edge(v + m, i, 0, 0);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 11; j++) {
      add_edge(i + m, trg, inf, j + d[i]);
      add_edge(trg, i + m, 0, -(j + d[i]));
    }
  }
  int flow = 0;
  int res = min_cost_flow(src, trg, N, inf, flow);
  for (int u = 1; u <= m; u++) {
    for (int i = head[u]; ~i; i = G[i].next) {
      int v = G[i].v, cap = G[i].cap;
      v -= m;
      if (cap == 0) {
        if (v == E[u - 1].first) {
          ans[v][E[u - 1].second] = 1;
        } else {
          ans[v][E[u - 1].first] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%d", ans[i][j]);
    printf("\n");
  }
  return 0;
}
