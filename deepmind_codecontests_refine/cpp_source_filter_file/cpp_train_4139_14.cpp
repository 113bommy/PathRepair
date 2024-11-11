#include <bits/stdc++.h>
const int MAXN = 3e5 + 5;
int mn[MAXN << 2], cnt[MAXN << 2], tag[MAXN << 2];
int res[MAXN << 2], tag2[MAXN << 2];
inline void pushup(int x) {
  mn[x] = std::min(mn[((x) << 1)], mn[((x) << 1 | 1)]);
  cnt[x] = 0;
  if (mn[x] == mn[((x) << 1)]) cnt[x] += cnt[((x) << 1)];
  if (mn[x] == mn[((x) << 1 | 1)]) cnt[x] += cnt[((x) << 1 | 1)];
}
inline void cover(int x, int d) {
  mn[x] += d;
  tag[x] += d;
}
inline void cover2(int x, int mn, int d) {
  if (::mn[x] != mn) return;
  res[x] += 1ll * cnt[x] * d;
  tag2[x] += d;
}
inline void pushdown(int x) {
  if (tag[x]) {
    cover(((x) << 1), tag[x]);
    cover(((x) << 1 | 1), tag[x]);
    tag[x] = 0;
  }
  if (tag2[x]) {
    cover2(((x) << 1), mn[x], tag2[x]);
    cover2(((x) << 1 | 1), mn[x], tag2[x]);
    tag2[x] = 0;
  }
}
inline void modify(int x, int l, int r, int L, int R, int d) {
  if (l == L && r == R) {
    cover(x, d);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(x);
  if (R <= mid)
    modify(((x) << 1), l, mid, L, R, d);
  else if (L > mid)
    modify(((x) << 1 | 1), mid + 1, r, L, R, d);
  else
    modify(((x) << 1), l, mid, L, mid, d),
        modify(((x) << 1 | 1), mid + 1, r, mid + 1, R, d);
  pushup(x);
}
inline void build(int x, int l, int r) {
  if (l == r) {
    mn[x] = l;
    cnt[x] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(((x) << 1), l, mid);
  build(((x) << 1 | 1), mid + 1, r);
  pushup(x);
}
inline long long query(int x, int l, int r, int L, int R) {
  if (l == L && r == R) return res[x];
  int mid = (l + r) >> 1;
  pushdown(x);
  if (R <= mid) return query(((x) << 1), l, mid, L, R);
  if (L > mid) return query(((x) << 1 | 1), mid + 1, r, L, R);
  return query(((x) << 1), l, mid, L, mid) +
         query(((x) << 1 | 1), mid + 1, r, mid + 1, R);
}
int a[MAXN];
int n;
int stk1[MAXN], stk2[MAXN], tp1, tp2;
std::vector<std::pair<int, int> > G[MAXN];
long long ans[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    G[r].push_back(std::make_pair(l, i));
  }
  build(1, 1, n);
  for (int i = 1; i <= n; ++i) {
    while (tp1 && a[stk1[tp1]] <= a[i]) {
      modify(1, 1, n, stk1[tp1 - 1] + 1, stk1[tp1], -a[stk1[tp1]]);
      --tp1;
    }
    while (tp2 && a[stk2[tp2]] >= a[i]) {
      modify(1, 1, n, stk2[tp2 - 1] + 1, stk2[tp2], a[stk2[tp2]]);
      --tp2;
    }
    modify(1, 1, n, stk1[tp1] + 1, i, a[i]);
    modify(1, 1, n, stk2[tp2] + 1, i, -a[i]);
    stk1[++tp1] = i;
    stk2[++tp2] = i;
    cover2(1, mn[1], 1);
    for (auto x : G[i]) ans[x.second] = query(1, 1, n, x.first, i);
  }
  for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
