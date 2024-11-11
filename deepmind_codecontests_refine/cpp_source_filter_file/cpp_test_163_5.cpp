#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  x *= f;
}
template <typename T, typename... Args>
void read(T &x, Args &...args) {
  read(x), read(args...);
}
template <typename T>
void wrt(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) wrt(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
void wrt(T x, char c) {
  wrt(x), putchar(c);
}
template <typename T1, typename T2>
void wrt(T1 x1, char c1, T2 x2, char c2) {
  wrt(x1, c1), wrt(x2, c2);
}
const int N = 1e5 + 10;
constexpr int mod = 1e9 + 7;
int T, n, m, rb, cb, rd, cd, dr, dc, U, D, P;
int pw(int a, int b) {
  int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
  }
  return res;
}
int inv(int a) { return pw(a, mod - 2); }
int main() {
  read(T);
  while (T--) {
    read(n, m, rb, cb, rd, cd, P);
    P = (1 - 1ll * P * inv(100) % mod + mod) % mod;
    dr = dc = D = 1, U = 0;
    for (int round = 1; round <= 4 * (n - 1) * (m - 1); round++) {
      if (rb + dr < 1 || rb + dr > n) dr = -dr;
      if (cb + dc < 1 || cb + dc > m) dc = -dc;
      rb += dr, cb += dc, U = (U + 1) % mod;
      if (rb == rd || cb == cd) U = 1ll * U * P % mod, D = 1ll * D * P % mod;
    }
    D = (1 - D + mod) % mod;
    wrt(1ll * U * inv(D) % mod, '\n');
  }
  return 0;
}
