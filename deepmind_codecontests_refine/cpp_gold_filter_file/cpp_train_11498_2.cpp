#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
int n, m, mat[501][501], dp[501];
long long dis[501][501], inf = 1ll << 50;
int main() {
  int u, v, l;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j) dis[i][j] = inf;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &l);
    u--, v--;
    mat[u][v] = mat[v][u] = dis[u][v] = dis[v][u] = l;
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (dis[i][k] + dis[k][j] < dis[i][j])
          dis[i][j] = dis[i][k] + dis[k][j];
  for (int i = 0; i < n; i++) {
    memset((dp), (0), sizeof(dp));
    for (int z = 0; z < n; z++)
      for (int j = 0; j < n; j++)
        if (mat[j][z] && dis[i][j] + mat[j][z] == dis[i][z]) dp[z]++;
    for (int z = i + 1; z < n; z++) {
      int ans = 0;
      for (int j = 0; j < n; j++)
        if (dis[i][j] + dis[j][z] == dis[i][z]) ans += dp[j];
      printf("%d ", ans);
    }
  }
  return 0;
}
