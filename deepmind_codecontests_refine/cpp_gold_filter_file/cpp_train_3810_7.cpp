#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
int min[200010][24];
int n;
int rmq(int l, int r) {
  l = (l - 1) % n + 1;
  r = (r - 1) % n + 1;
  int lg = log2(r - l + 1);
  return std::min(min[l][lg], min[r - (1 << lg) + 1][lg]);
}
struct SEG_Tree {
  int min[5000000];
  int lc[5000000];
  int rc[5000000];
  int lazy[5000000];
  int cnt = 0;
  void push_up(int cur) { min[cur] = std::min(min[lc[cur]], min[rc[cur]]); }
  void modify(int &cur, int ql, int qr, int l, int r, int c, int fa) {
    if (cur == 0) {
      cur = ++cnt;
      lc[cur] = rc[cur] = 0;
      if ((qr - 1) / n == (ql - 1) / n)
        min[cur] = rmq(ql, qr);
      else if ((qr - 1) / n == (ql - 1) / n + 1)
        min[cur] = std::min(rmq(ql, n), rmq(1, qr));
      else
        min[cur] = rmq(1, n);
    }
    if (lazy[fa]) min[cur] = lazy[cur] = lazy[fa];
    if (ql > r || qr < l) return;
    if (ql >= l && qr <= r) {
      min[cur] = c;
      lazy[cur] = c;
      return;
    }
    int mid = (ql + qr) >> 1;
    modify(lc[cur], ql, mid, l, r, c, cur);
    modify(rc[cur], mid + 1, qr, l, r, c, cur);
    lazy[cur] = 0;
    push_up(cur);
  }
  int query(int &cur, int ql, int qr, int l, int r, int fa) {
    if (cur == 0) {
      cur = ++cnt;
      lc[cur] = rc[cur] = 0;
      if ((qr - 1) / n == (ql - 1) / n)
        min[cur] = rmq(ql, qr);
      else if ((qr - 1) / n == (ql - 1) / n + 1)
        min[cur] = std::min(rmq(ql, n), rmq(1, qr));
      else
        min[cur] = rmq(1, n);
    }
    if (lazy[fa]) min[cur] = lazy[cur] = lazy[fa];
    if (ql > r || qr < l) return 2147483647;
    if (ql >= l && qr <= r) return min[cur];
    int mid = (ql + qr) >> 1;
    return std::min(query(lc[cur], ql, mid, l, r, cur),
                    query(rc[cur], mid + 1, qr, l, r, cur));
  }
} t;
int main() {
  t.min[0] = 2147483647;
  n = inp();
  int k = inp();
  int len = n * k;
  for (int i = 1; i <= n; i++) min[i][0] = inp();
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++)
      if (i + (1 << j) - 1 <= n)
        min[i][j] = std::min(min[i][j - 1], min[i + (1 << (j - 1))][j - 1]);
  int m = inp();
  int root = 0;
  while (m--) {
    int op = inp();
    if (op == 1) {
      int l = inp();
      int r = inp();
      int c = inp();
      t.modify(root, 1, len, l, r, c, 0);
    } else {
      int l = inp();
      int r = inp();
      printf("%d\n", t.query(root, 1, len, l, r, 0));
    }
  }
}
