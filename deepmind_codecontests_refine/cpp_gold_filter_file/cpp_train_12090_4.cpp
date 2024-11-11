#include <bits/stdc++.h>
int main() {
  int b, i;
  scanf("%d", &b);
  for (i = 0; i < b; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d %d\n", l, 2 * l);
  }
  return 0;
}
