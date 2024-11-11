#include <bits/stdc++.h>
namespace FAST_IO {
template <class T>
inline void read(T &x) {
  T flag = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  }
  x *= flag;
}
template <class T, class... _T>
inline void read(T &x, _T &...y) {
  return read(x), read(y...);
}
template <class T>
inline void write(T x, char ed = '\n') {
  static short st[30];
  short tp = 0;
  if (x < 0) putchar('-'), x = -x;
  do st[++tp] = x % 10, x /= 10;
  while (x);
  while (tp) putchar('0' | st[tp--]);
  putchar(ed);
}
}  // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const long long mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 2e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
long long fac[maxn], ifac[maxn];
long long r;
long long qpow(long long a, long long b, long long mod) {
  long long tmp = a, ans = 1;
  while (b) {
    if (b & 1) ans = ans * tmp % mod;
    tmp = tmp * tmp % mod;
    b >>= 1;
  }
  return ans;
}
void init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mod;
  }
  ifac[n] = qpow(fac[n], mod - 2, mod);
  for (int i = n - 1; i >= 0; i--) {
    ifac[i] = (i + 1) * ifac[i + 1] % mod;
  }
}
long long nCm(int n, int m) {
  if (n < m) return 0;
  return fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}
int sum[maxn][maxn];
int getSum(int x, int y, int l, int r) {
  if (x < l || y < r) return 0;
  return sum[x][y] - sum[l - 1][y] - sum[x][r - 1] + sum[l - 1][r - 1];
}
int ux[maxn], uy[maxn], dx[maxn], dy[maxn];
int cnt[maxn];
int x[maxn], y[maxn], b[maxn];
int main() {
  init(maxn - 5);
  read(n, m, r);
  for (int i = 1; i <= n; i++) {
    read(x[i], y[i], b[i]);
    sum[x[i]][y[i]]++;
  }
  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++) {
      sum[i][j] = sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }
  long long all = nCm(n, m);
  for (int i = 1; i <= n; i++) {
    ux[i] = max(1ll, x[i] - r);
    uy[i] = max(1ll, y[i] - r);
    dx[i] = min(100011ll, x[i] + r);
    dy[i] = min(100011ll, y[i] + r);
    cnt[i] = getSum(dx[i], dy[i], ux[i], uy[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + (all - nCm(n - cnt[i], m) + mod) * b[i] % mod * b[i]) % mod;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      int tux = max(ux[i], ux[j]);
      int tuy = max(uy[i], uy[j]);
      int tdx = min(dx[i], dx[j]);
      int tdy = min(dy[i], dy[j]);
      int cnt1 = cnt[j] - getSum(tdx, tdy, tux, tuy);
      long long t =
          nCm(n - cnt[i], m) + nCm(n - cnt[j], m) - nCm(n - cnt[i] - cnt1, m);
      ans = (ans + (all - t + 2 * mod) * b[i] % mod * b[j]) % mod;
    }
  }
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}
