#include <bits/stdc++.h>
using namespace std;
struct Node {
  int st, ed;
  long long p, s1, s0;
  Node *l, *r;
  Node() {}
  Node(int a, int b, int c, int d, Node *e, Node *f) {
    st = a, ed = b, p = 0, s0 = c, s1 = d, l = e, r = f;
  }
} * root;
const int p = 1e9;
int n, m;
long long f[200005], sumf[200005], a[200005];
void init() {
  f[0] = f[1] = 1;
  for (int i = 2; i <= n + 1; ++i) f[i] = (f[i - 1] + f[i - 2]) % p;
  sumf[0] = 1;
  for (int i = 1; i <= n + 1; ++i) sumf[i] = (sumf[i - 1] + f[i]) % p;
}
int get(Node *x, int y) {
  if (y == 1) return x->s0 % p;
  if (y == 2) return x->s1 % p;
  return (x->s0 * f[y - 3] % p + x->s1 * f[y - 2] % p) % p;
}
void update(Node *x) {
  int mid = (x->st + x->ed) >> 1;
  int len = (mid - x->st + 1);
  x->s0 = (x->l->s0 + get(x->r, len + 1)) % p;
  x->s1 = (x->l->s1 + get(x->r, len + 2)) % p;
}
Node *build(int l, int r) {
  if (l == r) return new Node(l, l, a[l], a[l], 0, 0);
  int mid = (l + r) >> 1;
  Node *ret = new Node(l, r, 0, 0, build(l, mid), build(mid + 1, r));
  update(ret);
  return ret;
}
void down(Node *x) {
  if (x->p) {
    (x->l->s0 += (x->p * sumf[x->l->ed - x->l->st])) %= p;
    (x->l->s1 += (x->p * sumf[x->l->ed - x->l->st + 1] - 1)) %= p;
    (x->r->s0 += (x->p * sumf[x->r->ed - x->r->st])) %= p;
    (x->r->s1 += (x->p * sumf[x->r->ed - x->r->st + 1] - 1)) %= p;
    (x->l->p += x->p) %= p;
    (x->r->p += x->p) %= p;
    x->p = 0;
  }
}
void change(Node *x, int st, int ed, int v) {
  if (x->st >= st && x->ed <= ed) {
    (x->s0 += (1ll * v * sumf[x->ed - x->st])) %= p;
    (x->s1 += (1ll * v * (sumf[x->ed - x->st + 1] - 1))) %= p;
    (x->p += v) %= p;
    return;
  }
  down(x);
  int mid = (x->st + x->ed) >> 1;
  if (mid >= st) change(x->l, st, ed, v);
  if (mid < ed) change(x->r, st, ed, v);
  update(x);
}
long long query(Node *x, int st, int ed) {
  if (x->st >= st && x->ed <= ed) return get(x, x->st - st + 1);
  down(x);
  long long ret = 0;
  int mid = (x->st + x->ed) >> 1;
  if (st <= mid) (ret += query(x->l, st, ed)) %= p;
  if (mid < ed) (ret += query(x->r, st, ed)) %= p;
  return ret;
}
void modify(Node *x, int aim, int v) {
  if (x->st == x->ed) {
    x->s0 = x->s1 = v;
    return;
  }
  down(x);
  int mid = (x->st + x->ed) >> 1;
  if (mid >= aim)
    modify(x->l, aim, v);
  else
    modify(x->r, aim, v);
  update(x);
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  root = build(1, n);
  for (int i = 1; i <= m; ++i) {
    int tp, x, y, z;
    scanf("%d%d%d", &tp, &x, &y);
    if (tp == 1)
      modify(root, x, y);
    else if (tp == 2)
      cout << query(root, x, y) << endl;
    else {
      scanf("%d", &z);
      change(root, x, y, z);
    }
  }
  return 0;
}
