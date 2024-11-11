#include <bits/stdc++.h>
using namespace std;
double dis(int x1, int y1, int cenx, int ceny) {
  double temp =
      (double)(x1 - cenx) * (x1 - cenx) + (double)(y1 - ceny) * (y1 - ceny);
  return sqrt(temp);
}
int main() {
  long long R, x1, y1, x2, y2;
  cin >> R >> x1 >> y1 >> x2 >> y2;
  if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) >= R * R)
    cout << x1 << " " << y1 << " " << R << endl;
  else if (x1 == x2 && x2 == y2) {
    double a = (double)R / 2;
    double x = (double)x1 + a;
    double y = y1;
    printf("%.8lf %.8lf %.8lf", x, y, a);
  } else {
    double a = dis(x2, y2, x1, y1);
    double b = a + (double)R;
    b /= 2;
    double ax = b * (double)abs(x2 - x1) / a;
    double ay = b * (double)abs(y2 - y1) / a;
    ax = fabs(ax - (double)abs(x2 - x1));
    ay = fabs(ay - (double)abs(y2 - y1));
    if (x1 > x2)
      ax += (double)x1;
    else
      ax = (double)x1 - ax;
    if (y1 > y2)
      ay += (double)y1;
    else
      ay = (double)y1 - ay;
    printf("%.8lf %.8lf %.8lf", ax, ay, b);
  }
  return 0;
}
