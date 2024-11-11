#include <bits/stdc++.h>
using namespace std;
const int N = 200004 * 4 + 11;
long long k[N], add[N];
int a[200004];
int n, m;
int x, y;
long long z;
long long ans;
int build(int l, int r, int o) {
  add[o] = 0;
  if (l == r) return k[o] = a[l];
  int mid = ((l + r) >> 1);
  return k[o] = build(l, mid, (o << 1)) + build(mid + 1, r, ((o << 1) | 1));
}
void pushdown(int l, int r, int o) {
  add[(o << 1)] += add[o];
  add[((o << 1) | 1)] += add[o];
  add[o] = 0;
}
void maintain(int l, int r, int o) {
  int mid = ((l + r) >> 1);
  if (r > l)
    k[o] = k[(o << 1)] + add[(o << 1)] * (mid - l + 1) + k[((o << 1) | 1)] +
           add[((o << 1) | 1)] * (r - mid);
  else
    k[o] = a[l];
}
void update(int l, int r, int o) {
  if (x <= l && r <= y) {
    add[o] += z;
  } else {
    pushdown(l, r, o);
    int mid = ((l + r) >> 1);
    if (x <= mid)
      update(l, mid, (o << 1));
    else
      maintain(l, mid, (o << 1));
    if (y > mid)
      update(mid + 1, r, ((o << 1) | 1));
    else
      maintain(mid + 1, r, ((o << 1) | 1));
  }
  maintain(l, r, o);
}
void query(int l, int r, int o) {
  if (x <= l && r <= y)
    ans += k[o] + add[o] * (r - l + 1);
  else {
    pushdown(l, r, o);
    int mid = ((l + r) >> 1);
    if (x <= mid) query(l, mid, (o << 1));
    if (y > mid) query(mid + 1, r, ((o << 1) | 1));
  }
  maintain(l, r, o);
}
int main() {
  long long lst = 0.0;
  while (~scanf("%d", &n)) {
    int i, c, e, f;
    int d;
    int tot = 1;
    int tp = 0;
    build(1, 200004, 1);
    while (n--) {
      scanf("%d", &c);
      if (c == 1) {
        scanf("%d%d", &e, &d);
        z = d;
        x = 1;
        y = min(e, tot);
        update(1, 200004, 1);
        lst += e * d;
      } else if (c == 2) {
        scanf("%d", &d);
        tot++;
        x = y = tot;
        z = d;
        update(1, 200004, 1);
        lst += d;
      } else {
        ans = 0;
        x = y = tot;
        query(1, 200004, 1);
        z = -ans;
        update(1, 200004, 1);
        tot--;
        lst += z;
      }
      ans = 0;
      x = 1;
      y = tot;
      query(1, n, 1);
      printf("%.9lf\n", ans * 1.0 / tot);
    }
  }
  return 0;
}
