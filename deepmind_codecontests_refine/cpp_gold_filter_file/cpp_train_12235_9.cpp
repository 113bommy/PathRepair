#include <bits/stdc++.h>
int n;
inline long long ksm(long long x, register int l) {
  long long ans = 1;
  while (l) {
    if (l & 1) ans = ans * x;
    x = x * x, l >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  if (n == 3) return puts("24"), 0;
  printf("%lld", 1ll * ksm(4, n - 4) * (36 * n - 12));
  return 0;
}
