#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, p, q;
  scanf("%lf%lf%lf", &l, &p, &q);
  double ans = p * l / (p + q);
  printf("%.4g", ans);
  return 0;
}
