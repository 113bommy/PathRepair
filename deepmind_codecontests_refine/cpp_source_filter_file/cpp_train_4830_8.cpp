#include <bits/stdc++.h>
using namespace std;
complex<double> a[205], A, B;
int n;
int R() { return (rand() << 16 + rand()); }
int main() {
  scanf("%d", &n);
  srand(6);
  if (n <= 4) return puts("No solution");
  double pi = acos(-1.), theta = pi * 2 / n, r = 100 * n;
  for (int i = 0; i < n; i++) a[i] = polar(r, theta * i);
  for (int i = 1; i + 1 < n; i += 2) {
    double x = (R() % (10000 * n) - 5000 * n) / 10000.;
    A = a[i - 1], B = i + 2 < n ? a[i + 2] : a[0];
    a[i] = A + (x / abs(a[i] - A) + 1) * (a[i] - A),
    a[i + 1] = B + (x / abs(a[i + 1] - B) + 1) * (a[i + 1] - B);
  }
  for (int i = 0; i < n; i++) printf("%.9lf %.9lf\n", a[i].real(), a[i].imag());
  return 0;
}
