#include <bits/stdc++.h>
using namespace std;
const long long N = 500010;
long long n, m, tot, cnt, ans[N], siz[N], head[N], d[N];
bool lef[N];
struct Edge {
  long long ver, suiv, edge;
} e[N << 1];
struct Node {
  long long l, r, id;
  Node() {}
  Node(long long _l, long long _r, long long _id) : l(_l), r(_r), id(_id) {}
};
vector<Node> q[N];
struct SegmentTree {
  long long add, mini;
} t[N << 2];
inline void lnk(long long x, long long y, long long z) {
  e[++tot].ver = y;
  e[tot].edge = z;
  e[tot].suiv = head[x];
  head[x] = tot;
}
inline void dfs1(long long x) {
  siz[x] = x;
  for (long long i = head[x]; i; i = e[i].suiv) {
    long long y = e[i].ver, z = e[i].edge;
    d[y] = d[x] + z;
    dfs1(y);
    siz[x] = max(siz[x], siz[y]);
  }
  if (!head[x]) lef[x] = 1;
}
inline void spread(long long p) {
  if (!t[p].add) return;
  t[p << 1].add += t[p].add, t[p << 1 | 1].add += t[p].add;
  t[p << 1].mini += t[p].add, t[p << 1 | 1].mini += t[p].add;
  t[p].add = 0;
}
inline void build(long long p, long long l, long long r) {
  if (l == r) {
    t[p].mini = lef[l] ? d[l] : 1ll << 60;
    return;
  }
  long long mid = l + r >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  t[p].mini = min(t[p << 1].mini, t[p << 1 | 1].mini);
}
inline void change(long long p, long long l, long long r, long long L,
                   long long R, long long val) {
  if (L <= l && r <= R) {
    t[p].add += val;
    t[p].mini += val;
    return;
  }
  spread(p);
  long long mid = l + r >> 1;
  if (L <= mid) change(p << 1, l, mid, L, R, val);
  if (R > mid) change(p << 1 | 1, mid + 1, r, L, R, val);
  t[p].mini = min(t[p << 1].mini, t[p << 1 | 1].mini);
}
inline long long query(long long p, long long l, long long r, long long L,
                       long long R) {
  if (L <= l && r <= R) return t[p].mini;
  spread(p);
  long long mid = l + r >> 1, res = 1ll << 60;
  if (L <= mid) res = min(res, query(p << 1, l, mid, L, R));
  if (R > mid) res = min(res, query(p << 1 | 1, mid + 1, r, L, R));
  return res;
}
inline void dfs2(long long x) {
  for (auto it = q[x].begin(); it != q[x].end(); it++)
    ans[(*it).id] = query(1, 1, n, (*it).l, (*it).r);
  for (long long i = head[x]; i; i = e[i].suiv) {
    long long y = e[i].ver, z = e[i].edge;
    change(1, 1, n, y, siz[y], -z - z);
    change(1, 1, n, 1, n, z);
    dfs2(y);
    change(1, 1, n, y, siz[y], z + z);
    change(1, 1, n, 1, n, -z);
  }
}
signed main() {
  scanf("%lld%lld", &n, &m);
  for (long long i = 2, y, z; i <= n; i++)
    scanf("%lld%lld", &y, &z), lnk(y, i, z);
  for (long long i = 1, p, l, r; i <= m; i++)
    scanf("%lld%lld%lld", &p, &l, &r), q[p].push_back(Node(l, r, i));
  dfs1(1);
  build(1, 1, n);
  dfs2(1);
  for (long long i = 1; i <= m; i++) printf("%lld\n", ans[i]);
  return 0;
}
