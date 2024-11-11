#include <bits/stdc++.h>
using namespace std;
const int SIGMA_SIZE = 26;
const int MAXNODE = 111000;
const int MAXS = 150 + 10;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
int n, p, q;
double f(double x) {
  double y = 1;
  for (int i = 0; i < n; i++) y = min(y, (1.0 - x * b[i]) / a[i]);
  return y * p + x * q;
}
int main() {
  cin >> n >> p >> q;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  double l = 0, r = 1. / (*max_element(b, b + n));
  for (int i = 0; i < 200; i++) {
    double ll = (l + l + r) / 3, rr = (r + r + l) / 3;
    if (f(ll) > f(rr))
      r = rr;
    else
      l = ll;
  }
  printf("%.10f\n", f((l + r) * 0.5));
  return 0;
}
