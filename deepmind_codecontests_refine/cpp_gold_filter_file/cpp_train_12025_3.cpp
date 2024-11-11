#include <bits/stdc++.h>
int main() {
  int n, a, b, c, i, p, atai_prothom = 1;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &a, &p);
    if (atai_prothom == 1) c = p, b = a * c;
    if (atai_prothom == 0) {
      if (c <= p)
        b = b + a * c;
      else {
        c = p;
        b = b + a * c;
      }
    }
    atai_prothom = 0;
  }
  printf("%d", b);
  return 0;
}
