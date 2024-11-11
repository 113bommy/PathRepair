#include <bits/stdc++.h>
using namespace std;
const int _ = 8e5 + 100, __ = _ << 2;
const long long INF = 3e18;
int n, m, N, cnt, s[_];
long long C, a[_], b[_], c[_], lsh[_], tag[__], bakbakak[__], bakabaka[__];
void puttag(int k, long long w) {
  tag[k] += w, bakabaka[k] += w, bakbakak[k] += w;
}
void pushdown(int k) {
  if (tag[k]) puttag((k << 1), tag[k]), puttag((k << 1 | 1), tag[k]);
  tag[k] = 0;
}
void pushup(int k) {
  bakbakak[k] = max(bakbakak[(k << 1)], bakbakak[(k << 1 | 1)]),
  bakabaka[k] = max(bakabaka[(k << 1)], bakabaka[(k << 1 | 1)]);
}
void update(int k, int l, int r, int tar, long long e1, long long e2) {
  if (l == r) {
    bakbakak[k] = max(bakbakak[k], e2), bakabaka[k] = max(bakabaka[k], e1);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(k);
  tar <= mid ? update((k << 1), l, mid, tar, e1, e2)
             : update((k << 1 | 1), mid + 1, r, tar, e1, e2);
  pushup(k);
}
void modify(int k, int l, int r, int ql, int qr, long long w) {
  if (ql <= l && r <= qr) {
    puttag(k, w);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(k);
  if (ql <= mid) modify((k << 1), l, mid, ql, qr, w);
  if (qr > mid) modify((k << 1 | 1), mid + 1, r, ql, qr, w);
  pushup(k);
}
void query(int k, int l, int r, int ql, int qr, long long &e1, long long &e2) {
  if (ql > qr) return;
  if (ql <= l && r <= qr) {
    e2 = max(e2, bakbakak[k]), e1 = max(e1, bakabaka[k]);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(k);
  if (ql <= mid) query((k << 1), l, mid, ql, qr, e1, e2);
  if (qr > mid) query((k << 1 | 1), mid + 1, r, ql, qr, e1, e2);
}
int main() {
  scanf("%d%d%lld", &n, &m, &C), n <<= 1, m <<= 1;
  for (int i = 1; i <= n; i += 2) scanf("%lld%lld", &a[i], &a[i + 1]);
  for (int i = 1; i <= m; i += 2) scanf("%lld%lld", &b[i], &b[i + 1]);
  for (int i = 1; i <= n; ++i) c[i] = a[i];
  for (int i = 1; i <= m; ++i) c[i + n] = b[i];
  sort(c + 1, c + n + m + 1), cnt = unique(c + 1, c + n + m + 1) - c - 1;
  long long diff = 0;
  lsh[++N] = 0;
  for (int i = 1, j = 1, k = 1; i < cnt; ++i) {
    long long len = c[i + 1] - c[i];
    s[i] = s[i - 1];
    if (c[i] == a[j]) s[i] ^= 1, ++j;
    if (c[i] == b[k]) s[i] ^= 2, ++k;
    if (s[i] == 1) diff -= len;
    if (s[i] == 2) diff += len;
    if (s[i] == 3) lsh[++N] = -C + diff, lsh[++N] = C + diff;
  }
  sort(lsh + 1, lsh + N + 1), N = unique(lsh + 1, lsh + N + 1) - lsh - 1,
                              diff = 0;
  modify(1, 1, N, 1, N, -INF),
      update(1, 1, N, lower_bound(lsh + 1, lsh + N + 1, 0) - lsh, 0, 0);
  long long sumx = 0, sumy = 0;
  for (int i = 1; i < cnt; ++i) {
    long long len = c[i + 1] - c[i];
    if (s[i] == 1) sumx += len;
    if (s[i] == 2) sumy += len;
    if (s[i] == 3) {
      int l = lower_bound(lsh + 1, lsh + N + 1, -C + sumy - sumx) - lsh,
          r = lower_bound(lsh + 1, lsh + N + 1, C + sumy - sumx) - lsh;
      long long e1 = -INF, e2 = -INF;
      query(1, 1, N, 1, l - 1, e1, e2);
      update(1, 1, N, l, e1, e1 - lsh[l]);
      e1 = -INF, e2 = -INF;
      query(1, 1, N, r + 1, N, e1, e2);
      update(1, 1, N, r, e2 + lsh[r], e2);
      modify(1, 1, N, l, r, len), modify(1, 1, N, 1, N, len);
    }
  }
  cout << bakabaka[1] + sumx;
  return 0;
}
