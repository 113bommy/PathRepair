#include <bits/stdc++.h>
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    int r, p1, p2, target, A, B;
    target = 0;
    for (int i = 0; i < n; i++) {
      int tmp;
      scanf("%d", &tmp);
      if (tmp > target) target = tmp;
    }
    r = target;
    target = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int tmp;
      scanf("%d", &tmp);
      if (tmp > target) target = tmp;
    }
    p1 = target;
    target = 2e9;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int tmp;
      scanf("%d", &tmp);
      if (tmp < target) target = tmp;
    }
    p2 = target;
    scanf("%d%d", &A, &B);
    printf("%.12lf\n", r * sqrt((double)(B * p1) / (B * p1 + A * p2)));
  }
  return 0;
}
