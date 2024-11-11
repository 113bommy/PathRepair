#include <bits/stdc++.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int ans = 0;
  a *= b;
  while (a >= b) {
    ans += a / b;
    a = (a + a % b) / b;
  }
  printf("%d", ans);
}
