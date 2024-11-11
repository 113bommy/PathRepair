#include <bits/stdc++.h>
using namespace std;
struct data {
  int lt, rt, ans, len;
  data() { lt = rt = ans = 0; }
};
struct segment_tree {
  int l, r;
  data p;
} t[2000606];
char c[50005];
int getans(int num) {
  if (num == 0) return 0;
  return num - 1;
}
data operator+(const data &a, const data &b) {
  data c;
  c.len = a.len + b.len;
  c.lt = a.lt + (a.lt == a.len) * b.lt;
  c.rt = b.rt + (b.rt == b.len) * a.rt;
  c.ans = a.ans + b.ans - getans(a.rt) - getans(b.lt) + getans(a.rt + b.lt);
  return c;
}
void build(int now, int l, int r) {
  t[now].l = l, t[now].r = r;
  if (l == r) {
    t[now].p.ans = 0;
    t[now].p.lt = t[now].p.rt = (c[l] == '.');
    t[now].p.len = 1;
    return;
  }
  build((now << 1), l, ((t[now].l + t[now].r) >> 1));
  build((now << 1 | 1), ((t[now].l + t[now].r) >> 1) + 1, r);
  t[now].p = t[(now << 1)].p + t[(now << 1 | 1)].p;
}
char aa[10];
void change(int now, int pos, char x) {
  if (pos == t[now].l && pos == t[now].r) {
    if (x == '.')
      t[now].p.lt = t[now].p.rt = 1;
    else
      t[now].p.lt = t[now].p.rt = 0;
    return;
  }
  if (pos <= ((t[now].l + t[now].r) >> 1))
    change((now << 1), pos, x);
  else
    change((now << 1 | 1), pos, x);
  t[now].p = t[(now << 1)].p + t[(now << 1 | 1)].p;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  scanf("%s", c + 1);
  build(1, 1, n);
  while (m--) {
    int x;
    scanf("%d%s", &x, aa);
    change(1, x, aa[0]);
    printf("%d\n", t[1].p.ans);
  }
}
