#include <bits/stdc++.h>
int main() {
  int a, ans = 0;
  scanf("%d", &a);
  while (a) {
    if (a & 7 == 1) ++ans;
    a >>= 3;
  }
  printf("%d\n", ans);
  return 0;
}
