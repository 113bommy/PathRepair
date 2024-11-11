#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
void doit(int& x1, int& x2, int xx, int x, int n) {
  x1 = x - xx / 2;
  x2 = x + xx / 2;
  if (xx % 2 == 1) x1--;
  if (x1 < 0) {
    x2 -= x1;
    x1 = 0;
  }
  if (x2 > n) {
    x1 -= x2 - n;
    x2 = n;
  }
}
int main() {
  int n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  int t = gcd(a, b);
  int xx = a / t;
  int yy = b / t;
  int x1, x2, y1, y2;
  int i = 0;
  while (++i) {
    if (xx * i > n || yy * i > m) break;
  }
  i--;
  doit(x1, x2, i * xx, x, n);
  doit(y1, y2, i * yy, y, m);
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  return 0;
}
