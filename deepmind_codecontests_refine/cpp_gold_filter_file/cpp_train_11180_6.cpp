#include <bits/stdc++.h>
using namespace std;
long long p = 1000000000;
namespace fib {
long long ff[200010];
inline void init() {
  ff[0] = 1;
  ff[1] = 1;
  for (int i = 2; i <= 200005; ++i) {
    ff[i] = ff[i - 1] + ff[i - 2];
    if (ff[i] >= p) ff[i] -= p;
  }
}
struct mat {
  long long d[2][2];
};
inline mat operator*(const mat& a, const mat& b) {
  mat c;
  c.d[0][0] = c.d[0][1] = c.d[1][0] = c.d[1][1] = 0;
  c.d[0][0] = (a.d[0][0] * b.d[0][0] + a.d[0][1] * b.d[0][1]) % p;
  c.d[0][1] = (a.d[0][0] * b.d[0][1] + a.d[0][1] * b.d[1][1]) % p;
  c.d[1][0] = (a.d[1][0] * b.d[0][0] + a.d[1][1] * b.d[1][0]) % p;
  c.d[1][1] = (a.d[1][0] * b.d[0][1] + a.d[1][1] * b.d[1][1]) % p;
  return c;
}
inline long long calc(long long f0, long long f1, long long n) {
  if (n == 0) return f0;
  if (n == 1) return f1;
  return (ff[n - 2] * f0 + ff[n - 1] * f1) % p;
}
}  // namespace fib
long long a[200010];
int n, q;
struct node {
  inline node(int a, int b) : l(a), r(b) {
    ch[0] = ch[1] = 0;
    add = 0;
  }
  node* ch[2];
  int l, r;
  long long f0, f1, add;
} * rt;
inline void down(node* x) {
  if (x->add) {
    int t = x->r - x->l + 1;
    x->f0 = x->f0 + x->add * (fib::calc(1, 1, t + 1) - 1 + p) % p;
    if (x->f0 >= p) x->f0 -= p;
    x->f1 = x->f1 + x->add * (fib::calc(1, 1, t + 2) - 2 + p) % p;
    if (x->f1 >= p) x->f1 -= p;
    for (int i = 0; i <= 1; ++i)
      if (x->ch[i]) {
        x->ch[i]->add = x->ch[i]->add + x->add;
        if (x->ch[i]->add >= p) x->ch[i]->add -= p;
      }
    x->add = 0;
  }
}
inline void update(node* x) {
  for (int i = 0; i <= 1; ++i) down(x->ch[i]);
  int t1 = x->ch[0]->r - x->ch[0]->l + 1;
  x->f0 = x->ch[0]->f0 + fib::calc(x->ch[1]->f0, x->ch[1]->f1, t1);
  if (x->f0 >= p) x->f0 -= p;
  x->f1 = x->ch[0]->f1 + fib::calc(x->ch[1]->f0, x->ch[1]->f1, t1 + 1);
  if (x->f1 >= p) x->f1 -= p;
}
inline node* build(int l, int r) {
  node* ret = new node(l, r);
  if (l == r) {
    ret->f0 = ret->f1 = a[l];
  } else {
    int m = (l + r) / 2;
    ret->ch[0] = build(l, m);
    ret->ch[1] = build(m + 1, r);
    update(ret);
  }
  return ret;
}
inline node query(node* x, int l, int r) {
  down(x);
  if (l == x->l && r == x->r)
    return *x;
  else {
    int m = x->ch[0]->r;
    if (r <= m)
      return query(x->ch[0], l, r);
    else if (l > m)
      return query(x->ch[1], l, r);
    else {
      node t1 = query(x->ch[0], l, m);
      node t2 = query(x->ch[1], m + 1, r);
      node t3(l, r);
      t3.ch[0] = &t1;
      t3.ch[1] = &t2;
      update(&t3);
      return t3;
    }
  }
}
inline void modify(node* x, int p, int v) {
  down(x);
  if (x->l == x->r) {
    x->f0 = x->f1 = v;
  } else {
    int m = x->ch[0]->r;
    if (p <= m)
      modify(x->ch[0], p, v);
    else
      modify(x->ch[1], p, v);
    update(x);
  }
}
inline void addnum(node* x, int l, int r, int d) {
  down(x);
  if (l <= x->l && r >= x->r) {
    x->add = x->add + d;
    if (x->add >= p) x->add -= p;
  } else {
    int m = x->ch[0]->r;
    if (l <= m) addnum(x->ch[0], l, r, d);
    if (r > m) addnum(x->ch[1], l, r, d);
    update(x);
  }
}
int main() {
  fib::init();
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  rt = build(1, n);
  for (int i = 1; i <= q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, v;
      scanf("%d%d", &x, &v);
      modify(rt, x, v);
    } else if (t == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", (int)query(rt, l, r).f0);
    } else {
      int l, r, d;
      scanf("%d%d%d", &l, &r, &d);
      addnum(rt, l, r, d);
    }
  }
  return 0;
}
