#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
const int Inf = 0x3f3f3f3f;
const int MAXN = 2e5 + 10;
inline int read() {
  register int x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) f = ch == '-' ? -1 : 1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
inline long long readll() {
  register long long x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) f = ch == '-' ? -1 : 1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
struct Edge1 {
  int u, v, d;
  Edge1(int u_ = 0, int v_ = 0, int d_ = 0) { u = u_, v = v_, d = d_; }
} e[MAXN << 1];
struct Edge2 {
  int x, y;
  bool s;
};
struct Node {
  int f[35];
  inline void Insert(int x) {
    for (int i = 30; i >= 0; --i)
      if (x & (1 << i)) {
        if (!f[i]) {
          f[i] = x;
          return;
        }
        x ^= f[i];
      }
  }
  inline int Query(int x) {
    for (int i = 30; i >= 0; --i)
      if ((x ^ f[i]) < x) x ^= f[i];
    return x;
  }
} n1;
map<pair<int, int>, int> mp;
vector<Edge1> v[MAXN << 2];
int n, m, c, Q, tim;
int st[MAXN << 1], ed[MAXN << 1];
int qx[MAXN], qy[MAXN];
int fa[MAXN], f[MAXN], dep[MAXN];
inline int Find_fa(int x) { return fa[x] == x ? x : Find_fa(fa[x]); }
inline int Find_dis(int x) { return fa[x] == x ? 0 : f[x] ^ Find_dis(fa[x]); }
inline void Insert(int k, int l, int r, int x, int y, Edge1 e1) {
  if (x <= l && r <= y) {
    v[k].push_back(e1);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) Insert(k << 1, l, mid, x, y, e1);
  if (y > mid) Insert(k << 1 | 1, mid + 1, r, x, y, e1);
}
inline void Solve(int k, int l, int r, Node G) {
  stack<Edge2> stk;
  for (int i = 0; i < (int)v[k].size(); ++i) {
    int x = v[k][i].u, y = v[k][i].v, d = v[k][i].d;
    int ex = Find_fa(x), ey = Find_fa(y);
    d ^= Find_dis(x) ^ Find_dis(y);
    if (ex == ey)
      G.Insert(d);
    else {
      if (dep[ex] > dep[ey]) swap(ex, ey), swap(x, y);
      Edge2 cur = (Edge2){ex, ey, 0};
      fa[ex] = ey;
      f[ex] = d;
      if (dep[ex] == dep[ey]) ++dep[ey], cur.s = 1;
      stk.push(cur);
    }
  }
  if (l == r)
    printf("%d\n", G.Query(Find_dis(qx[l]) ^ Find_dis(qy[l])));
  else {
    int mid = (l + r) >> 1;
    Solve(k << 1, l, mid, G);
    Solve(k << 1 | 1, mid + 1, r, G);
  }
  while (!stk.empty())
    f[fa[stk.top().x] = stk.top().x] = 0, dep[stk.top().y] -= stk.top().s,
                        stk.pop();
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read(), d = read();
    mp[make_pair(u, v)] = i;
    st[i] = 1;
    ed[i] = -1;
    e[i] = Edge1(u, v, d);
  }
  c = m;
  tim = 1;
  Q = read();
  for (int i = 1, opt, x, y, z; i <= Q; ++i) {
    opt = read();
    x = read();
    y = read();
    if (opt == 1) {
      z = read();
      mp[make_pair(x, y)] = ++c;
      st[c] = tim;
      ed[c] = -1;
      e[c] = Edge1(x, y, z);
    } else if (opt == 2)
      ed[mp[make_pair(x, y)]] = tim - 1;
    else
      qx[tim] = x, qy[tim] = y, ++tim;
  }
  --tim;
  for (int i = 1; i <= c; ++i) {
    if (ed[i] == -1) ed[i] = tim;
    if (st[i] <= ed[i]) Insert(1, 1, tim, st[i], ed[i], e[i]);
  }
  Solve(1, 1, tim, n1);
  return 0;
}
