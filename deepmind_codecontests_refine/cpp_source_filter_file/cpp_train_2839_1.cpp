#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, q, l, r;
long long sum, w1, w2, x, a1[N], b1[N], c1[N], delb[N], delc[N], tree[N * 4];
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
inline void new1(int p, long long f) { tree[p] += f; }
inline void pushdown(int p) {
  if (tree[p]) {
    new1(p << 1, tree[p]);
    new1(p << 1 | 1, tree[p]);
    tree[p] = 0;
  }
}
long long query(int p, int pa, int pb, int x) {
  if (pa == pb) return tree[p];
  pushdown(p);
  int mid = (pa + pb) >> 1;
  if (x <= mid)
    return query(p << 1, pa, mid, x);
  else
    return query(p << 1 | 1, mid + 1, pb, x);
}
void add(int p, int pa, int pb, int a, int b, long long x) {
  if (a <= pa && pb <= b) {
    new1(p, x);
    return;
  }
  int mid = (pa + pb) >> 1;
  if (a <= mid) add(p << 1, pa, mid, a, b, x);
  if (mid < b) add(p << 1 | 1, mid + 1, pb, a, b, x);
}
void build(int p, int a, int b) {
  if (a == b) {
    tree[p] = a1[a];
    return;
  }
  tree[p] = 0;
  int mid = (a + b) >> 1;
  build(p << 1, a, mid);
  build(p << 1 | 1, mid + 1, b);
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a1[i] = 1ll * read();
  build(1, 1, n);
  b1[1] = a1[1], c1[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (a1[i] > a1[i - 1])
      c1[i] = c1[i - 1], b1[i] = a1[i] - c1[i];
    else
      b1[i] = b1[i - 1], c1[i] = a1[i] - b1[i];
  }
  for (int i = 2; i <= n; ++i)
    delb[i] = b1[i] - b1[i - 1], delc[i] = c1[i - 1] - c1[i];
  q = read(), sum = b1[n] + c1[1];
  if (sum >= 0)
    printf("%lld\n", (sum + 1) / 2);
  else
    printf("%lld\n", sum / 2);
  for (int i = 1; i <= q; ++i) {
    l = read(), r = read(), x = 1ll * read();
    if (l != 1) {
      w1 = query(1, 1, n, l - 1);
      w2 = query(1, 1, n, l);
      if (w2 > w1) {
        if (w2 + x <= w1)
          sum -= delb[l], delc[l] = -delb[l] - x, delb[l] = 0;
        else
          sum += x, delb[l] += x;
      } else {
        if (w2 + x > w1)
          sum += x - delc[l], delb[l] = x - delc[l], delc[l] = 0;
        else
          delc[l] -= x;
      }
    } else
      sum += x;
    if (r != n) {
      w1 = query(1, 1, n, r);
      w2 = query(1, 1, n, r + 1);
      if (w2 > w1) {
        if (w2 <= w1 + x)
          sum -= delb[r + 1], delc[r + 1] = x - delb[r + 1], delb[r + 1] = 0;
        else
          sum -= x, delb[r + 1] -= x;
      } else {
        if (w2 > w1 + x)
          sum -= x - delc[r + 1], delb[r + 1] = -delc[r + 1] - x,
                                           delc[r + 1] = 0;
        else
          delc[r + 1] += x;
      }
    }
    add(1, 1, n, l, r, x);
    if (sum >= 0)
      printf("%lld\n", (sum + 1) / 2);
    else
      printf("%lld\n", sum / 2);
  }
  return 0;
}
