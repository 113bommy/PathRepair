#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * t;
}
const int N = 1e5 + 5;
const int M = 6e6 + 5;
int n, m, num, tot, Num;
int prt[N], d[N], sz[N], son[N], top[N], p[N];
int dfn[M], low[M], s[M], vis[M], b[M];
vector<int> G[M], S[N << 2];
void DFS1(int x, int f) {
  prt[x] = f, d[x] = d[f] + 1, sz[x] = 1;
  for (auto y : G[x])
    if (y ^ f) {
      DFS1(y, x), sz[x] += sz[y];
      if (sz[y] > sz[son[x]]) son[x] = y;
    }
}
void DFS2(int x, int tp) {
  top[x] = tp, p[x] = ++p[0];
  if (son[x]) DFS2(son[x], tp);
  for (auto y : G[x])
    if ((y ^ prt[x]) && (y ^ son[x])) DFS2(y, y);
}
void Ins(int x, int l, int r, int ql, int qr, int v) {
  if (ql <= l && r <= qr) {
    S[x].push_back(v);
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) Ins(x << 1, l, mid, ql, qr, v);
  if (qr > mid) Ins(x << 1 | 1, mid + 1, r, ql, qr, v);
}
void Upd(int x, int y, int v) {
  while (top[x] ^ top[y]) {
    if (d[top[x]] < d[top[y]]) swap(x, y);
    Ins(1, 1, n, p[top[x]], p[x], v), x = prt[top[x]];
  }
  if (d[x] > d[y]) swap(x, y);
  if (x ^ y) Ins(1, 1, n, p[x] + 1, p[y], v);
}
void Add(int x, int y) { G[x].push_back(y), G[y ^ 1].push_back(x ^ 1); }
void Build(int x, int l, int r, int p) {
  for (int i = 0; i < S[x].size(); i++) {
    int t = S[x][i];
    tot++;
    if (p) Add(p * 2, tot * 2), Add(p * 2, t ^ 1);
    p = tot, Add(t, tot * 2);
  }
  if (l == r) return;
  int mid = (l + r) >> 1;
  Build(x << 1, l, mid, p), Build(x << 1 | 1, mid + 1, r, p);
}
void Tarjan(int x) {
  dfn[x] = low[x] = ++dfn[0], vis[x] = 1, s[++num] = x;
  for (auto y : G[x]) {
    if (!dfn[y]) {
      Tarjan(y);
      low[x] = min(low[x], low[y]);
    } else if (vis[x])
      low[x] = min(low[x], dfn[y]);
  }
  if (low[x] == dfn[x]) {
    Num++;
    for (int y = 0; y ^ x;) b[y = s[num--]] = Num, vis[y] = 0;
  }
}
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    G[x].push_back(y), G[y].push_back(x);
  }
  DFS1(1, 0), DFS2(1, 1);
  m = read();
  for (int i = 1; i <= m; i++) {
    Upd(read(), read(), i * 2);
    Upd(read(), read(), i * 2 + 1);
  }
  for (int i = 1; i <= n; i++) G[i].clear();
  tot = m, Build(1, 1, n, 0);
  for (int i = 1; i <= 2 * tot; i++)
    if (!dfn[i]) Tarjan(i);
  for (int i = 1; i <= m; i++)
    if (b[i << 1] == b[i << 1 | 1]) return puts("No"), 0;
  puts("Yes");
  for (int i = 1; i <= m; i++)
    cout << ((b[i << 1] < b[i << 1 | 1]) ? 1 : 2) << '\n';
  return 0;
}
