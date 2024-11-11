#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 9;
const int max_n = 3e5 + 5;
int a[max_n];
long long f[max_n];
struct SegmentTree {
  struct Tree {
    int l, r;
    long long sum, a, b;
  } t[max_n << 2];
  long long F(int n, long long A, long long B) {
    if (n == 1) return A % mod;
    if (n == 2) return B % mod;
    return (A * f[n - 2] % mod + B * f[n - 1] % mod) % mod;
  }
  long long calc(int n, long long A, long long B) {
    return (F(n + 2, A, B) - B + mod) % mod;
  }
  void push_up(int rt) {
    t[rt].sum = (t[(rt << 1)].sum + t[(rt << 1 | 1)].sum) % mod;
  }
  void push_down(int rt) {
    if (t[rt].a != 0 || t[rt].b != 0) {
      t[(rt << 1)].a = (t[(rt << 1)].a + t[rt].a) % mod;
      t[(rt << 1)].b = (t[(rt << 1)].b + t[rt].b) % mod;
      t[(rt << 1)].sum =
          (t[(rt << 1)].sum +
           calc(t[(rt << 1)].r - t[(rt << 1)].l + 1, t[rt].a, t[rt].b)) %
          mod;
      t[(rt << 1 | 1)].a =
          (t[(rt << 1 | 1)].a +
           F(t[(rt << 1)].r - t[(rt << 1)].l + 2, t[rt].a, t[rt].b)) %
          mod;
      t[(rt << 1 | 1)].b =
          (t[(rt << 1 | 1)].b +
           F(t[(rt << 1)].r - t[(rt << 1)].l + 3, t[rt].a, t[rt].b)) %
          mod;
      t[(rt << 1 | 1)].sum =
          (t[(rt << 1 | 1)].sum +
           calc(t[(rt << 1 | 1)].r - t[(rt << 1 | 1)].l + 1,
                F(t[(rt << 1)].r - t[(rt << 1)].l + 2, t[rt].a, t[rt].b),
                F(t[(rt << 1)].r - t[(rt << 1)].l + 3, t[rt].a, t[rt].b))) %
          mod;
      t[rt].a = t[rt].b = 0;
    }
  }
  void build(int l, int r, int rt) {
    t[rt].l = l, t[rt].r = r;
    t[rt].a = t[rt].b = 0;
    if (l == r) {
      t[rt].sum = a[l] % mod;
      return;
    }
    int m = (t[rt].l + t[rt].r) / 2;
    build(l, m, (rt << 1));
    build(m + 1, r, (rt << 1 | 1));
    push_up(rt);
  }
  void update(int l, int r, int rt) {
    if (l <= t[rt].l && t[rt].r <= r) {
      t[rt].sum = (t[rt].sum + calc(t[rt].r - t[rt].l + 1, f[t[rt].l - l + 1],
                                    f[t[rt].l - l + 2])) %
                  mod;
      t[rt].a = (t[rt].a + f[t[rt].l - l + 1]) % mod;
      t[rt].b = (t[rt].b + f[t[rt].l - l + 2]) % mod;
      return;
    }
    push_down(rt);
    int m = (t[rt].l + t[rt].r) / 2;
    if (l <= m) update(l, r, (rt << 1));
    if (r > m) update(l, r, (rt << 1 | 1));
    push_up(rt);
  }
  long long query(int l, int r, int rt) {
    if (l <= t[rt].l && t[rt].r <= r) return t[rt].sum;
    push_down(rt);
    int m = (t[rt].l + t[rt].r) / 2;
    long long res = 0;
    if (l <= m) res = (res + query(l, r, (rt << 1))) % mod;
    if (r > m) res = (res + query(l, r, (rt << 1 | 1))) % mod;
    return res;
  }
  void print(int rt) {
    if (t[rt].l == t[rt].r) {
      printf("%lld ", t[rt].sum);
      return;
    }
    push_down(rt);
    int m = (t[rt].l + t[rt].r) / 2;
    print((rt << 1));
    print((rt << 1 | 1));
  }
} T;
void init() {
  f[1] = f[2] = 1;
  for (int i = 3; i <= max_n - 1; i++) f[i] = (f[i - 2] + f[i - 1]) % mod;
}
int main() {
  int n, m;
  init();
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  T.build(1, n, 1);
  while (m--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1)
      T.update(l, r, 1);
    else if (op == 2)
      printf("%lld\n", T.query(l, r, 1));
  }
  return 0;
}
