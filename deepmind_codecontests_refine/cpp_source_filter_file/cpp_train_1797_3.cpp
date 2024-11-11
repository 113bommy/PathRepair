#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
struct node {
  int pl, pr, sl, sr, mxlr, mxrl, slr, srl, plr, prl;
  int l, r, lz;
  node() { pl = pr = sl = sr = mxlr = mxrl = slr = srl = plr = prl = lz = 0; }
};
node arr[maxn << 2];
char str[maxn];
int n, q;
node pushup(node a, node b) {
  node c;
  c.l = a.l;
  c.r = b.r;
  c.pl = a.pl;
  if (a.pl == a.r - a.l + 1) c.pl += b.pl;
  c.pr = a.pr;
  if (a.pr == a.r - a.l + 1) c.pr += b.pr;
  c.sl = b.sl;
  if (b.sl == b.r - b.l + 1) c.sl += a.sl;
  c.sr = b.sr;
  if (b.sr == b.r - b.l + 1) c.sr += a.sr;
  c.plr = a.plr;
  if (a.plr == a.r - a.l + 1) c.plr += b.pr;
  if (a.pl == a.r - a.l + 1) {
    if (b.pr) c.plr = a.pl + b.pr;
    if (b.plr) c.plr = a.pl + b.plr;
  }
  c.prl = a.prl;
  if (a.prl == a.r - a.l + 1) c.prl += b.pl;
  if (a.pr == a.r - a.l + 1) {
    if (b.pl) c.prl = a.pr + b.pl;
    if (b.plr) c.prl = a.pr + b.plr;
  }
  c.slr = b.slr;
  if (b.slr == b.r - b.l + 1) c.slr += a.sl;
  if (b.sr == b.r - b.l + 1) {
    if (a.sl) c.slr = b.sr + a.sl;
    if (a.slr) c.slr = b.sr + a.slr;
  }
  c.srl = b.srl;
  if (b.srl == b.r - b.l + 1) c.srl += a.sr;
  if (b.sl == b.r - b.l + 1) {
    if (a.sr) c.srl = b.sl + a.sr;
    if (a.srl) c.srl = b.sl + a.srl;
  }
  c.mxlr = max(c.slr, c.plr);
  if (a.sl && b.pr) c.mxlr = max(c.mxlr, a.sl + b.pr);
  if (b.plr) c.mxlr = max(c.mxlr, b.plr + a.sl);
  if (a.slr) c.mxlr = max(c.mxlr, a.slr + b.pr);
  c.mxlr = max(c.mxlr, max(a.mxlr, b.mxlr));
  c.mxrl = max(c.srl, c.prl);
  if (a.sr && b.pl) c.mxrl = max(c.mxrl, a.sr + b.pl);
  if (b.prl) c.mxrl = max(c.mxrl, b.prl + a.sr);
  if (a.srl) c.mxrl = max(c.mxrl, a.srl + b.pl);
  c.mxrl = max(c.mxrl, max(a.mxrl, b.mxrl));
  return c;
}
void build(int o, int L, int R) {
  arr[o].l = L;
  arr[o].r = R;
  if (L == R) {
    if (str[L] == '<')
      arr[o].pl = arr[o].sl = 1;
    else
      arr[o].pr = arr[o].sr = 1;
    return;
  }
  int mid = (L + R) / 2;
  build(o << 1, L, mid);
  build(o << 1 | 1, mid + 1, R);
  arr[o] = pushup(arr[o << 1], arr[o << 1 | 1]);
}
void rev(int o) {
  swap(arr[o].pl, arr[o].pr);
  swap(arr[o].sl, arr[o].sr);
  swap(arr[o].slr, arr[o].srl);
  swap(arr[o].plr, arr[o].prl);
  swap(arr[o].mxlr, arr[o].mxrl);
  arr[o].lz ^= 1;
}
void pushdown(int o) {
  if (!arr[o].lz) return;
  rev(o << 1);
  rev(o << 1 | 1);
  arr[o].lz = 0;
}
node query(int o, int L, int R, int l, int r) {
  if (l <= L && R <= r) {
    rev(o);
    return arr[o];
  }
  pushdown(o);
  int mid = (L + R) / 2;
  node ret;
  if (r <= mid)
    ret = query(o << 1, L, mid, l, r);
  else if (l > mid)
    ret = query(o << 1 | 1, mid + 1, R, l, r);
  else
    ret = pushup(query(o << 1, L, mid, l, r),
                 query(o << 1 | 1, mid + 1, R, l, r));
  arr[o] = pushup(arr[o << 1], arr[o << 1 | 1]);
  return ret;
}
int main() {
  scanf("%d%d", &n, &q);
  scanf("%s", str + 1);
  build(1, 1, n);
  while (q--) {
    int L, R;
    scanf("%d%d", &L, &R);
    auto x = query(1, 1, n, L, R);
    int ans = max(x.mxrl, max(x.pl, x.sr));
    printf("%d\n", ans);
  }
  return 0;
}
