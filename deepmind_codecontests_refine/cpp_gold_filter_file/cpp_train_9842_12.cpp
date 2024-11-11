#include <bits/stdc++.h>
using namespace std;
inline void file() {
  freopen("D:\\go.txt", "r", stdin);
  freopen("D:\\leave.txt", "w", stdout);
}
int main() {
  double d, h, v, e;
  scanf("%lf%lf%lf%lf", &d, &h, &v, &e);
  if ((3.14159265359 * (d / 2) * (d / 2) * e >= v))
    printf("NO\n");
  else {
    double tmp1 = 3.14159265359 * (d / 2) * (d / 2) * h;
    double tmp = 3.14159265359 * (d / 2) * (d / 2) * e;
    printf("YES\n%.12f\n", tmp1 / (v - tmp));
  }
  return 0;
}
