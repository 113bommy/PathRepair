#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
using namespace std;
const int inf = 1e6 + 1;
const int up = 1e6;
int n, q;
int a[2001000];
bool app[2001000];
int ls[2001000], rs[2001000], ttot, mn[2001000], mncnt[2001000], root;
inline void pushup(int cur) {
  if (!mncnt[ls[cur]])
    mn[cur] = mn[rs[cur]], mncnt[cur] = mncnt[rs[cur]];
  else if (!mncnt[rs[cur]])
    mn[cur] = mn[ls[cur]], mncnt[cur] = mncnt[ls[cur]];
  else if (mn[ls[cur]] < mn[rs[cur]]) {
    mn[cur] = mn[ls[cur]], mncnt[cur] = mncnt[ls[cur]];
  } else if (mn[rs[cur]] < mn[ls[cur]]) {
    mn[cur] = mn[rs[cur]], mncnt[cur] = mncnt[rs[cur]];
  } else {
    mn[cur] = mn[ls[cur]], mncnt[cur] = mncnt[ls[cur]] + mncnt[rs[cur]];
  }
}
void build(int L, int R, int &cur) {
  cur = ++ttot;
  mncnt[cur] = app[L] ? 1 : 0;
  if (L == R) return;
  int mid = (L + R) >> 1;
  build(L, mid, ls[cur]), build(mid + 1, R, rs[cur]);
}
int tag[2001000];
inline void pusht(int cur, int v) {
  tag[cur] += v;
  mn[cur] += v;
}
inline void pushdown(int cur) {
  if (tag[cur])
    pusht(ls[cur], tag[cur]), pusht(rs[cur], tag[cur]), tag[cur] = 0;
}
void add(int L, int R, int l, int r, int v, int cur) {
  if (l <= L && R <= r) return pusht(cur, v), void();
  int mid = (L + R) >> 1;
  pushdown(cur);
  if (l <= mid) add(L, mid, l, r, v, ls[cur]);
  if (r > mid) add(mid + 1, R, l, r, v, rs[cur]);
  pushup(cur);
}
inline void add(int l, int r, int v) {
  if (1 <= l && r <= up)
    add(1, up, l, r, v, root);
  else
    puts("QAQ"), printf("l = %d, r = %d, v = %d\n", l, r, v);
}
void del_app(int L, int R, int p, int cur) {
  if (L == R) return mncnt[cur] = 0, void();
  int mid = (L + R) >> 1;
  pushdown(cur);
  if (p <= mid)
    del_app(L, mid, p, ls[cur]);
  else
    del_app(mid + 1, R, p, rs[cur]);
  pushup(cur);
}
inline void del_app(int p) { del_app(1, up, p, root); }
void ins_app(int L, int R, int p, int cur) {
  if (L == R) return mncnt[cur] = 1, void();
  int mid = (L + R) >> 1;
  pushdown(cur);
  if (p <= mid)
    ins_app(L, mid, p, ls[cur]);
  else
    ins_app(mid + 1, R, p, rs[cur]);
  pushup(cur);
}
inline void ins_app(int p) { ins_app(1, up, p, root); }
inline void calc_pair(int p) {
  if (p >= n) return;
  int mn = min(a[p], a[p + 1]), mx = max(a[p], a[p + 1]);
  add(mn, mx - 1, 1);
}
inline void erase_pair(int p) {
  if (p >= n) return;
  int mn = min(a[p], a[p + 1]), mx = max(a[p], a[p + 1]);
  add(mn, mx - 1, -1);
}
int main() {
  read(n);
  read(q);
  for (int i = 1; i <= n; ++i) read(a[i]), app[a[i]] = true;
  build(1, up, root);
  a[0] = inf;
  for (int i = 0; i < n; ++i) calc_pair(i);
  while (q--) {
    int p, v;
    read(p), read(v);
    erase_pair(p - 1), erase_pair(p);
    int y = a[p];
    a[p] = v;
    calc_pair(p - 1), calc_pair(p);
    del_app(y);
    ins_app(v);
    if (mn[root] == 1)
      printf("%d\n", mncnt[root]);
    else
      printf("0\n");
  }
  return 0;
}
