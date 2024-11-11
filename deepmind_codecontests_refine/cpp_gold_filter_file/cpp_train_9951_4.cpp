#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 1;
const long long int mod = 1e9 + 7;
long long int fac[N], inv[N];
long long int binpow(long long int x, long long int pow) {
  long long int res = 1ll;
  while (pow) {
    if (pow & 1) res = res * x % mod;
    x = x * x % mod;
    pow /= 2;
  }
  return res;
}
void build() {
  int i;
  fac[0] = 1ll;
  for (i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[N - 1] = binpow(fac[N - 1], mod - 2);
  for (i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
long long int nCk(int n, int k) {
  return fac[n] * inv[k] % mod * inv[n - k] % mod;
}
int main() {
  build();
  string s;
  cin >> s;
  int i, l = 0, r = 0, n = s.size();
  for (i = 0; i < n; i++)
    if (s[i] == ')') r++;
  long long int ans = 0ll;
  for (i = 0; i < n; i++) {
    if (s[i] == '(')
      l++;
    else
      r--;
    if (s[i] == '(') ans = (ans + nCk(l + r - 1, r - 1) % mod) % mod;
  }
  printf("%lld", ans);
}
