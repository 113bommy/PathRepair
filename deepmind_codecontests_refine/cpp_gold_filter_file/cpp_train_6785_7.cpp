#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
const int INF = 1e8 + 50;
int n;
long long x, a[N];
int bc[60];
int g[200][200], dis[200][200];
int main() {
  scanf("%d", &n);
  int k = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x);
    if (x == 0) {
      continue;
    }
    a[++k] = x;
    for (int j = 0; j < 60; j++) {
      if ((x >> j) & 1) {
        bc[j]++;
      }
    }
  }
  for (int i = 0; i < 60; i++) {
    if (bc[i] >= 3) {
      printf("3\n");
      return 0;
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      dis[i][j] = i == j ? 0 : INF;
      g[i][j] = i == j ? 0 : INF;
    }
  }
  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) {
      if ((a[i] & a[j]) != 0) {
        dis[i][j] = dis[j][i] = 1;
        g[i][j] = g[j][i] = 1;
      }
    }
  }
  int ans = INF;
  for (int p = 1; p <= k; p++) {
    for (int i = 1; i < p; i++) {
      for (int j = i + 1; j < p; j++) {
        ans = min(ans, g[i][p] + g[p][j] + dis[i][j]);
      }
    }
    for (int i = 1; i <= k; i++) {
      for (int j = 1; j <= k; j++) {
        dis[i][j] = min(dis[i][j], dis[i][p] + dis[p][j]);
      }
    }
  }
  if (ans == INF) {
    ans = -1;
  }
  printf("%d\n", ans);
  return 0;
}
