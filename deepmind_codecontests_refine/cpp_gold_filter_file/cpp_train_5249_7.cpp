#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, m, n, a, max, ct, ct1, res, max1;
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
    ct = 0;
    ct1 = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a);
      if (a == 1)
        ct++;
      else
        ct1++;
    }
    if (ct > m) {
      max = ct - m;
      if (ct1 > k) {
        max1 = ct1 - k;
        res = max + max1;
      } else
        res = max;
      printf("%d\n", res);
    } else {
      max = m - ct;
      k += max;
      if (k > ct1)
        printf("0\n");
      else {
        res = ct1 - k;
        printf("%d\n", res);
      }
    }
  }
  return 0;
}
