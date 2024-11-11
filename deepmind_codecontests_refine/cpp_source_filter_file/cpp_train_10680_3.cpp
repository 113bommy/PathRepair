#include <bits/stdc++.h>
inline int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    ch = getchar();
    if (ch == '-') w = -1;
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * w;
}
using namespace std;
const int N = 5005;
const int M = 2e6 + 5;
const int Mod = 1e9 + 7;
char str[M];
int n, k1, k2, tot, tim, ans;
int s[N], bg[N], vis[N];
int dfn[N], low[N], b[N];
int mn[N], mx[N], cnt[N];
int fac[M], inv[M];
inline void ad(int &x, int y) {
  x += y;
  if (x >= Mod) x -= Mod;
  if (x < 0) x += Mod;
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
vector<int> G[N], g[N], f[N];
stack<int> sta;
int gcd(int x, int y) {
  if (!y) return x;
  return gcd(y, x % y);
}
inline void input() {
  n = read(), k1 = read(), k2 = read();
  for (int i = 1; i <= n; ++i) {
    scanf("%s", str + 1);
    for (int j = 1; j <= n; ++j)
      if (str[j] == '1') G[i].push_back(j);
  }
  for (int i = 1; i <= n; ++i) {
    s[i] = read();
    scanf("%s", str + 1);
    for (int j = 1; j <= s[i]; ++j) {
      g[i].push_back(str[j] - '0');
      mn[i] += str[j] - '0';
    }
  }
}
void tarjan(int x) {
  dfn[x] = low[x] = ++tim;
  sta.push(x), vis[x] = 1;
  for (int i = 0, sz = G[x].size(); i < sz; ++i) {
    int y = G[x][i];
    if (!dfn[y]) {
      tarjan(y);
      low[x] = min(low[x], low[y]);
    } else if (vis[y])
      low[x] = min(low[x], dfn[y]);
  }
  if (low[x] == dfn[x]) {
    int now = 0;
    ++tot;
    do {
      now = sta.top(), sta.pop(), vis[now] = 0;
      b[now] = tot, bg[tot] = gcd(bg[tot], s[now]);
    } while (now != x);
  }
}
namespace sub1 {
inline void build() {
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) tarjan(i);
  for (int i = 1; i <= tot; ++i) f[i].resize(bg[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < s[i]; ++j) f[b[i]][j % bg[b[i]]] |= g[i][j];
}
inline void solve() {
  build();
  for (int i = tot; i > 1; --i) {
    int now = gcd(bg[i], bg[i - 1]);
    for (int j = 0; j < bg[i]; ++j) {
      f[i - 1][j % now] |= f[i][j];
      cnt[i] += f[i][j];
    }
  }
  for (int i = 0; i < bg[1]; ++i) cnt[1] += f[1][i];
  for (int i = 1; i <= n; ++i) mx[i] = cnt[b[i]] * s[i] / bg[b[i]];
}
}  // namespace sub1
namespace sub2 {
inline void solve() {
  for (int i = 1; i <= n; ++i) {
    int cnt1 = 0, cnt2 = 0;
    for (int j = 1; j <= n; ++j) {
      if (i == j) continue;
      if (mn[j] > mx[i])
        ++cnt1;
      else if (mx[j] > mx[i] || (mx[j] == mx[i] && j < i))
        ++cnt2;
    }
    if (cnt1 > k1 - 1) continue;
    for (int j = min(k2, min(k1 - 1 - cnt1, cnt2)); j + cnt1 + 1 >= k2; --j)
      ad(ans, 1ll * C(cnt2, j) * C(cnt1, k2 - j - 1) % Mod);
  }
  printf("%d\n", ans);
}
}  // namespace sub2
int main() {
  math_init(M - 5), input();
  sub1::solve(), sub2::solve();
  return 0;
}
