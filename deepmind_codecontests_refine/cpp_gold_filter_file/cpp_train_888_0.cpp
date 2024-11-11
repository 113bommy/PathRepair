#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  register char c = getchar();
  x = 0;
  for (; c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - '0';
}
inline void write(int x) {
  char c[10], *p = c;
  do {
    *p++ = '0' + x % 10;
    x /= 10;
  } while (x);
  do {
    putchar(*--p);
  } while (p > c);
  putchar('\n');
}
struct node {
  int a, b, c, d;
  node() : a(0), b(0), c(0), d(0) {}
  node(long long a, long long b, long long c, long long d)
      : a(a), b(b), c(c), d(d) {}
};
node segTree[400008], L[400008];
node id(1, 0, 0, 1), M(1, 1, 1, 0);
int lazy[400008];
inline node operator+(const node &a, const node &b) {
  return node(1LL * (a.a + b.a) % 1000000007, 1LL * (a.b + b.b) % 1000000007,
              1LL * (a.c + b.c) % 1000000007, 1LL * (a.d + b.d) % 1000000007);
}
inline node operator*(const node &a, const node &b) {
  int u = 1LL * (1LL * a.a * b.a + 1LL * a.b * b.c) % 1000000007;
  int v = 1LL * (1LL * a.a * b.b + 1LL * a.b * b.d) % 1000000007;
  int w = 1LL * (1LL * a.c * b.a + 1LL * a.d * b.c) % 1000000007;
  int x = 1LL * (1LL * a.c * b.b + 1LL * a.d * b.d) % 1000000007;
  return node(u, v, w, x);
}
inline node matPower(node x, long long n) {
  node res = node(1, 0, 0, 1);
  while (n > 0) {
    if (n & 1) res = res * x;
    x = x * x;
    n >>= 1;
  }
  return res;
}
inline void buildTree(int v, int s, int e) {
  if (s == e) {
    int x;
    read(x);
    segTree[v] = matPower(M, x);
    L[v] = id;
    return;
  }
  int m = (s + e) / 2;
  buildTree(2 * v, s, m);
  buildTree(2 * v + 1, m + 1, e);
  segTree[v] = segTree[2 * v] + segTree[2 * v + 1];
  L[v] = id;
}
inline void applyLazy(int v) {
  node M;
  segTree[v] = segTree[v] * L[v];
  return;
}
inline void propogate(int v, int l, int r) {
  if (lazy[v] > 0) {
    applyLazy(v);
    if (l != r) {
      lazy[2 * v] = lazy[2 * v + 1] = 1;
      L[2 * v] = L[2 * v] * L[v];
      L[2 * v + 1] = L[2 * v + 1] * L[v];
    }
    lazy[v] = 0;
    L[v] = id;
  }
  return;
}
inline void update(int v, int tl, int tr, int l, int r, node x) {
  propogate(v, tl, tr);
  if (l > r) return;
  if (tl == l && tr == r) {
    lazy[v] = 1;
    L[v] = L[v] * x;
    propogate(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  update(2 * v, tl, tm, l, min(tm, r), x);
  update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, x);
  segTree[v] = segTree[2 * v] + segTree[2 * v + 1];
}
inline node query(int v, int tl, int tr, int l, int r) {
  propogate(v, tl, tr);
  if (l > r) return node(0, 0, 0, 0);
  if (tl == l && tr == r) return segTree[v];
  int tm = (tl + tr) / 2;
  node left = query(2 * v, tl, tm, l, min(tm, r));
  node right = query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
  return (left + right);
}
int main() {
  int n, m, q, l, r, x;
  read(n);
  read(m);
  buildTree(1, 0, n - 1);
  while (m--) {
    read(q);
    read(l);
    read(r);
    if (q == 1) {
      read(x);
      node val = matPower(M, x);
      update(1, 0, n - 1, l - 1, r - 1, val);
    } else {
      write(query(1, 0, n - 1, l - 1, r - 1).b);
    }
  }
  return 0;
}
