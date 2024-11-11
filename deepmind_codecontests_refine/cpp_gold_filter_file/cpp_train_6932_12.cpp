#include <bits/stdc++.h>
using namespace std;
long long gcdext(long long a, long long b, long long& x, long long& y) {
  long long r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
  r2 = a, x2 = 1, y2 = 0, r1 = b, x1 = 0, y1 = 1;
  while (r1) {
    q = r2 / r1, r0 = r2 % r1;
    x0 = x2 - q * x1, y0 = y2 - q * y1;
    r2 = r1, x2 = x1, y2 = y1;
    r1 = r0, x1 = x0, y1 = y0;
  }
  long long g = r2;
  x = x2, y = y2;
  if (g < 0) g = -g, x = -x, y = -y;
  return g;
}
long long A, B, C;
int main() {
  cin >> A >> B >> C;
  C *= -1;
  long long x, y, G = gcdext(A, B, x, y);
  if (C % G == 0)
    cout << x * C / G << ' ' << y * C / G << '\n';
  else
    cout << -1 << '\n';
}
