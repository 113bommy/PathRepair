#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper")
using namespace std;
const long long mod = (1e9 + 7);
const double eps = (1e-9);
const long long oo = (long long)(1e18 + 5);
long long qp(long long b, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}
long long fac[(long long)(1e5 + 5)], ifac[(long long)(1e5 + 5)];
long long comb(int n, int m) {
  long long den = (ifac[m] * ifac[n - m]) % mod;
  return (fac[n] * den) % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  fac[0] = 1;
  for (int i = 1; i < (long long)(1e5 + 5); i++)
    fac[i] = (fac[i - 1] * i) % mod;
  ifac[(long long)(1e5 + 5) - 1] = qp(fac[(long long)(1e5 + 5) - 1], mod - 2);
  for (int i = (long long)(1e5 + 5) - 2; i >= 0; i--)
    ifac[i] = (ifac[i + 1] * (i + 1)) % mod;
  long long n, k;
  cin >> n >> k;
  int extras = 0;
  vector<int> fs(n + 1);
  map<int, int> first;
  fs[0] = k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == -1) {
      extras++;
      continue;
    }
    fs[first[x]]--;
    first[x]++;
    fs[first[x]]++;
  }
  vector<long long> mx(n + 1), nx(n + 1);
  for (int i = 0; i <= n; i++) {
    long long inv_den = qp(((n + (k - 2) * i) % mod), mod - 2);
    nx[i] = (i * k) % mod;
    mx[i] = n - i;
    long long div = 1, men = 0;
    if (i) {
      long long m1 = ((k - 1) * i) % mod;
      men = (m1 * mx[i - 1]) % mod;
      men = (men * inv_den) % mod;
      nx[i] = (nx[i] + m1 * nx[i - 1]) % mod;
    }
    div = (div - men + mod) % mod;
    inv_den = (inv_den * qp(div, mod - 2)) % mod;
    mx[i] = (mx[i] * inv_den) % mod;
    nx[i] = (nx[i] * inv_den) % mod;
  }
  vector<long long> vs(n + 1);
  vs[n] = nx[n];
  for (int i = n - 1; i >= 0; i--) vs[i] = (vs[i + 1] * mx[i] + nx[i]) % mod;
  vector<long long> adds(n + 1);
  for (int i = 0; i <= extras; i++)
    adds[i] = (qp(k - 1, extras - i) * comb(extras, i)) % mod;
  long long tot = qp(k, extras);
  long long sum = ((k - 1) * vs[0] + vs[n]) % mod;
  long long ans = mod - ((tot * sum) % mod);
  for (int i = n; i >= 0; i--)
    if (fs[i]) {
      long long x = fs[i];
      fs[i] = 0;
      for (int j = 0; j <= extras; j++)
        fs[i + j] = (fs[i + j] + x * adds[j]) % mod;
    }
  for (int i = 0; i <= n; i++) ans = (ans + fs[i] * vs[i]) % mod;
  ans = (ans * qp(tot, mod - 2)) % mod;
  cout << (ans) << '\n';
  return 0;
}
