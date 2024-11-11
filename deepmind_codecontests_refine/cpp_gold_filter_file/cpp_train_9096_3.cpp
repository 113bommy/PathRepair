#include <bits/stdc++.h>
using namespace std;
using namespace std;
int h[200050], nxt[200050], v[200050], w[200050], s, t, dep[200005], ec, m, n,
    ans, g, a[200050];
void add(int a, int b, int c) {
  v[++ec] = b;
  w[ec] = c;
  nxt[ec] = h[a];
  h[a] = ec;
}
void adj(int a, int b, int c) {
  add(a, b, c);
  add(b, a, 0);
}
bool bfs() {
  queue<int> q;
  q.push(s);
  memset(dep, 0, sizeof(dep));
  dep[s] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = h[x]; i; i = nxt[i])
      if (w[i] > 0 && !dep[v[i]]) dep[v[i]] = dep[x] + 1, q.push(v[i]);
  }
  return dep[t];
}
int dfs(int x, int dis) {
  if (x == t || !dis) return dis;
  int tp = 0;
  for (int i = h[x]; i && tp < dis; i = nxt[i])
    if (dep[v[i]] == dep[x] + 1 && w[i] > 0) {
      int f = dfs(v[i], min(dis - tp, w[i]));
      w[i] -= f;
      w[i ^ 1] += f;
      tp += f;
    }
  if (!tp) dep[x] = 0;
  return tp;
}
int din() {
  int aans = 0;
  while (bfs()) aans += dfs(s, 1e9);
  return aans;
}
int main() {
  ec = 1;
  scanf("%d%d%d", &n, &m, &g);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  t = n + m + 1;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (!a[i])
      adj(s, i, x);
    else
      adj(i, t, x);
  }
  for (int i = 1; i <= m; i++) {
    int op, w, k, x;
    scanf("%d%d%d", &op, &w, &k);
    if (op) {
      for (int j = 1; j <= k; j++) {
        scanf("%d", &x);
        adj(x, n + i, 1e9);
      }
      scanf("%d", &op);
      if (op)
        adj(n + i, t, g + w);
      else
        adj(n + i, t, w);
      ans += w;
    } else {
      for (int j = 1; j <= k; j++) {
        scanf("%d", &x);
        adj(n + i, x, 1e9);
      }
      scanf("%d", &op);
      if (op)
        adj(s, n + i, g + w);
      else
        adj(s, n + i, w);
      ans += w;
    }
  }
  printf("%d", ans - din());
}
