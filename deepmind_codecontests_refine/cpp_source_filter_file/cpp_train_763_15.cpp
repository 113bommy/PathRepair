#include <bits/stdc++.h>
int d[1000011], a, b, n, m;
int main() {
  memset(d, 0, sizeof(d));
  scanf("%d%d", &n, &m);
  long long r = n * (n - 1ll) * (n - 2) / 6;
  while (m--) {
    scanf("%d%d", &a, &b);
    r -= n - (++d[a]) - (++d[b]);
  }
  printf("%I64d\n", r % 10007);
  return 0;
}
