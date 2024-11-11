#include <bits/stdc++.h>
const int P = 998244353;
using namespace std;
template <typename T>
inline void ckmax(T &a, T b) {
  (a < b) && (a = b);
}
template <typename T>
inline void ckmin(T &a, T b) {
  (a > b) && (a = b);
}
inline int mul(int a, int b) { return 1ll * a * b % P; }
inline int add(int a, int b) { return a + b >= P ? a + b - P : a + b; }
inline int sub(int a, int b) { return a - b >= 0 ? a - b : a - b + P; }
inline void mulmod(int &a, int b) { a = mul(a, b); }
inline void addmod(int &a, int b) { ((a += b) >= P) && (a -= P); }
inline void submod(int &a, int b) { ((a -= b) < 0) && (a += P); }
inline int ksm(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1) {
    if (b & 1) ans = 1ll * ans * a % P;
    a = 1ll * a * a % P;
  }
  return ans;
}
inline int inv(int a) { return ksm(a, P - 2); }
namespace FastIO {
const int SIZE = 1 << 16;
char buf[SIZE], obuf[SIZE], str[64];
int bi = SIZE, bn = SIZE, opt;
int read(char *s) {
  while (bn) {
    for (; bi < bn && buf[bi] <= ' '; bi++)
      ;
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  int sn = 0;
  while (bn) {
    for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
    if (bi < bn) break;
    bn = fread(buf, 1, SIZE, stdin), bi = 0;
  }
  s[sn] = 0;
  return sn;
}
bool read(int &x) {
  if (x) x = 0;
  int bf = 0, n = read(str);
  if (!n) return 0;
  int i = 0;
  if (str[i] == '-') bf = 1, i = 1;
  for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
  if (bf) x = -x;
  return 1;
}
void write(int x) {
  if (!x)
    obuf[opt++] = '0';
  else {
    if (x < 0) obuf[opt++] = '-', x = -x;
    int sn = 0;
    while (x) str[sn++] = x % 10 + '0', x /= 10;
    for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
  }
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void write(char x) {
  obuf[opt++] = x;
  if (opt >= (SIZE >> 1)) {
    fwrite(obuf, 1, opt, stdout);
    opt = 0;
  }
}
void Fflush() {
  if (opt) fwrite(obuf, 1, opt, stdout);
  opt = 0;
}
};  // namespace FastIO
inline int read() {
  int x;
  FastIO::read(x);
  return x;
}
const int MN = 1e5 + 5;
int n, dis[MN], dx, dy;
vector<pair<int, int> > e[MN];
void dfs1(int op, int u, int fa) {
  if (op == 0 && dis[u] > dis[dx]) dx = u;
  if (op == 1 && dis[u] > dis[dy]) dy = u;
  for (auto it : e[u]) {
    int v = it.first, w = it.second;
    if (v == fa) continue;
    dis[v] = dis[u] + w;
    dfs1(op, v, u);
  }
}
struct Tr {
  int f[MN][21], g[MN][21], len[MN], top[MN], rk[MN], rt, lf[MN], s[MN], cnt,
      sum[MN], lson[MN];
  void dfs1(int u, int fa, int fr) {
    f[u][0] = fa, g[u][0] = fr;
    for (int i = 1; i <= 20; i++)
      f[u][i] = f[f[u][i - 1]][i - 1],
      g[u][i] = g[f[u][i - 1]][i - 1] + g[u][i - 1];
    for (auto it : e[u]) {
      int v = it.first, w = it.second;
      if (v == fa) continue;
      dfs1(v, u, w);
      ckmax(len[u], len[v] + w);
    }
  }
  void dfs2(int u, int tp) {
    top[u] = tp;
    lson[u] = 0;
    for (auto it : e[u]) {
      int v = it.first, w = it.second;
      if (v != f[u][0] && len[v] + w == len[u]) lson[u] = v;
    }
    if (!lson[u]) return void();
    dfs2(lson[u], tp);
    for (auto it : e[u]) {
      int v = it.first;
      if (v != f[u][0] && v != lson[u])
        s[lf[++cnt] = v] = len[v] + it.second, dfs2(v, v);
    }
  }
  void init() {
    dfs1(rt, 0, 0);
    dfs2(rt, rt);
    s[lf[++cnt] = rt] = len[rt];
    sort(lf + 1, lf + 1 + cnt, [&](int i, int j) { return s[i] > s[j]; });
    for (int i = (1); i <= (cnt); i++) {
      int u = lf[i];
      sum[i] = sum[i - 1] + s[u];
      while (u) rk[u] = i, u = lson[u];
    }
  }
  int qry(int x, int y) {
    y = 2 * y - 1;
    if (rk[x] <= y)
      return sum[y];
    else {
      int z = len[x];
      for (int i = 20; i >= 0; i--) {
        if (rk[f[x][i]] > y) z += g[x][i], x = f[x][i];
      }
      return max(sum[y - 1] + z + g[x][0], sum[y] - len[f[x][0]] + z + g[x][0]);
    }
  }
} t[2];
signed main() {
  int q, k = 0, s = 0;
  n = read(), q = read();
  for (int i = (1); i <= (n - 1); i++) {
    int u = read(), v = read(), w = read();
    e[u].push_back(make_pair(v, w)), e[v].push_back(make_pair(u, w));
    s += w;
  }
  for (int i = (1); i <= (n); i++) k += e[i].size() == 1;
  dfs1(0, 1, 0);
  memset(dis, 0, sizeof(dis));
  dfs1(1, dx, 0);
  t[0].rt = dx, t[1].rt = dy;
  t[0].init();
  t[1].init();
  int lstans = 0;
  while (q--) {
    int x = (read() + lstans - 1) % n + 1, y = (read() + lstans - 1) % n + 1;
    if (2 * y >= k)
      printf("%d\n", lstans = s);
    else
      printf("%d\n", lstans = max(t[0].qry(x, y), t[1].qry(x, y)));
  }
  return 0;
}
