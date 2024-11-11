#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, d;
  cin >> a >> d;
  d = fmod(d, 4 * a);
  int N;
  scanf("%d ", &N);
  ;
  double x = 0, y = 0;
  int q = 0;
  double togo;
  double willgo;
  for (int i = (0); i < (N); i++) {
    double rest = d;
    while (rest > 1e-10) {
      if (q == 0) {
        togo = a - x;
        if (togo - 1e-10 > rest) {
          x += rest;
          rest = 0;
        } else {
          x = a;
          rest -= togo;
          q++;
        }
      } else if (q == 1) {
        togo = a - y;
        if (togo - 1e-10 > rest) {
          y += rest;
          rest = 0;
        } else {
          y = a;
          rest -= togo;
          q++;
        }
      } else if (q == 2) {
        togo = x;
        if (togo - 1e-10 > rest) {
          x -= rest;
          rest = 0;
        } else {
          x = 0;
          rest -= togo;
          q++;
        }
      } else {
        togo = y;
        if (togo - 1e-10 > rest) {
          y -= rest;
          rest = 0;
        } else {
          y = 0;
          rest -= togo;
          q++;
        }
      }
      q %= 4;
    }
    printf("%lf %lf\n", x, y);
  }
  return 0;
}
