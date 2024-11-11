#include <bits/stdc++.h>
const int MN = 100005, MS = 1 << 18 | 7;
namespace Hashing {
const int Mod = 998244353, B = 114514, iB = 137043501;
int _w[MN * 2], *w = _w + MN;
void Init(int N) {
  w[0] = 1;
  for (int i = 1; i <= N; ++i)
    w[i] = (long long)w[i - 1] * B % Mod,
    w[-i] = (long long)w[-i + 1] * iB % Mod;
}
struct str {
  int x, m;
  str() { x = m = 0; }
  str(int v) { x = v, m = 1; }
  str(int _x, int _m) : x(_x), m(_m) {}
  friend bool operator==(str a, str b) { return a.m == b.m && a.x == b.x; }
  friend str operator+(str a, str b) {
    return str((a.x + (long long)b.x * w[a.m]) % Mod, a.m + b.m);
  }
  friend str operator-(str a, str b) {
    return str((long long)(a.x - b.x + Mod) * w[-b.m] % Mod, a.m - b.m);
  }
};
}  // namespace Hashing
using Hashing::str;
int N, Q;
struct dat {
  bool err;
  str vl, vr;
  dat() { err = 0; }
  dat(int x) {
    err = 0;
    x > 0 ? vr = str(x, 1) : vl = str(-x, 1);
  }
} tr[MS];
str gValL(int i, int k) {
  if (!k) return str();
  if (k == tr[i].vl.m) return tr[i].vl;
  if (k <= tr[(i << 1)].vl.m) return gValL((i << 1), k);
  return tr[(i << 1)].vl +
         (gValL(((i << 1) | 1), k - tr[(i << 1)].vl.m + tr[(i << 1)].vr.m) -
          tr[(i << 1)].vr);
}
str gValR(int i, int k) {
  if (!k) return str();
  if (k == tr[i].vr.m) return tr[i].vr;
  if (k <= tr[((i << 1) | 1)].vr.m) return gValR(((i << 1) | 1), k);
  return tr[((i << 1) | 1)].vr + (gValR((i << 1), k - tr[((i << 1) | 1)].vr.m +
                                                      tr[((i << 1) | 1)].vl.m) -
                                  tr[((i << 1) | 1)].vl);
}
void Upd(int i) {
  if (tr[(i << 1)].err || tr[((i << 1) | 1)].err) return tr[i].err = 1, void();
  tr[i].err = 0;
  tr[i].vl = tr[(i << 1)].vl;
  tr[i].vr = tr[((i << 1) | 1)].vr;
  if (tr[(i << 1)].vr.m <= tr[((i << 1) | 1)].vl.m) {
    if (tr[(i << 1)].vr == gValL(((i << 1) | 1), tr[(i << 1)].vr.m))
      tr[i].vl = tr[i].vl + (tr[((i << 1) | 1)].vl - tr[(i << 1)].vr);
    else
      tr[i].err = 1;
  } else {
    if (tr[((i << 1) | 1)].vl == gValR((i << 1), tr[((i << 1) | 1)].vl.m))
      tr[i].vr = tr[i].vr + (tr[(i << 1)].vr - tr[((i << 1) | 1)].vl);
    else
      tr[i].err = 1;
  }
}
void Build(int i, int l, int r) {
  if (l == r) {
    int x;
    scanf("%d", &x);
    tr[i] = x;
    return;
  }
  Build((i << 1), l, ((l + r) >> 1)),
      Build(((i << 1) | 1), ((l + r) >> 1) + 1, r);
  Upd(i);
}
void Mdf(int i, int l, int r, int p, int x) {
  if (l == r) return tr[i] = x, void();
  p <= ((l + r) >> 1) ? Mdf((i << 1), l, ((l + r) >> 1), p, x)
                      : Mdf(((i << 1) | 1), ((l + r) >> 1) + 1, r, p, x);
  Upd(i);
}
int stk[45], tp;
void Extract(int i, int l, int r, int a, int b) {
  if (r < a || b < l) return;
  if (a <= l && r <= b) return stk[++tp] = i, void();
  Extract((i << 1), l, ((l + r) >> 1), a, b),
      Extract(((i << 1) | 1), ((l + r) >> 1) + 1, r, a, b);
}
str seq[45];
str gVal(int i, int k) {
  if (!k) return str();
  if (k == seq[i].m) return seq[i];
  if (k <= tr[stk[i]].vr.m) return gValR(stk[i], k);
  return tr[stk[i]].vr +
         (gVal(i - 1, k - tr[stk[i]].vr.m + tr[stk[i]].vl.m) - tr[stk[i]].vl);
}
bool Qur(int l, int r) {
  tp = 0, Extract(1, 1, N, l, r);
  for (int i = 1; i <= tp; ++i) {
    if (tr[stk[i]].err) return 0;
    if (seq[i - 1].m < tr[stk[i]].vl.m) return 0;
    if (tr[stk[i]].vl == gVal(i - 1, tr[stk[i]].vl.m))
      seq[i] = tr[stk[i]].vr + (seq[i - 1] - tr[stk[i]].vl);
    else
      return 0;
  }
  return !seq[tp].m;
}
int main() {
  scanf("%d%*d", &N);
  Hashing::Init(N);
  Build(1, 1, N);
  scanf("%d", &Q);
  while (Q--) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1)
      Mdf(1, 1, N, x, y);
    else
      puts(Qur(x, y) ? "Yes" : "No");
  }
  return 0;
}
