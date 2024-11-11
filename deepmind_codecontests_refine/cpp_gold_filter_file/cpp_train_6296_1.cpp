#include <bits/stdc++.h>
inline int read() {
  int d = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    d = d * 10 + ch - 48, ch = getchar();
  }
  return d;
}
int n, m;
int head[1000005], ver[1000005], nxt[1000005], tot = 1;
int deg[1000005];
inline void add(int u, int v) {
  ver[++tot] = v, nxt[tot] = head[u], head[u] = tot;
  ver[++tot] = u, nxt[tot] = head[v], head[v] = tot;
}
int vis[1000005];
int stk[1000005], tots;
void dfs(int u) {
  for (int& p = head[u]; p; p = nxt[p])
    if (!vis[p]) {
      vis[p] = vis[p ^ 1] = 1;
      dfs(ver[p]);
    }
  stk[++tots] = u;
}
int u, v;
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
    u = read(), v = read();
    add(u, v);
    ++deg[u], ++deg[v];
  }
  u = 0;
  for (int i = 1; i <= n; ++i)
    if (deg[i] & 1) {
      if (u)
        add(u, i), u = 0, ++m;
      else
        u = i;
    }
  if (m & 1) add(1, 1), ++m;
  printf("%d\n", m);
  for (int i = 1; i <= n; ++i) {
    tots = 0;
    dfs(i);
    for (int i = 1; i < tots; ++i) {
      if (i & 1)
        printf("%d %d\n", stk[i], stk[i + 1]);
      else
        printf("%d %d\n", stk[i + 1], stk[i]);
    }
  }
  return 0;
}
