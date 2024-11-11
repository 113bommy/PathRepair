#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long powermodm(long long x, long long n, long long M) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
long long power(long long _a, long long _b) {
  long long _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a);
    _b /= 2;
    _a = (_a * _a);
  }
  return _r;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long ind = n / 2;
  long long l = a[ind], r = 1e12, ans = a[ind];
  while (l <= r) {
    long long mid = (l + r) >> 1, tmp = 0;
    for (long long i = ind; i < n; i++) {
      if (a[i] < mid) tmp += (mid - a[i]);
    }
    if (tmp <= k) {
      l = mid + 1;
      ans = max(ans, mid);
    } else
      r = mid - 1;
  }
  cout << ans;
  return 0;
}
