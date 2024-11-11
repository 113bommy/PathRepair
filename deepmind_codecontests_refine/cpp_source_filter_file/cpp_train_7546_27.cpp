#include <bits/stdc++.h>
using namespace std;
const long long m = 1e9 + 7;
long long modpow(long long a, long long b) {
  if (b == 0) return 1;
  long long u = modpow(a, b >> 1);
  u = u * u;
  u = u % m;
  if (b & 1) return (a * u) % m;
  return u;
}
const long long s = 2e5 + 8;
long long inv[s];
long long fac[s];
void init() {
  fac[0] = 1;
  fac[1] = 1;
  for (int i = 2; i < s; i++) {
    fac[i] = (i * fac[i - 1]) % m;
  }
  for (int i = 0; i < s; i++) {
    inv[i] = modpow(fac[i], m - 2);
  }
}
int main() {
  long long n;
  init();
  cin >> n;
  long long ans = fac[2 * n - 1] * inv[n];
  ans = ans % m;
  ans = ans * (inv[n - 1]);
  ans = ans % m;
  ans = ans << 1;
  ans = ans - n;
  cout << ans;
}
