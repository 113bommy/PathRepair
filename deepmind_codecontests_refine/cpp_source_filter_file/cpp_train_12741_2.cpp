#include <bits/stdc++.h>
using namespace std;
long gcd(long m, long n) {
  long temp = m % n;
  if (temp == 0)
    return n;
  else {
    m = n;
    n = temp;
    return gcd(m, n);
  }
}
int main() {
  long n, m, a, b, x, y, p, x1, x2, y1, y2;
  cin >> n >> m >> x >> y >> a >> b;
  long c = gcd(a, b);
  a /= c;
  b /= c;
  p = (n / a > m / b) ? (m / b) : (n / a);
  a *= p;
  b *= p;
  x1 = (x - (a + 1) / 2) >= 0 ? (x - (a + 1) / 2) : 0;
  if (x1 + a <= n)
    x2 = x1 + a;
  else {
    x2 = n;
    x1 = n - x2;
  }
  y1 = (y - (b + 1) / 2) >= 0 ? (y - (b + 1) / 2) : 0;
  if (y1 + b <= m)
    y2 = y1 + b;
  else {
    y2 = m;
    y1 = m - y2;
  }
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
}
