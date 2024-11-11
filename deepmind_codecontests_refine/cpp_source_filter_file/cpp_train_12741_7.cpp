#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n, m, x, y, a, b;
  while (cin >> n >> m >> x >> y >> a >> b) {
    int g = gcd(a, b);
    a /= g;
    b /= g;
    int k = min(n / a, m / b);
    int xlen = a * k;
    int ylen = b * k;
    double mincenterx = (double)xlen / 2;
    double mincentery = (double)ylen / 2;
    double maxcenterx = n - (double)xlen / 2;
    double maxcentery = m - (double)ylen / 2;
    double centerx, centery;
    if (x < mincenterx + 1e-8)
      centerx = mincenterx;
    else if (x > maxcenterx - 1e-8)
      centerx = maxcenterx;
    else if (xlen % 2 == 0)
      centerx = x;
    else
      centerx = x - 0.5;
    if (y < mincentery + 1e-8)
      centery = mincentery;
    else if (x > maxcentery - 1e-8)
      centery = maxcentery;
    else if (ylen % 2 == 0)
      centery = y;
    else
      centery = y - 0.5;
    cout << (int)(centerx - mincenterx + 1e-8) << " "
         << (int)(centery - mincentery + 1e-8) << " "
         << (int)(centerx + mincenterx + 1e-8) << " "
         << (int)(centery + mincentery + 1e-8) << endl;
  }
  return 0;
}
