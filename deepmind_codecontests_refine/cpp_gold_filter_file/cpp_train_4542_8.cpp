#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return f ? x : -x;
}
const int maxn = 55, maxm = maxn << 1;
int deg[maxn], head[maxn], nxt[maxm], to[maxm], e, sz[maxn], vis[maxn],
    dp[maxn][maxn][maxn][maxn], a[maxn][maxn];
void add(int x, int y) {
  deg[x]++;
  deg[y]++;
  to[++e] = y;
  nxt[e] = head[x];
  head[x] = e;
  to[++e] = x;
  nxt[e] = head[y];
  head[y] = e;
}
void Dfs(int u, int fa) {
  sz[u] = vis[u];
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v != fa) Dfs(v, u), sz[u] += sz[v];
  }
}
int dfs(int p, int u, int s1, int s2) {
  if (!s1 && !s2) return 0;
  if (!s1) return 0x3f3f3f3f;
  if (dp[p][u][s1][s2] < 0x3f3f3f3f) return dp[p][u][s1][s2];
  if (deg[u] == 1) return dp[p][u][s1][s2] = dfs(u, p, s2, 0) + a[p][u];
  int f[maxn];
  memset(f, 0, sizeof(f));
  f[0] = 0x3f3f3f3f;
  for (int i = head[u]; i; i = nxt[i]) {
    int v = to[i];
    if (v != p)
      for (int j = s1; j >= 0; --j)
        for (int k = 0; k <= j; ++k)
          f[j] = max(f[j], min(dfs(u, v, k, s1 + s2 - k), f[j - k]));
  }
  return dp[p][u][s1][s2] = f[s1] + a[p][u];
}
int main() {
  int n = read();
  for (int i = 1; i < n; ++i) {
    int u = read(), v = read(), w = read();
    a[u][v] = a[v][u] = w;
    add(u, v);
  }
  int s = read(), m = read();
  for (int i = 1; i <= m; ++i) ++vis[read()];
  int ans = 0x3f3f3f3f;
  Dfs(s, 0);
  memset(dp, 0x3f, sizeof(dp));
  for (int i = head[s]; i; i = nxt[i]) {
    int v = to[i];
    ans = min(ans, dfs(s, v, sz[v], m - sz[v]));
  }
  cout << ans << endl;
  return 0;
}
