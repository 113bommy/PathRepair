#include <bits/stdc++.h>
using namespace std;
int N;
int xi[111], eta[111], zeta[111];
pair<double, int> farthest(double x, double y, double z) {
  double opt = -1;
  int ret = -1;
  for (int i = 0; i < int(N); ++i) {
    double x0 = x - xi[i], y0 = y - eta[i], z0 = z - zeta[i];
    double d = sqrt(x0 * x0 + y0 * y0 + z0 * z0);
    if (d > opt) opt = d, ret = i;
  }
  return make_pair(opt, ret);
}
const double EPS = 1e-8;
int main() {
  cin >> N;
  for (int i = 0; i < int(N); ++i) cin >> xi[i] >> eta[i] >> zeta[i];
  double x = 42, y = 42, z = 42, coeff = 1;
  for (int k = 0; k < int(100000); ++k) {
    int i = farthest(x, y, z).second;
    x = (1 - coeff) * x + coeff * xi[i];
    y = (1 - coeff) * y + coeff * eta[i];
    z = (1 - coeff) * z + coeff * zeta[i];
    coeff *= 0.99;
  }
  printf("%.7f %.7f %.7f\n", x, y, z);
}
