#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const int inf = 1e9 + 7;
int n, m, k, c, d, a[110], uu[110], vv[110];
int tot = 1, f[N], nxt[N << 1];
int S, T, dis[N], vis[N], mf[N], pre[N], maxflow = 0, Ans = 0;
queue<int> q;
struct Edge {
  int u, v, flow, cost;
} e[N << 1];
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return f * x;
}
int num(int t, int node) { return (t - 1) * n + node; }
void Add(int u, int v, int flow, int cost) {
  tot++;
  nxt[tot] = f[u];
  f[u] = tot;
  e[tot] = (Edge){u, v, flow, cost};
  return;
}
void Addedge(int u, int v, int flow, int cost) {
  Add(u, v, flow, cost);
  Add(v, u, 0, -cost);
  return;
}
void Build() {
  S = (k + n) * n + 1;
  for (int i = 1; i <= k; i++) Addedge(S, a[i], 1, 0);
  for (int i = 1; i < n + k; i++) {
    Addedge(num(i, 1), num(i + 1, 1), inf, 0);
    for (int j = 2; j <= n; j++) Addedge(num(i, j), num(i + 1, j), inf, c);
  }
  for (int i = 1; i <= m; i++) {
    int u = uu[i], v = vv[i];
    for (int j = 1; j < n + k; j++)
      for (int l = 1; l <= n; l++) {
        int tmp = 2 * l - 1;
        Addedge(num(j, u), num(j + 1, v), 1, tmp * d + c);
        Addedge(num(j, v), num(j + 1, u), 1, tmp * d + c);
      }
  }
  T = num(n + k, 1);
  return;
}
int SPFA() {
  while (q.size()) q.pop();
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  memset(pre, 0, sizeof(pre));
  memset(mf, 0x3f, sizeof(mf));
  vis[S] = 1;
  dis[S] = 0;
  q.push(S);
  while (q.size()) {
    int tmp = q.front();
    q.pop();
    vis[tmp] = 0;
    for (int j = f[tmp]; j != -1; j = nxt[j]) {
      int v = e[j].v;
      if (!e[j].flow) continue;
      if (dis[v] <= dis[tmp] + e[j].cost) continue;
      mf[v] = min(mf[tmp], e[j].flow);
      pre[v] = j;
      dis[v] = dis[tmp] + e[j].cost;
      if (!vis[v]) {
        vis[v] = 1;
        q.push(v);
      }
    }
  }
  if (dis[T] != 0x3F3F3F3F)
    return 1;
  else
    return 0;
}
void Update() {
  int now = T;
  maxflow += mf[T];
  Ans += mf[T] * dis[T];
  while (now != S) {
    e[pre[now]].flow -= mf[T];
    e[pre[now] ^ 1].flow += mf[T];
    now = e[pre[now]].u;
  }
  return;
}
int main() {
  memset(f, -1, sizeof(f));
  n = read(), m = read(), k = read(), c = read(), d = read();
  for (int i = 1; i <= k; i++) a[i] = read();
  for (int i = 1; i <= m; i++) uu[i] = read(), vv[i] = read();
  Build();
  while (SPFA()) Update();
  printf("%d\n", Ans);
  return 0;
}
