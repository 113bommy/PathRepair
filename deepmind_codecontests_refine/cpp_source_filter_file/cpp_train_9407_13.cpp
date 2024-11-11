#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double Y1, Y2, Y3, XW, YW, R;
int main() {
  cin >> Y1 >> Y2 >> Y3 >> XW >> YW >> R;
  Y3 -= R;
  double p2x;
  double NX = XW, NY = 2 * Y3 - YW;
  double K = (NY - Y1) / NX;
  double B = Y1;
  p2x = (Y3 - B) / K;
  double aimy = -1;
  double Ly = Y1 + R, Ry = Y2 - R;
  for (int i = 0; i < 1000; i++) {
    double midy = (Ly + Ry) / 2;
    double dis =
        fabs(NX * (Y2 - midy)) / sqrt(NX * NX + (NY - midy) * (NY - midy));
    if (dis >= R + eps) {
      Ry = midy;
      aimy = midy;
    } else
      Ly = midy;
  }
  double p1x;
  if (aimy == -1)
    printf("-1\n");
  else {
    K = (NY - aimy) / NX;
    double B = aimy;
    p1x = (Y3 - B) / K;
    printf("%.10lf\n", p1x);
  }
  return 0;
}
