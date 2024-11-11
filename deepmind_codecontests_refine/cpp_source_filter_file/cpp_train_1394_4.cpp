#include <bits/stdc++.h>
using namespace std;
long long n, k, cnt5, cnt10;
const long long mod = 1e9 + 7;
long long a[55];
long long dp[55][55][2];
long long Fact[55];
long long fast(long long b, long long e) {
  if (!e) return 1;
  if (e & 1) return b * fast(b * b % mod, e >> 1) % mod;
  return fast(b * b % mod, e >> 1);
}
void init() {
  Fact[0] = Fact[1] = 1;
  for (long long i = 2; i < 55; i++) Fact[i] = i * Fact[i - 1];
}
long long nCr(long long n, long long r) {
  if (r > n) return 0;
  return Fact[n] * fast(Fact[r], mod - 2) % mod * fast(Fact[n - r], mod - 2) %
         mod;
}
long long solve(long long fives, long long tens, bool f) {
  if (f == 1 && fives + tens == 0) return 0;
  long long &ret = dp[fives][tens][f];
  if (~ret) return ret;
  ret = 5 * 55 * 55 * 55;
  if (f == 1) {
    if (fives < cnt5) ret = min(ret, solve(fives + 1, tens, 0) + 1);
    if (tens < cnt10 && k > 1) ret = min(ret, solve(fives, tens + 1, 0) + 1);
  } else {
    for (long long i = 0; i <= min(fives, k); i++) {
      if (i > k) continue;
      long long lft = (k - i) / 2;
      if (i || left)
        ret = min(ret, solve(fives - i, tens - min(tens, lft), 1) + 1);
    }
  }
  return ret;
}
long long dp2[55][55][205][2];
long long path;
long long solve2(long long fives, long long tens, long long num, bool f) {
  if (num > path) return 0;
  if (f == 1 && fives + tens == 0) return 1;
  long long &ret = dp2[tens][fives][num][f];
  if (~ret) return ret;
  ret = 0;
  if (f == 1) {
    for (long long i = 0; i <= cnt5 - fives; i++) {
      for (long long j = 0; j <= cnt10 - tens; j++) {
        if ((i + j) > 0 && i + j * 2 <= k) {
          ret = (ret + nCr(cnt5 - fives, i) * nCr(cnt10 - tens, j) % mod *
                           solve2(fives + i, tens + j, num + 1, f ^ 1) % mod) %
                mod;
        }
      }
    }
  } else {
    for (long long i = 0; i <= fives; i++) {
      for (long long j = 0; j <= tens; j++) {
        if ((i + j) > 0 && i + j * 2 <= k) {
          ret = (ret + nCr(fives, i) * nCr(tens, j) % mod *
                           solve2(fives - i, tens - j, num + 1, f ^ 1) % mod) %
                mod;
        }
      }
    }
  }
  return ret;
}
int main() {
  init();
  cin >> n >> k;
  k /= 50;
  for (long long i = 0; i < n; i++)
    cin >> a[i], cnt5 += (a[i] == 50), cnt10 += (a[i] == 100);
  if (!k || (k == 1 && (cnt10 || cnt5 > 1))) return puts("-1\n0");
  memset(dp, -1, sizeof dp);
  path = solve(cnt5, cnt10, 0);
  if (path > 200) return puts("-1\n0");
  cout << path << '\n';
  memset(dp2, -1, sizeof dp2);
  cout << solve2(cnt5, cnt10, 0, 0) << '\n';
}
