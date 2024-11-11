#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool t = false;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') t = true, ch = getchar();
  while (ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
  return t ? -x : x;
}
int n, m;
struct Line {
  int v, next, w;
} e[300300 << 1];
int h[300300], cnt = 1;
inline void Add(int u, int v, int w) {
  e[cnt] = (Line){v, h[u], w};
  h[u] = cnt++;
}
int fa[300300], dep[300300];
int son[300300], c[300300], tot, size[300300];
long long l[300300], dis[300300], S[300300];
bool vis[300300];
void dfs(int u, int ff) {
  dep[u] = dep[ff] + 1;
  fa[u] = ff;
  size[u] = 1;
  l[u] = dis[u];
  son[u] = 0;
  for (int i = h[u]; i; i = e[i].next)
    if (e[i].v != ff && !vis[e[i].v]) {
      dis[e[i].v] = dis[u] + e[i].w;
      dfs(e[i].v, u);
      size[u] += size[e[i].v];
      ++son[u];
      l[u] = max(l[u], l[e[i].v]);
    }
}
long long mx, Max;
int main() {
  n = read();
  m = read();
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read(), w = read();
    Add(u, v, w);
    Add(v, u, w);
  }
  dfs(1, 0);
  tot = dep[n];
  for (int i = tot, u = n; i; --i)
    c[i] = u, vis[u] = true, S[i] = dis[u], u = fa[u];
  memset(dis, 0, sizeof(dis));
  for (int i = 1; i <= tot; ++i) dfs(c[i], 0);
  mx = l[1] + S[1];
  Max = -S[tot];
  for (int i = 2; i <= tot; ++i) {
    if (son[c[i]]) Max = max(Max, mx + l[c[i]] - S[i]);
    mx = max(mx, l[c[i]] + S[i]);
  }
  mx = l[n] - S[tot];
  for (int i = tot - 1; i; --i) {
    if (son[c[i]]) Max = max(Max, mx + l[c[i]] + S[i]);
    mx = max(mx, l[c[i]] - S[i]);
  }
  for (int i = 1; i < tot - 1; ++i) Max = max(Max, -S[i + 2] + S[i]);
  bool fl = false;
  for (int i = 1; i <= tot; ++i)
    if (son[i] >= 2 || size[i] >= 3) fl = true;
  while (m--) {
    long long x = read() + Max + S[tot];
    if (fl) x = S[tot];
    printf("%I64d\n", min(x, S[tot]));
  }
  return 0;
}
