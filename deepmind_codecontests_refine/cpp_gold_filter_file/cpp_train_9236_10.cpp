#include <bits/stdc++.h>
using namespace std;
double js(double x, double y, double a, double b) {
  return sqrt((x - a) * (x - a) + (y - b) * (y - b));
}
int abs(int x, int y) {
  if (x > y) return x - y;
  return y - x;
}
int main() {
  double a[1005], b[1005];
  int n, m, k, x, y;
  while (cin >> k >> n >> m) {
    for (int i = 0; i < k; i++) {
      cin >> a[i];
    }
    cin >> x >> y;
    double minx = 0x3f3f3f3f;
    for (int i = 1; i < k; i++) {
      b[i] = (js(x, y, a[i], 0) * 1.0 / m + a[i] * 1.0 / n);
      minx = min(b[i], minx);
    }
    int maxn = 0x3f3f3f3f;
    for (int i = 1; i < k; i++)
      if (fabs(minx - b[i]) < 1e-10 && abs(i, x) < maxn) maxn = i;
    cout << maxn + 1 << endl;
  }
  return 0;
}
