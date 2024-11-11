#include <bits/stdc++.h>
using namespace std;
int n, k;
long double l, v1, v2;
bool ok(long double T, int g) {
  long double tb = (l - v1 * T) / (v2 - v1);
  long double tp = (tb * (v2 - v1)) / (v2 + v1);
  if (tb + (tb + tp) * (g - 1) <= T) return 1;
  return 0;
}
int main() {
  cin >> n >> l >> v1 >> v2 >> k;
  n = (n + k - 1) / k;
  long double hi = 1e10, lo = 0;
  for (int i = (0); i < (100); i++) {
    long double mid = (hi + lo) / 2.0;
    if (ok(mid, n))
      hi = mid;
    else
      lo = mid;
  }
  printf("%.12lf", (double)hi);
  return 0;
}
