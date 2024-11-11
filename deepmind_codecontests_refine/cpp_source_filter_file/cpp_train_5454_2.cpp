#include <bits/stdc++.h>
using namespace std;
double min(double a, double b) {
  if (a < b)
    return a;
  else
    return b;
}
double max(double a, double b) {
  if (a > b)
    return a;
  else
    return b;
}
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  int g = gcd(a, b);
  a = a / g, b = b / g;
  int coeff = min(n / a, m / b);
  int c = coeff * a, d = coeff * b;
  double cx, cy;
  cx = min(n - c / 2.0, x);
  cy = min(m - d / 2.0, y);
  cx = max(c / 2.0, x);
  cy = max(d / 2.0, y);
  if (cx == x && cy == y) {
    cx = (c % 2 ? x - 0.5 : x);
    cy = (d % 2 ? y - 0.5 : y);
  }
  int x1, y1, x2, y2;
  x1 = cx - c / 2.0, y1 = cy - d / 2.0;
  x2 = x1 + c, y2 = y1 + d;
  cout << x1 << " " << y1 << " " << x2 << " " << y2;
  return 0;
}
