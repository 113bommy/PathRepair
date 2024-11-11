#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
const int MOD = 1000000009;
const int INF = 1000000000;
const long long LINF = 1000000000000000000LL;
vector<complex<double> > vet;
double f(complex<double> p1, complex<double> p2) {
  return p1.real() * p2.imag() - p2.real() * p1.imag();
}
int main() {
  int n;
  double a, x, det, detx;
  scanf("%d", &n);
  if (n <= 4)
    puts("No solution");
  else {
    a = 2.0 * PI / n;
    complex<double> pos(0.0, 0.0), v(750.0, 0.0),
        rot = 0.999 * complex<double>(cos(a), sin(a)), res;
    for (int i = int(0); i <= int(n - 2); i++) {
      if (i) pos += v, v *= rot;
      vet.push_back(pos);
    }
    rot *= v, res = complex<double>(-vet.back().real(), -vet.back().imag()),
              det = f(v, rot), detx = f(res, rot), x = detx / det,
              vet.push_back(vet.back() + x * v);
    for (int i = int(0); i <= int(n - 1); i++)
      printf("%.6f %.6f\n", vet[i].real(), vet[i].imag());
  }
  return 0;
}
