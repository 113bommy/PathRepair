#include <bits/stdc++.h>
using namespace std;
int X[5010], A[5010], B[5010], C[5010], D[5010];
long long f[5010][5010];
long long _Min(long long x, long long y) { return x < y ? x : y; }
int main() {
  int n, sp, tp, i, j;
  scanf("%d%d%d", &n, &sp, &tp);
  for (i = 1; i <= n; i++) scanf("%d", &X[i]);
  for (i = 1; i <= n; i++) scanf("%d", &C[i]);
  for (i = 1; i <= n; i++) scanf("%d", &D[i]);
  for (i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (i = 1; i <= n; i++) scanf("%d", &B[i]);
  if (sp > tp) {
    int t = sp;
    sp = tp;
    tp = t;
    for (i = 1; i <= n; i++) {
      t = A[i];
      A[i] = C[i];
      C[i] = t;
      t = B[i];
      B[i] = D[i];
      D[i] = t;
    }
  }
  memset(f, 63, sizeof(f));
  f[0][0] = 0;
  for (i = 1; i < sp; i++) {
    for (j = 0; j <= n; j++) {
      if (j > 0 && (j > 1 || i == 1))
        f[i][j] = _Min(f[i][j], f[i - 1][j - 1] - 2 * X[i] + B[i] + D[i]);
      f[i][j] = _Min(f[i][j], f[i - 1][j + 1] + 2 * X[i] + A[i] + C[i]);
      if (j > 0 || i == 1) f[i][j] = _Min(f[i][j], f[i - 1][j] + A[i] + D[i]);
      if (j > 0 || i == 1) f[i][j] = _Min(f[i][j], f[i - 1][j] + B[i] + C[i]);
    }
  }
  for (i = 1; i <= n; i++) {
    if (i > 1 || sp == 1)
      f[sp][i] = _Min(f[sp][i], f[sp - 1][i - 1] - X[sp] + B[sp]);
    f[sp][i] = _Min(f[sp][i], f[sp - 1][i] + X[sp] + A[sp]);
  }
  for (i = sp + 1; i < tp; i++) {
    for (j = 1; j <= n; j++) {
      if (j > 1)
        f[i][j] = _Min(f[i][j], f[i - 1][j - 1] - 2 * X[i] + B[i] + D[i]);
      f[i][j] = _Min(f[i][j], f[i - 1][j + 1] + 2 * X[i] + A[i] + C[i]);
      if (j > 1) f[i][j] = _Min(f[i][j], f[i - 1][j] + A[i] + D[i]);
      f[i][j] = _Min(f[i][j], f[i - 1][j] + B[i] + C[i]);
    }
  }
  for (i = 0; i <= n; i++) {
    if (i > 0) f[tp][i] = _Min(f[tp][i], f[tp - 1][i] - X[tp] + D[tp]);
    f[tp][i] = _Min(f[tp][i], f[tp - 1][i + 1] + X[tp] + C[tp]);
  }
  for (i = tp + 1; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      if (j > 1)
        f[i][j] = _Min(f[i][j], f[i - 1][j - 1] - 2 * X[i] + B[i] + D[i]);
      f[i][j] = _Min(f[i][j], f[i - 1][j + 1] + 2 * X[i] + A[i] + C[i]);
      if (j > 0) f[i][j] = _Min(f[i][j], f[i - 1][j] + A[i] + D[i]);
      if (j > 0) f[i][j] = _Min(f[i][j], f[i - 1][j] + B[i] + C[i]);
    }
  }
  printf("%I64d\n", f[n][0]);
  return 0;
}
