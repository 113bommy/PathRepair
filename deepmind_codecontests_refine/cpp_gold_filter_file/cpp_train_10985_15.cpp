#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
double p[N], q[N];
double a[N], b[N];
void gg(double A, double B, double C, double &x) {
  double D = B * B - 4 * A * C;
  if (D < 0) D = 0;
  x = (-B + sqrt(D)) / A / 2;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  for (int i = 1; i <= n; ++i) cin >> q[i];
  double suma = 0, sumb = 0;
  for (int i = n; i; --i) {
    double x;
    gg(-1, sumb + q[i] + p[i] - suma, suma * (p[i] + q[i]) - q[i], x);
    double y = q[i] + p[i] - x;
    a[i] = x;
    b[i] = y;
    suma += x;
    sumb += y;
  }
  for (int i = 1; i <= n; ++i) printf("%.8f ", a[i]);
  printf("\n");
  for (int i = 1; i <= n; ++i) printf("%.8f ", b[i]);
  printf("\n");
  return 0;
}
