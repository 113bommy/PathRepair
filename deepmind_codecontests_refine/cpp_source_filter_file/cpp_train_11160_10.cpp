#include <bits/stdc++.h>
using namespace std;
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;
template <typename T>
inline void read(T &x) {
  char ch, t = 0;
  x = 0;
  while (!isdigit(ch = (iS == iT
                            ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                               (iS == iT ? EOF : *iS++))
                            : *iS++)))
    t |= ch == '-';
  while (isdigit(ch))
    x = x * 10 + (ch ^ 48),
    ch = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
  x = t ? -x : x;
}
inline int read_int() {
  int x;
  return read(x), x;
}
inline long long read_ll() {
  long long x;
  return read(x), x;
}
template <typename T>
inline void chkmin(T &a, T b) {
  a = a < b ? a : b;
}
template <typename T>
inline void chkmax(T &a, T b) {
  a = a > b ? a : b;
}
const int MAXN = 500010;
const int mod = 1e9 + 7;
int n, flag;
int tot = 1;
int fi[MAXN];
int deg[MAXN];
int ne[MAXN << 1];
int to[MAXN << 1];
inline void Link(int u, int v) {
  tot++;
  ++deg[u];
  to[tot] = v;
  ne[tot] = fi[u];
  fi[u] = tot;
}
int st[MAXN];
int ed[MAXN];
int fa[MAXN];
int vis[MAXN];
int fac[MAXN];
int dep[MAXN];
int tof[MAXN];
int L[MAXN << 1];
int R[MAXN << 1];
int f[MAXN << 1];
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline int Merge(int x, int y) {
  return x = find(x), y = find(y), x == y ? 0 : (f[x] = y, 1);
}
inline void dfs(int x, int la) {
  dep[x] = dep[la] + 1, fa[x] = la;
  for (int i = fi[x]; i; i = ne[i]) {
    int u = to[i];
    if (u == la) {
      tof[x] = i;
      continue;
    }
    dfs(u, x);
  }
}
inline void Solve(int u, int v) {
  queue<int> q;
  stack<int> s;
  int St = u, Ed = v;
  while (dep[u] > dep[v]) --deg[u], q.push(tof[u]), u = fa[u];
  while (dep[u] < dep[v]) --deg[v], s.push(tof[v]), v = fa[v];
  while (u != v) {
    --deg[u], q.push(tof[u]), u = fa[u];
    --deg[v], s.push(tof[v]), v = fa[v];
  }
  --deg[u];
  while (!s.empty()) q.push(s.top() ^ 1), s.pop();
  int las = q.front();
  q.pop();
  if (st[St] || L[las]) flag = 1;
  st[St] = las, L[las] = -1;
  while (!q.empty()) {
    int x = q.front();
    q.pop(), las ^= 1;
    if (R[las] || L[x] || Merge(x, las)) flag = 1;
    L[x] = las, R[las] = x, las = x;
  }
  las ^= 1;
  if (ed[Ed] || R[las]) flag = 1;
  ed[Ed] = las, R[las] = -1;
}
int main() {
  n = read_int(), fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
  for (int i = 1; i < n; i++) {
    int u = read_int(), v = read_int();
    Link(u, v), Link(v, u);
  }
  dfs(1, 0);
  for (int i = 2; i <= tot; i++) f[i] = i;
  for (int i = 1; i <= n; i++) {
    int x = read_int();
    if (!x) continue;
    if (vis[x] || x == i) {
      flag = 1;
      break;
    }
    vis[x] = 1, Solve(x, i);
    if (flag) break;
  }
  int res = !flag;
  for (int i = 1; i <= n; i++) {
    if (st[i] && ed[i]) {
      int x = st[i];
      while (x > 0) x = R[x];
      if (~x)
        res = 1LL * res * fac[deg[i]] % mod;
      else
        res *= deg[i] == -1;
    } else
      res = 1LL * res * fac[deg[i]] % mod;
  }
  cout << res << endl;
  return 0;
}
