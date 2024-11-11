#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
  return x * f;
}
const int maxn = 200050, lim = 30;
map<pair<int, int>, int> mp, rmp;
int n, m;
int Rank[maxn], val[maxn], anc[maxn], id[maxn];
int base[lim + 5], pos[lim + 5], top;
struct querys {
  int u, x, y, w, c;
  querys() {}
  querys(int _u, int _x, int _y, int _w, int _c) {
    u = _u;
    x = _x;
    y = _y;
    w = _w;
    c = _c;
  }
  inline bool operator<(const querys &a) const { return u < a.u; }
};
inline pair<int, int> getans(int x) {
  int res = 0;
  while (x != anc[x]) res ^= val[x], x = anc[x];
  return make_pair(x, res);
}
inline int Insert(int x) {
  for (int i = lim; i; i--)
    if (pos[i] && (x & (1 << i))) x ^= base[pos[i]];
  for (int i = lim; i; i--)
    if (!pos[i] && (x & (1 << i))) {
      base[++top] = x, pos[i] = top;
      return i;
    }
  return -1;
}
inline int query(int x, int y) {
  x = getans(x).second ^ getans(y).second;
  for (int i = lim; i; i--)
    if (pos[i] && (x & (1 << i))) x ^= base[pos[i]];
  return x;
}
inline void debug() {}
struct node {
  vector<querys> qry[maxn << 2];
  inline void insert(int now, int L, int R, int l, int r, const querys &t) {
    if (l <= L && R <= r) return (void)qry[now].push_back(t);
    int mid = L + R >> 1;
    if (r <= mid)
      insert(now << 1, L, mid, l, r, t);
    else if (l > mid)
      insert(now << 1 | 1, mid + 1, R, l, r, t);
    else
      insert(now << 1, L, mid, l, r, t),
          insert(now << 1 | 1, mid + 1, R, l, r, t);
  }
  inline void dfs(int now, int L, int R) {
    if (L == R) sort(qry[now].begin(), qry[now].end());
    for (int i = 0; i < qry[now].size(); ++i) {
      querys t = qry[now][i];
      if (t.u == 1) {
        pair<int, int> x = getans(t.x), y = getans(t.y);
        if (x.first == y.first) {
          int p = Insert(x.second ^ y.second ^ t.w);
          if (~p) qry[now][i].c = 3 + p;
        } else {
          if (Rank[x.first] < Rank[y.first]) swap(x, y);
          anc[y.first] = x.first;
          val[y.first] = t.w ^ x.second ^ y.second;
          if (Rank[x.first] == Rank[y.first])
            ++Rank[x.first], qry[now][i].c = 2;
          else
            qry[now][i].c = 1;
          qry[now][i].x = x.first, qry[now][i].y = y.first;
        }
      } else
        printf("%d\n", query(t.x, t.y)), debug();
    }
    if (L != R) {
      int mid = L + R >> 1;
      dfs(now << 1, L, mid);
      dfs(now << 1 | 1, mid + 1, R);
    }
    for (int i = qry[now].size() - 1; i >= 0; --i) {
      querys f = qry[now][i];
      if (!f.c) continue;
      if (f.c <= 2)
        anc[f.y] = f.y, val[f.y] = 0, Rank[f.x] -= f.c - 1;
      else
        pos[f.c - 3] = 0, --top;
    }
  }
} nut;
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) anc[i] = i;
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read(), w = read();
    if (x > y) swap(x, y);
    mp[make_pair(x, y)] = 0;
    rmp[make_pair(x, y)] = w;
  }
  m = read();
  for (int i = 1; i <= m; ++i) {
    int opt = read(), x = read(), y = read();
    if (x > y) swap(x, y);
    if (opt == 1) {
      int w = read();
      mp[make_pair(x, y)] = i;
      rmp[make_pair(x, y)] = w;
    } else if (opt == 2) {
      int pre = mp[make_pair(x, y)], w = rmp[make_pair(x, y)];
      mp.erase(mp.find(make_pair(x, y)));
      rmp.erase(rmp.find(make_pair(x, y)));
      nut.insert(1, 0, m, pre, i, querys(1, x, y, w, 0));
    } else
      nut.insert(1, 0, m, i, i, querys(2, x, y, 0, 0));
  }
  for (map<pair<int, int>, int>::iterator it = mp.begin(), it2 = rmp.begin();
       it != mp.end(), it2 != rmp.end(); it++, it2++)
    nut.insert(1, 0, m, it->second, m,
               querys(1, it->first.first, it->first.second, it2->second, 0));
  nut.dfs(1, 0, m);
}
