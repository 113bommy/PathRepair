#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, d1, b1, b2, d2;
  double PI = atan(1) * 4;
  cin >> a1 >> a2 >> d1 >> b1 >> b2 >> d2;
  double a = 0, cos60 = cos(60 / 180. * PI), sin60 = sin(60 / 180. * PI);
  double x[6], y[6];
  x[0] = 0;
  x[1] = x[0] - cos60 * a1;
  x[2] = x[1] + cos60 * a2;
  x[3] = x[2] + d1;
  x[4] = x[3] + cos60 * b1;
  x[5] = x[4] - cos60 * b2;
  y[0] = 0;
  y[1] = y[0] + sin60 * a1;
  y[2] = y[1] + sin60 * a2;
  y[3] = y[2];
  y[4] = y[3] - sin60 * b1;
  y[5] = y[4] - sin60 * b2;
  int j = 5;
  for (int i = 0; i < 6; i++) {
    a += (x[j] + x[i]) * (y[j] - y[i]);
    j = i;
  }
  cout << (long long)(a / sin60) << endl;
}
