#include <bits/stdc++.h>
using namespace std;
long long getint() {
  long long summ = 0, f = 1;
  char ch;
  for (ch = getchar(); !isdigit(ch) && ch != '-'; ch = getchar())
    ;
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  for (; isdigit(ch); ch = getchar())
    summ = (summ << 3) + (summ << 1) + ch - 48;
  return summ * f;
}
const long long mod = 998244353;
long long n, m, jc[500005], ni[500005], ha[500005], pw[500005], k[500005],
    a[500005];
long long ksm(long long x, long long y) {
  if (y == 1) return x;
  long long c = ksm(x, y / 2);
  c = c * c % mod;
  if (y & 1) c = c * x % mod;
  return c;
}
long long C(long long x, long long y) {
  return (jc[x] * ni[y] % mod) * ni[x - y] % mod;
}
long long getsum(long long l, long long r) {
  return ((ha[r] - ha[l - 1] * pw[r - l + 1]) % mod + mod) % mod;
}
string s;
long long ans = 0;
signed main() {
  jc[0] = 1;
  pw[0] = 1;
  for (long long i = 1; i <= 5e5 + 1; i++)
    jc[i] = jc[i - 1] * i % mod, pw[i] = pw[i - 1] * 10 % mod;
  ni[500000] = ksm(jc[500000], mod - 2);
  for (long long i = 500000 - 1; i >= 0; i--) ni[i] = ni[i + 1] * (i + 1) % mod;
  cin >> n >> m;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    a[i + 1] = s[i] - '0';
  }
  for (long long i = n - 1; i >= 1; i--) {
    k[i] = (k[i + 1] + pw[n - i - 1] % mod * C(i - 1, m - 1)) % mod;
  }
  for (long long i = 1; i <= n; i++) {
    k[i] = (k[i] + pw[n - i] * C(i - 1, m)) % mod;
  }
  for (long long i = 1; i <= n; i++) {
    ans += k[i] * a[i];
    ans %= mod;
  }
  cout << (ans % mod + mod) % mod;
  return 0;
}
