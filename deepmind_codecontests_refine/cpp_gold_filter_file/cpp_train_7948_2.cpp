#include <bits/stdc++.h>
using namespace std;
long long f[105], A, B, X, Y, x[105], y[105];
int i, Q, n, X1[105], Y1[105], X2[105], Y2[105], j, Y3[105];
int work(long long a, long long b, int c, int d) {
  if (a == b) return 0;
  if (c <= 0) return 1;
  if ((a == f[c] && b == 1 || b == f[c] && a == 1) && Y3[c]) return Y3[c];
  if (a == 1 && Y1[c] && b == y[c]) return Y1[c];
  if (a == f[c] && Y2[c] && b == y[c]) return Y2[c];
  if (b == 1 && X1[c] && a == x[c]) return X1[c];
  if (b == f[c] && X2[c] && a == x[c]) return X2[c];
  int Q = 453266144;
  if (a > f[c - 1] && b > f[c - 1]) {
    Q = min(Q, work(a - f[c - 1], b - f[c - 1], c - 2, d));
    return Q;
  }
  if (a <= f[c - 1] && b > f[c - 1]) {
    Q = min(Q, min(work(a, 1, c - 1, d), work(a, f[c - 1], c - 1, d)) +
                   work(1, b - f[c - 1], c - 2, d) + 1);
    return Q;
  }
  if (a > f[c - 1] && b <= f[c - 1]) {
    Q = min(Q, min(work(1, b, c - 1, d), work(f[c - 1], b, c - 1, d)) +
                   work(a - f[c - 1], 1, c - 2, d) + 1);
    return Q;
  }
  Q = min(work(a, 1, c - 1, d), work(a, f[c - 1], c - 1, d)) +
      min(work(1, b, c - 1, d), work(f[c - 1], b, c - 1, d)) + 2;
  Q = min(Q, work(a, b, c - 1, d));
  return Q;
}
int main() {
  f[0] = 2;
  f[1] = 3;
  for (i = 2; i <= 80; i++) f[i] = f[i - 1] + f[i - 2];
  for (i = 0; i <= 78; i++) Y3[i] = work(f[i], 1, i, 1);
  cin >> Q >> n;
  n--;
  while (Q--) {
    scanf("%I64d%I64d", &A, &B);
    if (A > B) swap(A, B);
    for (i = 0; i <= 80; i++) X1[i] = X2[i] = Y1[i] = Y2[i] = 0;
    for (i = 80; i >= 0; i--)
      if (f[i] < B) break;
    i++;
    X = A;
    Y = B;
    if (i < n) i++;
    for (j = i; j >= 0; j--) {
      if (X > f[j]) X -= f[j];
      if (Y > f[j]) Y -= f[j];
      x[j] = X;
      y[j] = Y;
    }
    j = i;
    for (i = 0; i <= j; i++)
      Y1[i] = work(1, y[i], i, 1), Y2[i] = work(f[i], y[i], i, 2),
      X1[i] = work(x[i], 1, i, 3), X2[i] = work(x[i], f[i], i, 4);
    printf("%d\n", work(A, B, j, 1));
  }
  return 0;
}
