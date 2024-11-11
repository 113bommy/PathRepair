#include <bits/stdc++.h>
using namespace std;
const double eps = -1e12;
const int N = 100100;
int i, j, k, n;
double A, B, C, d, sa[N], sb[N], a[N], b[N];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%lf", &sa[i]), sa[i] += sa[i - 1];
  for (i = 1; i <= n; i++) scanf("%lf", &sb[i]);
  for (i = n - 1; i; i--) sb[i] += sb[i + 1];
  for (i = 1; i <= n; i++) {
    A = sa[i];
    B = sb[i + 1];
    C = A - B + 1;
    d = C * C - 4.0 * A;
    if (d < eps)
      d = 0.0;
    else
      d = sqrt(d);
    a[i] = 0.5 * (C - d);
    b[i] = 0.5 * (C + d);
  }
  for (i = n; i; i--) a[i] -= a[i - 1];
  for (i = n; i; i--) b[i] -= b[i - 1];
  for (i = 1; i < n; i++) printf("%.9lf ", a[i]);
  printf("%.9lf\n", a[n]);
  for (i = 1; i < n; i++) printf("%.9lf ", b[i]);
  printf("%.9lf\n", b[n]);
}
