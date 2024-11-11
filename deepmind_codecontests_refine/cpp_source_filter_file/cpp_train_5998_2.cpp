#include <bits/stdc++.h>
const int mu = 998244353;
int n, m;
int ksm(int x, int y) {
  x = x % mu;
  int ans = 1;
  for (; y; y >>= 1, x = (long long)x * x % mu)
    if (y & 1) ans = (long long)ans * x % mu;
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  int ans = ksm(2 * (n + 1), m);
  ans = (long long)ans * (n + 1 - m) % mu * ksm(n + 1, mu - 2) % mu;
  printf("%d\n", ans);
}
