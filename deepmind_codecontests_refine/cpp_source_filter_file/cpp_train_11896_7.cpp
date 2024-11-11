#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int LIM = 100005;
long long power(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return (res % mod);
}
int32_t main() {
  long long tt = 1, n, k, x, y, z, i, j;
  while (tt--) {
    long long m, d;
    cin >> n >> d >> m;
    vector<long long> a, b;
    a.push_back(0LL);
    b.push_back(0LL);
    for (i = 0; i < n; i++) {
      cin >> x;
      if (x > m)
        a.push_back(x);
      else
        b.push_back(x);
    }
    long long an = a.size(), bn = b.size();
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    reverse(b.begin() + 1, b.end());
    an--;
    bn--;
    while (a.size() < n) a.push_back(0);
    for (i = 1; i <= an; i++) a[i] += a[i - 1];
    for (i = 1; i <= bn; i++) b[i] += b[i - 1];
    long long t;
    long long ans = 0;
    d++;
    for (i = 0; i <= bn; i++) {
      if (!((n - i) % d))
        t = (n - i) / d;
      else
        t = (n - i) / d + 1;
      ans = max(ans, b[i] + a[t]);
    }
    cout << ans;
  }
}
