#include <bits/stdc++.h>
using namespace std;
const int m = 50;
struct M {
  double v[60][60];
  M() { memset(v, 0, sizeof(v)); }
  double *operator[](const int &a) { return v[a]; }
  M operator*(const M &a) const {
    M b;
    int i, j, k;
    for (i = 0; i <= m; i++)
      for (j = 0; j <= m; j++)
        for (k = 0; k <= m; k++) b.v[i][j] += v[i][k] * a.v[k][j];
    return b;
  }
} S, T;
double p, a[60][60], b[60][60], f[60][60];
int n;
inline void pm(int y) {
  while (y) {
    if (y & 1) S = S * T;
    T = T * T, y >>= 1;
  }
}
int main() {
  int i, j, k, t;
  double tmp;
  scanf("%d%d", &n, &t), p = t * 1e-9;
  a[1][1] = p, a[1][2] = 1 - p;
  b[1][2] = 1 - p;
  for (i = 2; i <= m; i++) {
    a[i][1] = p, a[i][2] = 1 - p, b[i][2] = 1 - p;
    for (j = 2; j <= i; j++)
      a[i][j] += a[i][j - 1] * a[i - 1][j - 1],
          b[i][j] += b[i][j - 1] * a[i - 1][j - 1];
  }
  for (i = m; i >= 1; i--)
    for (j = 1; j <= m; j++)
      a[i][j] *= 1 - a[i - 1][j], b[i][j] *= 1 - a[i - 1][j];
  f[1][1] = 1, f[1][2] = 2;
  for (i = 2; i <= m; i++) {
    for (j = 2; j <= m; j++) {
      tmp = 0;
      for (k = 1; k < j; k++)
        f[i][j] += f[i - 1][k] * a[i - 1][k], tmp += a[i - 1][k];
      f[i][j] = f[i][j] / tmp + j;
    }
    tmp = 0;
    for (k = 2; k <= m; k++)
      f[i][1] += f[i - 1][k] * b[i - 1][k], tmp += b[i - 1][k];
    f[i][1] = f[i][1] / tmp + 1;
  }
  if (n <= m) {
    tmp = 0;
    for (i = 1; i <= n + 1; i++) tmp += f[n][i] * a[n][i];
    printf("%.12lf", tmp);
    return 0;
  }
  S[0][0] = T[0][0] = 1;
  for (i = 2; i <= m; i++) {
    tmp = 0;
    for (j = 1; j < i; j++) T[j][i] += a[m][j], tmp += a[m][j];
    for (j = 1; j < i; j++) T[j][i] /= tmp;
    T[0][i] = i;
  }
  tmp = 0;
  for (i = 2; i <= m; i++) T[i][1] += b[m][i], tmp += b[m][i];
  for (i = 2; i <= m; i++) T[i][1] /= tmp;
  T[0][1] = 1;
  for (i = 1; i <= m; i++) S[0][i] = f[m][i];
  pm(n - m);
  tmp = 0;
  for (i = 1; i <= m; i++) tmp += S[0][i] * a[m][i];
  printf("%.12lf", tmp);
  return 0;
}
