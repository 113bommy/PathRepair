#include <bits/stdc++.h>
int main() {
  unsigned long int n, p1, p2, p3, t1, t2, l[100], r[100], time = 0, i, t,
                                                           osho = 0;
  scanf("%u %u %u %u %u %u", &n, &p1, &p2, &p3, &t1, &t2);
  for (i = 0; i < n; i++) {
    scanf("%u %u", &l[i], &r[i]);
  }
  for (i = 0; i < n; i++) {
    time = time + p1 * (r[i] - l[i]);
  }
  for (i = 1; i < n; i++) {
    t = l[i] - r[i - 1];
    if (t >= (t1 + t2)) {
      t = t - t1 - t2;
      time = time + (p1 * t1) + (p2 * t2) + p3 * t;
      goto x;
    }
    if (t > t1 && t < t1 + t2) {
      t = t - t1;
      time = +time + p1 * t1 + p2 * t;
      goto x;
    }
    if (t <= t1) {
      time = time + p1 * t;
      goto x;
    }
  x:
    osho++;
  }
  printf("%u", time);
  return (0);
}
