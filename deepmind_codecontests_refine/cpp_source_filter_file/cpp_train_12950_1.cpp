#include <bits/stdc++.h>
using namespace std;
int n, x, a[34][34];
namespace pendejo {
int b[34][34], ans = -0x7fffffff;
int check(int y) {
  int i, j, k, l;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) b[i][j] = a[i][j];
  int s = 0;
  for (i = 1; i <= x; i++)
    for (j = 1; j <= x; j++)
      if (y & (1 << ((i - 1) * x + j) >> 1))
        for (k = i; k < i + x; k++)
          for (l = i; l < j + x; l++) b[k][l] = -b[k][l];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) s += b[i][j];
  return s;
}
void work() {
  int i;
  for (i = 0; i < (1 << (x * x)); i++) ans = max(ans, check(i));
  printf("%d\n", ans);
}
}  // namespace pendejo
namespace gzotpa {
int b[34][34], ans = -0x7fffffff;
int getrowmx(int p) {
  int i, j, mx = -0x7fffffff;
  int q = p + x;
  int A = 1, D = 1 * b[x][x];
  int sum = A * a[x][p] + D * a[x][p + x];
  for (i = 1; i < x; i++) {
    int Q1 = 1, E1 = Q1 * b[i][x], Z1 = Q1 * A, C1 = E1 * A;
    int Q2 = -1, E2 = Q2 * b[i][x], Z2 = Q2 * D, C2 = E2 * D;
    sum += max(Q1 * a[i][p] + Z1 * a[i + x][p] + E1 * a[i][p + x] +
                   C1 * a[i + x][p + x],
               Q2 * a[i][p] + Z2 * a[i + x][p] + E2 * a[i][p + x] +
                   C2 * a[i + x][p + x]);
  }
  mx = max(mx, sum);
  A = -1, D = -1 * b[x][x];
  sum = A * a[x][p] + D * a[x][p + x];
  for (i = 1; i < x; i++) {
    int Q1 = 1, E1 = Q1 * b[i][x], Z1 = Q1 * A, C1 = E1 * A;
    int Q2 = -1, E2 = Q2 * b[i][x], Z2 = Q2 * D, C2 = E2 * D;
    sum += max(Q1 * a[i][p] + Z1 * a[i + x][p] + E1 * a[i][p + x] +
                   C1 * a[i + x][p + x],
               Q2 * a[i][p] + Z2 * a[i + x][p] + E2 * a[i][p + x] +
                   C2 * a[i + x][p + x]);
  }
  mx = max(mx, sum);
  return mx;
}
int check(int y) {
  int i, s = 0;
  for (i = 1; i <= x; i++) {
    if (y & (1 << i >> 1))
      b[i][x] = -1;
    else
      b[i][x] = 1;
  }
  for (i = x + 1; i <= n; i++) b[i][x] = b[i - x][x] * b[x][x];
  for (i = 1; i <= n; i++) s += b[i][x] * a[i][x];
  for (i = 1; i < x; i++) s += getrowmx(i);
  return s;
}
void work() {
  int i, j;
  for (i = 0; i < (1 << x); i++) ans = max(ans, check(i));
  printf("%d\n", ans);
}
}  // namespace gzotpa
int main() {
  int i, j;
  scanf("%d", &n);
  x = (n + 1) >> 1;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  if (n <= 7) {
    using namespace pendejo;
    work();
  } else {
    using namespace gzotpa;
    work();
  }
  return 0;
}
