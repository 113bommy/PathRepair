#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
long long add(long long x, long long y) {
  x += y;
  if (x < 0) return x + MOD;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) return x + MOD;
  return x;
}
long long mult(long long x, long long y) { return (x * y) % MOD; }
long long bin_pow(long long x, long long p) {
  if (p == 0) return 1;
  if (p & 1) return mult(x, bin_pow(x, p - 1));
  return bin_pow(mult(x, x), p / 2);
}
long long rev(long long x) { return bin_pow(x, MOD - 2); }
const int N = 5050;
long long a[N];
long long dp[N];
int n;
long long ans[N];
long long k;
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  long long mulk = 1;
  for (int i = 0; i < n; i++) {
    mulk = mult(mulk, k - i);
    if (mulk == 0) break;
    ans[n - 1 - i] = mult(mulk, bin_pow(n, k - i - 1));
    if (i % 2 == 1) ans[n - 1 - i] = sub(0, ans[n - 1 - i]);
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j > 0; j--) dp[j] = add(dp[j], mult(dp[j - 1], a[i]));
  }
  long long ANS = 0;
  for (int i = 0; i < n; i++) ANS = add(ANS, mult(dp[i], ans[i]));
  ANS = mult(ANS, bin_pow(rev(n), k));
  printf("%lld\n", ANS);
  return 0;
}
