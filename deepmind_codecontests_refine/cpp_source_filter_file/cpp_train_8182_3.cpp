#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, lim = 1e5 + 10, mod = 1e9 + 7;
int n;
int cnt[maxn];
long long f[maxn], g[maxn];
long long sum = 0, ans = 0;
long long qpow(long long x, long long y) {
  long long ret = 1, bas = x;
  while (y) {
    if (y & 1) ret = ret * bas % mod;
    bas = bas * bas % mod;
    y >>= 1;
  }
  return ret;
}
int main() {
  cin >> n;
  for (int l = 1; l <= n; l++) {
    int wy;
    cin >> wy;
    cnt[wy]++;
    sum = (sum + (wy) + mod) % mod;
  }
  ans = (ans + (-sum * (sum - 1) % mod) + mod) % mod;
  g[0] = (sum - 1) * qpow(mod - sum, mod - 2) % mod;
  for (int l = 1; l <= lim; l++) {
    g[l] = g[l - 1] + (sum - 1) * qpow(mod + l - sum, mod - 2) % mod;
    g[l] %= mod;
    f[l] = f[l - 1] + g[l - 1];
    ans = (ans + (-f[l] * cnt[l] % mod) + mod) % mod;
  }
  cout << mod - ans << endl;
}
