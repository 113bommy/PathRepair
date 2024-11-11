#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b) {
    swap(a %= b, b);
  }
  return a;
}
long long n, m, x, y, a, b, g;
double dist1(long long curstep) {
  long long l1 = a / g * curstep;
  long long l2 = b / g * curstep;
  long long x1 = max(1ll, (x - (l1 - l1 / 2)));
  if (x1 + l1 > n) {
    x1 = n - l1;
  }
  long long x2 = x1 + l1;
  long long y1 = max(1ll, (y - (l2 - l2 / 2)));
  if (y1 + l2 > m) {
    y1 = m - l2;
  }
  long long y2 = y1 + l2;
  double c1 = (x1 + x2 + .0) / 2;
  double c2 = (y1 + y2 + .0) / 2;
  double tempdst = sqrt((c1 - x) * (c1 - x) + (c2 - y) * (c2 - y));
  return tempdst;
}
int main() {
  cin >> n >> m >> x >> y >> a >> b;
  g = gcd(a, b);
  a /= g;
  b /= g;
  long long step = min(n / a, m / b);
  a *= step;
  b *= step;
  long long l1 = a;
  long long l2 = b;
  long long x1 = max(0ll, (x - (l1 - l1 / 2)));
  if (x1 + l1 > n) {
    x1 = n - l1;
  }
  long long x2 = x1 + l1;
  long long y1 = max(0ll, (y - (l2 - l2 / 2)));
  if (y1 + l2 > m) {
    y1 = m - l2;
  }
  long long y2 = y1 + l2;
  cout << x1 << ' ';
  cout << y1 << ' ';
  cout << x2 << ' ';
  cout << y2;
  return 0;
}
