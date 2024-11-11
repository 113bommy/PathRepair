#include <bits/stdc++.h>
using namespace std;
double n, l, v1, v2, k;
bool f(double t) {
  int z = (n + k - 1) / k;
  double p = (t * v2) / (z + (z - 1) * ((v2 - v1) / (v2 + v1)));
  double t_in_bus = p / v2;
  double t_walking = t - t_in_bus;
  double potential_s = t_in_bus * v2 + t_walking * v1;
  if (potential_s >= l) {
    return true;
  } else {
    return false;
  }
}
int main() {
  cin >> n >> l >> v1 >> v2 >> k;
  double lo = 0, hi = l / v1 + 1;
  double EPS = 10e-7;
  int count = 0;
  while (lo + EPS < hi) {
    double mid = lo + (hi - lo) / 2;
    bool res = f(mid);
    if (res) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << std::setprecision(10) << hi << endl;
  return 0;
}
