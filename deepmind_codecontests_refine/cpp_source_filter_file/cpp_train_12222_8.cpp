#include <bits/stdc++.h>
using namespace std;
long long bigmod(long long a, long long b, long long m) {
  if (b == 0) return 1 % m;
  long long x = bigmod(a, b / 2, m);
  x = (x * x) % m;
  if (b % 2 == 1) x = (x * a) % m;
  return x;
}
const long long inf = 1LL << 28;
const long long mod = 1000000007LL;
int main() {
  long long n, m, r, i, j, k, l, ans, len;
  string s;
  while (cin >> s >> k) {
    len = (int)s.size();
    if (l > 1) {
      j = len * k;
      r = bigmod(2LL, j, mod) - 1;
      if (r < 0) r += mod;
      j = bigmod(2LL, len, mod) - 1;
      if (j < 0) j += mod;
      r = (r * bigmod(j, mod - 2, mod)) % mod;
    }
    ans = 0LL;
    for (i = 0; i < len; i++) {
      if (s[i] == '0' || s[i] == '5') {
        ans = (ans + bigmod(2LL, i, mod)) % mod;
      }
    }
    if (k > 1) {
      ans = (ans * r) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
