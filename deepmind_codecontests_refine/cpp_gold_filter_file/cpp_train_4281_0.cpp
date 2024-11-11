#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 5, MOD = 1e9 + 7, eps = 1e-7, INF = 1e9;
const double PI = acos(-1);
int n, q, a, b;
string str;
int acum[maxN];
long long mulmod(long long a, long long b) {
  long long ret = 0;
  while (b) {
    if (b & 1) ret = (ret + a) % MOD;
    b >>= 1, a = (a << 1) % MOD;
  }
  return ret;
}
long long fastPow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = ret * x % MOD;
    n >>= 1, x = mulmod(x, x);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n >> q >> str;
  acum[0] = 0;
  for (int i = int(0); i < int(n); i++) {
    char c = str[i];
    if (c == '0') {
      acum[i + 1] = acum[i];
    } else {
      acum[i + 1] = acum[i] + 1;
    }
  }
  for (int i = int(0); i < int(q); i++) {
    cin >> a >> b;
    long long tot = b - a + 1, ceros = tot - (acum[b] - acum[a - 1]);
    long long ans = (fastPow(2, tot) + MOD - 1) % MOD;
    ans -= (fastPow(2, ceros) + MOD - 1) % MOD;
    ans += MOD;
    ans %= MOD;
    cout << ans << '\n';
  }
  return 0;
}
