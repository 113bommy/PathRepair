#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long qpow(long long a, long long n) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return ans;
}
string a;
long long k;
int main() {
  cin >> a;
  scanf("%lld", &k);
  long long len = a.length();
  long long ans = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (a[i] == '0' || a[i] == '5') ans = (qpow(2, i) + ans) % mod;
  }
  long long inv = qpow((qpow(2, len) - 1 + mod) % mod, mod - 2);
  long long Sn = ans * ((qpow(2, k * len) - 1 + mod) % mod) % mod * inv % mod;
  printf("%lld\n", Sn);
  return 0;
}
