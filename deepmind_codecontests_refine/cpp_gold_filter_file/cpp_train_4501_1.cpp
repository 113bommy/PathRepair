#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
long long n, m, ans, t[300000];
long long f(long long x, long long k) {
  if (k == 0) return 1;
  if (k == 1) return x % p;
  long long g = f(x, k / 2);
  g = (g * g) % p;
  if (k % 2 > 0) g = (g * x) % p;
  return g;
}
signed main() {
  iostream::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  t[0] = t[1] = 1;
  for (long long i = 2; i <= m; i++) t[i] = (t[i - 1] * i) % p;
  for (long long h = n - 1; h <= m; h++) {
    long long a = (t[n - 3] * t[h - n + 1]) % p;
    a = f(a, p - 2);
    a = (t[h - 2] * a) % p;
    ans = (ans + (h - 1) * a) % p;
  }
  ans = (f(2ll, n - 3) * ans) % p;
  cout << ans;
  return 0;
}
