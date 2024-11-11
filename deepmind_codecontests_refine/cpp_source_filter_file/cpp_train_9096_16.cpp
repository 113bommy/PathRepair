#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int pre[3000001], last[10005], other[3000001], cap[3000001];
int d[10005], que[10005], a[10005], val[10005];
int n, m, l, g, S, T, ans;
inline int read(void) {
  int x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
void connect(int x, int y, int z) {
  l++;
  pre[l] = last[x];
  last[x] = l;
  other[l] = y;
  cap[l] = z;
  swap(x, y);
  l++;
  pre[l] = last[x];
  last[x] = l;
  other[l] = y;
  cap[l] = 0;
}
bool bfs(void) {
  memset(d, 0, sizeof d);
  int h = 1, t = 1;
  que[1] = S;
  d[S] = 1;
  while (h <= t) {
    int u = que[h];
    h++;
    for (int p = last[u]; p; p = pre[p]) {
      int v = other[p];
      if (d[v] || cap[p] == 0) continue;
      d[v] = d[u] + 1;
      que[++t] = v;
      if (v == T) return 1;
    }
  }
  return 0;
}
int dinic(int u, int flow) {
  if (u == T) return flow;
  int res = flow;
  for (int p = last[u]; p; p = pre[p]) {
    int v = other[p];
    if (res > 0 && cap[p] > 0 && d[v] == d[u] + 1) {
      int tmp = dinic(v, min(res, cap[p]));
      res -= tmp;
      cap[p] -= tmp;
      cap[p ^ 1] += tmp;
      if (tmp == 0) d[v] = 0;
    }
  }
  return flow - res;
}
int main() {
  n = read();
  m = read();
  g = read();
  l = 1;
  S = n + m + 1;
  T = n + m + 2;
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) val[i] = read();
  for (int i = 1; i <= n; i++)
    a[i] ? connect(i, T, val[i]) : connect(S, i, val[i]);
  for (int i = 1; i <= m; i++) {
    int opt = read(), w = read();
    ans += w;
    int k = read();
    for (int j = 1; j <= k; j++) {
      int x = read();
      opt ? connect(x, n + i, INF) : connect(n + i, x, INF);
    }
    int pd = read();
    if (pd == 1) w += g;
    opt ? connect(n + i, T, w) : connect(S, n + i, w);
  }
  while (bfs()) ans -= dinic(S, INF);
  printf("%d\n", ans);
  return 0;
}
