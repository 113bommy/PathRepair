#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 9;
long long pow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b % 2 == 1) {
      ret *= a;
      ret %= MOD;
    }
    a *= a;
    a %= MOD;
    b = b >> 1;
  }
  return ret;
}
int main() {
  long long n, k;
  long long a, b;
  cin >> n >> a >> b >> k;
  n += 1;
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < k; i++) {
    long long x = pow(a, n - i - 1);
    x *= pow(b, i);
    x %= MOD;
    if (s[i] == '+')
      ans += x;
    else
      ans -= x;
    ans %= MOD;
  }
  long long p = pow(b, k) * pow(pow(a, k), MOD - 2) % MOD;
  long long t = n / k;
  if (p == 1)
    ans *= t;
  else {
    long long y = pow(p, t) - 1;
    y += MOD;
    y %= MOD;
    y *= pow(p - 1, MOD - 2);
    y %= MOD;
    ans *= y;
  }
  ans %= MOD;
  ans += MOD;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}
