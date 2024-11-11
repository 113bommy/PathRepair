#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main() {
  ios::sync_with_stdio(false);
  int n, p, q;
  cout << fixed << setprecision(10);
  cin >> n >> p >> q;
  vector<int> a(n), b(n);
  int l = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    l = max(l, a[i]);
  }
  auto get = [&](double x) {
    double f = 1e18;
    for (int i = 0; i < n; i++) {
      f = min(f, (1 - x * a[i]) / b[i]);
    }
    return x * p + f * q;
  };
  double x = 0, y = 1.0 / l;
  for (int i = 0; i < 60; i++) {
    double dx = x + (y - x) / 3, dy = y - (y - x) / 3;
    if (get(dx) > get(dy)) {
      y = dy;
    } else
      x = dx;
  }
  cout << get(y) << '\n';
  return 0;
}
