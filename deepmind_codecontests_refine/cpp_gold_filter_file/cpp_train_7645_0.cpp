#include <bits/stdc++.h>
using namespace std;
double n, m;
double v[100002], pw;
double logpow(double a, int b) {
  double p = 1;
  while (b) {
    if (b & 1) p = p * a;
    a = a * a;
    (b >>= 1);
  }
  return p;
}
int main() {
  cin >> m >> n;
  pw = 1;
  for (int i = 1; i <= n; i++) pw /= m;
  double ans = 0;
  for (int i = 1; i <= m; i++) {
    v[i] = logpow(i / m, n);
    ans += 1.0 * i * (v[i] - v[i - 1]);
  }
  cout << fixed << setprecision(10) << ans;
  return 0;
}
