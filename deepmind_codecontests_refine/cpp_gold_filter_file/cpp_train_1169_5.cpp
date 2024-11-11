#include <bits/stdc++.h>
long long gi() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
std::mt19937 rnd(time(NULL));
template <class T>
void cxk(T& a, T b) {
  a = a > b ? a : b;
}
template <class T>
void cnk(T& a, T b) {
  a = a < b ? a : b;
}
int pow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % 998244353;
    x = 1ll * x * x % 998244353;
    y >>= 1;
  }
  return ret;
}
template <class Ta, class Tb>
void inc(Ta& a, Tb b) {
  a = a + b >= 998244353 ? a + b - 998244353 : a + b;
}
template <class Ta, class Tb>
void dec(Ta& a, Tb b) {
  a = a >= b ? a - b : a + 998244353 - b;
}
long long p[100];
int sl[19][1 << 17 | 1], sr[19][1 << 17 | 1];
void work(long long* L, long long* R, int p, int s[19][1 << 17 | 1]) {
  int n = R - L;
  for (int i = 0; i < 1 << n; ++i) {
    long long XOR = 0;
    for (int j = 0; j < n; ++j)
      if (i >> j & 1) XOR ^= L[j];
    s[__builtin_popcount(XOR >> p)][XOR & ((1 << p) - 1)]++;
  }
}
int ans[111], A[1 << 17 | 1], B[1 << 17 | 1];
void FWT(int* A, int n, int t) {
  for (int o = 1; o < n; o <<= 1)
    for (int* p = A; p != A + n; p += o << 1)
      for (int i = 0; i < o; ++i) {
        int x = p[i], y = p[i + o];
        p[i] = (x + y) % 998244353, p[i + o] = (x - y + 998244353) % 998244353;
        if (!t)
          p[i] = 1ll * (998244353 + 1 >> 1) * p[i] % 998244353,
          p[i + o] = 1ll * (998244353 + 1 >> 1) * p[i + o] % 998244353;
      }
}
int main() {
  int n = gi(), m = gi(), MUL = 1;
  for (int i = 1; i <= n; ++i) {
    long long x = gi();
    for (int j = m - 1; ~j; --j)
      if (x >> j & 1) {
        if (!p[j]) {
          p[j] = x;
          x = -1;
          break;
        } else
          x ^= p[j];
      }
    if (~x) MUL = 2 * MUL % 998244353;
  }
  for (int i = 0; i < m; ++i)
    if (!p[i]) MUL = 1ll * MUL * (998244353 + 1 >> 1) % 998244353;
  int s = m >> 1;
  work(p, p + s, s, sl), work(p + s, p + m, s, sr);
  for (int i = 0; i < 1 << s; ++i) A[i] = sl[0][i];
  FWT(A, 1 << s, 1);
  for (int i = 0; i <= m - s; ++i) {
    for (int j = 0; j < 1 << s; ++j) B[j] = sr[i][j];
    FWT(B, 1 << s, 1);
    for (int j = 0; j < 1 << s; ++j) B[j] = 1ll * B[j] * A[j] % 998244353;
    FWT(B, 1 << s, 0);
    for (int j = 0; j < 1 << s; ++j) inc(ans[__builtin_popcount(j) + i], B[j]);
  }
  for (int i = 0; i <= m; ++i) printf("%d ", 1ll * MUL * ans[i] % 998244353);
  return 0;
}
