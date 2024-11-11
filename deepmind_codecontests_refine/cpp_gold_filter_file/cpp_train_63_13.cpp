#include <bits/stdc++.h>
int main() {
  int n, k, ans = (1 << 30);
  scanf("%d%d", &n, &k);
  for (int i = 1, a; i <= n; ++i) {
    scanf("%d", &a);
    if (!(k % a) && k / a < ans) ans = k / a;
  }
  printf("%d", ans);
  return 0;
}
