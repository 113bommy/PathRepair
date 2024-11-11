#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 998244353;
long long int fastxp(long long int a, int x, int mod) {
  if (x == 0) return 1;
  if (x == 1) return a;
  return (fastxp((a * a) % mod, x / 2, mod) * ((x & 1) ? a : 1)) % mod;
}
long long int check(long long int x) {
  while (x < 0) x += MOD;
  if (x >= MOD) x %= MOD;
  return x;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 2) {
    printf("%d\n", m);
    return 0;
  }
  long long int plc = 1, ans = 0;
  for (int i = n - 1; i <= m; i++) {
    if (i == n - 1) {
      plc = fastxp(2, n - 3, MOD);
      plc *= (long long int)(n - 2);
      plc = check(plc);
    } else {
      plc *= (long long int)(i - 1);
      plc = check(plc);
      plc *= fastxp(i - (n - 1), MOD - 2, MOD);
      plc = check(plc);
    }
    ans += plc;
    ans = check(ans);
  }
  printf("%lld\n", ans);
}
