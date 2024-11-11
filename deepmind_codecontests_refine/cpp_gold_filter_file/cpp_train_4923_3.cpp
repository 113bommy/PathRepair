#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, c0, c1, h, p, i, ct0 = 0, ct1 = 0;
    scanf("%d %d %d %d\n", &n, &c0, &c1, &h);
    char s[n];
    for (i = 0; i < n; i++) scanf("%c", &s[i]);
    for (i = 0; i < n; i++) {
      if (s[i] == '0')
        ct0++;
      else
        ct1++;
    }
    if (c0 > c1) {
      if (c0 - c1 > h)
        p = (h * ct0) + (n * c1);
      else
        p = (c0 * ct0) + (c1 * ct1);
    } else {
      if (c1 - c0 > h)
        p = (h * ct1) + (n * c0);
      else
        p = (c0 * ct0) + (c1 * ct1);
    }
    printf("%d\n", p);
  }
  return 0;
}
