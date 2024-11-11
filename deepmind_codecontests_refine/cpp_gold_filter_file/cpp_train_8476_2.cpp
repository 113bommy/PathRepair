#include <bits/stdc++.h>
using namespace std;
double a, h;
double x;
int get1, get2;
int main() {
  scanf("%lf", &x);
  for (int i = 1; i <= 10; i++)
    for (int j = 1; j <= 10; j++) {
      a = i * 1.0, h = j * 1.0;
      double V = a * a / 4.0 * h;
      double H = sqrt(a * a / 4.0 + h * h);
      double S = a * H / 2.0;
      double D = V / S;
      if (fabs(D - x) <= 1e-5) get1 = i, get2 = j;
    }
  printf("%d %d\n", get1, get2);
  return 0;
}
