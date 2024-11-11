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
  if (x < 0) putchar('-'), x = -x;
  if (9 < x) wint(x / 10);
  putchar(x % 10 ^ '0');
}
template <typename Tp>
inline void chkmax(Tp& a, const Tp b) {
  a < b && (a = b, 0);
}
template <typename Tp>
inline void chkmin(Tp& a, const Tp b) {
  b < a && (a = b, 0);
}
const int MAXN = 2e5, MAXV = 2e6;
int n, a[MAXN + 5];
struct Line {
  long long k, b;
  inline long long operator()(const long long x) const { return k * x + b; }
};
struct LiChaoSegmentTree {
  Line line[MAXV * 2 + 5];
  inline int id(const int l, const int r) { return l + r + MAXV | (l != r); }
  inline void clear(const int l, const int r) {
    int rt = id(l, r), mid = l + r >> 1;
    line[rt].k = line[rt].b = 0;
    if (l == r) return;
    clear(l, mid), clear(mid + 1, r);
  }
  inline void insert(const int l, const int r, Line curl) {
    int rt = id(l, r), mid = l + r >> 1;
    if (!line[rt].k) return void(line[rt] = curl);
    if (line[rt](mid) < curl(mid)) std::swap(line[rt], curl);
    if (l == r) return;
    if (line[rt](l) < curl(l)) insert(l, mid, curl);
    if (line[rt](r) < curl(r)) insert(mid + 1, r, curl);
  }
  inline long long query(const int l, const int r, const int x) {
    int rt = id(l, r), mid = l + r >> 1;
    if (!line[rt].k) return -1e18;
    long long ret = line[rt](x);
    if (l == r) return ret;
    if (x <= mid)
      chkmax(ret, query(l, mid, x));
    else
      chkmax(ret, query(mid + 1, r, x));
    return ret;
  }
} lcst;
int main() {
  n = rint();
  int mn = MAXV, mx = -MAXV;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += 1ll * i * (a[i] = rint());
    chkmin(mn, a[i]), chkmax(mx, a[i]);
  }
  long long pre = 0, suf = 0, mxdelt = -1e18;
  for (int i = n; i; suf += a[i--]) {
    chkmax(mxdelt, lcst.query(mn, mx, a[i]) - 1ll * i * a[i] - suf);
    lcst.insert(mn, mx, {i, suf});
  }
  lcst.clear(mn, mx);
  for (int i = 1; i <= n; pre += a[i++]) {
    chkmax(mxdelt, lcst.query(mn, mx, a[i]) - 1ll * i * a[i] + pre);
    lcst.insert(mn, mx, {i, -pre});
  }
  wint(ans + mxdelt), putchar('\n');
  return 0;
}
