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
int dy[N], szy;
int x1[N], y4596431[N], x2[N], y2[N];
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
inline int idy(const int &v) {
  return lower_bound(dy + 1, dy + szy + 1, v) - dy;
}
inline int find(const int &x) { return par[x] > 0 ? par[x] = find(par[x]) : x; }
inline void join(int x, int y) {
  if (!x || !y) return;
  x = find(x), y = find(y);
  if (x == y) return;
  if (par[x] < par[y])
    par[x] += par[y], par[y] = x;
  else
    par[y] += par[x], par[x] = y;
}
int sz[N << 2], node[N << 2];
bool kicked[N << 2];
inline void ins(int p, int id) {
  for (sz[p += m - 1] = 1, node[p] = id; p >>= 1;) {
    ++sz[p];
    node[p] = id;
    kicked[p] = false;
  }
}
inline void del(int p) {
  for (sz[p += m - 1] = 0, node[p] = 0; p >>= 1;) {
    --sz[p];
    node[p] = (!node[((p) << 1)] ? node[((p) << 1 ^ 1)] : node[((p) << 1)]);
    kicked[p] = false;
  }
}
inline void psd(int u) {
  if (u >= m || !node[u] || kicked[u]) return;
  kicked[u] = true;
  join(node[((u) << 1)], node[((u) << 1 ^ 1)]);
  psd(((u) << 1)), psd(((u) << 1 ^ 1));
}
inline int getsz(int l, int r, int id) {
  int res = 0;
  for (l += m - 1, r += m - 1; l <= r; l >>= 1, r >>= 1) {
    if (l & 1) {
      res += sz[l];
      join(node[l], id);
      psd(l++);
    }
    if (~r & 1) {
      res += sz[r];
      join(node[r], id);
      psd(r--);
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (register int i = (1); i <= (n); ++i) {
    scanf("%d%d%d%d", x1 + i, y4596431 + i, x2 + i, y2 + i);
    dy[++szy] = y4596431[i], dy[++szy] = y2[i];
    res[i] = (long long)x2[i] - x1[i] + y2[i] - y4596431[i] + 1;
  }
  sort(dy + 1, dy + szy + 1), szy = unique(dy + 1, dy + szy + 1) - dy - 1;
  for (m = 2; m < szy; m <<= 1)
    ;
  for (register int i = (1); i <= (n); ++i) {
    y4596431[i] = idy(y4596431[i]), y2[i] = idy(y2[i]);
    if (y4596431[i] == y2[i]) {
      e[++cnt] = ev(0, x1[i], i, y4596431[i]);
      e[++cnt] = ev(2, x2[i], i, y4596431[i]);
    } else {
      e[++cnt] = ev(1, x1[i], i, y4596431[i], y2[i]);
    }
  }
  memset(par + 1, -1, sizeof(int) * n);
  sort(e + 1, e + cnt + 1);
  for (register int i = (1); i <= (cnt); ++i) {
    ev &t = e[i];
    if (t.tp == 0) {
      ins(t.l, t.id);
    } else if (t.tp == 1) {
      res[t.id] -= getsz(t.l, t.r, t.id);
    } else if (t.tp == 2) {
      del(t.l);
    } else
      assert(false);
  }
  for (register int i = (1); i <= (n); ++i)
    if (par[i] > 0) res[find(i)] += res[i];
  long long ans = 1;
  for (register int i = (1); i <= (n); ++i)
    if (par[i] < 0) getmax(ans, res[i]);
  printf("%d\n", ans - 1);
  return 0;
}
