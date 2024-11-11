#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
const long double eps = 1e-18;
int n, p, q;
int a[maxn], b[maxn];
long double calc(long double m) {
  long double k = 1e9;
  for (int i = 0; i < n; i++) k = min(k, (1. - a[i] * m) / b[i]);
  return p * m + q * k;
}
int main() {
  int k = 0;
  cin >> n >> p >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    k = max(k, a[i]);
  }
  long double lo = 0, hi = 1. / k;
  while (hi - lo > eps) {
    long double m1 = lo + (hi - lo) / 3, m2 = lo + 2 * (hi - lo) / 3;
    if (calc(m1) > calc(m2))
      hi = m2;
    else
      lo = m1;
  }
  cout << fixed << setprecision(10) << calc(lo) << '\n';
}
