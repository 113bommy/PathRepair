#include <bits/stdc++.h>
const int z = 998244353;
int fp(int a, int x) {
  if (x == 0) {
    return 1;
  }
  if (x % 2 == 1) {
    return 1ll * a * fp(a, x - 1) % z;
  }
  int t = fp(a, x / 2);
  return 1ll * t * t % z;
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int lb = 0;
  int ans = 1;
  for (int i = 0; i < m; i++) {
    int b;
    scanf("%d", &b);
    int t = fp(k, b - lb);
    ans = ans * (1ll * t * (t + 1) / 2) % z;
    lb = b;
  }
  ans = 1ll * ans * fp(k, n - 2 * lb) % z;
  printf("%d\n", ans);
  return 0;
}
