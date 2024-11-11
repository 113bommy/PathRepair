#include <bits/stdc++.h>
static const int MAXN = 500100;
long double min[MAXN], max[MAXN];
long double a[MAXN], b[MAXN];
static const long double eps = 1e-9;
int main() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> max[i];
  for (int i = 0; i < n; ++i) std::cin >> min[i];
  long double sa = 0, sb = 0;
  for (int i = 0; i < n; ++i) {
    long double sum = max[i] + min[i];
    long double B = sa - sb - sum;
    long double C = -sum * sa + max[i];
    long double D = B * B - 4. * C;
    if (D < 1e-12) D = 0;
    long double x1, x2;
    x1 = (-B - sqrtl(D)) / 2.;
    x2 = (-B + sqrtl(D)) / 2.;
    a[i] = x2;
    if (x2 < -eps || x2 > sum + eps) a[i] = x1;
    b[i] = sum - a[i];
    sa += a[i];
    sb += b[i];
  }
  std::cout << std::fixed << std::setprecision(9);
  for (int i = 0; i < n; ++i) std::cout << a[i] << ' ';
  std::cout << std::endl;
  for (int i = 0; i < n; ++i) std::cout << b[i] << ' ';
  std::cout << std::endl;
}
