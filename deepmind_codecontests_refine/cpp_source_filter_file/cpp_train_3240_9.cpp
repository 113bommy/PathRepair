#include <bits/stdc++.h>
inline int rint() {
  int x = 0, f = 1;
  char s = getchar();
  for (; s < '0' || '9' < s; s = getchar()) f = s == '-' ? -f : f;
  for (; '0' <= s && s <= '9'; s = getchar()) x = x * 10 + (s ^ '0');
  return x * f;
}
template <typename Tp>
inline void wint(Tp x) {
  if (x < 0) putchar('-'), x = ~x + 1;
  if (9 < x) wint(x / 10);
  putchar(x % 10 ^ '0');
}
inline int abs_(const int x) { return x < 0 ? -x : x; }
inline int max_(const int a, const int b) { return a < b ? b : a; }
const int MAXN = 50, MOD = 998244353, INV2 = 499122177, INV6 = 166374059;
int n, t, x[MAXN + 5], y[MAXN + 5];
namespace MatrixInter {
int tmp[MAXN * 4 + 5];
class SegmentTree {
 private:
  int cover[MAXN << 4], cnt[MAXN << 4];

 public:
  inline void clear(const int rt, const int l, const int r) {
    cover[rt] = cnt[rt] = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    clear(rt << 1, l, mid), clear(rt << 1 | 1, mid + 1, r);
  }
  inline void pushup(const int rt, const int l, const int r) {
    cover[rt] =
        cnt[rt] ? tmp[r] - tmp[l - 1] : cover[rt << 1] + cover[rt << 1 | 1];
  }
  inline void add(const int rt, const int al, const int ar, const int l,
                  const int r, const int v) {
    if (al <= l && r <= ar) {
      if (!(cnt[rt] += v))
        cover[rt] = l == r ? 0 : cover[rt << 1] + cover[rt << 1 | 1];
      else
        cover[rt] = tmp[r] - tmp[l - 1];
      return;
    }
    int mid = l + r >> 1;
    if (al <= mid) add(rt << 1, al, ar, l, mid, v);
    if (mid < ar) add(rt << 1 | 1, al, ar, mid + 1, r, v);
    pushup(rt, l, r);
  }
  inline int getTop() { return cover[1]; }
} st;
struct Event {
  int l, r, opt;
};
std ::vector<Event> evt[MAXN * 4 + 5];
inline int calcS(const int t) {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    tmp[++cnt] = x[i] - t - 1, tmp[++cnt] = x[i] + t;
    tmp[++cnt] = y[i] - t - 1, tmp[++cnt] = y[i] + t;
  }
  std ::sort(tmp + 1, tmp + cnt + 1);
  cnt = std ::unique(tmp + 1, tmp + cnt + 1) - tmp - 1;
  st.clear(1, 1, cnt);
  for (int i = 1; i <= cnt; ++i) evt[i].clear();
  for (int i = 1, up, dn, le, ri; i <= n; ++i) {
    up = std ::lower_bound(tmp + 1, tmp + cnt + 1, y[i] - t - 1) - tmp + 1;
    dn = std ::lower_bound(tmp + 1, tmp + cnt + 1, y[i] + t) - tmp;
    le = std ::lower_bound(tmp + 1, tmp + cnt + 1, x[i] - t - 1) - tmp;
    ri = std ::lower_bound(tmp + 1, tmp + cnt + 1, x[i] + t) - tmp;
    evt[le].push_back({up, dn, true}), evt[ri].push_back({up, dn, false});
  }
  int ret = 0;
  for (int i = 1; i <= cnt; ++i) {
    ret = (ret + 1ll * st.getTop() * (tmp[i] - tmp[i - 1]) % MOD) % MOD;
    for (Event e : evt[i]) st.add(1, e.l, e.r, 1, cnt, e.opt ? 1 : -1);
  }
  return ret;
}
}  // namespace MatrixInter
int itime[MAXN * MAXN + 5];
inline int preS(const int n) { return n * (n + 1ll) % MOD * INV2 % MOD; }
inline int sqrS(const int n) {
  return n * (n + 1ll) % MOD * (n * 2ll | 1) % MOD * INV6;
}
int main() {
  n = rint(), t = rint();
  for (int i = 1; i <= n; ++i) x[i] = rint(), y[i] = rint();
  int icnt = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1, tmpt; j <= n; ++j) {
      tmpt = max_(abs_(x[i] - x[j]), abs(y[i] - y[j])) >> 1;
      if (tmpt <= t) itime[++icnt] = tmpt;
      if (++tmpt <= t) itime[++icnt] = tmpt;
    }
  }
  itime[++icnt] = 0, itime[++icnt] = t;
  std ::sort(itime + 1, itime + icnt + 1);
  icnt = std ::unique(itime + 1, itime + icnt + 1) - itime - 1;
  int ans = 1ll * t * MatrixInter ::calcS(t) % MOD;
  for (int i = 1, tl, tr, a, b, c, ta, tb; i < icnt; ++i) {
    if ((tl = itime[i]) + 3 > (tr = itime[i + 1])) {
      for (; tl < tr; ++tl) ans = (ans - MatrixInter ::calcS(tl) + MOD) % MOD;
      continue;
    }
    c = MatrixInter ::calcS(tl), ta = MatrixInter ::calcS(tl + 1),
    tb = MatrixInter ::calcS(tl + 2);
    a = ((tb - ta * 2ll % MOD + c) % MOD + MOD) % MOD * INV2 % MOD;
    b = ((ta - c - a) % MOD + MOD) % MOD;
    ans = (ans - 1ll * a * sqrS(tr - tl - 1) % MOD + MOD) % MOD;
    ans = (ans - 1ll * b * preS(tr - tl - 1) % MOD + MOD) % MOD;
    ans = (ans - 1ll * c * (tr - tl) % MOD + MOD) % MOD;
  }
  return wint(ans), putchar('\n'), 0;
}
