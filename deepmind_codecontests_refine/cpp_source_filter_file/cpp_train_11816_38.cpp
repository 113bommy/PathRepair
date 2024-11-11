#include <bits/stdc++.h>
using namespace std;
const long long maxn = 305000;
long long mod = 1e9 + 7;
long long h, w, n;
long long dp[maxn], f[maxn], inv[maxn];
struct stu {
  long long x, y;
} a[maxn];
long long cmp(stu a, stu b) {
  if (a.x != b.x)
    return a.x < b.x;
  else
    return a.y < b.y;
}
long long ksm(long long base, long long b, long long mod) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= base;
      ans %= mod;
    }
    base *= base;
    base %= mod;
    b >>= 1;
  }
  return ans;
}
void init() {
  f[0] = 1, inv[0] = 1;
  for (long long i = 1; i <= 20005; i++) {
    f[i] = f[i - 1] * i % mod;
    inv[i] = ksm(f[i], mod - 2, mod);
  }
}
long long c(long long x, long long y) {
  if (x < y)
    return 0;
  else
    return f[x] * inv[y] % mod * inv[x - y] % mod;
}
signed main() {
  cin >> h >> w >> n;
  init();
  for (long long i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
  sort(a + 1, a + n + 1, cmp);
  a[n + 1].x = h, a[n + 1].y = w;
  for (long long i = 1; i <= n + 1; i++) {
    dp[i] = c(a[i].x + a[i].y - 2, a[i].x - 1);
    for (long long j = 1; j < i; j++) {
      if (a[j].x > a[i].x || a[j].y > a[i].y) continue;
      dp[i] = (dp[i] -
               dp[j] * c(a[i].x + a[i].y - a[j].x - a[j].y, a[i].x - a[j].x)) %
              mod;
    }
  }
  cout << (dp[n + 1] + mod) % mod << endl;
  return 0;
}
