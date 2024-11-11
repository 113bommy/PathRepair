#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, p, q;
  scanf("%lf%lf%lf", &l, &p, &q);
  double ans = (l * p) / (p + q);
  printf("%lf", ans);
  return 0;
}
