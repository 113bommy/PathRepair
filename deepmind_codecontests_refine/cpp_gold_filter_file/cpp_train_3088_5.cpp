#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 9;
long long binpow(long long a, long long b) {
  long long res = 1LL;
  while (b) {
    if (b & 1LL) {
      res = res * a;
      if (res >= MOD) res %= MOD;
    }
    a = a * a;
    if (a >= MOD) a %= MOD;
    b >>= 1LL;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b, k;
  cin >> n >> a >> b >> k;
  string s;
  cin >> s;
  long long sum = 0;
  for (int i = 0; i < k; i++) {
    if (s[i] == '+') {
      sum += (binpow(a, n - i) * binpow(b, i)) % MOD;
      if (sum >= MOD) sum %= MOD;
    } else {
      long long res = binpow(a, n - i) * binpow(b, i) % MOD;
      sum -= res;
      if (sum < 0) sum += MOD;
      if (sum >= MOD) sum %= MOD;
    }
  }
  if (k == n + 1) {
    cout << sum;
    return 0;
  }
  long long up = binpow(a, k);
  long long down = binpow(b, k);
  if (up == down) {
    cout << sum * ((n + 1) / k) % MOD;
    return 0;
  }
  long long r = down * binpow(up, MOD - 2LL) % MOD;
  long long k1 = binpow(r, (n + 1) / k);
  k1 = k1 - 1LL;
  long long k2 = binpow((r - 1LL), MOD - 2LL);
  assert(k1 >= 0LL);
  assert(k2 >= 0LL);
  assert(r >= 0LL);
  long long res1 = (k1 * k2) % MOD;
  assert(res1 >= 0LL);
  cout << (sum * res1) % MOD;
  return 0;
}
