#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e5 + 5;
long long t, n, m, k, a, b, d, val[siz], len[siz];
string s, q[siz];
long long bix(long long a, long long n) {
  long long ret = 1;
  while (n > 0) {
    if (n & 1) (ret *= a) %= mod;
    (a *= a) %= mod;
    n /= 2;
  }
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> n;
  for (long long i = 1; i <= n; i++) cin >> q[i];
  for (long long i = 0; i < 10; i++) val[i] = i, len[i] = 1;
  for (long long i = n; i >= 1; i--) {
    long long d = q[i][0] - '0';
    long long l = 0, m = 0;
    for (long long j = 3; j < q[i].size(); j++) {
      long long c = q[i][j] - '0';
      l += len[c];
      m = (m * bix(10, len[c]) + val[c]) % mod;
    }
    val[d] = m;
    len[d] = l % (mod - 1);
  }
  long long ans = 0;
  for (long long i = 0; i < s.size(); i++) {
    long long c = s[i] - '0';
    ans = (bix(10, len[c]) * ans + val[c]) % mod;
  }
  cout << ans << endl;
}
