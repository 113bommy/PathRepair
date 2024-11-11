#include <bits/stdc++.h>
using namespace std;
const int N = 105, INF = 0x3f3f3f3f;
int n, m, s, t, ans, Head[N], flow[N], dis[N], vis[N], pre[N];
struct edge {
  int to, next, w, c;
} E[100005];
inline void add(const int u, const int v, const int w, const int c) {
  static int ecnt = 1;
  E[++ecnt] = (edge){v, Head[u], w, c};
  Head[u] = ecnt;
  E[++ecnt] = (edge){u, Head[v], 0, -c};
  Head[v] = ecnt;
}
bool spfa() {
  memset(dis, INF, sizeof(int[t + 1]));
  memset(pre, 0, sizeof(int[t + 1]));
  static queue<int> Q;
  Q.push(s);
  dis[s] = 0;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    vis[u] = 0;
    for (int i = Head[u], v; i; i = E[i].next)
      if (E[i].w && dis[v = E[i].to] > dis[u] + E[i].c) {
        dis[v] = dis[u] + E[i].c;
        pre[v] = i;
        if (!vis[v]) Q.push(v), vis[v] = 1;
      }
  }
  return pre[t];
}
void MCMF() {
  while (spfa()) {
    int f = INF;
    for (int i = pre[t]; i; i = pre[E[i ^ 1].to]) f = min(f, E[i].w);
    for (int i = pre[t]; i; i = pre[E[i ^ 1].to]) E[i].w -= f, E[i ^ 1].w += f;
    ans += f * dis[t];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  s = n + 1, t = s + 1;
  while (m--) {
    int u, v, c, f;
    scanf("%d%d%d%d", &u, &v, &c, &f);
    flow[u] += f, flow[v] -= f;
    if (c >= f) {
      add(v, u, f, 1);
      add(u, v, c - f, 1);
      add(u, v, INF, 2);
    } else {
      ans += f - c;
      add(u, v, INF, 2);
      add(v, u, f - c, 0);
      add(v, u, c, 1);
    }
  }
  add(n, 1, INF, 0);
  for (int i = 1; i <= n; i++)
    if (flow[i] >= 0)
      add(i, t, flow[i], 0);
    else
      add(s, i, -flow[i], 0);
  MCMF();
  printf("%d\n", ans);
  return 0;
}
