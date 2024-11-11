#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 60;
const int mods = 1e9 + 7;
const int MAXN = 200005;
const int MX = 1 << 17;
const int inv2 = (mods + 1) >> 1;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
pair<int, int> fa[MAXN];
vector<pair<int, int> > e[MAXN];
vector<int> V[MAXN];
int vis[MAXN], f[MAXN], F[MAXN], g[MAXN], instk[MAXN], num = 0;
int upd(int x, int y) { return x + y >= mods ? x + y - mods : x + y; }
int quick_pow(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1ll * ret * x % mods;
    x = 1ll * x * x % mods;
  }
  return ret;
}
void Fwt_Xor(int *A, int opt) {
  for (int l = 2; l <= MX; l <<= 1)
    for (int j = 0, i = l >> 1; j < MX; j += l)
      for (int k = j; k < j + i; k++) {
        int x = A[k], y = A[k + i];
        A[k] = upd(x, y), A[k + i] = upd(x, mods - y);
      }
  int inv = quick_pow(MX, mods - 2);
  if (opt == -1)
    for (int i = 0; i < MX; i++) A[i] = 1ll * A[i] * inv % mods;
}
void dfs(int x, int father) {
  vis[x] = 1, instk[x] = 1;
  for (auto v : e[x]) {
    if (v.first == father) continue;
    if (vis[v.first]) {
      if (!instk[v.first]) continue;
      int t = x;
      num++;
      while (t != v.first) V[num].push_back(fa[t].second), t = fa[t].first;
      V[num].push_back(v.second);
      continue;
    }
    fa[v.first] = make_pair(x, v.second);
    dfs(v.first, x);
  }
  instk[x] = 0;
}
signed main() {
  int n = read(), m = read(), sum = 0;
  for (int i = 1, u, v, c; i <= m; i++)
    u = read(), v = read(), c = read(), e[u].push_back(make_pair(v, c)),
    e[v].push_back(make_pair(u, c)), sum ^= c;
  dfs(1, 0), f[0] = F[0] = 1, Fwt_Xor(f, 1);
  for (int i = 1; i <= num; i++) {
    for (int j = 0; j < MX; j++) g[j] = 0;
    for (auto v : V[i]) g[v] = 1;
    Fwt_Xor(g, 1), Fwt_Xor(F, 1);
    for (int j = 0; j < MX; j++)
      f[j] = 1ll * f[j] * g[j] % mods, F[j] = 1ll * F[j] * g[j] % mods;
    Fwt_Xor(F, -1);
    for (int j = 0; j < MX; j++)
      if (F[j] != 0) F[j] = 1;
  }
  Fwt_Xor(f, -1);
  for (int i = 0; i < MX; i++)
    if (F[i ^ sum]) {
      printf("%d %d\n", i, f[i ^ sum]);
      return 0;
    }
  return 0;
}
