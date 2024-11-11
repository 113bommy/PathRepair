#include <bits/stdc++.h>
int p1, p2, p3;
int t1, t2;
int n;
int pp = 0, p, k;
int i;
int ret;
int main() {
  scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
  scanf("%d%d", &p, &k);
  ret = (k - p) * p1;
  for (i = 1; i < n; i++) {
    pp = k;
    scanf("%d%d", &p, &k);
    if (p - pp > t1) {
      ret += t1 * p1;
      pp += t1;
      if (p - pp > t2)
        ret += t2 * p2 + (p - pp - t2) * p3;
      else
        ret += (p - pp) * p2;
    } else
      ret += (p - pp) * p1;
    ret += (k - p) * p1;
  }
  printf("%d", ret);
  getchar();
  getchar();
  return 0;
}
