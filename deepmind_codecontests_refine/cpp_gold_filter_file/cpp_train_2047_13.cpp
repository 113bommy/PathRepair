#include <bits/stdc++.h>
long long n, m, d, x, y;
int main() {
  scanf("%lld%lld%lld", &n, &m, &x);
  if (x < n) {
    printf("%lld %lld", x + 1, 1ll);
    return 0;
  }
  d = (x - n) / (m - 1) + 1;
  printf("%lld ", n - d + 1);
  y = 1;
  if (d & 1) {
    printf("%lld", 2 + (x - n) % (m - 1));
  } else {
    printf("%lld", ((m - 1) - ((x - n) % (m - 1)) + 1));
  }
}
