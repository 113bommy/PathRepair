#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5, Mo = 998244353;
inline long long read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-') ? 1 : 0, ch = getchar();
  while (isdigit(ch)) x = x * 10ll + (ch ^ 48), ch = getchar();
  return (f) ? -1ll * x : x;
}
long long n, m, a[N], tot, ans, flg;
namespace BF {
long long Swap[11][2], cnt[11], b[11], fac[11], ans;
unordered_map<long long, long long> Mp;
inline bool init(long long x) {
  memset(cnt, 0, sizeof(cnt));
  for (long long i = (1); i <= (n); i++) b[i] = i;
  for (long long i = (1); i <= (x); i++)
    cnt[Swap[i][0]]++, cnt[Swap[i][1]]++, swap(b[Swap[i][0]], b[Swap[i][1]]);
  for (long long i = (1); i <= (n); i++)
    if (cnt[i] > a[i]) return false;
  long long val = 0;
  for (long long i = (1); i <= (n); i++) val = val * 197 + b[i];
  if (!Mp[val]) ans++, Mp[val] = 1;
}
inline void dfs(long long x, long long goal) {
  if (x == goal + 1) return (void)init(goal);
  for (long long i = (1); i <= (n); i++)
    for (long long j = (i); j <= (n); j++)
      Swap[x][0] = i, Swap[x][1] = j, dfs(x + 1, goal), Swap[x][0] = 0,
      Swap[x][1] = 0;
}
inline void doit() {
  fac[0] = 1;
  for (long long i = (1); i <= (10); i++) fac[i] = fac[i - 1] * i % Mo;
  for (long long i = (1); i <= (n); i++) flg += (a[i] == 2);
  if (flg >= n - 1) printf("%lld\n", fac[n]), exit(0);
  tot >>= 1;
  for (long long i = (0); i <= (tot); i++) dfs(1, i);
  printf("%lld\n", ans), exit(0);
}
}  // namespace BF
namespace CTM {
long long fac[N], inv[N], ans;
inline long long ksm(long long x, long long y) {
  long long ans = 1ll;
  while (y) {
    if (y & 1ll) ans = ans * x % Mo;
    x = x * x % Mo;
    y >>= 1ll;
  }
  return ans;
}
inline long long C(long long x, long long y) {
  return fac[x] * inv[y] % Mo * inv[x - y] % Mo;
}
inline void doit() {
  fac[0] = inv[0] = 1;
  for (long long i = (1); i <= (n); i++) fac[i] = fac[i - 1] * i % Mo;
  for (long long i = (1); i <= (n); i++) inv[i] = ksm(fac[i], Mo - 2) % Mo;
  for (long long i = (0); i <= (n / 2); i++)
    ans = (ans +
           fac[i * 2ll] * C(n, i * 2ll) % Mo * ksm(ksm(2, i) % Mo, Mo - 2) %
               Mo * inv[i] % Mo +
           Mo) %
          Mo;
  printf("%lld\n", ans), exit(0);
}
}  // namespace CTM
namespace yh {
long long f[505][505];
inline void doit() {
  f[3][1] = 4, f[3][2] = 6, f[3][3] = 6, f[3][4] = 6;
  for (long long i = (4); i <= (n); i++)
    for (long long j = (1); j <= (n + 1); j++)
      f[i][j] =
          ((j - 1) * f[i - 1][j - 1] % Mo + f[i - 1][j] + f[i - 1][j + 1]) % Mo;
  printf("%lld\n", f[n][tot - n + 1]), exit(0);
}
}  // namespace yh
namespace YH {
long long f[N], gs1 = 0, Fac = 1;
inline void doit() {
  f[0] = f[1] = 1;
  for (long long i = (1); i <= (n); i++) gs1 += (a[i] == 1);
  for (long long i = (2); i <= (gs1); i++)
    f[i] = (f[i - 2] * (i - 1) + f[i - 1]) % Mo;
  for (long long i = (n); i >= (gs1 + 1); i--) Fac = Fac * i % Mo;
  printf("%lld\n", Fac * f[gs1] % Mo), exit(0);
}
}  // namespace YH
signed main() {
  n = read();
  for (long long i = (1); i <= (n); i++) a[i] = read(), tot += a[i];
  if (tot == n) CTM::doit();
  if (n <= 2) BF::doit();
  if (n <= 500) yh::doit();
  if (n <= 1e6) YH::doit();
  return 0;
}
