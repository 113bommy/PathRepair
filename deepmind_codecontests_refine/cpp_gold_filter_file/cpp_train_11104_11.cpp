#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int tot = 1;
int ver[N << 1], nxt[N << 1], head[N << 1];
int dfn[N], low[N], f[N][19], rt[N];
int vis[N], st[N], top, v[N], sum[N], is[N];
vector<int> e[N], dcc[N];
int cnt, num, dep[N], bel[N], c[N], n, m, q;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void add(int x, int y) {
  ver[++tot] = y;
  nxt[tot] = head[x];
  head[x] = tot;
}
void tarjan(int x, int fr) {
  dfn[x] = low[x] = ++num;
  dep[x] = dep[ver[fr ^ 1]] + 1;
  f[x][0] = ver[fr ^ 1];
  rt[x] = rt[ver[fr ^ 1]];
  for (int i = 1; i <= 18; i++) f[x][i] = f[f[x][i - 1]][i - 1];
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (vis[i] || i == (fr ^ 1)) continue;
    st[++top] = i;
    if (!dfn[y]) {
      tarjan(y, i);
      low[x] = min(low[x], low[y]);
      if (dfn[x] <= low[y]) {
        ++cnt;
        int z;
        dcc[cnt].push_back(x);
        do {
          z = st[top--];
          bel[z] = bel[z ^ 1] = cnt;
          vis[z] = vis[z ^ 1] = 1;
          dcc[cnt].push_back(ver[z]);
          e[cnt].push_back(z);
        } while (z != i);
      }
    } else
      low[x] = min(low[x], dfn[y]);
  }
}
void dfs(int x, int fa) {
  vis[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (vis[y] || (i == (fa ^ 1))) continue;
    sum[y] = sum[x] + is[i];
    dfs(y, i);
  }
}
bool dfs2(int x, int fa) {
  if (vis[x]) {
    if (c[x] == c[ver[fa ^ 1]])
      return 1;
    else
      return 0;
  }
  vis[x] = 1;
  c[x] = c[ver[fa ^ 1]] ^ 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = ver[i];
    if (i == (fa ^ 1) || bel[i] != bel[fa]) continue;
    if (dfs2(y, i)) return 1;
  }
  return 0;
}
int LCA(int x, int y) {
  if (dep[x] > dep[y]) swap(x, y);
  for (int i = 18; i >= 0; i--) {
    if (dep[f[y][i]] >= dep[x]) y = f[y][i];
  }
  if (x == y) return x;
  for (int i = 18; i >= 0; i--) {
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  }
  return f[x][0];
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    int u, v;
    u = read();
    v = read();
    add(u, v);
    add(v, u);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i, 0), rt[0] = i;
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= cnt; i++) {
    for (int j = 0; j < dcc[i].size(); j++) {
      vis[dcc[i][j]] = 0;
      vis[dcc[i][j] ^ 1] = 0;
    }
    if (dfs2(ver[e[i][0]], e[i][0])) {
      for (int j = 0; j < e[i].size(); j++) {
        is[e[i][j]] = is[e[i][j] ^ 1] = 1;
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i, 0);
  }
  q = read();
  while (q--) {
    int u, v;
    u = read();
    v = read();
    if (rt[u] != rt[v])
      puts("No");
    else {
      int l = LCA(u, v);
      if ((dep[u] + dep[v] - 2 * dep[l]) & 1)
        puts("Yes");
      else if (sum[u] + sum[v] - 2 * sum[l])
        puts("Yes");
      else
        puts("No");
    }
  }
  return 0;
}
