#include <bits/stdc++.h>
using namespace std;
int i, j, n, a[1000001], b[1000001];
double p, q, l, r;
double cost(double x) {
  double Min = 1;
  for (int i = 0; i < n; i++) {
    Min = min(Min, (1.0 - x * b[i]) / a[i]);
  }
  return (p * Min + x * q);
}
int main() {
  cin >> n >> p >> q;
  for (i = 0; i < n; i++) cin >> a[i] >> b[i];
  l = 0;
  r = 1. / (*max_element(b, b + n));
  while (r - l > 1e-16) {
    double midl = l + (r - l) / 3;
    double midr = l + (r - l) * 2 / 3;
    if (cost(midl) < cost(midr)) {
      l = midl;
    } else
      r = midr;
  }
  printf("%.10f", cost(l));
}
