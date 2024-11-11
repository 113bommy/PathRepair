#include <bits/stdc++.h>
using namespace std;
int deg[105], g[7][7];
int path[105];
int x[105], y[105];
int npath;
void dfs(int u) {
  for (int i = 0; i < 7; ++i)
    if (g[u][i] > 0) {
      --g[u][i];
      --g[i][u];
      dfs(i);
    }
  path[npath--] = u;
}
int main(int argc, char *argv[]) {
  int n, i = 0;
  memset(deg, 0, sizeof(deg));
  memset(g, 0, sizeof(g));
  for (scanf("%d", &n); i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    ++g[x[i]][y[i]];
    ++g[y[i]][x[i]];
    deg[x[i]]++;
    deg[y[i]]++;
  }
  int c = 0;
  int start = x[0];
  npath = n;
  for (i = 0; i <= 6; ++i)
    if (deg[i] & 1) ++c, start = i;
  dfs(start);
  if (npath >= 0 || c > 2) {
    printf("No solution");
    return 0;
  }
  for (int j = 0; j < n; ++j)
    for (i = 0; i < n; ++i) {
      if (x[i] == path[j] && path[j + 1] == y[i]) {
        x[i] = y[i] = -1;
        printf("%d +\n", i + 1);
        break;
      } else if (x[i] == path[j + 1] && y[i] == path[j]) {
        printf("%d -\n", i + 1);
        x[i] = y[i] = -1;
        break;
      }
    }
  return EXIT_SUCCESS;
}
