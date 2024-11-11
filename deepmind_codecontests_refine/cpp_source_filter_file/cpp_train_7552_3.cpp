#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int mod = 1000000007;
int a[maxn];
struct mat {
  int a[2][2];
  mat() { memset(a, 0, sizeof(a)); }
  void init() {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) a[i][j] = (i == j);
  }
  mat operator+(const mat &b) const {
    mat c;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) c.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
    return c;
  }
  mat operator*(const mat &b) const {
    mat c;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        c.a[i][j] =
            (1LL * a[i][0] * b.a[0][j] + 1LL * a[i][1] * b.a[1][j]) % mod;
    return c;
  }
  mat operator^(const int &t) const {
    mat base = (*this);
    mat c;
    c.init();
    int p = t;
    while (p) {
      if (p & 1) c = c * base;
      base = base * base;
      p >>= 1;
    }
    return c;
  }
};
mat f, s[maxn << 2], lz[maxn << 2];
int le[maxn << 2], ri[maxn << 2];
void Pushup(int n) { s[n] = s[n << 1] + s[n << 1 | 1]; }
void Pushdown(int n) {
  s[n << 1] = lz[n] * s[n << 1];
  s[n << 1 | 1] = lz[n] * s[n << 1 | 1];
  lz[n << 1] = lz[n] * lz[n << 1];
  lz[n << 1 | 1] = lz[n] * lz[n << 1 | 1];
  lz[n].init();
}
void build(int i, int l, int r) {
  lz[i].init();
  le[i] = l;
  ri[i] = r;
  if (l == r) {
    s[i] = f ^ (a[l] - 1);
    return;
  }
  int mid = (l + r) >> 1;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
  Pushup(i);
}
void update(int i, int l, int r, mat v) {
  if (l == le[i] && r == ri[i]) {
    s[i] = v * s[i];
    lz[i] = v * lz[i];
    return;
  }
  Pushdown(i);
  int mid = (le[i] + ri[i]) >> 1;
  if (l > mid)
    update(i << 1 | 1, l, r, v);
  else if (r <= mid)
    update(i << 1, l, r, v);
  else {
    update(i << 1, l, mid, v);
    update(i << 1 | 1, mid + 1, r, v);
  }
  Pushup(i);
}
int query(int i, int l, int r) {
  if (l == le[i] && r == ri[i]) {
    return s[i].a[0][0];
  }
  Pushdown(i);
  int mid = (le[i] + ri[i]) >> 1;
  if (l > mid)
    return query(i << 1 | 1, l, r);
  else if (r <= mid)
    return query(i << 1, l, r);
  else
    return (query(i << 1, l, mid) + query(i << 1 | 1, mid + 1, r)) % mod;
}
void init() {
  f.a[0][0] = 1;
  f.a[0][1] = 1;
  f.a[1][0] = 1;
  f.a[1][1] = 0;
}
int main() {
  init();
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int tp, l, r;
    scanf("%d%d%d", &tp, &l, &r);
    if (tp == 1) {
      int x;
      scanf("%d", &x);
      update(1, 1, n, f ^ x);
    } else
      printf("%d\n", query(1, l, r));
  }
}
