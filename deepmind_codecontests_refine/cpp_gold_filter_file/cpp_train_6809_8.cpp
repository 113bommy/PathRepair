#include <bits/stdc++.h>
using namespace std;
const int N = 305;
bool g[N][N];
int n, m, k, a[N], ta[N];
void run() {
  scanf("%d%d%d", &n, &m, &k);
  int x, y, z;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < k; i++) {
    scanf("%d", &ta[i]);
    a[ta[i]] = 1;
  }
  memset(g, true, sizeof(g));
  sort(ta, ta + k);
  z = -1;
  for (int i = 1; i <= n; i++)
    if (!a[i]) {
      x = ta[0];
      y = ta[1];
      z = i;
      break;
    }
  if (z == -1) {
    printf("-1\n");
    return;
  }
  g[x][y] = g[y][x] = false;
  for (int i = 1; i <= n; i++) {
    if (i == x || i == y || i == z || !a[i]) continue;
    g[i][x] = g[x][i] = false;
  }
  int res = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) res += g[i][j];
  res /= 2;
  if (res >= m) {
    res = m;
    printf("%d %d\n", x, z);
    g[x][z] = g[z][x] = false;
    --res;
    printf("%d %d\n", z, y);
    g[z][y] = g[y][z] = false;
    --res;
    for (int i = 1; i <= n; i++) {
      if (i == x || i == y || i == z) continue;
      printf("%d %d\n", i, y);
      g[i][y] = g[y][i] = false;
      --res;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++)
        if (g[i][j] && res > 0) {
          printf("%d %d\n", i, j);
          --res;
          if (res == m) break;
        }
      if (res == m) break;
    }
  } else
    printf("-1\n");
}
int main() {
  run();
  return 0;
}
