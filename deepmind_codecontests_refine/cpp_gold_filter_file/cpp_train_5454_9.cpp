#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  int d = gcd(a, b);
  a /= d;
  b /= d;
  int l = 1, r = (int)1e9 + 10;
  while (l < r) {
    int mid = l + r >> 1;
    long long w = 1LL * mid * a;
    long long h = 1LL * mid * b;
    if (w <= n && h <= m) {
      l = mid + 1;
    } else
      r = mid;
  }
  int w = (l - 1) * a;
  int h = (l - 1) * b;
  int x1 = x - w / 2;
  if (w & 1) x1--;
  int x2 = x + w / 2;
  int y1 = y - h / 2;
  if (h & 1) y1--;
  int y2 = y + h / 2;
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
}
