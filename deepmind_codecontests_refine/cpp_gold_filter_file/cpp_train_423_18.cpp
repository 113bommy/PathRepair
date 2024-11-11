#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)998244353;
const long double PI = 3.141592653589793238462643383279502884197;
long long fac[1] = {1}, inv[1] = {1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long mp(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
long long cmb(long long r, long long c) {
  return fac[r] * inv[c] % MOD * inv[r - c] % MOD;
}
int n, k;
int ok, ot;
long long dp1[501];
long long dp[501];
long long go1(int o) {
  if (o == n) return 1;
  if (dp1[o] != -1) return dp1[o];
  long long ret = 0;
  for (int i = 1; i <= ok; i++) {
    if (i + o > n) break;
    ret += go1(o + i);
  }
  return dp1[o] = ret % MOD;
}
long long go(int o) {
  if (o == n) return 1;
  if (dp[o] != -1) return dp[o];
  long long ret = 0;
  for (int i = 1; i <= ot; i++) {
    if (i + o > n) break;
    ret += go(o + i);
  }
  return dp[o] = ret % MOD;
}
long long cal() {
  long long pre = 0, tmp, now;
  long long ans = 0;
  for (int i = 1; i <= min(k, n); i++) {
    memset(dp1, -1, sizeof(dp1));
    memset(dp, -1, sizeof(dp));
    ok = i;
    now = go1(0);
    tmp = (now - pre + MOD) % MOD;
    pre = now;
    ot = k / i;
    ans += tmp * go(0) % MOD;
  }
  return ans * 2 % MOD;
}
int main() {
  memset(dp1, -1, sizeof(dp1));
  scanf("%d %d", &n, &k);
  k--;
  printf("%lld", cal());
}
