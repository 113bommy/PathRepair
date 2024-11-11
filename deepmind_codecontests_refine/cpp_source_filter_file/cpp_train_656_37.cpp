#include <bits/stdc++.h>
int n, ans, a;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= a; i++) {
    scanf("%d", &a);
    ans += i * a;
  }
  printf("%d", ans);
  return 0;
}
