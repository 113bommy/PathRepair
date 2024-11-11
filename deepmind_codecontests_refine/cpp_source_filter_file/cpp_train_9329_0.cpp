#include <bits/stdc++.h>
using namespace std;
int read() {
  int v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
const int N = 300, M = 10000;
const int INF = 1e9;
int a[N][N], n, q, flow, cost;
struct EG {
  int a, b, c, d, e;
} eg[M];
int head[N], en, S, T;
int dis[N], pre[N], rem[N];
bool inq[N];
void setEdge(int u, int v, int w, int z) {
  eg[++en] = (EG){v, head[u], w, z, u};
  head[u] = en;
  eg[++en] = (EG){u, head[v], 0, -z, v};
  head[v] = en;
}
void Clear() {
  memset(head, 0, sizeof head);
  en = 1;
}
bool Spfa() {
  memset(dis, 0x3f, sizeof dis);
  dis[S] = 0;
  memset(inq, 0, sizeof inq);
  inq[S] = 1;
  queue<int> Q;
  Q.push(S);
  pre[S] = 0, rem[S] = INF;
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    inq[u] = 0;
    for (int e = head[u]; e; e = eg[e].b) {
      int v = eg[e].a;
      if (eg[e].c > 0 && dis[u] + eg[e].d < dis[v]) {
        dis[v] = dis[u] + eg[e].d;
        pre[v] = e;
        rem[v] = min(rem[u], eg[e].c);
        if (!inq[v]) {
          inq[v] = 1;
          Q.push(v);
        }
      }
    }
  }
  if (dis[T] == 0x3f3f3f3f) return 0;
  flow += rem[T];
  cost += dis[T] * rem[T];
  int u = T;
  while (u != S) {
    eg[pre[u]].c -= rem[T];
    eg[pre[u] ^ 1].c += rem[T];
    u = eg[pre[u]].e;
  }
  return 1;
}
void MinCost() {
  flow = cost = 0;
  while (Spfa())
    ;
}
int main() {
  Clear();
  n = read(), q = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = 1;
  S = 3 * n + 1, T = S + 1;
  for (int i = 1; i <= q; i++) {
    int op = read();
    int l = read(), r = read(), v = read();
    if (op == 1) {
      for (int i = l; i <= r; i++)
        for (int j = 1; j < v; j++) a[i][j] = 0;
    } else {
      for (int i = l; i <= r; i++)
        for (int j = v + 1; j <= n; j++) a[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    setEdge(S, i, 1, 0);
    for (int j = 1; j <= n; j++)
      if (a[i][j]) setEdge(i, j + n, 1, 0);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) setEdge(i + n, i + 2 * n, 1, j * 2 - 1);
  for (int i = 1; i <= n; i++) setEdge(i + 2 * n, T, n, 0);
  MinCost();
  if (flow < n)
    puts("-1");
  else
    printf("%d\n", cost);
}
