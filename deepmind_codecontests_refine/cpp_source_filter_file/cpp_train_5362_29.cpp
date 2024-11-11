#include <bits/stdc++.h>
using namespace std;
int main() {
  long double x1, x2, y1, y2, vm, t, vx1, vx2, vy1, vy2;
  cin >> x1 >> y1 >> x2 >> y2 >> vm >> t >> vx1 >> vy1 >> vx2 >> vy2;
  long double low = 0, up = 10000000;
  for (int i = 0; i < 10000; i++) {
    long double mid = (low + up) / 2;
    long double xf = x1, yf = y1;
    long double z = 0;
    xf += vx1 * min(t, mid);
    xf += vx2 * max(z, mid - t);
    yf += vy1 * min(t, mid);
    yf += vy2 * max(z, mid - t);
    long double dist = ((xf - x2) * (xf - x2)) + ((yf - y2) * (yf - y2));
    dist = sqrt(dist);
    if (vm * mid >= dist)
      up = mid;
    else
      low = mid;
  }
  printf("%.8lf\n", (double)low);
}
