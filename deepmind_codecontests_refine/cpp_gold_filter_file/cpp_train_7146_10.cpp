#include <bits/stdc++.h>
using namespace std;
int main() {
  double r, x1, y1, x2, y2;
  scanf("%lf %lf %lf %lf %lf", &r, &x1, &y1, &x2, &y2);
  double dis1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  if (dis1 >= r * r)
    printf("%.8lf %.8lf %.8lf\n", x1, y1, r);
  else if (x1 == x2 && y1 == y2)
    printf("%.8lf %.8lf %.8lf\n", x1 + r / 2.0, y1, r / 2.0);
  else {
    double D = sqrt(dis1);
    double R = (D + r) / 2.0;
    printf("%.8lf %.8lf %.8lf\n", x2 + (x1 - x2) * R / D,
           y2 + (y1 - y2) * R / D, R);
  }
}
