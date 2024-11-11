#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 2e5 + 10, INF = 1e9;
int b[N], val[N], S, T, num = 1, to[M], c[M], la[M], he[N], d[N], cur[N],
                        maxflow;
queue<int> q;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
  return x * f;
}
void addedge(int x, int y, int ca) {
  to[++num] = y;
  c[num] = ca;
  la[num] = he[x];
  he[x] = num;
  to[++num] = x;
  c[num] = 0;
  la[num] = he[y];
  he[y] = num;
}
bool BFS() {
  memset(d, -1, sizeof(d));
  while (!q.empty()) q.pop();
  d[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (register int i = he[u]; i; i = la[i]) {
      int v = to[i];
      if (c[i] && d[v] == -1) {
        d[v] = d[u] + 1;
        q.push(v);
        if (v == T) return 1;
      }
    }
  }
  return 0;
}
int DFS(int u, int flow) {
  if (u == T || !flow) return flow;
  int rest = flow;
  for (register int i = cur[u]; i; i = la[i]) {
    int v = to[i];
    cur[u] = i;
    if (c[i] && d[u] + 1 == d[v]) {
      int k = DFS(v, min(rest, c[i]));
      if (!k) {
        d[v] = -1;
        continue;
      }
      rest -= k;
      c[i] -= k;
      c[i ^ 1] += k;
      if (!rest) return flow;
    }
  }
  return flow - rest;
}
void Dinic() {
  while (BFS()) {
    memcpy(cur, he, sizeof(he));
    maxflow += DFS(S, INF);
  }
}
int main() {
  int n = read(), m = read(), g = read();
  for (register int i = 1; i <= n; ++i) b[i] = read();
  for (register int i = 1; i <= n; ++i) val[i] = read();
  S = n + m + 1;
  T = S + 1;
  for (register int i = 1; i <= n; ++i)
    if (b[i] == 0)
      addedge(i, T, 0), addedge(S, i, val[i]);
    else
      addedge(i, T, val[i]), addedge(S, i, 0);
  int sum = 0;
  for (register int i = 1; i <= m; ++i) {
    int opt = read(), w = read(), k = read();
    sum += w;
    if (opt == 0)
      for (register int j = 1; j <= k; ++j) {
        int x = read();
        addedge(i + n, x, INF);
      }
    else
      for (register int j = 1; j <= k; ++j) {
        int x = read();
        addedge(x, i + n, INF);
      }
    int flag = read();
    if (flag == 0) {
      if (opt == 0)
        addedge(S, i + n, w);
      else
        addedge(i + n, T, w);
    } else {
      if (opt == 0)
        addedge(S, i + n, w + g);
      else
        addedge(i + n, T, w + g);
    }
  }
  Dinic();
  printf("%d\n", sum - maxflow);
  return 0;
}
