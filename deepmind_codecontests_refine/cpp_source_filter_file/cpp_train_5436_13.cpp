#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
inline T LCM(T x, T y) {
  T tp = GCD(x, y);
  if ((x / tp) * 1. * y > 9e18) return 9e18;
  return (x / tp) * y;
}
template <typename T>
inline T BigMod(T A, T B, T M) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T InvMod(T A, T M) {
  return BigMod(A, M - 2, M);
}
long long gcdr(long long a, long long b) {
  if (a == 0) return b;
  return gcdr(b % a, a);
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) {
  if (a < b) return a;
  return b;
}
void FastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
}
const long long size3 = 300005;
const long long size2 = 200005;
const long long size1 = 100005;
long long dp[2001][12], n, m;
long long solve(long long current, long long pre) {
  if (current > m) {
    return 1;
  }
  if (dp[current][pre] != -1) {
    return dp[current][pre];
  }
  long long ans = 0;
  for (long long i = pre; i <= n; i++) {
    ans += ((solve(current + 1, i) % 1000000007) * (i - pre + 1)) % 1000000007;
  }
  dp[current][pre] = ans % 1000000007;
  return dp[current][pre];
}
int main() {
  long long t, i, j, x, y;
  t = 1;
  while (t--) {
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &n);
    scanf("%lld", &m);
    long long ans = (solve(1, 1)) % 1000000007;
    printf("%lld", ans);
    printf("\n");
  }
  return 0;
}
