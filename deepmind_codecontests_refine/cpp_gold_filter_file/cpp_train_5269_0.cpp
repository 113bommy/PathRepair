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
int root[1000010];
struct President_Tree {
  int lc[10000000], rc[10000000];
  long long k[10000000], b[10000000];
  int cnt;
  void push_up(int cur) {
    k[cur] = k[lc[cur]] + k[rc[cur]];
    b[cur] = b[lc[cur]] + b[rc[cur]];
  }
  void insert(int &cur, int last, int x, int kc, int bc, int l, int r) {
    cur = ++cnt;
    if (l == r) {
      k[cur] = k[last] + kc;
      b[cur] = b[last] + bc;
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
      insert(lc[cur], lc[last], x, kc, bc, l, mid);
      rc[cur] = rc[last];
    } else {
      lc[cur] = lc[last];
      insert(rc[cur], rc[last], x, kc, bc, mid + 1, r);
    }
    push_up(cur);
  }
  long long query(int cur, int last, int ql, int qr, long long x, int l,
                  int r) {
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return x * (k[cur] - k[last]) + (b[cur] - b[last]);
    int mid = (l + r) >> 1;
    return query(lc[cur], lc[last], ql, qr, x, l, mid) +
           query(rc[cur], rc[last], ql, qr, x, mid + 1, r);
  }
} t;
int main() {
  int n = inp();
  for (int i = 1; i <= n; i++) {
    int xl = inp();
    int xr = inp();
    int yl = inp();
    int k = inp();
    int b = inp();
    int yr = inp();
    t.insert(root[i], root[i - 1], 0, 0, yl, 0, 1e9);
    t.insert(root[i], root[i], xl + 1, k, b - yl, 0, 1e9);
    t.insert(root[i], root[i], xr + 1, -k, yr - b, 0, 1e9);
  }
  int m = inp();
  long long lastans = 0;
  while (m--) {
    int l = inp();
    int r = inp();
    int x = (inp() + lastans) % 1000000000;
    lastans = t.query(root[r], root[l - 1], 0, x, x, 0, 1e9);
    printf("%lld\n", lastans);
  }
}
