#include <bits/stdc++.h>
using namespace std;
int getint() {
  unsigned int c;
  int x = 0;
  while (((c = getchar()) - '0') >= 10) {
    if (c == '-') return -getint();
    if (!~c) exit(0);
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while (((c = getchar()) - '0') < 10);
  return x;
}
int getstr(char* s) {
  int c, n = 0;
  while ((c = getchar()) <= ' ') {
    if (!~c) exit(0);
  }
  do {
    s[n++] = c;
  } while ((c = getchar()) > ' ');
  s[n] = 0;
  return n;
}
template <class T>
inline bool chmin(T& a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
int cache[1111][1111];
int solve(int rem1, int rem2) {
  int& res = cache[rem1][rem2];
  if (~res) return res;
  if (rem1 == 0 && rem2 == 0) return res = 1;
  if (rem1 == 0) return res = solve(rem1, rem2 - 1) + 1;
  if (rem2 == 0) return res = solve(rem1 - 1, rem2) + 1;
  res = 1;
  res += solve(rem1 - 1, rem2);
  res += solve(rem1, rem2 - 1);
  return res;
}
const int MOD = 1000000007;
struct modint {
  int v;
  modint() : v(0) {}
  modint(int a) : v(a) {
    if (v < 0) v += MOD;
    if (v >= MOD) v -= MOD;
  }
  modint(long long a) {
    if (a < 0) a = a % MOD + MOD;
    if (a >= MOD) a = a % MOD;
    v = a;
  }
  void clear() { v = ~0; }
  bool is() { return ~v; }
  int to_int() { return v; }
  modint& operator+=(modint x) { return *this = v + x.v; }
  modint& operator-=(modint x) { return *this = MOD + v - x.v; }
  modint& operator*=(modint x) { return *this = (long long)v * x.v; }
  modint operator+(modint x) const { return modint(v) += x; }
  modint operator-(modint x) const { return modint(v) -= x; }
  modint operator*(modint x) const { return modint(v) *= x; }
  modint operator-() { return modint(0) - *this; }
};
ostream& operator<<(ostream& os, modint x) {
  os << x.v;
  return os;
}
modint mod_pow(modint x, long long n) {
  modint y = 1;
  for (; n; x *= x, n >>= 1)
    if (n & 1) y *= x;
  return y;
}
modint mod_inv(modint x) {
  long long u1 = 1, u2 = 0, u3 = MOD, v1 = 0, v2 = 1, v3 = x.v, q, t1, t2, t3;
  while (v3)
    q = u3 / v3, t1 = u1 - v1 * q, u1 = v1, v1 = t1, t3 = u3 - v3 * q, u3 = v3,
    v3 = t3, t2 = u2 - v2 * q, u2 = v2, v2 = t2;
  if (u2 < 0) u2 += MOD;
  return u2;
}
modint& operator/=(modint& x, modint y) { return x *= mod_inv(y); }
modint operator/(modint x, modint y) { return x /= y; }
const int PREPN = 3000111;
modint inv[PREPN], perm[PREPN], permInv[PREPN];
modint cmbC(int n, int k) {
  return (k < 0 or n < k) ? 0 : perm[n] * permInv[k] * permInv[n - k];
}
modint cmbH(int n, int k) { return cmbC(n + k - 1, k); }
void prepare() {
  perm[0] = permInv[0] = 1;
  for (int i = 1; i < PREPN; i++) {
    i == 1 ? inv[i] = 1 : inv[i] = -modint(MOD / i) * inv[MOD % i];
    perm[i] = perm[i - 1] * i;
    permInv[i] = permInv[i - 1] * inv[i];
  }
}
modint solve(int n) {
  modint res = perm[2 * n - 1] * 2 / (perm[n] * perm[n - 1]) - 1;
  return res;
}
int main() {
  int i, j, tcc, tc = 1 << 28;
  prepare();
  for (tcc = 0; tcc < tc; tcc++) {
    int n = getint() + 1;
    cout << solve(n) << endl;
  }
  return 0;
}
