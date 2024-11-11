#include <bits/stdc++.h>
using namespace std;
long long n, k, mod;
long long power[1002];
long long cache[1002][102][2];
long long dp(long long pos, long long modd, long long g) {
  if (!modd && pos && g) return 0;
  if (pos == n) return 1;
  if (cache[pos][modd][g] != -1) return cache[pos][modd][g];
  long long ans = 0;
  for (long long j = (pos == n - 1); j < 10; j++)
    ans += dp(pos + 1, (j * power[pos] + modd) % k, g || j);
  return cache[pos][modd][g] = ans % mod;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k >> mod;
  long long ans = 0;
  power[0] = 1 % k;
  long long pow = 9;
  for (long long i = 1; i < n; i++)
    power[i] = (power[i - 1] * 10) % k, pow *= 10, pow %= mod;
  memset(cache, -1, sizeof(cache));
  cout << (pow - dp(0, 0, 0) + mod) % mod;
}
