#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 100007, __ = 1000007, mo = 1000000007;
template <typename T1, typename T2>
inline T1 ad(T1 &a, T2 b) {
  return a = a + b >= mo ? a + b - mo : a + b;
}
template <typename T1, typename T2>
inline T1 dl(T1 &a, T2 b) {
  return a = a >= b ? a - b : a - b + mo;
}
template <typename T1, typename T2>
inline T1 add(T1 a, T2 b) {
  return a + b >= mo ? a + b - mo : a + b;
}
template <typename T1, typename T2>
inline T1 del(T1 a, T2 b) {
  return a >= b ? a - b : a - b + mo;
}
struct sgt {
  static const int _t = __ << 2;
  long long t[_t];
  int tcls[_t];
  void up(int x) { t[x] = add(t[(x << 1)], t[(x << 1 | 1)]); }
  void putcls(int x) { tcls[x] = 1, t[x] = 0; }
  void dwn(int x) {
    if (tcls[x]) putcls((x << 1)), putcls((x << 1 | 1)), tcls[x] = 0;
  }
  void plant(int x, int l, int r) {
    t[x] = 0, tcls[x] = 0;
    if (l == r) return;
    plant((x << 1), l, ((l + r) >> 1)),
        plant((x << 1 | 1), ((l + r) >> 1) + 1, r), up(x);
  }
  void change(int x, int l, int r, int tar, long long d) {
    if (l == r) {
      ad(t[x], d);
      return;
    }
    dwn(x);
    if (tar <= ((l + r) >> 1))
      change((x << 1), l, ((l + r) >> 1), tar, d);
    else
      change((x << 1 | 1), ((l + r) >> 1) + 1, r, tar, d);
    up(x);
  }
  void qinxi(int x, int l, int r, int tl, int tr) {
    if (tl <= l && r <= tr) {
      putcls(x);
      return;
    }
    dwn(x);
    if (tl <= ((l + r) >> 1)) qinxi((x << 1), l, ((l + r) >> 1), tl, tr);
    if (tr > ((l + r) >> 1)) qinxi((x << 1 | 1), ((l + r) >> 1) + 1, r, tl, tr);
    up(x);
  }
  long long finder(int x, int l, int r, int tl, int tr) {
    if (tl <= l && r <= tr) return t[x];
    dwn(x);
    if (tr <= ((l + r) >> 1))
      return finder((x << 1), l, ((l + r) >> 1), tl, tr);
    if (tl > ((l + r) >> 1))
      return finder((x << 1 | 1), ((l + r) >> 1) + 1, r, tl, tr);
    return add(finder((x << 1), l, ((l + r) >> 1), tl, tr),
               finder((x << 1 | 1), ((l + r) >> 1) + 1, r, tl, tr));
  }
} t;
struct cxk {
  int xl, yl, xr, yr;
  long long val;
  cxk(int xl_ = 0, int yl_ = 0, int xr_ = 0, int yr_ = 0, long long val_ = 0) {
    xl = xl_, yl = yl_, xr = xr_, yr = yr_, val = val_;
  }
  friend int operator<(cxk a, cxk b) { return a.yl < a.yr; }
} ps[_];
int n, m, lps;
vector<int> qa[__], qd[__];
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty(), lps = ty();
  for (int i = 1, a, b, c, d; i <= lps; i++)
    a = ty(), b = ty(), c = ty(), d = ty(), ps[i] = cxk(a, b, c, d);
  sort(ps + 1, ps + lps + 1);
  for (int i = 1; i <= lps; i++)
    qa[ps[i].xl].emplace_back(i), qd[ps[i].xr + 1].emplace_back(i);
  set<pair<int, int>> hav;
  hav.emplace(0, 0);
  for (int i = 1; i <= n; i++) {
    for (auto a : qa[i]) {
      int b = hav.lower_bound(make_pair(-ps[a].yr - 1, 0))->second;
      if ((!b || ps[b].yr + 1 <= ps[a].yr) && ps[a].yr < m)
        ps[a].val = t.finder(1, 1, m, ps[b].yr + 1, ps[a].yr);
    }
    for (auto a : qa[i]) {
      hav.emplace(-ps[a].yl, a), hav.emplace(-ps[a].yr, a);
      t.qinxi(1, 1, m, ps[a].yl, ps[a].yr);
      if (ps[a].val) t.change(1, 1, m, ps[a].yr + 1, ps[a].val);
    }
    for (auto a : qd[i])
      hav.erase(make_pair(-ps[a].yl, a)), hav.erase(make_pair(-ps[a].yr, a));
    if (i == 1) t.change(1, 1, m, 1, 1);
  }
  int loc = hav.lower_bound(make_pair(-m, 0))->first;
  cout << t.finder(1, 1, m, -loc + 1, m) << lf;
  return 0;
}
