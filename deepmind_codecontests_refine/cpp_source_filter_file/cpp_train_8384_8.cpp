#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  double l, v1, v2;
  while (~scanf("%d%lf%lf%lf%d", &n, &l, &v1, &v2, &k)) {
    int g = n / k + (n % k);
    double a = (v1 + v2) * l / (v1 + v2 + 2 * (g - 1) * v1);
    double sum = a / v2 + (l - a) / v1;
    printf("%.7f\n", sum);
  }
  return 0;
}
