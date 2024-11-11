#include <bits/stdc++.h>
int main() {
  long long a, b, c, alla = 0, allb = 0, allc = 0;
  int i, na, nb, nc, j;
  scanf("%d", &na);
  nb = na - 1;
  nc = nb - 1;
  for (i = 0; i < na; i++) {
    scanf("%lld", &a);
    alla += a;
  }
  for (i = 0; i < nb; i++) {
    scanf("%lld", &b);
    allb += b;
  }
  for (i = 0; i < nc; i++) {
    scanf("%lld", &c);
    allc += c;
  }
  printf("%d\n%d\n", alla - allb, allb - allc);
  return 0;
}
