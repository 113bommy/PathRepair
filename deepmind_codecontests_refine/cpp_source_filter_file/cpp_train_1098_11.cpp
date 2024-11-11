#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000006;
const int MAXM = 200005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
namespace ModCalculator {
const int MOD = 1e9 + 7;
inline void Inc(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
inline void Dec(int &x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
inline int Add(int x, int y) {
  Inc(x, y);
  return x;
}
inline int Sub(int x, int y) {
  Dec(x, y);
  return x;
}
inline int Mul(int x, int y) { return 1LL * x * y % MOD; }
inline int ksm(int x, int k) {
  int ret = 1;
  for (; k; k >>= 1) {
    if (k & 1) ret = Mul(ret, x);
    x = Mul(x, x);
  }
  return ret;
}
inline int Inv(int x) { return ksm(x, MOD - 2); }
}  // namespace ModCalculator
using namespace ModCalculator;
int n, m, k, tot;
struct Line {
  int x, yl, yr, t;
  bool operator<(const Line &rhs) const {
    if (x == rhs.x && t == rhs.t) {
      return (yl == rhs.yl) ? (yr > rhs.yr) : (yl > rhs.yl);
    }
    return (x == rhs.x) ? (t < rhs.t) : (x < rhs.x);
  }
} p[MAXM];
set<pair<int, int> > S;
struct SegmentTree {
  int key[MAXN << 2], cov[MAXN];
  inline void pushup(int rt) {
    key[rt] = Add(key[(rt << 1)], key[(rt << 1) | 1]);
  }
  inline void putcov(int rt) {
    key[rt] = 0;
    cov[rt] = 1;
  }
  inline void pushdown(int rt) {
    if (cov[rt]) {
      putcov((rt << 1));
      putcov((rt << 1) | 1);
      cov[rt] = 0;
    }
  }
  void Update(int rt, int b, int e, int po, int v) {
    if (b == e) {
      key[rt] = v;
      return;
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (po <= mid)
      Update((rt << 1), b, mid, po, v);
    else
      Update((rt << 1) | 1, mid + 1, e, po, v);
    pushup(rt);
  }
  void Cover(int rt, int b, int e, int l, int r) {
    if (l <= b && e <= r) {
      putcov(rt);
      return;
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (l <= mid) Cover((rt << 1), b, mid, l, r);
    if (r > mid) Cover((rt << 1) | 1, mid + 1, e, l, r);
    pushup(rt);
  }
  int Query(int rt, int b, int e, int l, int r) {
    if (l <= b && e <= r) {
      return key[rt];
    }
    int mid = (b + e) >> 1;
    pushdown(rt);
    if (r <= mid) return Query((rt << 1), b, mid, l, r);
    if (l > mid) return Query((rt << 1) | 1, mid + 1, e, l, r);
    return Add(Query((rt << 1), b, mid, l, r),
               Query((rt << 1) | 1, mid + 1, e, l, r));
  }
} T;
void init() {
  read(n);
  read(m);
  read(k);
  for (int i = 1; i <= k; ++i) {
    int xl, yl, xr, yr;
    read(xl);
    read(yl);
    read(xr);
    read(yr);
    p[++tot] = (Line){xl, yl, yr, 1};
    p[++tot] = (Line){xr + 1, yl, yr, -1};
  }
  sort(p + 1, p + tot + 1);
}
void solve() {
  T.Update(1, 1, m, 1, 1);
  S.insert(make_pair(0, 0));
  int l = 1, r = 1;
  for (; r <= tot && p[r].x == 1; ++r) {
    S.insert(make_pair(p[r].yl, p[r].yr));
  }
  for (int i = 2; i <= n; ++i) {
    for (l = r; r <= tot && p[r].x == i; ++r) {
      if (p[r].t == 1 && p[r].yr < m) {
        pair<int, int> cur = *--S.lower_bound(make_pair(p[r].yr + 2, 0));
        int tmp = 0;
        if (cur.second < p[r].yr)
          tmp = T.Query(1, 1, m, cur.second + 1, p[r].yr + 1);
        T.Update(1, 1, m, p[r].yr + 1, tmp);
      }
    }
    for (; l < r; ++l) {
      if (p[l].t == 1) break;
      S.erase(make_pair(p[l].yl, p[l].yr));
    }
    for (; l < r; ++l) {
      S.insert(make_pair(p[l].yl, p[l].yr));
      T.Cover(1, 1, m, p[l].yl, p[l].yr);
    }
  }
  pair<int, int> cur = *(--S.end());
  printf("%d\n", (cur.second < m) ? T.Query(1, 1, m, cur.second + 1, m) : 0);
}
int main() {
  init();
  solve();
  return 0;
}
