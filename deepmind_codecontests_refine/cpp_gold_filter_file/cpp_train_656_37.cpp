#include <bits/stdc++.h>
int n, ans, a;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    ans += i * a;
  }
  printf("%d\n", ans);
  return 0;
}
