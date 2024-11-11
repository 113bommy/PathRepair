#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
struct Segment1 {
  int tag[1000005 * 4], L[1000005 * 4], R[1000005 * 4], v[1000005 * 4];
  void build(int l, int r, int k) {
    L[k] = l;
    R[k] = r;
    if (l == r) {
      v[k] = l;
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2 + 1);
    v[k] = max(v[k * 2], v[k * 2 + 1]);
  }
  void pushdown(int k) {
    v[k * 2] += tag[k];
    v[k * 2 + 1] += tag[k];
    tag[k * 2] += tag[k];
    tag[k * 2 + 1] += tag[k];
    tag[k] = 0;
  }
  void modify(int l, int r, int k, int x, int y, int val) {
    if (l >= x && r <= y) {
      v[k] += val;
      tag[k] += val;
      return;
    }
    int mid = (l + r) >> 1;
    pushdown(k);
    if (x <= mid) modify(l, mid, k * 2, x, y, val);
    if (y > mid) modify(mid + 1, r, k * 2 + 1, x, y, val);
    v[k] = max(v[k * 2], v[k * 2 + 1]);
  }
  int query(int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    pushdown(k);
    if (v[k * 2] >= 0) return query(l, mid, k * 2);
    return query(mid + 1, r, k * 2 + 1);
  }
} S;
struct Segment2 {
  int tag[1000005 * 4], L[1000005 * 4], R[1000005 * 4], v[1000005 * 4];
  void build(int l, int r, int k) {
    L[k] = l;
    R[k] = r;
    if (l == r) {
      v[k] = l;
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2 + 1);
    v[k] = min(v[k * 2], v[k * 2 + 1]);
  }
  void pushdown(int k) {
    v[k * 2] += tag[k];
    v[k * 2 + 1] += tag[k];
    tag[k * 2] += tag[k];
    tag[k * 2 + 1] += tag[k];
    tag[k] = 0;
  }
  void modify(int l, int r, int k, int x, int y, int val) {
    if (l >= x && r <= y) {
      v[k] += val;
      tag[k] += val;
      return;
    }
    int mid = (l + r) >> 1;
    pushdown(k);
    if (x <= mid) modify(l, mid, k * 2, x, y, val);
    if (y > mid) modify(mid + 1, r, k * 2 + 1, x, y, val);
    v[k] = min(v[k * 2], v[k * 2 + 1]);
  }
  int query(int l, int r, int k, int x, int y) {
    if (l >= x && r <= y) return v[k];
    int mid = (l + r) >> 1, res = 0x3f3f3f3f;
    pushdown(k);
    if (x <= mid) res = min(res, query(l, mid, k * 2, x, y));
    if (y > mid) res = min(res, query(mid + 1, r, k * 2 + 1, x, y));
    return res;
  }
} T;
int n;
int main() {
  S.build(-500005, 0, 1);
  T.build(-500005, 500005, 1);
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    if (x < 0) S.modify(-500005, 0, 1, x, 0, 1);
    T.modify(-500005, 500005, 1, -500005, x - 1, 1);
    int pos = S.query(-500005, 0, 1);
    printf("%d\n", T.query(-500005, 500005, 1, pos, 500005));
  }
  return 0;
}
