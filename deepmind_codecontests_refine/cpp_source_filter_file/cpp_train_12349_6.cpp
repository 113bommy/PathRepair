#include <bits/stdc++.h>
using namespace std;
int n, m;
double f[56][5678];
int A[56], B[56], P[56];
bool CK(double mx) {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m + 1; j <= 5000; j++) f[i + 1][j] = mx;
    for (int j = 0; j <= m; j++)
      f[i][j] = min(
          mx, (f[i + 1][j + A[i + 1]] + A[i + 1]) * P[i + 1] / 100 +
                  (f[i + 1][j + B[i + 1]] + B[i + 1]) * (100 - P[i + 1]) / 100);
  }
  return f[0][0] < mx;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &A[i], &B[i], &P[i]);
  double l = 0, r = 1e9, mid;
  while (r - l > 1e-8) {
    mid = (l + r) / 2;
    if (CK(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.6lf", l);
}
