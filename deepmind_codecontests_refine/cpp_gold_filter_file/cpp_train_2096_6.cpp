#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
int t;
double tmp;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lf", &tmp);
    if (tmp == 179) {
      puts("360");
      continue;
    }
    for (int i = 3;; i++) {
      int alfa = (i - 2) * 180;
      if (alfa % i == 0) {
        double akk = 1.0 * alfa / i;
        double att = akk / (i - 2);
        double aqq = tmp / att;
        if (fabs(aqq - (int)aqq) < eps && akk >= tmp) {
          printf("%d\n", i);
          break;
        }
      }
    }
  }
  return 0;
}
