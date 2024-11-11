#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
vector<int> E[maxn];
int siz[maxn], deep[maxn];
long long sumdis[maxn], start[maxn];
int f[maxn][19];
int n, m;
void dfs(int x) {
  siz[x] = 1;
  sumdis[x] = 0;
  for (int i = 0; i < E[x].size(); i++) {
    int y = E[x][i];
    if (siz[y] == 0) {
      deep[y] = deep[x] + 1;
      f[y][0] = x;
      dfs(y);
      siz[x] += siz[y];
      sumdis[x] += sumdis[y] + (long long)siz[y];
    }
  }
}
int getlca(int x, int y) {
  if (deep[x] < deep[y]) return getlca(y, x);
  for (int i = (18); i >= (0); i--)
    if (deep[f[x][i]] >= deep[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = (18); i >= (0); i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
void dfs1(int x) {
  start[x] = sumdis[x];
  if (f[x][0]) start[x] += start[f[x][0]] - (siz[x] + sumdis[x]) + (n - siz[x]);
  for (int i = 0; i < E[x].size(); i++) {
    int y = E[x][i];
    if (f[y][0] == x) dfs1(y);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n - 1); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    E[x].push_back(y);
    E[y].push_back(x);
  }
  deep[(n + 1) / 2] = 1;
  dfs((n + 1) / 2);
  deep[0] = 0;
  for (int j = (1); j <= (18); j++)
    for (int i = (1); i <= (n); i++)
      if (f[f[i][j - 1]][j - 1]) f[i][j] = f[f[i][j - 1]][j - 1];
  dfs1((n + 1) / 2);
  for (int i = (1); i <= (m); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int lca = getlca(x, y);
    double ans = (double)deep[x] + deep[y] - 2 * deep[lca] + 1;
    if (lca != x && lca != y) {
      ans += (sumdis[x] * 1.0) / (siz[x] * 1.0);
      ans += (sumdis[y] * 1.0) / (siz[y] * 1.0);
    } else {
      if (x == lca) swap(x, y);
      int t = x;
      for (int i = (18); i >= (0); i--)
        if (deep[f[t][i]] > deep[y]) t = f[t][i];
      ans += (sumdis[x] * 1.0) / (siz[x] * 1.0);
      ans += (start[y] - sumdis[t] - siz[t]) * 1.0 / ((n - siz[t]) * 1.0);
    }
    printf("%.6f\n", ans);
  }
}
