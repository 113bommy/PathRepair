#include <bits/stdc++.h>
using namespace std;
long long n, x[4], ta, tb;
unsigned long long tc, td, te, tf;
double tt;
long double y[8], r, pi = 3.14159265358979323846264338327950288419716939937510;
int main() {
  for (int a = 0; a < 8; a++) {
    scanf("%lf", &tt);
    y[a] = tt;
  }
  r = sqrt(y[2] * y[2] + y[3] * y[3]);
  y[2] /= r;
  y[3] /= r;
  y[4] /= 2;
  y[6] /= 2;
  printf("%.20lf %.20lf\n", (double)(y[0] + y[2] * y[5]),
         (double)(y[1] + y[3] * y[5]));
  printf("%.20lf %.20lf\n", (double)(y[0] - y[3] * y[4]),
         (double)(y[1] + y[2] * y[4]));
  printf("%.20lf %.20lf\n", (double)(y[0] - y[3] * y[6]),
         (double)(y[1] + y[2] * y[6]));
  printf("%.20lf %.20lf\n", (double)(y[0] - y[3] * y[6] - y[2] * y[7]),
         (double)(y[1] + y[2] * y[6] - y[3] * y[7]));
  printf("%.20lf %.20lf\n", (double)(y[0] + y[3] * y[6] - y[2] * y[7]),
         (double)(y[1] - y[2] * y[6] - y[3] * y[7]));
  printf("%.20lf %.20lf\n", (double)(y[0] + y[3] * y[6]),
         (double)(y[1] - y[2] * y[6]));
  printf("%.20lf %.20lf\n", (double)(y[0] + y[3] * y[4]),
         (double)(y[1] - y[2] * y[4]));
  ta = x[1];
  if (abs(ta) % 2 == 0) ta++;
  tb = x[3];
  if (abs(tb) % 2 == 0) tb--;
  tc = (tb - ta + 2) / 2;
  ta = x[1];
  if (abs(ta) % 2 == 1) ta++;
  tb = x[3];
  if (abs(tb) % 2 == 1) tb--;
  td = (tb - ta + 2) / 2;
  ta = x[0];
  if (abs(ta) % 2 == 0) ta++;
  tb = x[2];
  if (abs(tb) % 2 == 0) tb--;
  te = (tb - ta + 2) / 2;
  ta = x[0];
  if (abs(ta) % 2 == 1) ta++;
  tb = x[2];
  if (abs(tb) % 2 == 1) tb--;
  tf = (tb - ta + 2) / 2;
  return 0;
}
