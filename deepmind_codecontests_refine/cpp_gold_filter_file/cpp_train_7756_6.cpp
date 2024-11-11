#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Que {
  int op, v, id;
} q[200010];
inline int Read() {
  char c = getchar();
  int num = 0;
  while ('0' > c || c > '9') c = getchar();
  while ('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
  return (num);
}
inline int Pow(int x, int y) {
  int rs = 1;
  while (y) {
    if (y & 1) rs = rs * 1ll * x % 1000000007;
    x = x * 1ll * x % 1000000007, y /= 2;
  }
  return (rs);
}
vector<int> e[200010];
int fa[200010], dfn[200010], tm, sz[200010], bl[200010], R[200010];
inline void Dfs(int x) {
  sz[x] = 1;
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa[x]) fa[e[x][i]] = x, Dfs(e[x][i]), sz[x] += sz[e[x][i]];
}
inline void Dfs2(int x, int y) {
  bl[x] = y, dfn[x] = ++tm;
  int k = 0;
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa[x] && sz[k] < sz[e[x][i]]) k = e[x][i];
  if (k) Dfs2(k, y);
  for (int i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa[x] && e[x][i] != k) Dfs2(e[x][i], e[x][i]);
  R[x] = tm;
}
int t[200010 * 4];
inline void Add(int x, int l, int r, int a) {
  int md = (l + r) / 2;
  if (l == r) {
    t[x]++;
    return;
  }
  if (a <= md)
    Add(x * 2, l, md, a);
  else
    Add(x * 2 + 1, md + 1, r, a);
  t[x] = t[x * 2] * 1ll * t[x * 2 + 1] % 1000000007;
}
inline int Ask(int x, int l, int r, int a, int b) {
  int md = (l + r) / 2;
  if (l == a && r == b) return (t[x]);
  if (b <= md) return (Ask(x * 2, l, md, a, b));
  if (md < a) return (Ask(x * 2 + 1, md + 1, r, a, b));
  int L = Ask(x * 2, l, md, a, md);
  int R = Ask(x * 2 + 1, md + 1, r, md + 1, b);
  return (L * 1ll * R % 1000000007);
}
inline int Solv(int x) {
  int rs = 1;
  while (x) {
    int nm = Ask(1, 1, n, dfn[bl[x]], dfn[x]);
    rs = rs * 1ll * nm % 1000000007, x = fa[bl[x]];
  }
  return (rs);
}
int ts[200010 * 4], lzy[200010 * 4];
inline void Down(int x) {
  if (!lzy[x]) return;
  int l = x * 2, r = x * 2 + 1;
  ts[l] = ts[l] * 1ll * lzy[x] % 1000000007;
  lzy[l] = lzy[l] * 1ll * lzy[x] % 1000000007;
  ts[r] = ts[r] * 1ll * lzy[x] % 1000000007;
  lzy[r] = lzy[r] * 1ll * lzy[x] % 1000000007;
  lzy[x] = 1;
}
inline void Addp(int x, int l, int r, int a, int b, int c) {
  if (l == a && r == b) {
    ts[x] = ts[x] * 1ll * c % 1000000007;
    lzy[x] = lzy[x] * 1ll * c % 1000000007;
    return;
  }
  int md = (l + r) / 2;
  Down(x);
  if (b <= md) Addp(x * 2, l, md, a, b, c);
  if (md < a) Addp(x * 2 + 1, md + 1, r, a, b, c);
  if (a <= md && md < b) {
    Addp(x * 2, l, md, a, md, c);
    Addp(x * 2 + 1, md + 1, r, md + 1, b, c);
  }
  ts[x] = (ts[x * 2] + ts[x * 2 + 1]) % 1000000007;
}
inline void Adds(int x, int l, int r, int a, int b) {
  ts[x] = (ts[x] + b) % 1000000007;
  if (l == r) return;
  int md = (l + r) / 2;
  Down(x);
  if (a <= md)
    Adds(x * 2, l, md, a, b);
  else
    Adds(x * 2 + 1, md + 1, r, a, b);
  ts[x] = (ts[x * 2] + ts[x * 2 + 1]) % 1000000007;
}
inline int Asks(int x, int l, int r, int a, int b) {
  int md = (l + r) / 2;
  if (l == a && r == b) return (ts[x]);
  Down(x);
  if (b <= md) return (Asks(x * 2, l, md, a, b));
  if (md < a) return (Asks(x * 2 + 1, md + 1, r, a, b));
  int L = Asks(x * 2, l, md, a, md);
  int R = Asks(x * 2 + 1, md + 1, r, md + 1, b);
  return ((L + R) % 1000000007);
}
int du[200010];
int main() {
  int v1 = Read();
  n = 1, m = Read();
  for (int i = 1; i <= m; i++) {
    q[i].op = Read(), q[i].v = Read();
    if (q[i].op == 1) {
      e[q[i].v].push_back(++n);
      q[i].id = n, q[i].v = Read();
    }
  }
  Dfs(1);
  Dfs2(1, 1);
  Add(1, 1, n, dfn[1]);
  Adds(1, 1, n, dfn[1], v1);
  du[1] = 1;
  for (int i = 1; i <= n * 4; i++) lzy[i] = 1;
  for (int i = 1; i <= m; i++) {
    if (q[i].op == 1) {
      int x = q[i].id;
      int d = Solv(fa[x]);
      du[x]++, du[fa[x]]++;
      Adds(1, 1, n, dfn[x], d * 1ll * q[i].v % 1000000007);
      d = du[fa[x]] * 1ll * Pow(du[fa[x]] - 1, 1000000007 - 2) % 1000000007;
      Addp(1, 1, n, dfn[fa[x]], R[fa[x]], d);
      Add(1, 1, n, dfn[x]);
      Add(1, 1, n, dfn[fa[x]]);
    } else {
      int x = q[i].v;
      int ans = Asks(1, 1, n, dfn[x], R[x]);
      int d = Solv(fa[x]);
      d = Pow(d, 1000000007 - 2);
      printf("%d\n", ans * 1ll * d % 1000000007);
    }
  }
}
