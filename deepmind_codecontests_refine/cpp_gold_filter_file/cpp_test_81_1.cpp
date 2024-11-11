#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (ch != 45 && (ch > '9' || ch < '0')) ch = getchar();
  if (ch == 45) {
    f = -1, ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
void cmin(int &a, int b) { a = min(a, b); }
void cmax(int &a, int b) { a = max(a, b); }
const int N = 1000005;
int i, j, k, n, s, t, m, d;
int b[N];
struct people {
  int s, a;
  friend bool operator<(people a, people b) {
    if (max(a.s, a.a) != max(b.s, b.a)) return max(a.s, a.a) < max(b.s, b.a);
    return a.s < b.s;
  }
} p[N];
struct segmentTree {
  int a[N << 2], lazy[N << 2];
  void push_up(int rt) { a[rt] = max(a[rt << 1], a[rt << 1 | 1]); }
  void push_down(int rt) {
    if (lazy[rt] == 0) return;
    lazy[rt << 1] += lazy[rt], lazy[rt << 1 | 1] += lazy[rt];
    a[rt << 1] += lazy[rt], a[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
  }
  void updata(int l, int r, int rt, int x, int y, int op, int c) {
    if (x <= l && y >= r) {
      if (op == 1)
        cmax(a[rt], c);
      else
        a[rt]++, lazy[rt]++;
      return;
    }
    push_down(rt);
    int mid = (l + r) / 2;
    if (x <= mid) updata(l, mid, rt << 1, x, y, op, c);
    if (y > mid) updata(mid + 1, r, rt << 1 | 1, x, y, op, c);
    push_up(rt);
  }
  int quert(int l, int r, int rt, int x, int y) {
    if (x <= l && y >= r) return a[rt];
    int ret = -1000000000, mid = (r + l) / 2;
    push_down(rt);
    if (x <= mid) cmax(ret, quert(l, mid, rt << 1, x, y));
    if (y > mid) cmax(ret, quert(mid + 1, r, rt << 1 | 1, x, y));
    return ret;
  }
} T;
signed main() {
  memset(T.a, 191, sizeof(T.a));
  read(n), read(d);
  b[n * 2 + 1] = d;
  for (i = 1; i <= n; i++) {
    read(p[i].s), read(p[i].a);
    b[i] = p[i].s, b[i + n] = p[i].a;
  }
  sort(p + 1, p + n + 1);
  sort(b + 1, b + 2 * n + 2);
  m = unique(b + 1, b + 2 * n + 2) - b - 1;
  d = lower_bound(b + 1, b + m + 1, d) - b;
  for (i = 1; i <= n; i++) {
    p[i].a = lower_bound(b + 1, b + m + 1, p[i].a) - b;
    p[i].s = lower_bound(b + 1, b + m + 1, p[i].s) - b;
  }
  T.updata(1, m, 1, d, d, 1, 0);
  for (i = 1; i <= n; i++) {
    if (p[i].s > p[i].a) {
      int ans = T.quert(1, m, 1, 1, p[i].a) + 1;
      T.updata(1, m, 1, p[i].a, p[i].a, 1, ans);
      T.updata(1, m, 1, p[i].a + 1, p[i].s, 0, 1);
    } else {
      int ans = T.quert(1, m, 1, 1, p[i].s) + 1;
      T.updata(1, m, 1, p[i].a, p[i].a, 1, ans);
    }
  }
  cout << T.a[1];
  return 0;
}
