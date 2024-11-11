#include <bits/stdc++.h>
using namespace std;
long long gi() {
  long long res = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar();
  return res * w;
}
const long long INF = 3e18;
const int MAX_N = 2e5 + 5;
struct lsh {
  long long o[MAX_N << 2];
  int cnt;
  void ins(long long v) { o[++cnt] = v; }
  int find(long long v) { return lower_bound(&o[1], &o[cnt + 1], v) - o; }
  void build() {
    sort(&o[1], &o[cnt + 1]);
    cnt = unique(&o[1], &o[cnt + 1]) - o - 1;
  }
} X, Y;
long long mx1[MAX_N << 4], mx2[MAX_N << 4], tag[MAX_N << 4];
void pushup(int o) {
  mx1[o] = max(mx1[(o << 1)], mx1[(o << 1 | 1)]),
  mx2[o] = max(mx2[(o << 1)], mx2[(o << 1 | 1)]);
}
void puttag(int o, long long v) { mx1[o] += v, mx2[o] += v, tag[o] += v; }
void pushdown(int o) {
  if (!tag[o]) return;
  puttag((o << 1), tag[o]), puttag((o << 1 | 1), tag[o]);
  tag[o] = 0;
}
void build(int o = 1, int l = 1, int r = Y.cnt) {
  mx1[o] = mx2[o] = -INF;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build((o << 1), l, mid), build((o << 1 | 1), mid + 1, r);
}
void modify(int ql, int qr, long long v, int o = 1, int l = 1, int r = Y.cnt) {
  if (ql <= l && r <= qr) return puttag(o, v);
  pushdown(o);
  int mid = (l + r) >> 1;
  if (ql <= mid) modify(ql, qr, v, (o << 1), l, mid);
  if (qr > mid) modify(ql, qr, v, (o << 1 | 1), mid + 1, r);
  pushup(o);
}
void update(int pos, long long v1, long long v2, int o = 1, int l = 1,
            int r = Y.cnt) {
  if (l == r) return (void)(mx1[o] = max(mx1[o], v1), mx2[o] = max(mx2[o], v2));
  pushdown(o);
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update(pos, v1, v2, (o << 1), l, mid);
  else
    update(pos, v1, v2, (o << 1 | 1), mid + 1, r);
  pushup(o);
}
void query(int ql, int qr, long long &v1, long long &v2, int o = 1, int l = 1,
           int r = Y.cnt) {
  if (ql > qr) return;
  if (ql <= l && r <= qr)
    return (void)(v1 = max(v1, mx1[o]), v2 = max(v2, mx2[o]));
  pushdown(o);
  int mid = (l + r) >> 1;
  if (ql <= mid) query(ql, qr, v1, v2, (o << 1), l, mid);
  if (qr > mid) query(ql, qr, v1, v2, (o << 1 | 1), mid + 1, r);
}
int N, M, C, mrk[MAX_N << 2];
long long a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N];
int main() {
  N = gi(), M = gi(), C = gi();
  for (int i = 1; i <= N; i++) X.ins(a[i] = gi()), X.ins(b[i] = gi());
  for (int i = 1; i <= M; i++) X.ins(c[i] = gi()), X.ins(d[i] = gi());
  X.build();
  for (int i = 1; i <= N; i++) a[i] = X.find(a[i]), b[i] = X.find(b[i]);
  for (int i = 1; i <= M; i++) c[i] = X.find(c[i]), d[i] = X.find(d[i]);
  for (int i = 1; i <= N; i++) mrk[a[i]] ^= 1, mrk[b[i]] ^= 1;
  for (int i = 1; i <= M; i++) mrk[c[i]] ^= 2, mrk[d[i]] ^= 2;
  for (int i = 2; i <= X.cnt; i++) mrk[i] ^= mrk[i - 1];
  long long shift = 0;
  Y.ins(0);
  for (int i = 1; i < X.cnt; i++) {
    long long len = X.o[i + 1] - X.o[i];
    if (mrk[i] == 1) shift -= len;
    if (mrk[i] == 2) shift += len;
    if (mrk[i] == 3) Y.ins(-C + shift), Y.ins(C + shift);
  }
  Y.build(), shift = 0, build(), update(Y.find(0), 0, 0);
  long long s = 0;
  for (int i = 1; i < X.cnt; i++) {
    long long len = X.o[i + 1] - X.o[i];
    if (mrk[i] & 1) shift -= len, s += len;
    if (mrk[i] & 2) shift += len;
    if (mrk[i] == 3) {
      int l = Y.find(-C + shift), r = Y.find(C + shift);
      long long vl = -INF, vr = -INF, t1 = -INF, t2 = -INF;
      query(1, l, t1, t2), vl = t1, t1 = t2 = -INF;
      query(r, Y.cnt, t1, t2), vr = t2 + (C + shift);
      update(l, vl, vl - (shift - C));
      update(r, vr, vr - (shift + C));
      modify(l, r, len);
    }
  }
  printf("%lld\n", mx1[1] + s);
  return 0;
}
