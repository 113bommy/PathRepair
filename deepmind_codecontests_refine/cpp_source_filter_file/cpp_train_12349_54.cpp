#include <bits/stdc++.h>
using namespace std;
const int M = 5005, N = 60;
double f[N][M], p[N];
int a[N], b[N];
int n, r;
inline int ck(double mid) {
  for (int i = n - 1; i >= 0; i--) {
    for (int j = r + 1; j < M; j++) f[i + 1][j] = mid;
    for (int j = 0; j <= r; j++) {
      f[i][j] =
          min(mid, p[i] / 100.0 * (f[i + 1][j + a[i]] + a[i]) +
                       (1.0 - p[i] / 100.0) * (f[i + 1][j + b[i]] + b[i]));
    }
  }
  return f[0][0] < mid;
}
int main() {
  scanf("%d%d", &n, &r);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%lf", &a[i], &b[i], &p[i]);
  }
  double l = 0, r = 1e11, mid = 0;
  while (r - l < 1e-10) {
    mid = 0.5 * (l + r);
    if (ck(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.9lf", mid);
  return 0;
}
