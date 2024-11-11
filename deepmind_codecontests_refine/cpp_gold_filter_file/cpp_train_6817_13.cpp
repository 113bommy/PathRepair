#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 11;
double dp1[N][N][N];
double dp2[N][N][N];
int f[N][N][N];
void dfs(int x, int y, int z) {
  if (f[x][y][z] == 1) return;
  f[x][y][z] = 1;
  if (x == y && y == z) {
    dp1[x][y][z] = 1.0 / 3.0;
    dp2[x][y][z] = 1.0 / 3.0;
    return;
  }
  if (x == 0) {
    dp1[x][y][z] = 0.0;
    if (y == 0) {
      dp2[x][y][z] = 0.0;
    } else {
      dp2[x][y][z] = 1.0;
    }
    return;
  }
  if (y == 0) {
    dp2[x][y][z] = 0.0;
    if (z == 0) {
      dp1[x][y][z] = 1.0;
    } else {
      dp1[x][y][z] = 0.0;
    }
    return;
  }
  if (z == 0) {
    if (x == 0) {
      dp1[x][y][z] = 0.0;
      dp2[x][y][z] = 1.0;
    } else {
      dp1[x][y][z] = 1.0;
      dp2[x][y][z] = 0.0;
    }
    return;
  }
  dfs(x - 1, y, z);
  dfs(x, y - 1, z);
  dfs(x, y, z - 1);
  double n = x + y + z;
  double sum = 1.0 * x * z + 1.0 * x * y + 1.0 * y * z;
  dp1[x][y][z] = (x * z * dp1[x - 1][y][z] + x * y * dp1[x][y - 1][z] +
                  y * z * dp1[x][y][z - 1]) /
                 sum;
  dp2[x][y][z] = (x * z * dp2[x - 1][y][z] + x * y * dp2[x][y - 1][z] +
                  y * z * dp2[x][y][z - 1]) /
                 sum;
}
int main() {
  memset(f, 0, sizeof(f));
  int x, y, z;
  while (3 == scanf("%d%d%d", &x, &y, &z)) {
    dfs(x, y, z);
    printf("%.12f %.12f %.12f\n", dp1[x][y][z], dp2[x][y][z],
           1 - dp1[x][y][z] - dp2[x][y][z]);
  }
  return 0;
}
