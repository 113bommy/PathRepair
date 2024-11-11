#include <bits/stdc++.h>
using namespace std;
const long long N = 5000 * 1001, M = 719, MOD = 1e9 + 7;
long long n, _hash[N], hash_rev[N], dp[N], pw[N];
long long sum;
string s;
bool is_pal(long long r) {
  if (r == 0) return true;
  long long mid = (r + 1) / 2 - 1;
  long long tt = n - 1 - (mid + 1);
  if (r % 2 == 0) tt--;
  long long t = _hash[mid], t2 = hash_rev[tt] - hash_rev[tt - mid - 1];
  if ((pw[tt - mid] * t) % MOD == (t2 + MOD) % MOD) return true;
  return false;
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> s;
  n = s.size();
  pw[0] = 1;
  _hash[0] = (long long)s[0];
  for (long long i = 1; i < n; i++) {
    pw[i] = (pw[i - 1] * M) % MOD;
    _hash[i] = (_hash[i - 1] + (pw[i] * (long long)s[i])) % MOD;
  }
  reverse(s.begin(), s.end());
  hash_rev[0] = (long long)s[0];
  for (long long i = 1; i < n; i++)
    hash_rev[i] = (hash_rev[i - 1] + (pw[i] * (long long)s[i])) % MOD;
  reverse(s.begin(), s.end());
  for (long long i = 1; i <= n; i++) {
    if (is_pal(i - 1)) dp[i] = dp[i / 2] + 1;
    sum += dp[i];
  }
  cout << sum << "\n";
}
