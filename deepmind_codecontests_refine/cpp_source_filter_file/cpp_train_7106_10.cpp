#include <bits/stdc++.h>
using namespace std;
const long long N = 1030;
const long long mod = 1e9 + 7;
long long bp(long long x, long long y) {
  long long ans = 1;
  x %= mod;
  while (y) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long mod_inverse(long long x) { return bp(x, mod - 2); }
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long max(long long a, long long b) {
  if (a < b) swap(a, b);
  return a;
}
long long min(long long a, long long b) {
  if (a > b) swap(a, b);
  return a;
}
long long countSetBits(long long n) {
  long long count = 0;
  while (n) {
    count += n & 1;
    n >>= 1;
  }
  return count;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long b[m];
  for (long long i = 0; i < m; i++) cin >> b[i];
  long long ans = 1e18 + 5;
  for (long long i = 4; i < (1 << 9); i++) {
    long long flag = 1;
    for (long long j = 0; j < n; j++) {
      flag = 1;
      for (long long k = 0; k < m; k++)
        if (((a[j] & b[k]) | i) == i) {
          flag = 0;
          break;
        }
      if (flag == 1) break;
    }
    if (flag == 0) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
}
signed main() { solve(); }
