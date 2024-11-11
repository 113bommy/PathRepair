#include <bits/stdc++.h>
using namespace std;
static const int M = 100005;
static const int P = 1e9 + 9;
char s[M];
struct segment {
  int B;
  int pw[M];
  int table[M];
  struct node {
    int L, R, sum, lazy;
    void calc(int table[]) { sum = 1LL * lazy * table[R - L + 1] % P; }
  } tree[M << 2];
  void down(int p) {
    if (~tree[p].lazy) {
      tree[p << 1].lazy = tree[p << 1 | 1].lazy = tree[p].lazy;
      tree[p].lazy = -1;
      tree[p << 1].calc(table);
      tree[p << 1 | 1].calc(table);
    }
  }
  void up(int p) {
    tree[p].sum = ((long long)tree[p << 1].sum +
                   (long long)tree[p << 1 | 1].sum *
                       pw[tree[p << 1].R - tree[p << 1].L + 1]) %
                  P;
  }
  void build(int p, int L, int R) {
    tree[p].L = L;
    tree[p].R = R;
    tree[p].lazy = -1;
    if (L == R) {
      tree[p].sum = 1LL * pw[0] * (s[L] - '0') % P;
      return;
    }
    int mid = L + R >> 1;
    build(p << 1, L, mid);
    build(p << 1 | 1, mid + 1, R);
    up(p);
  }
  void update(int p, int L, int R, int c) {
    if (tree[p].L == L && tree[p].R == R) {
      tree[p].lazy = c;
      tree[p].calc(table);
      return;
    }
    down(p);
    int mid = tree[p].L + tree[p].R >> 1;
    if (R <= mid)
      update(p << 1, L, R, c);
    else if (L > mid)
      update(p << 1 | 1, L, R, c);
    else {
      update(p << 1, L, mid, c);
      update(p << 1 | 1, mid + 1, R, c);
    }
    up(p);
  }
  int query(int p, int L, int R) {
    if (tree[p].L == L && tree[p].R == R) return tree[p].sum;
    int mid = tree[p].L + tree[p].R >> 1;
    down(p);
    if (R <= mid)
      return query(p << 1, L, R);
    else if (L > mid)
      return query(p << 1 | 1, L, R);
    else {
      return ((long long)query(p << 1, L, mid) +
              (long long)query(p << 1 | 1, mid + 1, R) * pw[mid - L + 1]) %
             P;
    }
  }
  void init() {
    pw[0] = 1;
    for (int i = 1; i < M; ++i) pw[i] = 1LL * pw[i - 1] * B % P;
    for (int i = 1; i < M; ++i) table[i] = (table[i - 1] + pw[i - 1]) % P;
  }
} ds[2];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  m += k;
  scanf("%s", s + 1);
  ds[0].B = 1000000010;
  ds[1].B = 1000000008;
  for (int i = 0; i < 2; ++i) {
    ds[i].init();
    ds[i].build(1, 1, n);
  }
  while (m--) {
    int k, l, r, d;
    scanf("%d %d %d %d", &k, &l, &r, &d);
    if (k == 1) {
      for (int i = 0; i < 2; ++i) ds[i].update(1, l, r, d);
    } else {
      if (d == r - l + 1)
        puts("YES");
      else if (ds[0].query(1, l, r - d) == ds[0].query(1, l + d, r) &&
               ds[1].query(1, l, r - d) == ds[1].query(1, l + d, r))
        puts("YES");
      else
        puts("NO");
    }
  }
  return 0;
}
