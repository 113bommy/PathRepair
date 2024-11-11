#include <bits/stdc++.h>
int main() {
  int l, p, q;
  float ans;
  scanf("%d\n%d\n%d\n", &l, &p, &q);
  ans = p * l * 1.0 / (p + q);
  printf("%f", ans);
  return 0;
}
