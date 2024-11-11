#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000003;
long long fast_pow(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % MOD)
    if (y & 1) ret = ret * x % MOD;
  return ret % MOD;
}
long long get_inv(long long x) { return fast_pow(x, MOD - 2); }
int main() {
  long long n, k;
  cin >> n >> k;
  if (((k - 1) >> n) && n < 62) {
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  long long gcd = 0;
  for (long long i = 1; i <= min(60ll, n); i++) gcd += ((k - 1) >> i) + 1;
  gcd += n - min(60ll, n);
  long long ans_b = fast_pow(
      2, ((k % (MOD - 1)) * (n % (MOD - 1)) - gcd % (MOD - 1) + MOD - 1) %
             (MOD - 1));
  long long last = fast_pow(2, n), ans_a = 0;
  if (last >= k) {
    long long x = last;
    ans_a = 1;
    for (long long i = 0; i < k; i++) ans_a = ans_a * (x - i) % MOD;
    ans_a = ans_a * get_inv(fast_pow(2, gcd)) % MOD;
  }
  cout << (ans_b - ans_a + MOD) % MOD << " " << ans_b << endl;
  return 0;
}
