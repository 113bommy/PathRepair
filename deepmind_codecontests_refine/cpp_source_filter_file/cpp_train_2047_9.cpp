#include <bits/stdc++.h>
long long n, m, d, x, y;
int main() {
  scanf("%lld%lld%lld", &n, &m, &x);
  if (x < n) {
    printf("%lld %lld", 1, x + 1);
    return 0;
  }
  d = (x - n) / (m - 1) + 1;
  printf("%lld ", n - d + 1);
  y = 1;
  if (d & 1) {
    printf("%lld", 1 + (x - n) % (m - 1));
  } else {
    printf("%lld", ((m - 1) - ((x - n) % (m - 1)) + 1));
  }
}
