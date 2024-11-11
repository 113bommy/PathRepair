#include <bits/stdc++.h>
int main() {
  int n;
  double m;
  scanf("%d%lf", &n, &m);
  double sum = 180.0 * (n - 2) / n;
  double ang = (180 - sum) / 2;
  int flag = 3;
  for (int i = 3; i <= n; i++) {
    int tmp = (180.0 - sum) * (i - 2) / 2;
    if (fabs(ang - m) > fabs(tmp - m)) {
      ang = tmp;
      flag = i;
    }
  }
  printf("2 1 %d", flag);
}
