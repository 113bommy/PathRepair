#include <bits/stdc++.h>
struct Node {
  long long s;
  int l, r;
  int L, R;
} node[(400010)];
int a[(400010)];
inline int empty(int x, int l, int r) { return node[x].l == r - l + 1; }
inline void pullup(Node &f, Node &x, Node &y, int l, int m, int r) {
  int empl = x.l == m - l + 1, empr = y.l == r - m;
  if (a[m] <= a[m + 1]) {
    if (empl) {
      f.l = m - l + 1 + y.l;
    } else {
      f.l = x.l;
    }
    if (empr) {
      f.r = r - m + y.r;
    } else {
      f.r = y.r;
    }
    f.s = x.s + y.s - 1ll * x.r * (x.r - 1) / 2 - 1ll * y.l * (y.l - 1) / 2 +
          1ll * (x.r + y.l) * (x.r + y.l - 1) / 2;
  } else {
    f.l = x.l;
    f.r = y.r;
    f.s = x.s + y.s;
  }
}
void build(int a[], int x, int l, int r) {
  if (l == r) {
    node[x].l = node[x].r = 1;
    node[x].s = 1;
  } else {
    int m = l + r >> 1;
    build(a, x << 1, l, m);
    build(a, x << 1 | 1, m + 1, r);
    pullup(node[x], node[x << 1], node[x << 1 | 1], l, m, r);
  }
  node[x].L = l, node[x].R = r;
}
int L, R;
int cnt;
Node *li[100];
void query(int x, int l, int r) {
  if (l >= L && r <= R) {
    li[cnt++] = node + x;
  } else {
    int m = l + r >> 1, cnt = 0;
    if (L <= m) {
      query(x << 1, l, m);
    }
    if (R > m) {
      query(x << 1 | 1, m + 1, r);
    }
  }
}
void modify(int x, int l, int r) {
  if (l != r) {
    int m = l + r >> 1;
    if (L <= m) {
      modify(x << 1, l, m);
    } else {
      modify(x << 1 | 1, m + 1, r);
    }
    pullup(node[x], node[x << 1], node[x << 1 | 1], l, m, r);
  }
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  build(a, 1, 1, n);
  while (q--) {
    int op;
    scanf("%d%d%d", &op, &L, &R);
    if (op == 1) {
      a[L] = R;
      int lb = L >= 2 ? L - 1 : 1, rb = L < n ? L + 1 : n;
      for (L = lb; L <= rb; ++L) modify(1, 1, n);
    } else {
      cnt = 0;
      query(1, 1, n);
      Node ans = *li[0];
      for (int i = 1; i < cnt; ++i) {
        Node temp = ans;
        pullup(ans, temp, *li[i], li[i - 1]->L, li[i - 1]->R, li[i]->R);
      }
      printf("%lld\n", ans.s);
    }
  }
}
