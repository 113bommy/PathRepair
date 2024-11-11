#include <bits/stdc++.h>
using namespace std;
long long ncr(long long n, long long r) {
  long long st = 1;
  for (int i = 1; i <= r; i++) {
    st *= n - i + 1;
    st /= i;
  }
  return st;
}
long long pow2(long long n, long long e) {
  if (e <= 0) return 1;
  long long tmp = pow(n, e / 2);
  tmp = tmp * tmp;
  if (e % 2) tmp *= n;
  return tmp;
}
int main() {
  double px, py, vx, vy, a, b, c, d;
  cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
  complex<double> O = complex<double>(px, py);
  complex<double> v = complex<double>(vx, vy);
  v = v / abs(v);
  complex<double> pts[7];
  pts[0] = O + b * v;
  pts[1] = O + a / 2 * complex<double>(0, 1) * v;
  pts[6] = O + a / 2 * complex<double>(0, -1) * v;
  pts[2] = O + c / 2 * complex<double>(0, 1) * v;
  pts[3] = pts[2] - d * v;
  pts[5] = O + c / 2 * complex<double>(0, -1) * v;
  pts[4] = pts[5] - d * v;
  for (int i = 0; i < 6; i++)
    printf("%.15f %.15f\n", pts[i].real(), pts[i].imag());
}
