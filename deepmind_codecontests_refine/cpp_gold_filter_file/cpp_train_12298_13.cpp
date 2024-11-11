#include <bits/stdc++.h>
int l[123], r[123];
int main() {
  int n;
  int i;
  int sum = 0;
  int p1, p2, p3, t1, t2;
  scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    sum += (r[i] - l[i]) * p1;
  }
  for (i = 1; i < n; i++) {
    if (l[i] - r[i - 1] > t1) {
      sum += t1 * p1;
      if (l[i] - r[i - 1] > (t1 + t2)) {
        sum += t2 * p2;
        sum += (l[i] - r[i - 1] - t1 - t2) * p3;
      } else
        sum += (l[i] - r[i - 1] - t1) * p2;
    } else
      sum += (l[i] - r[i - 1]) * p1;
  }
  printf("%d\n", sum);
  return 0;
}
