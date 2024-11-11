#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long x, y, x1, y1, x2, y2, xf, yf;
  double xc, yc;
  long long a, b, c;
  double mind = 111111111111111.0;
  long long maxd = -111111111111111LL;
  cin >> n >> x >> y >> xf >> yf;
  x2 = xf;
  y2 = yf;
  maxd = max(maxd, (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
  mind = min(mind, double((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y)));
  for (int i = 1; i < n; i++) {
    cin >> x1 >> y1;
    a = y1 - y2;
    b = x1 - x2;
    c = x1 * y2 - x2 * y1;
    xc = b * (b * x - a * y) - a * c;
    xc = xc / double(a * a + b * b);
    yc = a * (a * y - b * x) - b * c;
    yc = yc / double(a * a + b * b);
    if (xc >= min(x1, x2) && xc >= max(x1, x2) && yc >= min(y1, y2) &&
        yc <= max(y1, y2))
      mind = min(mind, (xc - x) * (xc - x) + (yc - y) * (yc - y));
    mind = min(mind, double((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
    maxd = max(maxd, (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
    x2 = x1;
    y2 = y1;
  }
  x1 = xf;
  y1 = yf;
  a = y1 - y2;
  b = x1 - x2;
  c = x1 * y2 - x2 * y1;
  xc = b * (b * x - a * y) - a * c;
  xc = xc / double(a * a + b * b);
  yc = a * (a * y - b * x) - b * c;
  yc = yc / double(a * a + b * b);
  if (xc >= min(x1, x2) && xc >= max(x1, x2) && yc >= min(y1, y2) &&
      yc <= max(y1, y2))
    mind = min(mind, (xc - x) * (xc - x) + (yc - y) * (yc - y));
  printf("%.12lf\n", 3.141592653589793 * (maxd - mind));
  return 0;
}
