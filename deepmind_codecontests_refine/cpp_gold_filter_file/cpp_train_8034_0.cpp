#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int p[10];
struct T {
  int mn[2];
} t[N << 2][10], zero = {1000000000, 1000000000};
T operator+(T a, T b) {
  if (b.mn[0] < a.mn[0]) swap(b.mn[0], a.mn[0]);
  if (b.mn[0] < a.mn[1]) swap(b.mn[0], a.mn[1]);
  if (b.mn[1] < a.mn[0]) swap(b.mn[1], a.mn[0]);
  if (b.mn[1] < a.mn[1]) swap(b.mn[1], a.mn[1]);
  return a;
}
void build(int st, int en, int rt) {
  for (int i = 0; i < 10; i++) {
    t[rt][i] = zero;
  }
  if (st == en) {
    for (int i = 0; i < 10; i++) {
      if (a[st] / p[i] % 10) {
        t[rt][i].mn[0] = a[st];
      }
    }
    return;
  }
  int md = (st + en) >> 1;
  build(st, md, rt << 1);
  build(md + 1, en, rt << 1 | 1);
  for (int i = 0; i < 10; i++) {
    t[rt][i] = t[rt << 1][i] + t[rt << 1 | 1][i];
  }
}
void modify(int pos, int val, int st, int en, int rt) {
  if (st == en) {
    for (int i = 0; i < 10; i++) {
      if (val / p[i] % 10)
        t[rt][i] = {val, 1000000000};
      else
        t[rt][i] = {1000000000, 1000000000};
    }
    return;
  }
  int md = (st + en) >> 1;
  if (pos <= md)
    modify(pos, val, st, md, rt << 1);
  else
    modify(pos, val, md + 1, en, rt << 1 | 1);
  for (int i = 0; i < 10; i++) {
    t[rt][i] = t[rt << 1][i] + t[rt << 1 | 1][i];
  }
}
T query(int l, int r, int st, int en, int rt, int type) {
  if (l <= st && en <= r) return t[rt][type];
  int md = (st + en) >> 1;
  if (l <= md) {
    if (r > md)
      return query(l, r, st, md, rt << 1, type) +
             query(l, r, md + 1, en, rt << 1 | 1, type);
    else
      return query(l, r, st, md, rt << 1, type);
  } else
    return query(l, r, md + 1, en, rt << 1 | 1, type);
}
int main(void) {
  p[0] = 1;
  for (int i = 1; i < 10; i++) {
    p[i] = p[i - 1] * 10;
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  build(1, n, 1);
  int opt, l, r;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &opt, &l, &r);
    if (opt == 1) {
      modify(l, r, 1, n, 1);
    } else {
      int ans = 2e9;
      for (int i = 0; i < 10; i++) {
        T ret = query(l, r, 1, n, 1, i);
        if (ret.mn[1] != 1e9) ans = min(ret.mn[0] + ret.mn[1], ans);
      }
      if (ans == 2e9) ans = -1;
      printf("%d\n", ans);
    }
  }
}
