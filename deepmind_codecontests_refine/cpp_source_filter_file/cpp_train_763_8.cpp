#include <bits/stdc++.h>
using namespace std;
int n, m, deg[1111222];
int main() {
  if (0) {
    freopen("aaa.inp", "r", stdin);
    freopen("aaa.out", "w", stdout);
  };
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++;
    deg[v]++;
  }
  long long z = (long long)n * (n - 1) * (n - 2) / 6;
  long long x = 0, y = 0;
  for (int i = (int)1; i <= (int)n; i++) {
    y += (long long)deg[i] * (deg[i] - 1) / 2;
    deg[i] = n - 1 - deg[i];
    x += (long long)deg[i] * (deg[i] - 1) / 2;
  }
  printf("%i64d\n", (x + y - z) / 2);
  return 0;
};
