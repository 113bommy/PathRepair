#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long Inf = 1e10;
const int P = 1e9 + 7;
const int N = 100005;
inline long long IN() {
  long long x = 0;
  int ch = 0, f = 0;
  for (ch = getchar(); ch != -1 && (ch < 48 || ch > 57); ch = getchar())
    f = (ch == '-');
  for (; ch >= 48 && ch <= 57; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  return f ? (-x) : x;
}
template <typename T>
inline int chkmin(T &a, const T &b) {
  if (b < a) return a = b, 1;
  return 0;
}
template <typename T>
inline int chkmax(T &a, const T &b) {
  if (b > a) return a = b, 1;
  return 0;
}
void renew(int &x, const int &y) {
  x += y;
  if (x >= P) x -= P;
  if (x < 0) x += P;
}
int Pow(int x, int y, int p) {
  int a = 1;
  for (; y; y >>= 1, x = (long long)x * x % p)
    if (y & 1) a = (long long)a * x % p;
  return a;
}
int K;
long long l, r;
struct comp {
  int re, im;
  comp() {}
  comp(int a, int b) : re(a), im(b) {}
  comp conj() { return comp(re, (P - im) % P); }
  int norm() { return ((1LL * re * re - 5LL * im * im) % P + P) % P; }
  comp operator+(const comp &a) const {
    return comp((re + a.re) % P, (im + a.im) % P);
  }
  comp operator-(const comp &a) const {
    return comp((re - a.re + P) % P, (im - a.im + P) % P);
  }
  comp operator*(const comp &a) const {
    return comp((1LL * re * a.re + 5LL * im * a.im) % P,
                (1LL * re * a.im + 1LL * im * a.re) % P);
  }
  comp operator*(const int &a) const {
    return comp(1LL * re * a % P, 1LL * im * a % P);
  }
  comp operator/(comp a) const {
    comp b = a.conj();
    comp c = (*this) * b;
    int v = b.norm();
    v = Pow(v, P - 2, P);
    return c * v;
  }
} one, zero, phi, inv, invk, inv5, chg;
comp Pow(comp x, long long y) {
  comp ans = one;
  for (; y; y >>= 1, x = x * x)
    if (y & 1) ans = ans * x;
  return ans;
}
int f[505], s[505][505];
int c[505][505];
int calc(long long x, int K) {
  comp lam = Pow(inv, K), Lam;
  comp ans = zero;
  for (int j = (int)(0); j <= (int)(K); j++) {
    comp res = zero;
    if (lam.re == one.re && lam.im == one.im) {
      res = comp(x % P, 0);
    } else {
      res = (lam - Pow(lam, x + 1)) / (one - lam);
    }
    res = res * c[K][j];
    if ((K - j) & 1)
      ans = ans - res;
    else
      ans = ans + res;
    lam = lam * chg;
  }
  ans = ans * Pow(inv5, K);
  return ans.re;
}
int F(long long x) {
  for (int i = (int)(0); i <= (int)(K); i++) f[i] = calc(x, i);
  int ans = 0;
  for (int i = (int)(0); i <= (int)(K); i++) {
    int val = 1LL * s[K][i] * f[i] % P;
    if ((K - i) & 1)
      renew(ans, -val);
    else
      renew(ans, val);
  }
  for (int i = (int)(1); i <= (int)(K); i++)
    ans = 1LL * ans * Pow(i, P - 2, P) % P;
  return ans;
}
int main() {
  one = comp(1, 0);
  phi = comp(1, 1) / comp(2, 0);
  inv = comp(1, P - 1) / comp(2, 0);
  chg = phi / inv;
  zero = comp(0, 0);
  inv5 = one / comp(0, 1);
  s[0][0] = 1;
  for (int i = (int)(1); i <= (int)(200); i++)
    for (int j = (int)(0); j <= (int)(i); j++) {
      s[i][j] = (s[i - 1][j - 1] + 1LL * s[i - 1][j] * (i - 1) % P);
    }
  for (int i = (int)(0); i <= (int)(200); i++) {
    c[i][0] = 1;
    for (int j = (int)(1); j <= (int)(i); j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
  }
  cin >> K >> l >> r;
  cout << (F(r + 2) - F(l + 1) + P) % P << endl;
  return 0;
}
