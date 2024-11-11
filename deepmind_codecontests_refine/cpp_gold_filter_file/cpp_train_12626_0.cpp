#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 10;
int n, m;
long long a[mx], t[mx << 2], sum[mx << 2], tag[mx << 2];
void build(int rt, int l, int r) {
  if (l == r) {
    t[rt] = a[r];
    sum[rt] = a[r];
    return;
  }
  int mid = l + r >> 1;
  build(rt << 1, l, mid), build(rt << 1 | 1, mid + 1, r);
  t[rt] = t[rt << 1 | 1];
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown(int rt, int l, int r, int mid) {
  if (tag[rt]) {
    t[rt << 1] = t[rt << 1 | 1] = t[rt];
    sum[rt << 1] = t[rt] * (mid - l + 1);
    sum[rt << 1 | 1] = t[rt] * (r - mid);
    tag[rt << 1] = tag[rt << 1 | 1] = 1;
    tag[rt] = 0;
  }
}
void updata(int rt, int l, int r, int nl, int nr, long long c) {
  if (nl <= l && r <= nr) {
    t[rt] = c;
    sum[rt] = c * (r - l + 1);
    tag[rt] = 1;
    return;
  }
  int mid = l + r >> 1;
  pushdown(rt, l, r, mid);
  if (nl <= mid) updata(rt << 1, l, mid, nl, nr, c);
  if (nr > mid) updata(rt << 1 | 1, mid + 1, r, nl, nr, c);
  t[rt] = t[rt << 1 | 1];
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
int query(int rt, int l, int r, long long c, long long x) {
  if (l == r) {
    if (x <= r && c >= t[rt])
      return r;
    else
      return r + 1;
  }
  int mid = l + r >> 1;
  pushdown(rt, l, r, mid);
  if (x <= mid && c >= t[rt << 1])
    return query(rt << 1, l, mid, c, x);
  else
    return query(rt << 1 | 1, mid + 1, r, c, x);
}
long long ask(int rt, int l, int r, int nl, int nr) {
  if (nl <= l & r <= nr) {
    return sum[rt];
  }
  long long ans = 0;
  int mid = l + r >> 1;
  pushdown(rt, l, r, mid);
  if (nl <= mid) ans += ask(rt << 1, l, mid, nl, nr);
  if (nr > mid) ans += ask(rt << 1 | 1, mid + 1, r, nl, nr);
  return ans;
}
int ss(int rt, int l, int r, long long c, long long now) {
  if (l == r) {
    if (c >= sum[rt] - now)
      return r;
    else
      return r - 1;
  }
  int mid = l + r >> 1;
  pushdown(rt, l, r, mid);
  if (c >= sum[rt << 1] - now) {
    now -= sum[rt << 1];
    return ss(rt << 1 | 1, mid + 1, r, c, now);
  } else
    return ss(rt << 1, l, mid, c, now);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  build(1, 1, n);
  long long op, x, y;
  while (m--) {
    scanf("%lld%lld%lld", &op, &x, &y);
    if (op == 1) {
      int p = query(1, 1, n, y, -1);
      if (p <= x) updata(1, 1, n, p, x, y);
    } else {
      long long ans = 0;
      while (y && x <= n) {
        long long p = query(1, 1, n, y, x);
        if (p > n) break;
        long long now = 0;
        if (p > 1) now = ask(1, 1, n, 1, p - 1);
        long long q = ss(1, 1, n, y, now);
        if (p <= q) {
          y -= ask(1, 1, n, p, q);
          ans += q - p + 1;
          x = q + 1;
        } else
          break;
      }
      printf("%lld\n", ans);
    }
  }
}
