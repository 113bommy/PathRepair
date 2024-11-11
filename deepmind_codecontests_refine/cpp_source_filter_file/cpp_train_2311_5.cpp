#include <bits/stdc++.h>
using namespace std;
int id[12][12], cnt, to[110][8];
double f[110];
bool vis[110];
double dfs(int u) {
  if (vis[u]) {
    return f[u];
  }
  vis[u] = 1;
  double rep = 0.0;
  for (int i = 1; i <= 6; i++) {
    rep += min(dfs(to[u][i]), dfs(to[to[u][i]][0]));
  }
  rep /= 6.0;
  rep += 1.0;
  return f[u] = rep;
}
int main() {
  for (int i = 1; i <= 10; i++) {
    if (i & 1) {
      for (int j = 1; j <= 10; j++) {
        id[i][j] = ++cnt;
      }
    } else {
      for (int j = 10; j; j--) {
        id[i][j] = ++cnt;
      }
    }
  }
  for (int i = 1; i <= 100; i++) {
    to[i][0] = i;
    for (int j = 1; j <= 6; j++) {
      to[i][j] = i > j ? i - j : i;
    }
  }
  for (int i = 1, u; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      scanf("%d", &u);
      if (u) {
        to[id[i][j]][0] = id[u][j];
      }
    }
  }
  for (int i = 1; i <= 6; i++) {
    vis[i] = 1;
  }
  f[1] = 0.0;
  f[2] = 6.0;
  f[3] = 6.0;
  f[4] = 6.0;
  f[5] = 6.0;
  f[6] = 6.0;
  for (int i = 7; i <= 100; i++) {
    dfs(i);
  }
  printf("%.6lf\n", dfs(100));
  return 0;
}
