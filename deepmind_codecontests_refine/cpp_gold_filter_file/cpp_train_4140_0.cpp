#include <bits/stdc++.h>
using namespace std;
const int MAXN = 120005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int n, m, p[MAXN];
vector<pair<int, int> > q[MAXN];
int stk1[MAXN], top1, stk2[MAXN], top2;
int mn[MAXN << 2], cnt[MAXN << 2], mtag[MAXN << 2], ctag[MAXN << 2];
long long sum[MAXN << 2], ans[MAXN];
inline void putmn(int rt, int mtg) {
  mn[rt] += mtg;
  mtag[rt] += mtg;
}
inline void putcnt(int rt, int ctg) {
  sum[rt] += 1LL * ctg * cnt[rt];
  ctag[rt] += ctg;
}
inline void pushdown(int rt) {
  if (mtag[rt]) {
    putmn(rt << 1, mtag[rt]);
    putmn((rt << 1) | 1, mtag[rt]);
    mtag[rt] = 0;
  }
  if (ctag[rt]) {
    if (mn[rt] == mn[rt << 1]) putcnt(rt << 1, ctag[rt]);
    if (mn[rt] == mn[(rt << 1) | 1]) putcnt((rt << 1) | 1, ctag[rt]);
    ctag[rt] = 0;
  }
}
inline void pushup(int rt) {
  mn[rt] = min(mn[rt << 1], mn[(rt << 1) | 1]);
  cnt[rt] = 0;
  if (mn[rt] == mn[rt << 1]) cnt[rt] += cnt[rt << 1];
  if (mn[rt] == mn[(rt << 1) | 1]) cnt[rt] += cnt[(rt << 1) | 1];
  sum[rt] = sum[rt << 1] + sum[(rt << 1) | 1];
}
void Build(int rt, int b, int e) {
  mn[rt] = b;
  cnt[rt] = 1;
  if (b == e) return;
  int mid = (b + e) >> 1;
  Build(rt << 1, b, mid);
  Build((rt << 1) | 1, mid + 1, e);
}
void Update(int rt, int b, int e, int l, int r, int val) {
  if (l <= b && e <= r) {
    putmn(rt, val);
    return;
  }
  int mid = (b + e) >> 1;
  pushdown(rt);
  if (l <= mid) Update(rt << 1, b, mid, l, r, val);
  if (r > mid) Update((rt << 1) | 1, mid + 1, e, l, r, val);
  pushup(rt);
}
long long Query(int rt, int b, int e, int l, int r) {
  if (l <= b && e <= r) return sum[rt];
  int mid = (b + e) >> 1;
  pushdown(rt);
  if (r <= mid) return Query(rt << 1, b, mid, l, r);
  if (l > mid) return Query((rt << 1) | 1, mid + 1, e, l, r);
  return Query(rt << 1, b, mid, l, r) + Query((rt << 1) | 1, mid + 1, e, l, r);
}
void init() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(p[i]);
  }
  read(m);
  for (int i = 1; i <= m; ++i) {
    int l, r;
    read(l);
    read(r);
    q[r].push_back(make_pair(l, i));
  }
}
void solve() {
  Build(1, 1, n);
  for (int i = 1; i <= n; ++i) {
    while (top1 && p[stk1[top1]] < p[i]) {
      Update(1, 1, n, stk1[top1 - 1] + 1, stk1[top1], p[i] - p[stk1[top1]]);
      --top1;
    }
    stk1[++top1] = i;
    while (top2 && p[stk2[top2]] > p[i]) {
      Update(1, 1, n, stk2[top2 - 1] + 1, stk2[top2], p[stk2[top2]] - p[i]);
      --top2;
    }
    stk2[++top2] = i;
    putmn(1, -1);
    putcnt(1, 1);
    for (auto qr : q[i]) {
      ans[qr.second] = Query(1, 1, n, qr.first, i);
    }
  }
  for (int i = 1; i <= m; ++i) {
    printf("%lld\n", ans[i]);
  }
}
int main() {
  init();
  solve();
  return 0;
}
