#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int l, p, q;
  scanf("%d%d%d", &l, &p, &q);
  double t;
  t = (double)l / (p + q);
  double l1 = p * t;
  printf("%lf\n", l1);
  return 0;
}
