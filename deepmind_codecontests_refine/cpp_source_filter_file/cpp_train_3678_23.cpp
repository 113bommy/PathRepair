#include <bits/stdc++.h>
using namespace std;
inline void read() {}
template <typename T, typename... Ts>
inline void read(T& A, Ts&... As) {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  A = x * f, read(As...);
}
inline void write(char a) { putchar(a); }
template <typename T>
inline void write(T a) {
  if (a < 0ll) putchar('-'), a = -a;
  if (a > 9ll) write(a / 10ll);
  putchar(a % 10ll + '0');
}
template <typename T, typename... Ts>
inline void write(T A, Ts... As) {
  write(A), write(As...);
}
const int N = 100010;
int n, m, u, v, mod;
long long res = 1, cnt;
int fa[N], siz[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline long long qpow(long long a, long long b, long long mod) {
  long long ans = 1;
  a %= mod;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1, a = a * a % mod;
  }
  return ans % mod;
}
signed main() {
  read(n, m, mod);
  for (register int i = 1; i <= n; ++i) fa[i] = i;
  for (register int i = 1; i <= m; ++i) read(u, v), fa[find(u)] = find(v);
  for (register int i = 1; i <= n; ++i) ++siz[find(i)];
  for (register int i = 1; i <= n; ++i)
    if (siz[i]) (res *= siz[i]) %= mod, ++cnt;
  write(cnt == 1 ? 0 : res * qpow(n, cnt - 2, mod) % mod);
  return 0;
}
