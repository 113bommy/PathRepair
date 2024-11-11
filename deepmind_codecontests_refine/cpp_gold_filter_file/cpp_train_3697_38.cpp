#include <bits/stdc++.h>
using namespace std;
int n;
long double x[2020], y[2020];
const long double eps = 1e-14;
int m;
long double a[2020], b[2020];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double q = a * a + b * b;
    x[i] = a * c / q;
    y[i] = b * c / q;
  }
  long long answer = 0;
  for (int i = 1; i <= n; i++) {
    m = 0;
    for (int j = i + 1; j <= n; j++) a[++m] = x[j] - x[i], b[m] = y[j] - y[i];
    for (int j = 1; j < m; j++)
      for (int k = j + 1; k <= m; k++) {
        if (fabs(b[j] * a[k] - a[j] * b[k]) < eps) answer++;
      }
  }
  printf("%I64d\n", answer);
  return 0;
}
