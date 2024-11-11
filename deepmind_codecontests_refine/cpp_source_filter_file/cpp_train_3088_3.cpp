#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T>
inline void uin(T &a, T b) {
  if (b < a) a = b;
}
template <typename T>
inline void uax(T &a, T b) {
  if (b > a) a = b;
}
const long long mod = 1e9 + 9;
inline void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
}
inline long long madd(long long x, long long y) {
  add(x, y);
  return x;
}
inline void mull(long long &x, long long y) {
  x *= y;
  x %= mod;
}
inline long long mult(long long x, long long y) {
  mull(x, y);
  return x;
}
long long pw(long long a, long long k) {
  if (k == 0) return 1;
  long long lol = pw(a, k >> 1LL);
  if (k & 1) {
    return mult(mult(lol, lol), a);
  }
  return mult(lol, lol);
}
inline void divide(long long &a, long long b) { a = mult(a, pw(b, mod - 2)); }
inline long long getdiv(long long a, long long b) {
  return mult(a, pw(b, mod - 2));
}
signed main() {
  ios_base::sync_with_stdio(false);
  long long n, a, b, k;
  cin >> n >> a >> b >> k;
  long long B = 0;
  for (long long i = 1; i <= (long long)k; ++i) {
    char c;
    cin >> c;
    long long kek = mult(pw(a, n - i + 1), pw(b, i - 1));
    if (c == '-') {
      add(B, -kek);
    } else {
      add(B, kek);
    }
  }
  long long q = getdiv(pw(b, k), pw(a, k));
  if (q == 1) {
    cout << mult(q, (n + 1) / q) << "\n";
  } else {
    cout << getdiv(madd(mult(B, pw(q, (n + 1) / k)), -B), q - 1) << "\n";
  }
  return 0;
}
