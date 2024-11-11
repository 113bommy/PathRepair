#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
const int M = N * N + 5;
const int INF = 0x3f3f3f3f;
int head[N], dis[N], s, t, no, vis[N], pre[N];
struct Edge {
  int u, v, next, flow, cost;
  Edge(){};
  Edge(int x, int y, int z, int w, int c)
      : u(x), v(y), next(z), flow(w), cost(c){};
} e[2 * M];
void add(int x, int y, int z, int c) {
  e[no] = Edge(x, y, head[x], z, c);
  head[x] = no++;
  e[no] = Edge(y, x, head[y], 0, -c);
  head[y] = no++;
}
void init() {
  memset(head, -1, sizeof(head));
  no = 0;
}
struct MCMF {
  bool SPFA() {
    int i, x, y;
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while (!q.empty()) {
      x = q.front();
      q.pop();
      vis[x] = false;
      for (i = head[x]; i != -1; i = e[i].next) {
        if (e[i].flow && dis[y = e[i].v] > dis[x] + e[i].cost) {
          dis[y] = dis[x] + e[i].cost;
          pre[y] = i;
          if (vis[y]) continue;
          vis[y] = true;
          q.push(y);
        }
      }
    }
    return dis[t] != dis[t + 1];
  }
  pair<int, int> operator()(int s, int t, int n) {
    int min_cost = 0, max_flow = 0, min_flow;
    while (SPFA()) {
      min_flow = INF;
      for (int i = pre[t]; i != -1; i = pre[e[i].u])
        min_flow = min(min_flow, e[i].flow);
      for (int i = pre[t]; i != -1; i = pre[e[i].u]) {
        e[i].flow -= min_flow;
        e[i ^ 1].flow += min_flow;
      }
      min_cost += dis[t] * min_flow;
      max_flow += min_flow;
    }
    return make_pair(max_flow, min_cost);
  }
} mcmf;
int n, q, u, v, c, w, mn[N], mx[N];
void solve() {
  init();
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) mn[i] = 0, mx[i] = n;
  for (int _ = 0; _ < q; _++) {
    int ty, l, r, v;
    scanf("%d%d%d%d", &ty, &l, &r, &v);
    for (int i = l; i <= r; i++)
      if (ty == 1)
        mn[i] = max(mn[i], v);
      else if (ty == 2)
        mx[i] = min(mx[i], v);
  }
  s = 2 * n + 1;
  t = 2 * n + 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) add(s, i, 1, 2 * j - 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = mn[i]; j <= mx[i]; j++) add(j, i + n, 1, 0);
    add(i + n, t, 1, 0);
  }
  pair<int, int> ans = mcmf(s, t, 2 * n + 2);
  printf("%d\n", ans.first == n ? ans.second : -1);
}
int main() {
  solve();
  return 0;
}
