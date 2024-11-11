#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
using namespace std;
inline void MIN(int &a, int b) {
  if (b < a) a = b;
}
inline void MAX(int &a, int b) {
  if (a < b) a = b;
}
int n, w, q, block;
int a[101000];
int Lg2[101000], Mx[20][101000], Mn[20][101000];
inline void build_st() {
  Lg2[0] = -1;
  for (int i = 1; i <= n; ++i) Lg2[i] = Lg2[i >> 1] + 1;
  for (int i = 1; i <= n; ++i) Mx[0][i] = Mn[0][i] = a[i];
  for (int j = 1; j <= Lg2[n]; ++j)
    for (int i = 1; i + (1 << j) - 1 <= n; ++i)
      Mx[j][i] = max(Mx[j - 1][i], Mx[j - 1][i + (1 << (j - 1))]),
      Mn[j][i] = min(Mn[j - 1][i], Mn[j - 1][i + (1 << (j - 1))]);
}
inline int query_mx(int l, int r) {
  int j = Lg2[r - l + 1];
  return max(Mx[j][l], Mx[j][r - (1 << j) + 1]);
}
inline int query_mn(int l, int r) {
  int j = Lg2[r - l + 1];
  return min(Mn[j][l], Mn[j][r - (1 << j) + 1]);
}
inline int get_nxt(int p, int limi) {
  int l = p, r = n, res = n + 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (query_mx(p, mid) - query_mn(p, mid) > limi)
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  return res;
}
pair<int, int> qy[101000];
vector<pair<int, int> > vec[101000];
namespace LCT {
int son[101000][2], fa[101000], siz[101000], tag[101000];
inline void pushup(int cur) {
  siz[cur] = siz[son[cur][0]] + siz[son[cur][1]] + 1;
}
inline bool notroot(int cur) {
  return son[fa[cur]][0] == cur || son[fa[cur]][1] == cur;
}
inline bool get_which(int cur) { return son[fa[cur]][1] == cur; }
inline void rotate(int cur) {
  int faa = fa[cur], fafa = fa[faa];
  bool flag = get_which(cur);
  fa[cur] = fafa;
  if (notroot(faa)) son[fafa][get_which(faa)] = cur;
  son[faa][flag] = son[cur][flag ^ 1];
  if (son[cur][flag ^ 1]) fa[son[cur][flag ^ 1]] = faa;
  fa[faa] = cur;
  son[cur][flag ^ 1] = faa;
  pushup(faa);
}
inline void pusht(int cur) {
  if (!cur) return;
  tag[cur] ^= 1;
  swap(son[cur][0], son[cur][1]);
}
inline void pushdown(int cur) {
  if (tag[cur]) pusht(son[cur][0]), pusht(son[cur][1]), tag[cur] = 0;
}
int stk[101000], stop;
inline void splay(int cur) {
  int x = cur;
  while (notroot(x)) stk[++stop] = x, x = fa[x];
  pushdown(x);
  while (stop) pushdown(stk[stop--]);
  for (int faa = fa[cur]; notroot(cur); rotate(cur), faa = fa[cur])
    if (notroot(faa)) rotate(get_which(faa) == get_which(cur) ? faa : cur);
  pushup(cur);
}
inline void Access(int x) {
  for (int lst = 0; x; lst = x, x = fa[x]) splay(x), son[x][1] = lst, pushup(x);
}
inline void Cut(int x, int faa) {
  if (!faa) return;
  Access(faa);
  splay(x);
  fa[x] = 0;
}
inline void Link(int x, int faa) {
  splay(x);
  if (fa[x]) printf("Link(%d, %d), but %d have father %d\n", x, faa, x, fa[x]);
  fa[x] = faa;
}
inline int query(int limi) {
  int p = 1, res = 0;
  while (p != n + 1) {
    Access(p);
    splay(p);
    res += siz[son[p][0]];
    int rt = p;
    while (son[rt][0]) rt = son[rt][0];
    splay(rt);
    if (rt <= n) ++res, rt = get_nxt(rt, limi);
    p = rt;
  }
  return res;
}
}  // namespace LCT
int nxt[101000], ans[101000];
int main() {
  read(n), read(w), read(q);
  block = sqrt(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  build_st();
  for (int i = 1; i <= q; ++i)
    read(qy[i].first), qy[i].first = w - qy[i].first, qy[i].second = i;
  sort(qy + 1, qy + 1 + q);
  for (int i = 1; i <= n; ++i) {
    int mn = a[i], mx = a[i], tq = 1;
    for (int j = 1; j <= block && i + j <= n; ++j) {
      if (mn <= a[i + j] && a[i + j] <= mx) continue;
      MIN(mn, a[i + j]), MAX(mx, a[i + j]);
      int p = lower_bound(qy + 1, qy + 1 + q, make_pair(mx - mn, 0)) - qy;
      if (p != tq) vec[tq].push_back(make_pair(i, j)), tq = p;
    }
    vec[tq].push_back(make_pair(i, block));
  }
  for (int i = 1; i <= q; ++i) {
    for (unsigned int j = 0; j < vec[i].size(); ++j) {
      int p = vec[i][j].first, d = vec[i][j].second;
      LCT::Cut(p, nxt[p]);
      nxt[p] = p + d;
      if (d < block) LCT::Link(p, p + d);
    }
    ans[qy[i].second] = LCT::query(qy[i].first);
  }
  for (int i = 1; i <= q; ++i) printf("%d\n", ans[i] - 1);
  return 0;
}
