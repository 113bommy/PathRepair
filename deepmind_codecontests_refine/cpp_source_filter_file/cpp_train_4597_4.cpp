#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-7;
const int NEGATIVE = 0;
const int POSITIVE = 1;
const int SAME = -1;
const int INVERTED = -2;
int invert(int x) {
  switch (x) {
    case NEGATIVE:
      return POSITIVE;
    case POSITIVE:
      return NEGATIVE;
    case SAME:
      return INVERTED;
    case INVERTED:
      return SAME;
  }
  throw;
}
struct SegmentTree {
  int ds;
  int* a;
  int getds(int n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
  }
  SegmentTree(int n) : ds(getds(n)), a(new int[2 * ds]) {
    for (int i = 0; i < 2 * ds; i++) a[i] = SAME;
  }
  void fix(int l, int r, int val) { fix(1, 0, ds - 1, l, r, val); }
  void fix(int cur, int cl, int cr, int l, int r, int val) {
    if (l <= cl && cr <= r) {
      if (val == INVERTED)
        a[cur] = invert(a[cur]);
      else
        a[cur] = val;
    } else if (r < cl || cr < l) {
    } else {
      push(cur);
      int mid = (cl + cr) / 2;
      fix(2 * cur, cl, mid, l, r, val);
      fix(2 * cur + 1, mid + 1, cr, l, r, val);
    }
  }
  int get(int x) {
    x += ds;
    int res = SAME;
    while (x) {
      if (a[x] != SAME) {
        if (a[x] == INVERTED)
          res = invert(res);
        else
          res = a[x];
      }
      x >>= 1;
    }
    return res;
  }
  void push(int cur) {
    if (a[cur] != SAME) {
      if (a[cur] == INVERTED) {
        a[2 * cur] = invert(a[2 * cur]);
        a[2 * cur + 1] = invert(a[2 * cur]);
      } else {
        a[2 * cur] = a[cur];
        a[2 * cur + 1] = a[cur];
      }
      a[cur] = SAME;
    }
  }
};
const int MAXN = 100000;
int a[MAXN];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  SegmentTree tree(MAXN + 1);
  while (q--) {
    char s[10];
    int x;
    scanf("%s%d", s, &x);
    if (s[0] == '>') {
      if (x >= -1) {
        int lo = x + 1;
        int hi = MAXN;
        tree.fix(lo, hi, NEGATIVE);
      } else {
        int lo = 0;
        int mid = abs(x);
        int hi = MAXN;
        tree.fix(lo, mid + 1, INVERTED);
        tree.fix(mid, hi, NEGATIVE);
      }
    } else {
      if (x <= 1) {
        int lo = abs(x - 1);
        int hi = MAXN;
        tree.fix(lo, hi, POSITIVE);
      } else {
        int lo = 0;
        int mid = abs(x);
        int hi = MAXN;
        tree.fix(lo, mid - 1, INVERTED);
        tree.fix(mid, hi, POSITIVE);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int type = tree.get(abs(a[i]));
    int res = 0;
    switch (type) {
      case SAME:
        res = a[i];
        break;
      case INVERTED:
        res = -a[i];
        break;
      case NEGATIVE:
        res = -abs(a[i]);
        break;
      case POSITIVE:
        res = abs(a[i]);
        break;
    }
    printf("%d ", res);
  }
  puts("");
  return 0;
}
