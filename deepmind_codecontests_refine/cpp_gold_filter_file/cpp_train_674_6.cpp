#include <bits/stdc++.h>
using namespace std;
const int maxn = 202;
const int maxs = 1000004;
int data[maxn * maxn], n, m, q;
int iscir[maxn * maxn], cir[maxn * maxn][10], N[maxn * maxn];
int X[10], Y[10];
void readin() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c = '\n';
      while (c == '\n') scanf("%c", &c);
      data[i * m + j] = c - '0';
    }
  for (int i = 0; i < 10; i++) scanf("%d%d", &X[i], &Y[i]);
}
int vis[maxn * maxn];
int next(int u) {
  int x = u / m, y = u % m;
  x += X[data[u]];
  y += Y[data[u]];
  int v;
  if (x >= n || y >= m || x < 0 || y < 0)
    v = u;
  else
    v = x * m + y;
  return v;
}
void find_cir(int u) {
  vis[u] = -1;
  int v = N[u];
  if (vis[v] != 1) {
    if (vis[v] == -1)
      iscir[v] = 1;
    else
      find_cir(v);
  }
  vis[u] = 1;
}
void get_cir(int i, int u) {
  cir[i][data[u]] = 1;
  vis[u] = 1;
  int v = N[u];
  if (vis[v]) return;
  get_cir(i, v);
}
char s[maxs];
bool is[maxs][10];
bool ishead[maxn * maxn];
void head_dfs(int u) {
  vis[u] = 1;
  if (vis[N[u]]) return;
  head_dfs(N[u]);
}
void get_head() {
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n * m; i++) vis[N[i]] = 1;
  for (int i = 0; i < n * m; i++)
    if (!vis[i]) ishead[i] = true;
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n * m; i++)
    if (ishead[i]) head_dfs(i);
  for (int i = 0; i < n * m; i++)
    if (iscir[i] && !vis[i]) ishead[i] = true;
}
bool judge() {
  int len = strlen(s);
  for (int i = len - 1; i >= 0; i--) {
    memset(is[i], false, sizeof(is[i]));
    if (i != len - 1)
      for (int j = 0; j < 10; j++) is[i][j] = is[i + 1][j];
    is[i][s[i] - '0'] = true;
  }
  for (int i = 0; i < n * m; i++)
    if (ishead[i]) {
      int u = i, cur = 0;
      while (!iscir[u]) {
        while (s[cur] - '0' != data[u]) {
          u = N[u];
          if (iscir[u]) break;
        }
        if (!iscir[u]) {
          u = N[u];
          cur++;
          if (cur == len) return true;
        }
      }
      int flag = 1;
      for (int j = 0; j < 10; j++)
        if (is[cur][j] && !cir[u][j]) flag = 0;
      if (flag) return true;
    }
  return false;
}
void solve() {
  memset(iscir, 0, sizeof(iscir));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n * m; i++) {
    N[i] = next(i);
    for (int j = 0; j < 10; j++) cir[i][j] = 0;
  }
  for (int i = 0; i < n * m; i++)
    if (vis[i] != 1) find_cir(i);
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n * m; i++)
    if (iscir[i]) get_cir(i, i);
  get_head();
  for (int i = 0; i < q; i++) {
    scanf("%s", s);
    if (judge())
      printf("YES\n");
    else
      printf("NO\n");
  }
}
int main() {
  readin();
  solve();
  return 0;
}
