#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 200000;
typedef struct R {
  int len;
  long long sum;
  long long mnoddpref, mnoddsuff;
  long long mxevnpref, mxevnsuff;
} R;
R merge(const R &a, const R &b) {
  if (a.len == 0)
    return b;
  else if (b.len == 0)
    return a;
  R c;
  c.len = a.len + b.len;
  c.sum = a.len % 2 == 0 ? a.sum + b.sum : a.sum - b.sum;
  c.mnoddpref = min(a.mnoddpref,
                    a.len % 2 == 0 ? a.sum + b.mnoddpref : a.sum - b.mxevnpref);
  c.mxevnpref = max(a.mxevnpref,
                    a.len % 2 == 0 ? a.sum + b.mxevnpref : a.sum - b.mnoddpref);
  c.mnoddsuff =
      min(b.mnoddsuff, b.len % 2 == 0
                           ? (b.len % 2 == 0 ? -b.sum : b.sum) + a.mnoddsuff
                           : (b.len % 2 == 0 ? -b.sum : b.sum) - a.mxevnsuff);
  c.mxevnsuff =
      max(b.mxevnsuff, b.len % 2 == 0
                           ? (b.len % 2 == 0 ? -b.sum : b.sum) + a.mxevnsuff
                           : (b.len % 2 == 0 ? -b.sum : b.sum) - a.mnoddsuff);
  return c;
}
int n, nq;
int a[MAXN];
R seg[2 * MAXN];
int slazy[2 * MAXN];
void sinit() {
  for (int i = (0); i < (n); ++i) {
    int idx = n + i;
    seg[idx].len = 1, seg[idx].sum = a[i], seg[idx].mnoddpref = a[i],
    seg[idx].mnoddsuff = a[i], seg[idx].mxevnpref = 0, seg[idx].mxevnsuff = 0;
  }
  for (int idx = n - 1; idx >= 1; --idx)
    seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
  memset(slazy, 0, sizeof(slazy));
}
void smod(int idx, int by) {
  R &a = seg[idx];
  if (a.len % 2 == 1) a.sum += by;
  a.mnoddpref += by;
  a.mnoddsuff += by;
  slazy[idx] += by;
}
void _spush(int idx) {
  if (slazy[idx] == 0) return;
  smod(idx << 1, slazy[idx]);
  smod(idx << 1 | 1, slazy[idx]);
  slazy[idx] = 0;
}
void spush(int idx) {
  int h = 0;
  while (idx >> h) ++h;
  for (--h; h > 0; --h) _spush(idx >> h);
}
void sbuild(int idx) {
  for (idx >>= 1; idx; idx >>= 1) {
    _spush(idx);
    seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
  }
}
void sinc(int l, int r, int by) {
  int lidx = l + n, ridx = r + n + 1;
  for (; lidx < ridx; lidx >>= 1, ridx >>= 1) {
    if (lidx & 1) smod(lidx++, by);
    if (ridx & 1) smod(--ridx, by);
  }
  sbuild(l + n), sbuild(r + n);
}
R sget(int l, int r) {
  int lidx = l + n, ridx = r + n + 1;
  spush(lidx), spush(ridx - 1);
  R lret;
  lret.len = 0, lret.sum = 0, lret.mnoddpref = lret.mnoddpref = LLONG_MAX,
  lret.mxevnpref = lret.mxevnsuff = LLONG_MIN;
  R rret;
  rret.len = 0, rret.sum = 0, rret.mnoddpref = rret.mnoddpref = LLONG_MAX,
  rret.mxevnpref = rret.mxevnsuff = LLONG_MIN;
  for (; lidx < ridx; lidx >>= 1, ridx >>= 1) {
    if (lidx & 1) lret = merge(lret, seg[lidx++]);
    if (ridx & 1) rret = merge(seg[--ridx], rret);
  }
  return merge(lret, rret);
}
bool ok(const R &a) {
  bool ok1 = a.mnoddpref >= 1 && a.mxevnpref <= 0 && a.sum == a.len % 2;
  bool ok2 = a.mnoddsuff >= 1 && a.mxevnsuff <= 0 && a.sum == a.len % 2;
  return ok1 || ok2;
}
void chk() {
  int l = 2, r = 99;
  int sum = 0;
  long long mnodd = LLONG_MAX, mxevn = 0;
  for (int i = (l); i <= (r); ++i)
    sum += (i - l) % 2 == 0 ? +a[i] : -a[i],
        mnodd = min(mnodd, (i - l) % 2 == 0 ? sum : mnodd),
        mxevn = max(mxevn, (i - l) % 2 == 1 ? sum : mxevn);
  R res = sget(l, r);
  printf("%lld %lld vs %lld %lld\n", res.mnoddpref, res.mxevnpref, mnodd,
         mxevn);
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  sinit();
  scanf("%d", &nq);
  for (int qi = (0); qi < (nq); ++qi) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int l, r, k;
      scanf("%d%d%d", &l, &r, &k);
      sinc(l, r, k);
    }
    if (type == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      R res = sget(l, r);
      printf("%d\n", ok(res) ? 1 : 0);
    }
  }
}
int main() {
  run();
  return 0;
}
