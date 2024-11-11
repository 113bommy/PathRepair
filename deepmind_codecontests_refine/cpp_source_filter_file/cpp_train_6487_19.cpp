#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5, MOD = 1e9 + 7;
long long PowerMod(long long x, int p, int m) {
  if (!p) return 1;
  long long y = PowerMod(x, p >> 1, m);
  y = y % m;
  y = (y * y) % m;
  if (p & 1) y = (y * x) % m;
  return y;
}
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if (m == 1) {
    puts("1");
  } else if (k > n || k == 1) {
    printf("%lld\n", PowerMod(m, n, MOD));
  } else if (k == n) {
    printf("%lld\n", (PowerMod(m, n / 2, MOD) + m * (n % 2)) % MOD);
  } else {
    printf("%d\n", m * max(1, m * (k % 2)));
  }
  return 0;
}
