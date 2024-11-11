#include <bits/stdc++.h>
using namespace std;
queue<int> q;
long long Ans;
int n, m, s, t, cnt;
int dis[605], cur[605];
int head[605], w[200005], to[200005], Next[200005];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void add(int u, int v, int p) {
  w[++cnt] = p;
  to[cnt] = v;
  Next[cnt] = head[u];
  head[u] = cnt;
}
int bfs() {
  memset(dis, 0, sizeof dis);
  memcpy(cur, head, sizeof cur);
  q.push(s);
  dis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (register int i = head[u]; i != -1; i = Next[i]) {
      int v = to[i];
      if (w[i] && !dis[v]) {
        q.push(v);
        dis[v] = dis[u] + 1;
      }
    }
  }
  return dis[t];
}
int dfs(int u, int f) {
  if (u == t || !f) return f;
  int res = 0;
  for (register int &i = cur[u]; i != -1; i = Next[i]) {
    int v = to[i];
    if (w[i] && dis[v] == dis[u] + 1) {
      int d = dfs(v, min(f, w[i]));
      res += d;
      f -= d;
      w[i] -= d;
      w[i ^ 1] += d;
      if (!f) break;
    }
  }
  return res;
}
long long Dinic() {
  long long res = 0;
  while (bfs()) {
    while (int d = dfs(s, 1e8 + 233)) res += d;
  }
  return res;
}
int main() {
  cnt = -1;
  memset(head, -1, sizeof head);
  n = read();
  s = 0;
  t = n + n + 1;
  for (register int i = 1; i <= n; ++i) {
    int k = read();
    while (k--) {
      int x = read();
      add(i, x + n, 1e8 + 233);
      add(x + n, i, 0 - 0);
    }
  }
  for (register int i = 1; i <= n; ++i) {
    int x = read();
    Ans = Ans + 1e7 + 114 - x;
    add(s, i, 1e7 + 114 - x);
    add(i, s, 0 - 0 - 0);
  }
  for (register int i = 1; i <= n; ++i) {
    add(i + n, t, 1e7 + 114);
    add(t, i + n, 0 - 0);
  }
  printf("%lld\n", Dinic() - Ans);
  return 0;
}
