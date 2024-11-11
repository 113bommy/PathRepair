#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, R;
  cin >> n >> R;
  vector<double> a(n + 5), b(n + 5), c(n + 5);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    c[i] /= 100.0;
  }
  auto ck = [&](double mid) {
    vector<vector<double>> f(n + 5, vector<double>(5105));
    for (int i = n; i >= 1; --i) {
      for (int j = 0; j <= R; ++j) {
        for (int j = R + 1; j <= R + 100; ++j) f[i + 1][j] = mid;
        f[i][j] = min(mid, (f[i + 1][j + a[i]] + a[i]) * c[i] +
                               (f[i + 1][j + b[i]] + b[i]) * (1.0 - c[i]));
      }
    }
    return mid <= f[1][0];
  };
  auto bf = [&]() {
    double l = 0, r = 1e9;
    for (int i = 50; i; --i) {
      double mid = (l + r) / 2.0;
      if (ck(mid))
        l = mid;
      else
        r = mid;
    }
    printf("%.12f", l);
  };
  bf();
  return 0;
}
