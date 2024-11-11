#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10;
const int EMAX = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int n, m, s, t;
struct edges {
  int to, nxt, flow, dis, from;
} edge[EMAX << 1];
int head[MAX], tot;
inline void init() {
  memset(head, -1, sizeof(head));
  tot = -1;
}
inline void addedge(int u, int v, int flow, int dis) {
  ++tot;
  edges& e = edge[tot];
  e.to = v, e.from = u, e.flow = flow, e.dis = dis, e.nxt = head[u];
  head[u] = tot;
  ++tot;
  edges& ee = edge[tot];
  ee.to = u, ee.from = v, ee.flow = 0, ee.dis = -dis, ee.nxt = head[v];
  head[v] = tot;
}
int dis[MAX], flow[MAX], vis[MAX], pre[MAX], last[MAX];
bool spfa(int s, int t) {
  memset(dis, 0x3f, sizeof(dis));
  memset(flow, 0x3f, sizeof(flow));
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(s);
  vis[s] = 1, dis[s] = 0, pre[t] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; i != -1; i = edge[i].nxt) {
      edges& e = edge[i];
      if (e.flow > 0 && dis[e.to] > dis[u] + e.dis) {
        dis[e.to] = dis[u] + e.dis;
        pre[e.to] = u;
        last[e.to] = i;
        flow[e.to] = min(flow[u], e.flow);
        if (!vis[e.to]) {
          vis[e.to] = 1;
          q.push(e.to);
        }
      }
    }
  }
  return pre[t] != -1;
}
int maxflow, mincost;
void MCMF() {
  while (spfa(s, t)) {
    int u = t;
    maxflow += flow[t];
    mincost += flow[t] * dis[t];
    while (u != s) {
      edge[last[u]].flow -= flow[t];
      edge[last[u] ^ 1].flow += flow[t];
      u = pre[u];
    }
  }
}
int arr[MAX];
int main() {
  init();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  s = 0, t = 2 * n + 1;
  int ss = t + 1, tt = ss + 1;
  addedge(s, ss, 4, 0);
  addedge(tt, t, 4, 0);
  for (int i = 1; i <= n; ++i) {
    addedge(i, i + n, 1, -1);
    addedge(ss, i, 1, 0);
    addedge(i + n, tt, 1, 0);
    for (int j = i + 1, k = 0; j <= n && k < 3; ++j) {
      if (arr[i] - arr[j] == 1) {
        addedge(i + n, j, 1, 0);
        ++k;
      }
    }
    for (int j = i + 1, k = 0; j <= n && k < 3; ++j) {
      if (arr[i] - arr[j] == -1) {
        addedge(i + n, j, 1, 0);
        ++k;
      }
    }
    for (int j = i + 1, k = 0; j <= n && k < 3; ++j) {
      if (arr[i] % 7 == arr[j] % 7) {
        addedge(i + n, j, 1, 0);
        ++k;
      }
    }
  }
  MCMF();
  cout << -mincost << endl;
  return 0;
}
