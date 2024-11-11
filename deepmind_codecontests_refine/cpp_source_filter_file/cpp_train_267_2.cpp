#include <bits/stdc++.h>
int main() {
  int c, v, v1, a, l, nd = 0, rc = 0;
  scanf("%d%d%d%d%d", &c, &v, &v1, &a, &l);
  while (rc <= c) {
    if (v + (nd * a) <= v1) {
      rc = rc + v + (nd * a);
      nd++;
      if (rc == c) break;
      rc = rc - l;
    } else {
      rc = rc + v1;
      nd++;
      if (rc == c) break;
      rc = rc - l;
    }
  }
  printf("%d", nd);
}
