#include <bits/stdc++.h>
namespace pb_ds {
namespace io {
const int MaxBuff = 1 << 15;
const int Output = 1 << 23;
char B[MaxBuff], *S = B, *T = B;
char Out[Output], *iter = Out;
inline void flush() {
  fwrite(Out, 1, iter - Out, stdout);
  iter = Out;
}
}  // namespace io
template <class Type>
inline Type Read() {
  using namespace io;
  register char ch;
  register Type ans = 0;
  register bool neg = 0;
  while (ch = ((S == T) && (T = (S = B) + fread(B, 1, MaxBuff, stdin), S == T)
                   ? 0
                   : *S++),
         (ch < '0' || ch > '9') && ch != '-')
    ;
  ch == '-' ? neg = 1 : ans = ch - '0';
  while (ch = ((S == T) && (T = (S = B) + fread(B, 1, MaxBuff, stdin), S == T)
                   ? 0
                   : *S++),
         '0' <= ch && ch <= '9')
    ans = ans * 10 + ch - '0';
  return neg ? -ans : ans;
}
template <class Type>
inline void Print(register Type x, register char ch = '\n') {
  using namespace io;
  if (!x)
    *iter++ = '0';
  else {
    if (x < 0) *iter++ = '-', x = -x;
    static int s[100];
    register int t = 0;
    while (x) s[++t] = x % 10, x /= 10;
    while (t) *iter++ = '0' + s[t--];
  }
  *iter++ = ch;
}
}  // namespace pb_ds
using namespace pb_ds;
using namespace std;
const int N = 2e6 + 5;
const int Mod = 998244353;
inline void ad(int &x, int y) {
  x += y;
  if (x >= Mod) x -= Mod;
}
inline int Pow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % Mod;
    x = 1ll * x * x % Mod;
    y >>= 1;
  }
  return res;
}
int fac[N], inv[N];
inline void math_init(int nn) {
  fac[0] = 1;
  for (int i = 1; i <= nn; ++i) fac[i] = 1ll * fac[i - 1] * i % Mod;
  inv[nn] = Pow(fac[nn], Mod - 2);
  for (int i = nn; i; --i) inv[i - 1] = 1ll * inv[i] * i % Mod;
}
inline int C(int x, int y) {
  if (x < y || x < 0 || y < 0) return 0;
  return 1ll * (1ll * fac[x] * inv[y] % Mod) * inv[x - y] % Mod;
}
int n, ans = 1, m, tot, k;
int p[N], a[N], cnt[N];
int main() {
  math_init(N - 5);
  n = k = Read<int>();
  for (int i = 1; i <= n; ++i) m = max(m, a[i] = Read<int>());
  for (int i = 1; i <= n; ++i) {
    ++p[a[i] + 1];
    for (int j = a[i] + 1; j <= m; j += n) ++cnt[j];
  }
  for (int i = 1; i <= m; ++i) {
    ++tot, k -= p[i];
    if (tot < cnt[i]) break;
    tot -= cnt[i];
    ad(ans, C(tot + n - 1, n - 1));
    ad(ans, Mod - C(tot - k + n - 1, n - 1));
  }
  printf("%d\n", ans);
  return 0;
}
