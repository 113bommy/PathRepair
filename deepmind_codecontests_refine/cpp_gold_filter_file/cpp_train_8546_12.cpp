#include <bits/stdc++.h>
int q[1000000], d[1000], c[1000][1000], flow, pre[1000];
bool inq[1000];
int head, tail, s, t, n;
void bfs() {
  int u;
  head = tail = 0;
  q[head] = t;
  d[t] = 0;
  for (u = s; u < t; u++) d[u] = 999999999;
  while (head <= tail) {
    u = q[head++];
    inq[u] = false;
    for (int v = s; v <= t; v++)
      if (c[v][u] && d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        if (!inq[v]) q[++tail] = v, inq[v] = true;
      }
  }
}
bool dfs(int u) {
  int v, min;
  if (u == t) return true;
  for (v = s; v <= t; v++)
    if (c[u][v] && d[v] == d[u] - 1)
      if (dfs(v)) {
        pre[v] = u;
        return true;
      }
  for (v = s, min = 999999999; v <= t; v++)
    if (c[u][v] && d[v] < min) min = d[v];
  d[u] = min + 1;
  if (u == s && d[s] < t) return dfs(s);
  return false;
}
void sap() {
  int u, min;
  bfs();
  while (dfs(s)) {
    for (u = t, min = 999999999; u != s; u = pre[u])
      if (c[pre[u]][u] < min) min = c[pre[u]][u];
    flow += min;
    for (u = t; u != s; u = pre[u]) c[pre[u]][u] -= min, c[u][pre[u]] += min;
  }
}
int main() {
  scanf("%d", &n);
  int i, m, num, tot = 0;
  s = 0;
  t = 2 * n + 1;
  for (i = 1; i <= n; i++) {
    scanf("%d", &m);
    while (m--) {
      scanf("%d", &num);
      c[i][num + n] = 999999999;
    }
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &num);
    c[s][i] = 100000001 - num;
    c[i + n][t] = 100000001;
    tot += num;
  }
  sap();
  printf("%d\n", tot + flow - n * 100000001);
}
