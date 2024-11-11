#include <bits/stdc++.h>
int main() {
  long long m, ans = 1;
  int n;
  scanf("%d%I64d", &n, &m);
  for (int i = 0; i < n; i++) {
    ans *= 2;
    if (ans > m) {
      printf("%d", ans);
      return 0;
    }
  }
  printf("%I64d", m % ans);
  return 0;
}
