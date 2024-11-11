#include <bits/stdc++.h>
using namespace std;
int g[105][105];
int path[2005], ret[2005];
int n, m;
int dfs(int x, int dep, int flag) {
  if (dep == m) {
    return flag;
  }
  for (int i = flag ? 1 : path[dep + 1]; i <= n; ++i) {
    if (g[x][i]) {
      g[x][i]--;
      g[i][x]--;
      ret[dep] = i;
      if (dfs(i, dep + 1, flag | (i != path[dep + 1]))) return 1;
      g[x][i]++;
      g[i][x]++;
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d", &path[0]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &path[i]);
    g[path[i - 1]][path[i]] = g[path[i]][path[i - 1]] = true;
  }
  if (dfs(path[0], 0, 0)) {
    printf("%d", path[0]);
    for (int i = 0; i < m; ++i) {
      printf(" %d", ret[i]);
    }
    puts("");
  } else {
    printf("No solution\n");
  }
  return 0;
}
