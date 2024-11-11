#include <bits/stdc++.h>
using namespace std;
int n, Q, opt, l, r, x, a[200005], b[200005], c[200005];
struct Node {
  int b[32];
} d[200005 * 4];
inline void insert(int k, int x) {
  for (int i = 31; ~i; i--) {
    if (x & (1 << i)) {
      if (d[k].b[i])
        x ^= d[k].b[i];
      else {
        d[k].b[i] = x;
        break;
      }
    }
  }
}
inline void pushup(int k) {
  for (int i = 0; i <= 31; i++) d[k].b[i] = d[k * 2].b[i];
  for (int i = 31; ~i; i--)
    if (d[k * 2 + 1].b[i]) insert(k, d[k * 2 + 1].b[i]);
}
void build(int k, int l, int r) {
  if (l == r) {
    insert(k, b[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(k * 2, l, mid);
  build(k * 2 + 1, mid + 1, r);
  pushup(k);
}
void update(int k, int l, int r, int x, int y) {
  if (l == r) {
    b[l] ^= y;
    for (int i = 0; i <= 31; i++) d[k].b[i] = 0;
    insert(k, b[l]);
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update(k * 2, l, mid, x, y);
  else
    update(k * 2 + 1, mid + 1, r, x, y);
  pushup(k);
}
inline void merge(int x, int y) {
  for (int i = 31; ~i; i--)
    if (d[y].b[i]) insert(x, d[y].b[i]);
}
void sum(int k, int l, int r, int x, int y) {
  if (x <= l && y >= r) {
    merge(0, k);
    return;
  }
  int mid = (l + r) >> 1;
  if (y <= mid)
    sum(k * 2, l, mid, x, y);
  else if (x > mid)
    sum(k * 2 + 1, mid + 1, r, x, y);
  else
    sum(k * 2, l, mid, x, mid), sum(k * 2 + 1, mid + 1, r, mid + 1, y);
}
inline int lowbit(int x) { return x & -x; }
inline void add(int x, int y) {
  for (int i = x; i <= n; i += lowbit(i)) c[i] ^= y;
}
inline int getsum(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i)) ans ^= c[i];
  return ans;
}
int main() {
  scanf("%d%d", &n, &Q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) b[i] = a[i] ^ a[i + 1];
  if (n > 1) build(1, 1, n - 1);
  while (Q--) {
    scanf("%d%d%d", &opt, &l, &r);
    if (opt == 1) {
      scanf("%d", &x);
      add(l, x);
      if (r < n) add(r + 1, x);
      if (l > 1) update(1, 1, n, l - 1, x);
      if (r < n) update(1, 1, n, r, x);
    } else {
      for (int i = 0; i <= 31; i++) d[0].b[i] = 0;
      if (l < r) sum(1, 1, n - 1, l, r - 1);
      int tmp = getsum(l) ^ a[l], tot = 0;
      insert(0, tmp);
      for (int i = 0; i <= 31; i++)
        if (d[0].b[i]) tot++;
      printf("%d\n", 1 << tot);
    }
  }
  return 0;
}
