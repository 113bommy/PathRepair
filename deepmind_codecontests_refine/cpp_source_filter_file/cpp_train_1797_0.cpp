#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 19 | 10), size = 1 << 20, mod = 998244353;
template <class o>
void qr(o &x) {
  char c = getchar();
  x = 0;
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= f;
}
template <class o>
void qw(o x) {
  if (x / 10) qw(x / 10);
  putchar(x % 10 + '0');
}
template <class o>
void pr1(o x) {
  if (x < 0) x = -x, putchar('-');
  qw(x);
  putchar(' ');
}
template <class o>
void pr2(o x) {
  if (x < 0) x = -x, putchar('-');
  qw(x);
  puts("");
}
int n, m;
char s[N];
struct node {
  int len[2][2], rev, ans, s;
} e, tr[N * 2][2], t;
node operator*(node a, node b) {
  if (!a.ans) return b;
  node c = a;
  c.s += b.s;
  c.len[1][0] = b.len[1][0];
  c.len[1][1] = b.len[1][1];
  c.rev = 0;
  c.ans = max(c.ans, b.ans);
  int l, r;
  if (!a.len[0][1] && !a.len[1][1])
    l = 1;
  else if (a.len[0][1] && !a.len[1][1])
    l = 2;
  else if (a.len[1][0] && a.len[1][1])
    l = 3;
  else
    l = 4;
  if (!b.len[0][1] && !b.len[1][1])
    r = 1;
  else if (!b.len[0][0] && b.len[1][0])
    r = 2;
  else if (b.len[0][0] && b.len[0][1])
    r = 3;
  else
    r = 4;
  if (l == 1) {
    switch (r) {
      case 1:
        c.len[0][0] = c.len[1][0] = a.len[0][0] + b.len[0][0];
        break;
      case 2:
        c.len[0][1] = b.len[0][1];
        break;
      case 3:
        c.len[0][0] += b.len[0][0];
        c.len[0][1] = b.len[0][1];
        if (b.len[0][0] + b.len[0][1] == b.s)
          c.len[1][0] = c.len[0][0], c.len[1][1] = c.len[0][1];
        break;
      case 4:
        c.len[0][1] = b.len[0][1];
        c.len[1][0] = c.len[0][0];
        c.len[1][1] = c.len[0][1];
        break;
    }
  } else if (l == 2) {
    switch (r) {
      case 1:
        c.len[1][0] += a.len[1][0];
        break;
      case 2:
        c.ans = max(c.ans, a.len[1][0] + b.len[0][1]);
        break;
      case 3:
        c.ans = max(c.ans, a.len[1][0] + b.len[0][0] + b.len[0][1]);
        if (b.len[0][0] + b.len[0][1] == b.s) c.len[1][0] += b.len[0][0];
        break;
      case 4:
        c.len[1][0] = a.len[1][0];
        break;
    }
  } else if (l == 3) {
    switch (r) {
      case 1:
        break;
      case 2:
        c.ans = max(c.ans, a.len[1][0] + a.len[1][1] + b.len[0][1]);
        if (a.len[1][0] + a.len[1][1] == a.s) c.len[0][1] += b.len[0][1];
        break;
      case 3:
        break;
      case 4:
        c.len[1][0] = a.len[1][0];
        c.len[1][1] += b.len[0][1];
        if (a.len[1][0] + a.len[1][1] == a.s)
          c.len[0][0] = c.len[1][0], c.len[0][1] = c.len[1][1];
        break;
    }
  } else {
    switch (r) {
      case 1:
        break;
      case 2:
        c.len[0][1] += b.len[0][1];
        break;
      case 3:
        break;
      case 4:
        c.len[1][1] = (c.len[0][1] += b.len[0][1]);
        break;
    }
  }
  c.ans = max(c.ans, max(c.len[0][0] + c.len[0][1], c.len[1][0] + c.len[1][1]));
  return c;
}
void bt(int x, int l, int r) {
  node &a = tr[x][1], &b = tr[x][0];
  if (l == r) {
    int c = s[l];
    a.len[0][c] = a.len[1][c] = 1;
    a.len[0][c ^ 1] = a.len[1][c ^ 1] = 0;
    a.rev = 0;
    a.ans = a.s = 1;
    b.len[0][c ^ 1] = b.len[1][c ^ 1] = 1;
    b.len[0][c] = b.len[1][c] = 0;
    b.rev = 0;
    b.ans = b.s = 1;
    return;
  }
  int mid = (l + r) / 2;
  bt((x << 1), l, mid);
  bt((x << 1 | 1), mid + 1, r);
  a = tr[(x << 1)][1] * tr[(x << 1 | 1)][1];
  b = tr[(x << 1)][0] * tr[(x << 1 | 1)][0];
}
void fz(int x) {
  swap(tr[x][0], tr[x][1]);
  tr[x][0].rev ^= 1;
  tr[x][1].rev ^= 1;
}
void change(int x, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    fz(x);
    t = t * tr[x][1];
    return;
  }
  if (tr[x][1].rev)
    fz((x << 1)), fz((x << 1 | 1)), tr[x][1].rev ^= 1, tr[x][0].rev ^= 1;
  int mid = (l + r) / 2;
  if (L <= mid) change((x << 1), l, mid, L, R);
  if (mid < R) change((x << 1 | 1), mid + 1, r, L, R);
  tr[x][1] = tr[(x << 1)][1] * tr[(x << 1 | 1)][1];
  tr[x][0] = tr[(x << 1)][0] * tr[(x << 1 | 1)][0];
}
int main() {
  qr(n);
  qr(m);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) s[i] = (s[i] != '>');
  bt(1, 1, n);
  while (m--) {
    int l, r;
    qr(l);
    qr(r);
    t = e;
    change(1, 1, n, l, r);
    pr2(t.ans);
  }
  return 0;
}
