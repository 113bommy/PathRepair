#include <bits/stdc++.h>
using namespace std;
namespace Legendgod {
namespace Read {
template <typename T>
void r1(T &x) {
  x = 0;
  int f(1);
  char c(getchar());
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x * 10) + (c ^ 48);
  x *= f;
}
template <typename T, typename... Args>
void r1(T &x, Args &...arg) {
  r1(x), r1(arg...);
}
}  // namespace Read
using namespace Read;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int n, a[maxn];
int f[2][maxn];
vector<int> buc[2];
void Solve() {
  int i, j;
  r1(n);
  for (i = 1; i <= n; ++i) r1(a[i]);
  for (int v : buc[0]) f[0][v] = 0;
  for (int v : buc[1]) f[1][v] = 0;
  buc[0].clear(), buc[1].clear();
  int ans(0);
  for (i = n; i >= 1; --i) {
    int now = (i & 1), bef(now ^ 1);
    for (int v : buc[now]) f[now][v] = 0;
    buc[now].clear();
    buc[now].push_back(a[i]);
    f[now][a[i]] = 1;
    int last = a[i];
    for (int v : buc[bef]) {
      int K = (a[i] + v - 1) / v;
      int st = a[i] / K;
      ans = (ans + 1ll * (K - 1) * i % mod * f[bef][v] % mod) % mod;
      f[now][st] = (f[now][st] + f[bef][v]) % mod;
      if (last != st) buc[now].push_back(st), last = st;
    }
  }
  printf("%d\n", ans);
}
signed main() {
  int i, j, T;
  r1(T);
  while (T--) Solve();
  return 0;
}
}  // namespace Legendgod
signed main() { return Legendgod::main(), 0; }
