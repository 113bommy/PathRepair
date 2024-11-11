#include <bits/stdc++.h>
using namespace std;
const int maxn = 14;
struct mat {
  long long x, y, u, v, mod;
  mat(long long a = 0, long long b = 0, long long c = 0, long long d = 0,
      long long e = 0)
      : x(a), y(b), u(c), v(d), mod(e) {}
  long long mul(long long x, long long y, long long mod) {
    if (y == 0) return 0;
    if (y == 1) return x;
    long long s = mul(x, y / 2, mod);
    return y & 1 ? ((s + s) % mod + x) % mod : (s + s) % mod;
  }
  mat operator*(const mat &ot) {
    mat ret;
    ret.mod = mod;
    ret.x = (mul(x, ot.x, mod) + mul(y, ot.u, mod)) % mod;
    ret.y = (mul(x, ot.y, mod) + mul(y, ot.v, mod)) % mod;
    ret.u = (mul(u, ot.x, mod) + mul(v, ot.u, mod)) % mod;
    ret.v = (mul(u, ot.y, mod) + mul(v, ot.v, mod)) % mod;
    return ret;
  }
};
long long cycle[maxn], n;
void prepare() {
  cycle[0] = 1;
  cycle[1] = 60;
  cycle[2] = 300;
  cycle[3] = 1500;
  for (int i = 4; i < maxn; i++) cycle[i] = cycle[i - 1] * 10;
}
mat power(long long a, long long mod) {
  if (a == 1) return mat(1, 1, 1, 0, mod);
  mat s = power(a / 2, mod);
  return a & 1 ? s * s * mat(1, 1, 1, 0, mod) : s * s;
}
long long fac(long long a, long long mod) {
  if (a == 1) return 0;
  if (a == 2) return 1;
  return power(a - 2, mod).x;
}
long long solve() {
  long long p = 10;
  map<long long, bool> a[maxn];
  int x = 0, y = 1;
  for (int i = 1; i <= 60; i++) {
    if (x == n % p) a[0][i] = 1;
    int z = (x + y) % p;
    x = y;
    y = z;
  }
  for (int i = 1; i < maxn - 1; i++) {
    p *= 10;
    for (map<long long, bool>::iterator it = a[i - 1].begin();
         it != a[i - 1].end(); it++) {
      for (long long x = it->first; x <= cycle[i + 1]; x += cycle[i]) {
        long long t = fac(x, p);
        if (t != n % p) continue;
        a[i][x] = 1;
      }
    }
  }
  if (a[maxn - 2].empty())
    return 0;
  else
    return (a[maxn - 2].begin())->first;
}
int main() {
  prepare();
  cin >> n;
  cout << solve() - 1 << endl;
  return 0;
}
