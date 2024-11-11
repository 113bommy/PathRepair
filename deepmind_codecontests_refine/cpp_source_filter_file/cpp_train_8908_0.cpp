#include <bits/stdc++.h>
using namespace std;
const double epsilon = 1e-6;
bool isPossible(double t, int* x, int* v, int n) {
  double from = 0, to = 1e18 + 1e9;
  for (int i = 0; i < n; i++) {
    double currFrom = 1.0 * x[i] - v[i] * t;
    double currTo = 1.0 * x[i] + v[i] * t;
    from = max(from, currFrom);
    to = min(to, currTo);
    if (from - to >= epsilon) return 0;
  }
  return 1;
}
int main() {
  int n;
  scanf(" %d", &n);
  int pos[n], vel[n];
  for (int i = 0; i < n; i++) scanf(" %d", &pos[i]);
  for (int i = 0; i < n; i++) scanf(" %d", &vel[i]);
  double l = 0, r = 1e9;
  while (r - l >= epsilon) {
    double mid = (l + r) / 2;
    if (isPossible(mid, pos, vel, n))
      r = mid;
    else
      l = mid;
  }
  printf("%lf\n", r);
  return 0;
}
