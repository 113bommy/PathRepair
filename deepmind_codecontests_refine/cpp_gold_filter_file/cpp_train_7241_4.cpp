#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, top, tim, pos, Max;
int From[800005], To[800005];
int head[800005], to[1600005], Next[1600005];
int s[800005], vis[800005], dfn[800005], low[800005];
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
inline void add(int u, int v) {
  to[++cnt] = v;
  Next[cnt] = head[u];
  head[u] = cnt;
}
void Tarjan(int u, int fa) {
  vis[s[++top] = u] = 1;
  dfn[u] = low[u] = ++tim;
  for (register int i = head[u]; ~i; i = Next[i]) {
    int v = to[i];
    if (v == fa) continue;
    if (!dfn[v]) {
      Tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else if (vis[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    int size = 0;
    while (s[top + 1] != u) {
      ++size;
      vis[s[top--]] = 0;
    }
    if (Max < size) {
      pos = u;
      Max = size;
    }
  }
  return;
}
void dfs(int u) {
  vis[u] = 1;
  for (register int i = head[u]; ~i; i = Next[i]) {
    int v = to[i];
    if (vis[v]) {
      From[i >> 1] = u;
      To[i >> 1] = v;
      continue;
    }
    if (low[u] != low[v]) {
      From[i >> 1] = v;
      To[i >> 1] = u;
    } else {
      From[i >> 1] = u;
      To[i >> 1] = v;
    }
    dfs(v);
  }
  return;
}
int main() {
  cnt = -1;
  memset(head, -1, sizeof head);
  n = read();
  m = read();
  for (register int i = 1; i <= m; ++i) {
    int u, v;
    u = read();
    v = read();
    add(u, v);
    add(v, u);
  }
  Tarjan(1, 0);
  while (top) vis[s[top--]] = 0;
  dfs(pos);
  printf("%d\n", Max);
  for (register int i = 0; i < m; ++i) printf("%d %d\n", From[i], To[i]);
  return 0;
}
