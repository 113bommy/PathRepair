#include <bits/stdc++.h>
using namespace std;
char ch, B[1 << 20], *S = B, *T = B;
long long rdint() {
  long long aa, bb;
  while (ch = (S == T && (T = (S = B) + fread(B, 1, 1 << 20, stdin), S == T)
                   ? 0
                   : *S++),
         !(ch >= '0' && ch <= '9') && ch != '-')
    ;
  ch == '-' ? aa = bb = 0 : (aa = ch - '0', bb = 1);
  while (ch = (S == T && (T = (S = B) + fread(B, 1, 1 << 20, stdin), S == T)
                   ? 0
                   : *S++),
         (ch >= '0' && ch <= '9'))
    aa = aa * 10 + ch - '0';
  return bb ? aa : -aa;
}
long long rdll() {
  long long aa, bb;
  while (ch = (S == T && (T = (S = B) + fread(B, 1, 1 << 20, stdin), S == T)
                   ? 0
                   : *S++),
         !(ch >= '0' && ch <= '9') && ch != '-')
    ;
  ch == '-' ? aa = bb = 0 : (aa = ch - '0', bb = 1);
  while (ch = (S == T && (T = (S = B) + fread(B, 1, 1 << 20, stdin), S == T)
                   ? 0
                   : *S++),
         (ch >= '0' && ch <= '9'))
    aa = aa * 10 + ch - '0';
  return bb ? aa : -aa;
}
long long mod, l, r, k;
struct Matrix {
  long long a[3][3];
  Matrix() { memset(a, 0, sizeof a); }
  Matrix operator*(const Matrix &b) const {
    Matrix res;
    for (long long i = 1; i <= 2; ++i)
      for (long long j = 1; j <= 2; ++j)
        for (long long k = 1; k <= 2; ++k)
          res.a[i][j] = (res.a[i][j] + 1ll * a[i][k] * b.a[k][j] % mod) % mod;
    return res;
  }
} ans, base;
void init() {
  base.a[1][1] = base.a[1][2] = base.a[2][1] = 1;
  ans.a[1][1] = ans.a[1][2] = 1;
}
void qpow(long long b) {
  while (b) {
    if (b & 1) ans = ans * base;
    base = base * base;
    b >>= 1;
  }
}
inline void work() {
  mod = rdll();
  l = rdll();
  r = rdll();
  k = rdll();
  long long id = 0;
  for (register long long i = 1; i * i <= r; ++i) {
    if (r / i - (l - 1) / i >= k) {
      ((id) < (i) ? ((id) = (i)) : (id));
    }
    if (r / (r / i) - (l - 1) / (r / i) >= k) {
      ((id) < (r / i) ? ((id) = (r / i)) : (id));
    }
  }
  if (id <= 2) {
    id = 1 % mod;
    printf("%lld\n", id);
  } else {
    init();
    qpow(id - 2);
    printf("%lld\n", ans.a[1][1] % mod);
  }
}
signed main() {
  work();
  return 0;
}
