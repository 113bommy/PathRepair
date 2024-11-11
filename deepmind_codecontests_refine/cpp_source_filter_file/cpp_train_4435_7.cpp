#include <bits/stdc++.h>
using namespace std;
double n, h;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> h;
  for (int i = 1; i < n; ++i) {
    double l = 0, r = h;
    for (int j = 1; j <= 100; ++j) {
      double x = (l + r) / 2;
      double p = x * x / h;
      if (p * n / i > h)
        r = x;
      else
        l = x;
    }
    cerr << setprecision(10) << fixed << l << " ";
  }
}
