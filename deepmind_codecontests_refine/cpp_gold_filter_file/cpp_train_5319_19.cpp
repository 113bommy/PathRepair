#include <bits/stdc++.h>
using namespace std;
int a[200009], b[200009];
bool ok(int n, int m, double fuel) {
  for (int i = 0; i < n; i++) {
    double required = 1.0 * (m + fuel) / a[i];
    if (required > fuel + 1e-7) return false;
    fuel -= required;
    if (fuel < 0) fuel = 0;
    required = 1.0 * (m + fuel) / b[(i + 1) % n];
    if (required > fuel + 1e-7) return false;
    fuel -= required;
    if (fuel < 0) fuel = 0;
  }
  return true;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  double hi = 1000000001.0, lo = 0;
  for (int i = 0; i < 200; i++) {
    double mi = (hi + lo) / 2.0;
    if (ok(n, m, mi))
      hi = mi;
    else
      lo = mi;
  }
  if (!ok(n, m, hi)) {
    puts("-1");
    return 0;
  }
  printf("%.10lf\n", hi);
}
