#include <bits/stdc++.h>
using namespace std;
long long nod(long long a, long long b) { return b ? nod(b, a % b) : a; }
int main() {
  long long n, m, x, y, a, b;
  cin >> n >> m >> x >> y >> a >> b;
  long long q = nod(a, b);
  a /= q;
  b /= q;
  long long len = n / a, width = m / b;
  long long k = min(len, width);
  len = k * a;
  width = k * b;
  long long x1, x2, y1, y2;
  if (len % 2 != 0) {
    x1 = x - len / 2 - 1;
    x2 = x + len / 2;
  } else {
    x1 = x - len / 2;
    x2 = x + len / 2;
  }
  if (width % 2 != 0) {
    y1 = x - width / 2 - 1;
    y2 = y + width / 2;
  } else {
    y1 = y - width / 2;
    y2 = y + width / 2;
  }
  if (x1 < 0) {
    x2 += -x1;
    x1 = 0;
  }
  if (x2 > n) {
    x1 -= (x2 - n);
    x2 = n;
  }
  if (y1 < 0) {
    y2 += -y1;
    y1 = 0;
  }
  if (y2 > m) {
    y1 -= (y2 - m);
    y2 = m;
  }
  cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
  return 0;
}
