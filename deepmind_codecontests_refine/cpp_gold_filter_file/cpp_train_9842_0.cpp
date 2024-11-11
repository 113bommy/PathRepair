#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, h, v, e;
  scanf("%d%d%d%d", &d, &h, &v, &e);
  double v1 = 3.141592653589793238462643383279502884 * (double)d * (double)d /
              (double)4;
  v1 = (double)v / (double)v1;
  if (v1 <= e)
    printf("NO\n");
  else {
    printf("YES\n");
    double ans = (double)h / (double)(v1 - e);
    printf("%.12f\n", ans);
  }
  return 0;
}
