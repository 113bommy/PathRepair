#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  double t1, t2, ans;
  t1 = (double)a / (double)b;
  t2 = (double)c / (double)d;
  ans = t1 / (1 - t1 * t2);
  printf("%.12f", ans);
  return 0;
}
