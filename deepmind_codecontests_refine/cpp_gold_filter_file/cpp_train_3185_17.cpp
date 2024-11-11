#include <bits/stdc++.h>
int main() {
  int a, b, ans = 1;
  scanf("%d%d", &a, &b);
  for (; a <= b; a *= 3, b *= 2, ans++)
    ;
  printf("%d", ans - 1);
  return 0;
}
