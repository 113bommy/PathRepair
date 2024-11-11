#include <bits/stdc++.h>
using namespace std;
template <int size>
class NoCombination {
 public:
  long long fac[size], inv[size], f[size];
  long long mod;
  void init(long long m) {
    mod = m;
    fac[0] = fac[1] = inv[0] = inv[1] = f[0] = f[1] = 1;
    for (int i = 2; i < size; i++) {
      fac[i] = fac[i - 1] * i % mod;
      f[i] = (mod - mod / i) * f[mod % i] % mod;
      inv[i] = inv[i - 1] * f[i] % mod;
    }
  }
  long long C(long long a, long long b) {
    return fac[a] * inv[b] % mod * inv[a - b] % mod;
  }
};
int cmp(const void *x, const void *y) {
  int dx = *((int *)(x)), dy = *((int *)(y));
  return dx > dy ? 1 : -1;
}
NoCombination<100005> nc;
const long long mod = 1000000007;
bool f[1000005];
int p[1000005], m = 0;
inline long long pow(long long a, long long b, long long p) {
  long long rtn = 1;
  while (b) {
    if (b & 1) rtn = rtn * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return rtn;
}
int main() {
  std::ios::sync_with_stdio(0), cin.tie(0);
  nc.init(mod);
  memset(f, true, sizeof(f));
  f[0] = f[1] = false;
  for (int i = 2; i < 1000000; i++) {
    if (f[i]) {
      p[m++] = i;
      for (int j = i + i; j < 1000000; j++) f[j] = false;
    }
  }
  int q, x, y;
  long long ans;
  cin >> q;
  while (q--) {
    cin >> x >> y;
    ans = 1;
    int maxp = (int)sqrt(x);
    for (int i = 0; i < m; i++) {
      if (x == 1 || p[i] > maxp) break;
      if (x % p[i] != 0) continue;
      int cnt = 0;
      while (x % p[i] == 0) x /= p[i], cnt++;
      ans = ans * nc.C(y + cnt - 1, cnt) % mod;
    }
    if (x > 1) ans = ans * y % mod;
    ans = ans * pow(2, y - 1, mod) % mod;
    cout << ans << endl;
  }
  return 0;
}
