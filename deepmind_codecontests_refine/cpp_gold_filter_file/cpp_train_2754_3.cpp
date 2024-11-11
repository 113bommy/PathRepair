#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T qmin(const T &a, const T &b) {
  return a < b ? a : b;
}
template <typename T>
inline T qmax(const T &a, const T &b) {
  return a > b ? a : b;
}
template <typename T>
inline void getmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <typename T>
inline void getmax(T &a, const T &b) {
  if (a < b) a = b;
}
inline void fileio(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const int inf = (int)1e9 + 7;
const long long linf = (long long)1e17 + 7;
const int N = 4e5 + 7;
int dx[N], szx, dy[N], szy;
int x_1[N], y_1[N], x2[N], y2[N];
int par[N];
long long res[N];
int n, m;
struct ev {
  int tp, tm, id, l, r;
  inline ev() {}
  inline ev(const int &a, const int &b, const int &c, const int &d,
            const int &e = 0)
      : tp(a), tm(b), id(c), l(d), r(e) {}
  inline bool operator<(const ev &b) const {
    if (tm != b.tm) return tm < b.tm;
    return tp < b.tp;
  }
} e[N];
int cnt;
inline int idx(const int &v) {
  return lower_bound(dx + 1, dx + szx + 1, v) - dx;
}
inline int idy(const int &v) {
  return lower_bound(dy + 1, dy + szy + 1, v) - dy;
}
inline int find(const int &x) { return !par[x] ? x : par[x] = find(par[x]); }
inline void join(int x, int y) {
  x = find(x), y = find(y);
  if (x == y) return;
  par[y] = x;
  res[x] += res[y];
}
int sz[N << 2], lpos[N << 2], rpos[N << 2];
int cur[N];
inline void upd(const int &p) {
  int lc = ((p) << 1), rc = ((p) << 1 ^ 1);
  sz[p] = sz[lc] + sz[rc];
  lpos[p] = (!lpos[lc] ? lpos[rc] : lpos[lc]);
  rpos[p] = (!rpos[rc] ? rpos[lc] : rpos[rc]);
}
inline void ins(int p, int id) {
  cur[p] = id;
  p += m - 1;
  assert(!sz[p]);
  lpos[p] = rpos[p] = p - (m - 1);
  sz[p] = 1;
  for (; p >>= 1;) upd(p);
}
inline void del(int p) {
  cur[p] = 0;
  p += m - 1;
  assert(sz[p]);
  sz[p] = lpos[p] = rpos[p] = 0;
  for (; p >>= 1;) upd(p);
}
inline pair<int, int> getlr(int l, int r) {
  int resl = inf, resr = -inf;
  for (l += m - 1, r += m - 1; l <= r; l >>= 1, r >>= 1) {
    if (l & 1) {
      if (lpos[l]) getmin(resl, lpos[l]);
      if (rpos[l]) getmax(resr, rpos[l]);
      ++l;
    }
    if (~r & 1) {
      if (lpos[r]) getmin(resl, lpos[r]);
      if (rpos[r]) getmax(resr, rpos[r]);
      --r;
    }
  }
  return make_pair(resl, resr);
}
inline int getsz(int l, int r) {
  int res = 0;
  for (l += m - 1, r += m - 1; l <= r; l >>= 1, r >>= 1) {
    if (l & 1) res += sz[l++];
    if (~r & 1) res += sz[r--];
  }
  return res;
}
set<pair<int, int> > s;
set<pair<int, int> >::iterator it, it1, it2;
int main() {
  scanf("%d", &n);
  for (register int i = (1); i <= (n); ++i) {
    scanf("%d%d%d%d", x_1 + i, y_1 + i, x2 + i, y2 + i);
    dx[++szx] = x_1[i], dx[++szx] = x2[i];
    dy[++szy] = y_1[i], dy[++szy] = y2[i];
    res[i] = (long long)x2[i] - x_1[i] + (long long)y2[i] - y_1[i];
  }
  sort(dx + 1, dx + szx + 1), szx = unique(dx + 1, dx + szx + 1) - dx - 1;
  sort(dy + 1, dy + szy + 1), szy = unique(dy + 1, dy + szy + 1) - dy - 1;
  for (register int i = (1); i <= (n); ++i) {
    x_1[i] = idx(x_1[i]), y_1[i] = idy(y_1[i]);
    x2[i] = idx(x2[i]), y2[i] = idy(y2[i]);
    if (x_1[i] == x2[i]) {
      e[++cnt] = ev(1, x_1[i], i, y_1[i], y2[i]);
    } else if (y_1[i] == y2[i]) {
      e[++cnt] = ev(0, x_1[i], i, y_1[i]);
      e[++cnt] = ev(2, x2[i], i, y_1[i]);
    } else
      assert(false);
  }
  for (m = 2; m <= szy; m <<= 1)
    ;
  sort(e + 1, e + cnt + 1);
  s.insert(make_pair(0, 0)), s.insert(make_pair(inf, inf));
  for (register int i = (1); i <= (cnt); ++i) {
    ev &t = e[i];
    if (t.tp == 0) {
      int p = t.l;
      ins(p, t.id);
      it = --s.upper_bound(make_pair(p, inf));
      if (it->second < p) {
        s.insert(make_pair(p, p));
      } else {
        int ul = it->first, ur = it->second;
        pair<int, int> tmp;
        s.erase(it);
        tmp = getlr(ul, p - 1);
        if (tmp.first <= tmp.second) s.insert(tmp);
        tmp = getlr(p + 1, ur);
        if (tmp.first <= tmp.second) s.insert(tmp);
        s.insert(make_pair(p, p));
      }
    } else if (t.tp == 1) {
      int l = t.l, r = t.r, ul = 0, ur = 0;
      pair<int, int> tmp = getlr(l, r);
      if (tmp.first > tmp.second) continue;
      int tot = res[t.id], rt = find(cur[tmp.first]);
      it2 = --s.upper_bound(make_pair(l, inf));
      if (it2->second < l) ++it2;
      ul = it2->first, ur = it2->second;
      tot -= getsz(qmax(it2->first, l), qmin(it2->second, r)) - 1;
      for (it = it2; (++it)->first <= r;) {
        tot -= getsz(it->first, qmin(it->second, r)) - 1;
        int u = find(cur[it->first]);
        if (u == rt)
          --tot;
        else
          join(rt, u);
        ur = it->second;
      }
      res[rt] += tot;
      s.erase(it2, it);
      s.insert(make_pair(ul, ur));
    } else if (t.tp == 2) {
      int p = t.l;
      del(p);
      it = --s.upper_bound(make_pair(p, inf));
      int ul = it->first, ur = it->second;
      if (ul == p || ur == p) {
        s.erase(it);
        if (ul != ur) s.insert(getlr(ul, ur));
      }
    } else
      assert(false);
  }
  long long ans = 0;
  for (register int i = (1); i <= (n); ++i)
    if (!par[i]) getmax(ans, res[i]);
  printf("%lld\n", ans);
  return 0;
}
