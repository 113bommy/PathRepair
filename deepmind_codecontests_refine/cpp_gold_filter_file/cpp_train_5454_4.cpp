#include <bits/stdc++.h>
using namespace std;
const double eps = 1.0e-11;
const double pi = acos(-1.0);
long long gcd(long long a, long long b) {
  while (a && b) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}
int main() {
  long long n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  long long g = gcd(a, b);
  a /= g;
  b /= g;
  long long c = min(n / a, m / b);
  long long w = a * c;
  long long h = b * c;
  long long x1 = x - (w + 1) / 2;
  long long y1 = y - (h + 1) / 2;
  long long x2 = x1 + w;
  long long y2 = y1 + h;
  if (x1 < 0) {
    x2 -= x1;
    x1 = 0;
  }
  if (y1 < 0) {
    y2 -= y1;
    y1 = 0;
  }
  if (x2 > n) {
    x1 += (n - x2);
    x2 = n;
  }
  if (y2 > m) {
    y1 += (m - y2);
    y2 = m;
  }
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  return 0;
}
