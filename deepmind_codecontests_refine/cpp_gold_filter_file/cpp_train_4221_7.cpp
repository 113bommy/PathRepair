#include <bits/stdc++.h>
int main() {
  int a, ans = 0;
  scanf("%d", &a);
  while (a) {
    if (a % 8 == 1) ++ans;
    a /= 8;
  }
  printf("%d\n", ans);
  return 0;
}
