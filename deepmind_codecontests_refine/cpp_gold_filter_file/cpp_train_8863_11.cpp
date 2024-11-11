#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long INF = 1e+14;
const long double eps = 1e-8;
const long double pi = acos(-1.0);
long long mod_inverse(long long x) {
  long long n = mod - 2;
  long long ret = 1;
  while (n) {
    if (n & 1) ret = ret * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
struct perm {
 private:
  int sz;
  vector<long long> p, invp;

 public:
  perm(int n) {
    sz = n + 1;
    p.resize(sz), invp.resize(sz);
    p[0] = 1;
    for (int i = 1; i <= sz - 1; i++) {
      p[i] = p[i - 1] * i % mod;
    }
    invp[sz - 1] = 1;
    long long cop = mod - 2, x = p[sz - 1];
    while (cop) {
      if (cop % 2) invp[sz - 1] = invp[sz - 1] * x % mod;
      cop >>= 1;
      x = x * x % mod;
    }
    for (int i = sz - 1 - 1; i >= 0; i--) {
      invp[i] = invp[i + 1] * (i + 1) % mod;
    }
  }
  long long comb(long long x, long long y) {
    if (x < y || y < 0) return 0;
    long long ret = p[x];
    (ret *= invp[y]) %= mod;
    (ret *= invp[x - y]) %= mod;
    return ret;
  }
  long long combP(long long x, long long y) {
    if (x < y || y < 0) return 0;
    return p[x] * invp[x - y] % mod;
  }
  long long pl(int x) { return p[x]; }
  long long invpl(int x) { return invp[x]; }
};
long long inv[10001];
vector<long long> v;
void init() {
  v.push_back(1);
  v.push_back(0);
  long long s = 1;
  for (int i = 3; i < 4053; i += 2) {
    v.push_back(s);
    v.push_back(0);
    s = s * i % mod;
  }
  for (int i = 1; i <= 10000; i++) inv[i] = mod_inverse(i);
}
void solve() {
  init();
  perm p(10000);
  int k, n;
  long long l;
  cin >> n >> k >> l;
  long long ans = 0;
  long long zz = mod_inverse(v[2 * n]);
  for (int i = 0; i < 2 * n - 1; i++) {
    int le = i + 1;
    int ri = 2 * n - le;
    for (int j = k; j <= n; j++) {
      if (j > min(le, ri)) break;
      if ((le - j) % 2) continue;
      long long c = p.comb(le, j) * p.comb(ri, j) % mod * v[le - j] % mod *
                    v[ri - j] % mod;
      c = c * p.pl(j) % mod;
      c = c * zz % mod;
      for (int aa = 1; aa <= 3; aa++) {
        if (le + ri + aa - 2 <= 0) continue;
        c = c * inv[le + ri + aa - 2] % mod;
      }
      c = c * 2 * n % mod * (2 * n - 1) % mod;
      ans = (ans + c) % mod;
    }
  }
  ans = ans * l % mod;
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
