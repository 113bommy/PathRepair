#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 5;
const int MOD = (int)1e9 + 7;
const int inf = 0x3f3f3f3f;
struct Seg {
  long long w;
  int aw, iw;
};
int w[N], a[N];
Seg seg[N << 2];
inline int addMod(int a, int b) { return a + b >= MOD ? a + b - MOD : a + b; }
inline Seg merge(const Seg& a, const Seg& b) {
  Seg ret;
  ret.aw = addMod(a.aw, b.aw);
  ret.w = a.w + b.w;
  ret.iw = addMod(a.iw, b.iw);
  return ret;
}
inline void update(int pos, int l, int r, int rt) {
  if (l == r) {
    seg[rt].aw = (long long)a[pos] * w[pos] % MOD;
    seg[rt].w = w[pos];
    seg[rt].iw = (long long)pos * w[pos] % MOD;
    return;
  }
  int m = (l + r) >> 1;
  if (pos <= m) {
    update(pos, l, m, rt << 1);
  } else {
    update(pos, m + 1, r, rt << 1 | 1);
  }
  seg[rt] = merge(seg[rt << 1], seg[rt << 1 | 1]);
}
inline int findK(long long w, int l, int r, int rt) {
  if (l == r) {
    return l;
  }
  int m = (l + r) >> 1;
  if (seg[rt << 1].w > w) {
    return findK(w, l, m, rt << 1);
  } else {
    return findK(w - seg[rt << 1].w, m + 1, r, rt << 1 | 1);
  }
}
inline Seg query(int ql, int qr, int l, int r, int rt) {
  if (ql <= l && r <= qr) {
    return seg[rt];
  }
  int m = (l + r) >> 1;
  Seg ret = Seg{0, 0, 0};
  if (ql <= m) {
    ret = merge(ret, query(ql, qr, l, m, rt << 1));
  }
  if (m < qr) {
    ret = merge(ret, query(ql, qr, m + 1, r, rt << 1 | 1));
  }
  return ret;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
    update(i, 1, n, 1);
  }
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < 0) {
      x = -x;
      w[x] = y;
      update(x, 1, n, 1);
    } else {
      long long pref = x == 1 ? 0 : query(1, x - 1, 1, n, 1).w;
      pref = pref + query(x, y, 1, n, 1).w / 2;
      int k = findK(pref, 1, n, 1);
      Seg t1 = query(x, k, 1, n, 1);
      Seg t2 = k == y ? Seg{0, 0, 0} : query(k + 1, y, 1, n, 1);
      int ans = addMod(t2.aw, MOD - t1.aw);
      ans = addMod(
          ans, (long long)a[k] * addMod(t1.w % MOD, MOD - t2.w % MOD) % MOD);
      ans = addMod(ans,
                   (long long)k * addMod(t2.w % MOD, MOD - t1.w % MOD) % MOD);
      ans = addMod(ans, addMod(t1.iw, MOD - t2.iw));
      printf("%d\n", ans);
    }
  }
}
