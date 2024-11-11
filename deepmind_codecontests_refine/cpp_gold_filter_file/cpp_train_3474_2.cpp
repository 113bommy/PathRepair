#include <bits/stdc++.h>
using namespace std;
const int sz = 1024;
const long long int s_c[] = {1, 1, -1, -1, 1, 1, -1};
const int s_x[] = {-1, 1, -2, 1, -2, 0, -1};
const int s_y[] = {0, -1, -1, -2, -2, -3, -3};
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int sgn[] = {+1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, 1, -1, 1, -1};
const int ddx[] = {-1, 0, -1, 0};
const int ddy[] = {-2, -2, -1, -1};
int n, m, k;
long long int mat[sz][sz];
long long int a(int x, int y) {
  return (0 > x || x >= n || 0 > y || y >= m) ? 0 : mat[x][y];
}
long long int sum[sz * 4][sz * 2] = {0LL};
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++) scanf("%lld", &mat[i][j]);
  for (int y = (-m); y < (m); y++)
    for (int x = (-n); x < (n + m); x++) {
      sum[(x) + sz][(y) + sz] = 0LL;
      for (int i = (0); i < (7); i++)
        sum[(x) + sz][(y) + sz] +=
            s_c[i] * sum[(x + s_x[i]) + sz][(y + s_y[i]) + sz];
      for (int i = (0); i < (16); i++)
        sum[(x) + sz][(y) + sz] += sgn[i] * a(x + k * dx[i / 4] + ddx[i % 4],
                                              y + k * dy[i / 4] + ddy[i % 4]);
    }
  long long int max_val = -1LL;
  int xx, yy;
  for (int x = (k - 1); x < (n - k + 1); x++)
    for (int y = (k - 1); y < (m - k + 1); y++)
      if (max_val < sum[(x) + sz][(y) + sz]) {
        max_val = sum[(x) + sz][(y) + sz];
        xx = x;
        yy = y;
      }
  printf("%d %d\n", xx + 1, yy + 1);
  return 0;
}
