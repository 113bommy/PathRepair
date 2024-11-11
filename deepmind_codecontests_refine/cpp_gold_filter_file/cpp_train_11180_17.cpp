#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000000;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 201000;
struct node {
  long long fib[4];
  int fg;
} nd[N * 4];
int fib[N], a[N];
int n, ty, l, r, v, m;
long long ret[2], ans;
void build(int p, int l, int r) {
  if (l == r) {
    nd[p].fib[0] = fib[l];
    nd[p].fib[1] = fib[l + 1];
    nd[p].fib[2] = nd[p].fib[0] * a[l] % mod;
    nd[p].fib[3] = nd[p].fib[1] * a[l] % mod;
  } else {
    int md = (l + r) >> 1;
    build(p + p, l, md);
    build(p + p + 1, md + 1, r);
    for (int i = 0; i < 4; i++)
      nd[p].fib[i] = (nd[p + p].fib[i] + nd[p + p + 1].fib[i]) % mod;
  }
}
void setp(int p, int w) {
  nd[p].fg += w;
  nd[p].fib[2] = (nd[p].fib[2] + nd[p].fib[0] * w) % mod;
  nd[p].fib[3] = (nd[p].fib[3] + nd[p].fib[1] * w) % mod;
}
void push(int p) {
  if (nd[p].fg) {
    setp(p + p, nd[p].fg);
    setp(p + p + 1, nd[p].fg);
    nd[p].fg = 0;
  }
}
void modify(int p, int l, int r, int x, long long w) {
  if (l == r) {
    nd[p].fib[2] = fib[l] * w % mod;
    nd[p].fib[3] = fib[l + 1] * w % mod;
  } else {
    push(p);
    int md = (l + r) >> 1;
    if (x <= md)
      modify(p + p, l, md, x, w);
    else
      modify(p + p + 1, md + 1, r, x, w);
    for (int i = 2; i < 4; i++)
      nd[p].fib[i] = (nd[p + p].fib[i] + nd[p + p + 1].fib[i]) % mod;
  }
}
void add(int p, int l, int r, int tl, int tr, int w) {
  if (l == tl && r == tr)
    setp(p, w);
  else {
    push(p);
    int md = (l + r) >> 1;
    if (tr <= md)
      add(p + p, l, md, tl, tr, w);
    else if (tl > md)
      add(p + p + 1, md + 1, r, tl, tr, w);
    else
      add(p + p, l, md, tl, md, w), add(p + p + 1, md + 1, r, md + 1, tr, w);
    for (int i = 2; i < 4; i++)
      nd[p].fib[i] = (nd[p + p].fib[i] + nd[p + p + 1].fib[i]) % mod;
  }
}
void query(int p, int l, int r, int tl, int tr) {
  if (l == tl && r == tr) {
    for (int i = 2; i < 4; i++) ret[i - 2] = (ret[i - 2] + nd[p].fib[i]) % mod;
  } else {
    push(p);
    int md = (l + r) >> 1;
    if (tr <= md)
      query(p + p, l, md, tl, tr);
    else if (tl > md)
      query(p + p + 1, md + 1, r, tl, tr);
    else
      query(p + p, l, md, tl, md), query(p + p + 1, md + 1, r, md + 1, tr);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n + 1; i++) scanf("%d", a + i);
  fib[0] = fib[1] = 1;
  for (int i = 2; i < n + 10; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
  build(1, 1, n);
  for (int i = 0; i < m; i++) {
    scanf("%d", &ty);
    if (ty == 1) {
      scanf("%d%d", &l, &v);
      modify(1, 1, n, l, v);
    } else if (ty == 2) {
      scanf("%d%d", &l, &r);
      ret[0] = ret[1] = 0;
      query(1, 1, n, l, r);
      ans = (fib[l] * ret[0] - fib[l - 1] * ret[1]) % mod;
      if (l % 2 == 1) ans *= -1;
      if (ans < 0) ans += mod;
      printf("%I64d\n", ans);
    } else {
      scanf("%d%d%d", &l, &r, &v);
      add(1, 1, n, l, r, v);
    }
  }
}
