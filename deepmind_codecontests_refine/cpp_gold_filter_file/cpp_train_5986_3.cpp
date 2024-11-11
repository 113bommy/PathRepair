#include <bits/stdc++.h>
using namespace std;
inline double cro(complex<double> a, complex<double> b) {
  return imag(conj(a) * b);
}
double aPol(vector<complex<double> > p) {
  int n = p.size();
  double ret = 0;
  for (int i = 0; i < (int)(n); i++) ret += cro(p[i], p[(i + 1) % n]) / 2;
  return ret;
}
int N;
long long x[200000], y[200000];
int gcd_(int x, int y) {
  if (y == 0) return x;
  return gcd_(y, x % y);
}
int gcd(int x, int y) {
  if (x < 0) x = -x;
  if (y < 0) y = -y;
  return gcd_(x, y);
}
int main() {
  cin >> N;
  for (int i = 0; i < (int)(N); i++) cin >> x[i] >> y[i];
  for (int i = 0; i < (int)(N); i++) x[i + N] = x[i], y[i + N] = y[i];
  vector<complex<double> > pol;
  for (int i = 0; i < (int)(N); i++) pol.push_back(complex<double>(x[i], y[i]));
  double S = aPol(pol);
  double ans = 0;
  double sum = 0;
  for (int d = 1; d <= (int)(min(40, N - 1)); d++) {
    double app = pow(2, -1 - d) * (1 - pow(2, 1 + d - N));
    for (int i = 0; i < (int)(N); i++) {
      double s = 0;
      for (int j = 0; j < (int)(d); j++)
        s += cro(pol[(i + j) % N], pol[(i + j + 1) % N]);
      s += cro(pol[(i + d) % N], pol[i]);
      s /= 2;
      ans += app * (-s - gcd(x[i] - x[i + d], y[i] - y[i + d]) / 2.0);
      sum += app;
    }
  }
  if (N < 60) ans *= pow(2, N) / (pow(2, N) - 1 - N - N * (N - 1) / 2);
  ans = S + 1 + ans;
  printf("%.12f\n", ans);
}
