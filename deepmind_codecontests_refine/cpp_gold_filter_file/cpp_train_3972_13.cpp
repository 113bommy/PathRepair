#include <bits/stdc++.h>
using namespace std;
const int maxn = 300030;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
struct point {
  int l, r, x, y;
} p[maxn];
int n, nd, fa[maxn * 2], sz[maxn * 2], xs[maxn * 2], ys[maxn * 2], stk[maxn][3],
    tp;
vector<pair<int, int> > vec[maxn * 4];
map<pair<int, int>, int> mp;
long long s, ans[maxn];
int getfa(int x) { return x == fa[x] ? x : getfa(fa[x]); }
inline void unite(int x, int y) {
  x = getfa(x);
  y = getfa(y);
  if (x == y) return;
  if (sz[x] > sz[y]) swap(x, y);
  stk[++tp][0] = x;
  stk[tp][1] = y;
  stk[tp][2] = sz[y];
  sz[y] = max(sz[y], sz[x] + 1);
  fa[x] = y;
  s -= 1ll * xs[x] * ys[x] + 1ll * xs[y] * ys[y];
  xs[y] += xs[x];
  ys[y] += ys[x];
  s += 1ll * xs[y] * ys[y];
}
inline void undo() {
  int x = stk[tp][0], y = stk[tp][1];
  sz[y] = stk[tp--][2];
  s -= 1ll * xs[y] * ys[y];
  xs[y] -= xs[x];
  ys[y] -= ys[x];
  s += 1ll * xs[x] * ys[x] + 1ll * xs[y] * ys[y];
  fa[x] = x;
}
void update(int o, int l, int r, int ql, int qr, int x, int y) {
  if (l >= ql && r <= qr) return void(vec[o].push_back(make_pair(x, y)));
  int mid = (l + r) >> 1;
  if (mid >= ql) update(o << 1, l, mid, ql, qr, x, y);
  if (mid < qr) update(o << 1 | 1, mid + 1, r, ql, qr, x, y);
}
void solve(int o, int l, int r) {
  int tmp = tp;
  for (int i = (0); i <= ((int)vec[o].size() - 1); i++)
    unite(vec[o][i].first, vec[o][i].second);
  if (l == r)
    ans[l] = s;
  else {
    int mid = (l + r) >> 1;
    solve(o << 1, l, mid);
    solve(o << 1 | 1, mid + 1, r);
  }
  while (tp > tmp) undo();
}
int main() {
  n = read();
  for (int i = (1); i <= (n); i++) {
    int x = read(), y = read();
    pair<int, int> tmp = make_pair(x, y);
    if (mp[tmp])
      p[mp[tmp]].r = i - 1, mp[tmp] = 0;
    else
      p[mp[tmp] = ++nd] = (point){i, n, x, y};
  }
  for (int i = (1); i <= (nd); i++)
    update(1, 1, n, p[i].l, p[i].r, p[i].x, p[i].y + 300000);
  for (int i = (1); i <= (300000); i++) fa[i] = i, sz[i] = xs[i] = 1;
  for (int i = (300001); i <= (600000); i++) fa[i] = i, sz[i] = ys[i] = 1;
  solve(1, 1, n);
  for (int i = (1); i <= (n); i++) printf("%I64d ", ans[i]);
}
