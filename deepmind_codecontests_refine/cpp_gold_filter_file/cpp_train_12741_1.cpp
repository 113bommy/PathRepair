#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, y, a, b, amax, bmax;
  cin >> n >> m >> x >> y >> a >> b;
  for (int i = 2; i * i <= max(a, b); ++i) {
    while (a % i == 0 && b % i == 0) {
      a /= i;
      b /= i;
    }
  }
  int minimal = min(n / a, m / b);
  amax = a * minimal;
  bmax = b * minimal;
  int x1, y1, x2, y2;
  x1 = max(0, x - amax);
  y1 = max(0, y - bmax);
  if (amax % 2 == 0) {
    if (x > (x1 + amax / 2)) {
      x1 += min(x - (x1 + amax / 2), n - (x1 + amax));
    }
  } else {
    if (x > (x1 + amax / 2)) {
      if (x - (x1 + amax / 2) <= n - (x1 + amax))
        x1 += (x - (x1 + amax / 2)) - 1;
      else
        x1 += n - (x1 + amax);
    }
  }
  if (bmax % 2 == 0) {
    if (y > (y1 + bmax / 2)) {
      y1 += min(y - (y1 + bmax / 2), m - (y1 + bmax));
    }
  } else {
    if (y > (y1 + bmax / 2)) {
      if (y - (y1 + bmax / 2) <= m - (y1 + bmax))
        y1 += (y - (y1 + bmax / 2)) - 1;
      else
        y1 += m - (y1 + bmax);
    }
  }
  cout << x1 << " " << y1 << " " << x1 + amax << " " << y1 + bmax;
  return 0;
}
