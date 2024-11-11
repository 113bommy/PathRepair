#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  long long ans = 0;
  const double xx = 100., yy = 100 * sqrt(3);
  for (int i = m + 1; i <= n - m; i++) {
    double x1 = xx * i, y1 = yy * i;
    for (int j = m + 1; j <= n - m; j++) {
      double x2 = 200 * (n + 1) - xx * j, y2 = yy * j;
      double res = x1 + y1 * (y1 - y2) / (x1 - x2);
      ans += max(0, min(n - m, (int)(res / 200 - 5e-8)) - m);
    }
  }
  cout << 3 * ans;
  return 0;
}
