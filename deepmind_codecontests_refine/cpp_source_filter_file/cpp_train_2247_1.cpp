#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool debug = false;
int main() {
  scanf("%d", &n);
  double R, r;
  while (n--) {
    scanf("%lf%lf%d", &R, &r, &k);
    double x = (R + r) / 4 / R / r;
    double y = k * (R - r) / 2 / r / R;
    double rx = (R - r) / 4 / R / r;
    printf("%.10lf", rx / (x * x + y * y - rx * rx));
  }
  return 0;
}
