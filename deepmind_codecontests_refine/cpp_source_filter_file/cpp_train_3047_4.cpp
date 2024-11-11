#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100;
const int MOD = 1000000007;
const double eps = 1e-8;
const double PI = acos(-1.0);
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long qpow(long long a, long long n, long long p = MOD) {
  long long r = 1 % p;
  for (a %= p; n; a = a * a % p, n >>= 1)
    if (n & 1) r = r * a % p;
  return r;
}
long long inv(long long x, long long p = MOD) {
  return x <= 1 ? 1 : inv(p % x, p) * (p - p / x) % p;
}
long long a[1000005], c[1000005][2];
long long dp[1000005][2];
void solve() {
  int n, r1, r2, r3, d;
  scanf("%d%d%d%d%d", &n, &r1, &r2, &r3, &d);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    c[i][0] = a[i] * r1 + r3;
    c[i][1] = min((a[i] + 2) * r1, 1LL * r2 + r1);
  }
  dp[0][0] = -d;
  dp[0][1] = d;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = min(dp[i - 1][0] + c[i][0], dp[i - 1][1] + c[i][1]) + d;
    dp[i][1] = dp[i - 1][0] + c[i][1] + 2 * d;
  }
  long long ans = min(dp[n][0], dp[n - 1][1] + c[n][0]);
  printf("%lld\n", ans);
}
int main(int argc, char* argv[]) {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
