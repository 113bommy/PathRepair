#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, mod = 998244353;
int n;
int a[N];
long long dp1[N], dp2[N];
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  memset(dp1, 0, n + 1 << 3);
  memset(dp2, 0, n + 1 << 3);
  dp1[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    dp1[x + 1] = (dp1[x + 1] + dp1[x + 1] + dp1[x]) % mod;
    if (x > 0) dp2[x - 1] = (dp2[x - 1] + dp2[x - 1] + dp1[x - 1]) % mod;
    dp2[x + 1] = (dp2[x + 1] + dp2[x + 1]) % mod;
  }
  long long ans = 0;
  for (int i = 0; i <= n + 1; ++i) ans = (ans + dp1[i] + dp2[i]) % mod;
  --ans;
  ans = (ans % mod + mod) % mod;
  printf("%lld\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) work();
}
