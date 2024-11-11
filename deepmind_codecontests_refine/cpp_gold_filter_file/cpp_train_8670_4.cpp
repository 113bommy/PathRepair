#include <bits/stdc++.h>
using namespace std;
long long gcdex(long long a, long long b, long long& x, long long& y) {
  long long ax = 1, ay = 0;
  long long bx = 0, by = 1;
  while (b) {
    long long r = a / b;
    long long t = a - r * b;
    a = b;
    b = t;
    long long tx = ax - r * bx;
    ax = bx;
    bx = tx;
    long long ty = ay - r * by;
    ay = by;
    by = ty;
  }
  x = ax;
  y = ay;
  return a;
}
long long modinv(long long a, long long mod) {
  long long x, y;
  gcdex(a, mod, x, y);
  if (x < 0) {
    x += mod;
  }
  return x;
}
const int N = 1e5;
const int M = 1e9 + 7;
template <int S>
struct Comb {
  long long r[S + 1];
  long long f[S + 1];
  long long mod;
  Comb(int m) {
    mod = m;
    f[0] = 1;
    r[0] = 1;
    for (long long i = 1; i <= S; i++) {
      f[i] = i * f[i - 1] % m;
      r[i] = modinv(i, m) * r[i - 1] % m;
    }
  }
  long long c(int n, int i) {
    if (i < 0 || n < i) {
      return 0;
    }
    return f[n] * r[i] % mod * r[n - i] % mod;
  }
};
Comb<N> comb(M);
long long C(int n, int i) { return comb.c(n, i); }
long long powmod(long long p, long long n, long long mod) {
  long long q = p % mod;
  long long pow = 1;
  while (n) {
    if (n & 1) {
      pow *= q;
      pow %= mod;
    }
    q = q * q;
    q %= mod;
    n /= 2;
  }
  return pow;
}
bool ok(int v) {
  if (v == 0) {
    return false;
  }
  while (v) {
    long long r = v % 10;
    if (r == 4 || r == 7) {
    } else {
      return false;
    }
    v /= 10;
  }
  return true;
}
long long mem[1030][1030];
vector<int> cs;
int S;
int K;
long long f(int s, int r) {
  if (mem[s][r] >= 0) {
    return mem[s][r];
  }
  if (s == cs.size()) {
    return mem[s][r] = C(S, K - r);
  }
  long long ret = f(s + 1, r) + cs[s] * f(s + 1, r + 1) % M;
  ret %= M;
  return mem[s][r] = ret;
}
int main() {
  int n, k;
  cin >> n >> k;
  K = k;
  map<int, int> ls;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (ok(a)) {
      ls[a]++;
    } else {
      S++;
    }
  }
  for (auto c : ls) {
    cs.push_back(c.second);
  }
  memset(mem, -1, sizeof(mem));
  printf("%lld\n", f(0, 0));
  return 0;
}
