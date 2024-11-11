#include <bits/stdc++.h>
using namespace std;
int read();
int n, a[200005], p[200005];
struct Seg {
  int c[1000006], v[1000006], s[1000006], tg[1000006], stg[1000006];
  int len[1000006], slen[1000006];
  long long sum[1000006];
  void clear(int l, int r, int k) {
    v[k] = s[k] = c[k] = tg[k] = stg[k] = len[k] = slen[k] = sum[k] = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    clear(l, mid, k << 1), clear(mid + 1, r, k << 1 | 1);
  }
  void update(int k) {
    int L = k << 1, R = k << 1 | 1;
    c[k] = c[L] + c[R], len[k] = len[L] + len[R], sum[k] = sum[L] + sum[R];
    if (v[L] > v[R]) {
      v[k] = v[L], s[k] = max(s[L], v[R]);
      len[k] = len[L], slen[k] = slen[L] + len[R] + slen[R];
    } else if (v[L] < v[R]) {
      v[k] = v[R], s[k] = max(v[L], s[R]);
      len[k] = len[R], slen[k] = slen[R] + len[L] + slen[L];
    } else {
      v[k] = v[L], s[k] = max(s[L], s[R]);
      len[k] = len[L] + len[R], slen[k] = slen[R] + slen[L];
    }
  }
  void Tag(int k, int t1, int t2, int ctm) {
    if (!ctm) t1 = t2;
    v[k] += t1, tg[k] += t1, s[k] += t2, stg[k] += t2;
    sum[k] += 1ll * t1 * len[k] + 1ll * t2 * slen[k];
  }
  void psd(int k) {
    int L = k << 1, R = k << 1 | 1, mr = v[R] >= v[L];
    Tag(L, tg[k], stg[k], v[L] >= v[R]);
    Tag(R, tg[k], stg[k], mr), tg[k] = stg[k] = 0;
  }
  int add(int l, int r, int k, int st, int en) {
    if (st > r || en < l) return 0;
    if (st <= l && en >= r) return Tag(k, 1, 1, 1), c[k];
    int mid = (psd(k), l + r >> 1), rt = 0;
    rt = add(l, mid, k << 1, st, en) + add(mid + 1, r, k << 1 | 1, st, en),
    update(k);
    return rt;
  }
  void modi(int l, int r, int k, int p, int tv) {
    if (l == r) return sum[k] = v[k] = tv, len[k] = c[k] = 1, void();
    int mid = (psd(k), l + r >> 1);
    p <= mid ? modi(l, mid, k << 1, p, tv)
             : modi(mid + 1, r, k << 1 | 1, p, tv),
        update(k);
  }
  void pmin(int l, int r, int k, int st, int en, int tv) {
    if (st > r || en < l || tv >= v[k]) return;
    if (st <= l && en >= r && tv > s[k])
      return Tag(k, min(tv - v[k], 0), 0, 1), void();
    int mid = (psd(k), l + r >> 1);
    pmin(l, mid, k << 1, st, en, tv), pmin(mid + 1, r, k << 1 | 1, st, en, tv),
        update(k);
  }
  void prt(int l, int r, int k) {
    if (l == r) return c[k] ? printf("%d ", v[k]) : 0, void();
    int mid = (psd(k), l + r >> 1);
    prt(l, mid, k << 1), prt(mid + 1, r, k << 1 | 1);
  }
} seg;
long long res[200005];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) p[a[i] = read()] = i;
  for (int t = 1; t <= 2; ++t) {
    seg.clear(1, n, 1);
    for (int i = 1, x; i <= n; ++i) {
      x = seg.add(1, n, 1, p[i] + 1, n), seg.modi(1, n, 1, p[i], i + 1);
      seg.pmin(1, n, 1, 1, p[i] - 1, i - x), res[i] += seg.sum[1];
    }
    for (int i = 1; i <= n; ++i) p[i] = n - p[i] + 1;
  }
  for (int i = 1; i <= n; ++i) printf("%d\n", res[i] - i * (i + 2));
  return 0;
}
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
