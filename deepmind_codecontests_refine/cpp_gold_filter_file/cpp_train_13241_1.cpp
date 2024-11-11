#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long n, k, a[N];
map<long long, long long> cnt;
long long w[N], ans;
long long qpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = r * a;
    b >>= 1;
    a = a * a;
  }
  return r;
}
int32_t main() {
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  long long LIM = 0;
  if (k > 40)
    LIM = 1;
  else {
    while (qpow(LIM, k) <= 1e10) ++LIM;
  }
  if (k > 2) {
    for (long long i = 1; i <= LIM; ++i) w[i] = qpow(i, k);
    for (long long i = 1; i <= n; ++i) {
      for (long long j = 1; j <= LIM; ++j)
        if (w[j] % a[i] == 0) ans += cnt[w[j] / a[i]];
      cnt[a[i]]++;
    }
  } else {
    for (long long i = 1; i <= n; ++i) {
      long long x = a[i], w = 1;
      for (long long j = 2; j * j <= x; ++j)
        if (x % j == 0) {
          long long c = 0;
          while (x % j == 0) x /= j, c++;
          if (c & 1) w *= j;
        }
      if (x > 1) w *= x;
      ans += cnt[w];
      cnt[w]++;
    }
  }
  cout << ans << endl;
}
