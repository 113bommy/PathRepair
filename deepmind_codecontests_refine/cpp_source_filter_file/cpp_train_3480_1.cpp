#include <bits/stdc++.h>
int main() {
  int k, a, b, v;
  while (scanf("%d%d%d%d", &k, &a, &b, &v) != EOF) {
    int s = 0;
    while (a > 0) {
      s++;
      if (b >= k) {
        b -= k;
        a -= k * v;
      } else {
        if (b > 0) {
          a -= (b + 1) * v;
          b = 0;
        } else
          a -= v;
      }
    }
    printf("%d\n", s);
  }
  return 0;
}
