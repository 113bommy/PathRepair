#include <bits/stdc++.h>
int fix(double x) {
  if (fabs(x) <= 1e-9)
    return 0;
  else if (x > 1e-9)
    return 1;
  else
    return -1;
}
int main() {
  double s;
  while (scanf("%lf", &s) != EOF) {
    double num[4];
    double ans[4];
    for (int i = 1; i <= 3; i++) scanf("%lf", &num[i]);
    num[0] = 0;
    for (int i = 1; i <= 3; i++) num[0] += num[i];
    if (fix(num[0]) == 0)
      for (int i = 1; i <= 3; i++) ans[i] = s / 3;
    else
      for (int i = 1; i <= 3; i++) ans[i] = s * num[i] / num[0];
    for (int i = 1; i <= 3; i++)
      if (i == 3)
        printf("%.12f\n", ans[i]);
      else
        printf("%.12f ", ans[i]);
  }
  return 0;
}
