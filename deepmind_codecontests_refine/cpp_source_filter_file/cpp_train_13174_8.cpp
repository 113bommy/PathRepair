#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ans = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) ans = ans * 10 + ch - '0', ch = getchar();
  return ans;
}
const int N = 200;
int n, k;
int d[N];
int p[N];
int ans[N];
int f[N][N];
int dis[N][N];
vector<int> e[N];
void dfs(int u, int fa) {
  for (int i = 1; i <= n; ++i) f[i][u] = d[dis[i][u]] + k;
  for (int t = 0; t < e[u].size(); ++t) {
    int v = e[u][t];
    if (v == fa) continue;
    dfs(v, u);
    for (int i = 1; i <= n; ++i) f[i][u] += min(f[p[v]][v], f[i][v] - k);
  }
  p[u] = 1;
  for (int i = 2; i <= n; ++i)
    if (f[i][u] < f[p[u]][u]) p[u] = i;
}
void findans(int u, int fa, int lst) {
  for (int t = 0; t < e[u].size(); ++t) {
    int v = e[u][t];
    if (v == fa) continue;
    if (f[lst][v] - k > f[p[v]][v])
      ans[v] = lst;
    else
      ans[v] = p[v];
    findans(v, u, ans[v]);
  }
}
int main() {
  memset(dis, 0x3f, sizeof dis);
  n = read();
  k = read();
  for (int i = 1; i < n; ++i) d[i] = read();
  for (int i = 1; i < n; ++i) {
    int u, v;
    u = read();
    v = read();
    dis[u][v] = dis[v][u] = 1;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) dis[i][i] = 0;
  for (int _ = 1; _ <= n; ++_) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][_] + dis[_][j]);
    }
  }
  dfs(1, -1);
  ans[1] = p[1];
  findans(1, -1, ans[1]);
  printf("%d\n", f[p[1]][1]);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  putchar('\n');
  return 0;
}
