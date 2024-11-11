#include <bits/stdc++.h>
using namespace std;
double pi = atan(1) * 4;
int main() {
  int n, r;
  scanf("%d%d", &n, &r);
  double alpha = 180.0 / (double)n * 1.0;
  double x = sin((double)alpha * pi / 180.0);
  double res = (r * x) * 1.0 / (1 - x) * 1.0;
  printf("%.7f", res);
  return 0;
}
