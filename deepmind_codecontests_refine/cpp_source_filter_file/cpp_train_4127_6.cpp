#include <bits/stdc++.h>
using namespace std;
clock_t __stt;
inline void TStart() { __stt = clock(); }
inline void TReport() {
  printf("\nTaken Time : %.3lf sec\n",
         (double)(clock() - __stt) / CLOCKS_PER_SEC);
}
template <typename T>
T MIN(T a, T b) {
  return a < b ? a : b;
}
template <typename T>
T MAX(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
T ABS(T a) {
  return a > 0 ? a : (-a);
}
template <typename T>
void UMIN(T &a, T b) {
  if (b < a) a = b;
}
template <typename T>
void UMAX(T &a, T b) {
  if (b > a) a = b;
}
int sx, sy, n, x[25], y[25], c[25][25], v[25][25], dp[16777216];
int ls[16777216];
int main() {
  int i, j, k;
  scanf("%d%d%d", &sx, &sy, &n);
  for (i = 0; i < n; ++i) {
    scanf("%d%d", x + i, y + i);
    x[i] -= sx;
    y[i] -= sy;
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j <= n; ++j) {
      v[i][j] = (1 << i) | (1 << j);
      c[i][j] = x[i] * x[i] + y[i] * y[i] + x[j] * x[j] + y[j] * y[j] +
                (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    }
    v[i][n] = (1 << i);
  }
  fill(dp, dp + (1 << n), 2000000000);
  dp[0] = 0;
  for (i = 0; i < (1 << n) - 1; ++i) {
    for (j = 0; j < n; ++j)
      if (!(i & (1 << j))) break;
    for (k = j + 1; j <= n; ++j) {
      if (!(i & (1 << k)) && dp[i] + c[j][k] < dp[i | v[j][k]]) {
        dp[i | v[j][k]] = dp[i] + c[j][k];
        ls[i | v[j][k]] = k * n + j;
      }
    }
  }
  printf("%d\n0", dp[(1 << n) - 1]);
  for (i = (1 << n) - 1; i;) {
    j = ls[i] % n;
    k = ls[i] / n;
    i ^= (1 << j);
    if (k < n) i ^= (1 << k);
    if (k == n)
      printf(" %d 0", j + 1);
    else
      printf(" %d %d 0", j + 1, k + 1);
  }
  printf("\n");
  return 0;
}
