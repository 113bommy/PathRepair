#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int n, m, p;
int len[MAXN << 2], tag[MAXN << 2];
struct Node {
  int x[5], y[5], t;
  void output() {
    printf("%d", t);
    for (int i = 0; i < t; ++i) {
      printf(" %d", x[i]);
    }
    printf("\n");
  }
} seg[MAXN << 2];
Node operator+(Node a, Node b) {
  Node c = a;
  for (int i = 0; i < b.t; ++i) {
    bool mer = 0;
    for (int j = 0; j < c.t; ++j) {
      if (b.x[i] == c.x[j]) {
        c.y[j] += b.y[i];
        mer = 1;
        break;
      }
    }
    if (mer) continue;
    if (c.t < p) {
      c.x[c.t] = b.x[i];
      c.y[c.t++] = b.y[i];
    } else {
      int k = 0;
      for (int j = 1; j < c.t; ++j) {
        if (c.y[j] < c.y[k]) k = j;
      }
      int del = b.y[i];
      if (b.y[i] > c.y[k]) {
        del = c.y[k];
        c.x[k] = b.x[i];
        c.y[k] = b.y[i];
      }
      for (int j = 0; j < c.t; ++j) {
        c.y[j] -= del;
      }
    }
  }
  return c;
}
inline void puttag(int rt, int tg) {
  tag[rt] = tg;
  seg[rt].x[0] = tg;
  seg[rt].y[0] = len[rt];
  seg[rt].t = 1;
}
inline void pushdown(int rt) {
  if (tag[rt]) {
    puttag((rt << 1), tag[rt]);
    puttag((rt << 1) | 1, tag[rt]);
    tag[rt] = 0;
  }
}
void Build(int rt, int b, int e) {
  len[rt] = e - b + 1;
  if (b == e) {
    int x;
    read(x);
    puttag(rt, x);
    return;
  }
  int mid = (b + e) >> 1;
  Build((rt << 1), b, mid);
  Build((rt << 1) | 1, mid + 1, e);
  seg[rt] = seg[(rt << 1)] + seg[(rt << 1) | 1];
}
void Update(int rt, int b, int e, int l, int r, int v) {
  if (l <= b && e <= r) {
    puttag(rt, v);
    return;
  }
  int mid = (b + e) >> 1;
  pushdown(rt);
  if (l <= mid) Update((rt << 1), b, mid, l, r, v);
  if (r > mid) Update((rt << 1) | 1, mid + 1, e, l, r, v);
  seg[rt] = seg[(rt << 1)] + seg[(rt << 1) | 1];
}
Node Query(int rt, int b, int e, int l, int r) {
  if (l <= b && e <= r) return seg[rt];
  int mid = (b + e) >> 1;
  pushdown(rt);
  if (r <= mid) return Query((rt << 1), b, mid, l, r);
  if (l > mid) return Query((rt << 1) | 1, mid + 1, e, l, r);
  return Query((rt << 1), b, mid, l, r) +
         Query((rt << 1) | 1, mid + 1, e, l, r);
}
void init() {
  read(n);
  read(m);
  read(p);
  p = 100 / p;
  Build(1, 1, n);
}
void solve() {
  int op, l, r, v;
  while (m--) {
    read(op);
    read(l);
    read(r);
    if (op == 1) {
      read(v);
      Update(1, 1, n, l, r, v);
    } else {
      Query(1, 1, n, l, r).output();
    }
  }
}
int main() {
  init();
  solve();
  return 0;
}
