#include <bits/stdc++.h>
using namespace std;
const int M = 34567;
int g(int a, int b) {
  if (a == 0) return b;
  return g(b % a, a);
}
int main() {
  int n, m, x, y, a, b, k, w, h, x1, x2, y1, y2;
  cin >> n >> m >> x >> y >> a >> b;
  int t = g(a, b);
  a /= t;
  b /= t;
  k = min(n / a, m / b);
  w = k * a;
  h = k * b;
  double tx = x, ty = y;
  if (w % 2) tx -= 0.5;
  if (h % 2) ty -= 0.5;
  x1 = int(tx - w * 1.0 / 2);
  x2 = int(tx + w * 1.0 / 2);
  y1 = int(ty - h * 1.0 / 2);
  y2 = int(ty + h * 1.0 / 2);
  if (x1 < 0) x2 -= x1, x1 = 0;
  if (x2 > n) x1 -= x2 - n, x2 = n;
  if (y1 < 0) y2 -= y1, y1 = 0;
  if (y2 > n) y1 -= y2 - n, y2 = n;
  cout << x1 << " " << y1 << " " << x2 << " " << y2;
}
