#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0, ff = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (isdigit(ch)) sum = sum * 10 + (ch ^ 48), ch = getchar();
  return sum * ff;
}
const int N = 4e5 + 7;
int n, m;
char s[N];
struct tree {
  int l, r, sum, lmax, rmax, lmin, rmin, max1, max2, ans;
} t[N * 4];
int max(int x, int y) {
  if (x > y) return x;
  return y;
}
int min(int x, int y) {
  if (x < y) return x;
  return y;
}
int ls(int x) { return x << 1; }
int rs(int x) { return x << 1 | 1; }
void push_up(int root) {
  t[root].sum = t[ls(root)].sum + t[rs(root)].sum;
  t[root].lmax = max(t[ls(root)].lmax, t[ls(root)].sum + t[rs(root)].lmax);
  t[root].lmin = min(t[ls(root)].lmin, t[ls(root)].sum + t[rs(root)].lmin);
  t[root].rmax = max(t[rs(root)].rmax, t[rs(root)].sum + t[ls(root)].rmax);
  t[root].rmin = min(t[rs(root)].rmin, t[rs(root)].sum + t[ls(root)].rmin);
  t[root].max1 =
      max(t[ls(root)].max1, max(-t[ls(root)].sum + t[rs(root)].max1,
                                t[rs(root)].lmax + t[ls(root)].rmax -
                                    (t[ls(root)].sum - t[ls(root)].rmax)));
  t[root].max2 =
      max(t[rs(root)].max2, max(t[rs(root)].sum + t[ls(root)].max2,
                                t[rs(root)].sum - t[rs(root)].lmin -
                                    (t[rs(root)].lmin + t[ls(root)].rmin)));
  t[root].ans = max(max(t[ls(root)].ans, t[rs(root)].ans),
                    max(t[ls(root)].max2 + t[rs(root)].lmax,
                        t[rs(root)].max1 - t[ls(root)].rmin));
  return;
}
void build(int root, int l, int r) {
  t[root].l = l, t[root].r = r;
  if (l == r) {
    if (s[l] == '(')
      t[root].sum = 1, t[root].lmax = t[root].rmax = 1,
      t[root].lmin = t[root].rmin = 0;
    else
      t[root].sum = -1, t[root].lmax = t[root].rmax = 0,
      t[root].lmin = t[root].rmin = -1;
    t[root].ans = t[root].max1 = t[root].max2 = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(ls(root), l, mid);
  build(rs(root), mid + 1, r);
  push_up(root);
  return;
}
void modify(int root, int p, int v) {
  if (p == t[root].l && p == t[root].r) {
    t[root].lmax = t[root].rmax = max(0, v);
    t[root].lmin = t[root].rmin = min(0, v);
    t[root].sum = v;
    t[root].ans = t[root].max1 = t[root].max2 = 1;
    return;
  }
  int mid = (t[root].l + t[root].r) >> 1;
  if (p <= mid)
    modify(ls(root), p, v);
  else
    modify(rs(root), p, v);
  push_up(root);
  return;
}
int main() {
  n = read(), m = read();
  scanf("%s", s + 1);
  n = (n - 1) << 1;
  build(1, 1, n);
  printf("%d\n", t[1].ans);
  while (m--) {
    int x = read(), y = read();
    if (s[x] != s[y]) {
      swap(s[x], s[y]);
      modify(1, x, s[x] == '(' ? 1 : -1);
      modify(1, y, s[y] == '(' ? 1 : -1);
    }
    printf("%d\n", t[1].ans);
  }
  return 0;
}
