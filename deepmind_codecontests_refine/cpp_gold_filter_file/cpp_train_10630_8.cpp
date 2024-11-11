#include <bits/stdc++.h>
using namespace std;
bool flag = 0;
long long n, m, a, mod = 998244353, inv2, ans = 1;
long long inline modify(long long a) {
  a %= mod;
  if (a < 0) {
    a += mod;
  }
  return a;
}
long long inline qpow(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      res *= a;
      res %= mod;
    }
    a *= a;
    a %= mod;
    p >>= 1;
  }
  return modify(res);
}
long long inline add(long long a, long long b) {
  long long res = a + b;
  return modify(res);
}
long long inline mul(long long a, long long b) {
  long long res = a * b;
  return modify(res);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> a;
  inv2 = qpow(2, mod - 2);
  long long pre = 0;
  for (int i = 1; i <= m; ++i) {
    long long cur;
    cin >> cur;
    long long tmp = qpow(a, cur - pre);
    ans *= modify(qpow(a, 2 * (cur - pre)) - mul(mul(tmp, tmp - 1), inv2));
    ans = modify(ans);
    pre = cur;
  }
  ans *= qpow(a, n - 2 * pre);
  ans %= mod;
  cout << ans << '\n';
}
