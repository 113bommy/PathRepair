#include <bits/stdc++.h>
using namespace std;
const long long N = 2050, p = 1e9 + 7;
long long n, a[N];
long long b[N];
long long fc[N], fcinv[N];
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return res;
}
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] > 0) b[a[i]]++;
  }
  long long cnt = 0, tt = 0;
  for (long long i = 1; i <= n; ++i) {
    if (a[i] == -1) {
      ++tt;
      if (b[i]) ++cnt;
    }
  }
  fc[0] = 1;
  for (long long i = 1; i < N; ++i) fc[i] = fc[i - 1] * i % p;
  fcinv[N - 1] = qpow(fc[N - 1], p - 2);
  for (long long i = N - 2; i >= 0; --i) fcinv[i] = (i + 1) * fcinv[i + 1] % p;
  long long res = fc[tt];
  for (long long i = 1; i <= tt - cnt; ++i) {
    (((res += (i % 2 ? -1 : 1) * fc[tt - cnt] * fcinv[tt - cnt - i] % p *
              fcinv[i] % p * fc[tt - i] % p) %= p) += p) %= p;
  }
  cout << res;
  return 0;
}
