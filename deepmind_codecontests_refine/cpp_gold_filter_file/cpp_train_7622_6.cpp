#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const int M = 6e5 + 10;
const int MOD = 1e9 + 7;
struct Node {
  int v, l, r, c;
  Node(int _v = 0, int _l = 0, int _r = 0, int _c = 0) {
    v = _v;
    l = _l;
    r = _r;
    c = _c;
  }
} t[M << 2];
int a[N], p[N], x[N], w[M], f[N], g[N], n, m, q;
void pushup(int k) {
  int lk = k << 1, rk = k << 1 | 1;
  t[k].v =
      (t[lk].v + t[rk].v + 1LL * t[lk].l * t[rk].r % MOD * g[t[lk].c]) % MOD;
  t[k].l = (t[lk].l + 1LL * t[rk].l * f[t[lk].c]) % MOD;
  t[k].r = (t[lk].r + 1LL * t[rk].r * g[t[lk].c]) % MOD;
  t[k].c = t[lk].c + t[rk].c;
}
void update(int p, int c, int k, int l, int r) {
  if (p < l || p > r) return;
  if (l == r) {
    if (c) {
      t[k].c++;
      t[k].v = (t[k].v + 1LL * t[k].l * w[l] % MOD * g[t[k].c]) % MOD;
      t[k].l = (t[k].l + 1LL * w[l] * f[t[k].c - 1]) % MOD;
      t[k].r = (t[k].r + 1LL * w[l] * g[t[k].c]) % MOD;
    } else {
      t[k].l = (t[k].l - 1LL * w[l] * f[t[k].c - 1] % MOD + MOD) % MOD;
      t[k].r = (t[k].r - 1LL * w[l] * g[t[k].c] % MOD + MOD) % MOD;
      t[k].v =
          (t[k].v - 1LL * t[k].l * w[l] % MOD * g[t[k].c] % MOD + MOD) % MOD;
      t[k].c--;
    }
    return;
  }
  int lk = k << 1, rk = k << 1 | 1, mid = (l + r) >> 1;
  update(p, c, lk, l, mid);
  update(p, c, rk, mid + 1, r);
  pushup(k);
}
int fpow(int x, int p) {
  int rs = 1;
  while (p) {
    if (p & 1) rs = 1LL * rs * x % MOD;
    x = 1LL * x * x % MOD;
    p >>= 1;
  }
  return rs;
}
int main() {
  scanf("%d", &n);
  m = 0;
  f[0] = g[0] = 1;
  f[1] = 2;
  g[1] = fpow(2, MOD - 2);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i - 1] * 2 % MOD;
    g[i] = 1LL * g[i - 1] * g[1] % MOD;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    w[++m] = a[i];
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d %d", &p[i], &x[i]);
    w[++m] = x[i];
  }
  sort(w + 1, w + 1 + m);
  m = unique(w + 1, w + 1 + m) - w - 1;
  for (int i = 1; i <= n; ++i) a[i] = lower_bound(w + 1, w + 1 + m, a[i]) - w;
  for (int i = 1; i <= q; ++i) x[i] = lower_bound(w + 1, w + 1 + m, x[i]) - w;
  for (int i = 1; i <= n; ++i) update(a[i], 1, 1, 1, m);
  printf("%d\n", t[1].v);
  for (int i = 1; i <= q; ++i) {
    update(a[p[i]], 0, 1, 1, m);
    update(x[i], 1, 1, 1, m);
    a[p[i]] = x[i];
    printf("%d\n", t[1].v);
  }
}
