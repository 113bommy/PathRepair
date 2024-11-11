#include <bits/stdc++.h>
using namespace std;
unsigned long long x, k;
unsigned long long mod = 1000000007;
unsigned long long p(unsigned long long a, unsigned long long b) {
  if (b < 0) return -1;
  if (b == 0) return 0;
  unsigned long long t = a;
  a = 1;
  while (b) {
    if (b & 1) {
      a *= t;
      a %= mod;
    }
    b /= 2;
    t *= t;
    t %= mod;
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> x >> k;
  if (k == 0) {
    cout << x * 2;
    return 0;
  }
  if (x == 0) {
    cout << 0;
    return 0;
  }
  x %= mod;
  unsigned long long ans = (x * p(2, k + 1)) % mod;
  ans += mod - (p(2, k) - 1);
  cout << ans % mod;
}
