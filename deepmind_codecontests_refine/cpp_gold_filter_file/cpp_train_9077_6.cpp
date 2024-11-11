#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
struct T {
  int mn, tag, cnt;
} t[(1000001 + 5) << 2];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
    if (ch == -1) return 0;
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void pushup(int rt) {
  if (t[(rt << 1)].mn == t[(rt << 1 | 1)].mn)
    t[rt].mn = t[(rt << 1)].mn,
    t[rt].cnt = t[(rt << 1)].cnt + t[(rt << 1 | 1)].cnt;
  else if (t[(rt << 1)].mn < t[(rt << 1 | 1)].mn)
    t[rt].mn = t[(rt << 1)].mn, t[rt].cnt = t[(rt << 1)].cnt;
  else
    t[rt].mn = t[(rt << 1 | 1)].mn, t[rt].cnt = t[(rt << 1 | 1)].cnt;
}
inline void pushdown(int rt) {
  if (t[rt].tag)
    t[(rt << 1)].tag += t[rt].tag, t[(rt << 1)].mn += t[rt].tag,
        t[(rt << 1 | 1)].tag += t[rt].tag, t[(rt << 1 | 1)].mn += t[rt].tag,
        t[rt].tag = 0;
}
void update(int rt, int l, int r, int x, int v) {
  if (l == r) {
    t[rt].cnt += v;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(rt);
  if (x <= mid)
    update((rt << 1), l, mid, x, v);
  else
    update((rt << 1 | 1), mid + 1, r, x, v);
  pushup(rt);
}
void update(int rt, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) {
    t[rt].mn += v, t[rt].tag += v;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(rt);
  if (L <= mid) update((rt << 1), l, mid, L, R, v);
  if (mid < R) update((rt << 1 | 1), mid + 1, r, L, R, v);
  pushup(rt);
}
int query(int rt, int l, int r, int L, int R) {
  if (L <= l && r <= R) return (t[rt].mn == 1) * t[rt].cnt;
  int mid = (l + r) >> 1, ans = 0;
  pushdown(rt);
  if (L <= mid) ans += query((rt << 1), l, mid, L, R);
  if (mid < R) ans += query((rt << 1 | 1), mid + 1, r, L, R);
  return ans;
}
void update(int l, int r, int v) {
  if (l == r) return;
  if (l > r) swap(l, r);
  update(1, 0, 1000001, l, r - 1, v);
}
int main() {
  n = read(), m = read(), a[0] = 1000001;
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 0; i <= n; i++)
    update(a[i], a[i + 1], 1), update(1, 0, 1000001, a[i], 1);
  while (m--) {
    int x, k;
    x = read(), k = read();
    update(a[x - 1], a[x], -1), update(a[x], a[x + 1], -1),
        update(1, 0, 1000001, a[x], -1), a[x] = k;
    update(a[x - 1], a[x], 1), update(a[x], a[x + 1], 1),
        update(1, 0, 1000001, a[x], 1),
        printf("%d\n", query(1, 0, 1000001, 1, 1000001 - 1));
  }
  return 0;
}
