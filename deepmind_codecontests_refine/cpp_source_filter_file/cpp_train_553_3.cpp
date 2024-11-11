#include <bits/stdc++.h>
using namespace std;
const int N = 66;
int d[N][N][N];
int f[N][N][N];
int main() {
  int n, m, qq;
  scanf("%d %d %d", &n, &m, &qq);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        scanf("%d", &d[i][j][k]);
      }
    }
  }
  for (int car = 0; car < m; ++car) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          d[car][i][j] = min(d[car][i][j], d[car][i][k] + d[car][k][j]);
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      f[1][i][j] = 1e9;
      for (int car = 0; car < m; ++car) {
        f[1][i][j] = min(f[1][i][j], d[car][i][j]);
      }
    }
  }
  for (int changes = 2; changes <= n; ++changes) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        f[changes][i][j] = 1e9;
        for (int k = 0; k < n; ++k) {
          f[changes][i][j] =
              min(f[changes][i][j], f[changes - 1][i][k] + f[1][k][j]);
        }
      }
    }
  }
  while (qq--) {
    int x, y, k;
    scanf("%d %d %d", &x, &y, &k);
    printf("%d\n", f[min(n, k + 1)][x - 1][y - 1]);
  }
  return 0;
}
