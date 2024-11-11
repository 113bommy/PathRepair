#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long power(long long base, long long exponent, long long modx = mod) {
  long long ret = 1 % modx;
  base %= modx;
  while (exponent) {
    if (exponent & 1) {
      ret = (ret * base) % modx;
    }
    base = (base * base) % modx;
    exponent >>= 1;
  }
  return ret;
}
long long inv(long long val, long long modx = mod) {
  return power(val, modx - 2, modx);
}
vector<long long> fac, ifac;
void preFac(long long sz) {
  fac.resize(sz + 1), ifac.resize(sz + 1);
  fac[0] = 1;
  for (int i = 1; i <= sz; i++) {
    fac[i] = (i * fac[i - 1]) % mod;
  }
  ifac[sz] = inv(fac[sz]);
  for (int i = sz - 1; i >= 0; i--) {
    ifac[i] = ((i + 1) * ifac[i + 1]) % mod;
  }
}
long long nCr(long long N, long long R) {
  if (R <= N && R >= 0) {
    return ((fac[N] * ifac[R]) % mod * ifac[N - R]) % mod;
  }
  return 0;
}
vector<long long> polymul(vector<long long> a, vector<long long> b) {
  vector<long long> ret(a.size() + b.size() - 1, 0);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      ret[i + j] = (ret[i + j] + a[i] * b[j]) % mod;
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  preFac(n + 1);
  vector<int> c(n, 0);
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    c[u - 1]++;
  }
  long long ans = 0;
  vector<long long> pol = {1};
  for (int i = 0; i < n; i++) {
    if (c[i] == 0) continue;
    long long cur = 0;
    if (c[i] >= 2) {
      for (int j = 0; j < pol.size(); j++) {
        long long p1 = pol[j];
        long long sz = j;
        p1 = (p1 * (ifac[n] * fac[n - sz]) % mod) % mod;
        long long p2 = ((long long)c[i] * (c[i] - 1)) % mod;
        p2 = (p2 * inv((n - sz) * (n - sz - 1))) % mod;
        (cur += p1 * p2) %= mod;
      }
    }
    (ans += cur) %= mod;
    pol = polymul(pol, {1, c[i]});
  }
  cout << ans << endl;
  return 0;
}
