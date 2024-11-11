#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N = 2e6 + 10, M = 2e6 + 10, INF = 1e9;
int n, m, S, T;
int h[N], e[M], w[M], ne[M], idx;
int q[N], d[N], cur[N];
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};
int id[210][210];
char str[N];
void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
  e[idx] = a, w[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}
bool bfs() {
  int hh = 0, tt = 0;
  memset(d, -1, sizeof d);
  q[0] = S, d[S] = 0, cur[S] = h[S];
  while (hh <= tt) {
    int t = q[hh++];
    for (int i = h[t]; ~i; i = ne[i]) {
      int ver = e[i];
      if (d[ver] == -1 && w[i]) {
        d[ver] = d[t] + 1;
        cur[ver] = h[ver];
        if (ver == T) return true;
        q[++tt] = ver;
      }
    }
  }
  return false;
}
int find(int u, int limit) {
  if (u == T) return limit;
  int flow = 0;
  for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
    cur[u] = i;
    int ver = e[i];
    if (d[ver] == d[u] + 1 && w[i]) {
      int t = find(ver, min(w[i], limit - flow));
      if (!t) d[ver] = -1;
      w[i] -= t, w[i ^ 1] += t, flow += t;
    }
  }
  return flow;
}
int dinic() {
  int r = 0, flow;
  while (bfs())
    while (flow = find(S, INF)) r += flow;
  return r;
}
int tt;
int s;
int main() {
  idx = 0;
  memset(h, -1, sizeof h);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> (str + 1);
    for (int j = 1; j <= m; j++)
      if (str[j] == '#') id[i][j] = ++tt;
  }
  S = 0;
  T = tt + 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (id[i][j]) {
        int cnt0 = 0, cnt1 = 0;
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (!(1 <= x && x <= n && 1 <= y && y <= m && id[x][y])) {
            if (k == 0 || k == 3)
              ++cnt0;
            else
              ++cnt1;
          } else
            add(id[i][j], id[x][y], 1);
        }
        add(S, id[i][j], cnt0);
        add(id[i][j], T, cnt1);
      }
  cout << dinic() / 2;
  return 0;
}
