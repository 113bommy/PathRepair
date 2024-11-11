#include <bits/stdc++.h>
const int mod = 1000000007;
struct M {
  int a[2][2];
};
inline int mul(int a, int b) { return (long long)a * b % mod; }
M mm[32];
M mul(M a, M b) {
  M c;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      c.a[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        c.a[i][j] += mul(a.a[i][k], b.a[k][j]);
        if (c.a[i][j] >= mod) c.a[i][j] -= mod;
      }
    }
  }
  return c;
}
M eye;
M pow(int k) {
  M res = eye;
  for (int i = 0; i < 31; i++) {
    if (k >> i & 1) {
      res = mul(res, mm[i]);
    }
  }
  return res;
}
const int N = 1 << 3;
int b[N + N][2];
M lazy[N + N];
void upd(int ii, M &mt) {
  int c[2] = {};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      c[i] += mul(mt.a[i][j], b[ii][j]);
      if (c[i] >= mod) c[i] -= mod;
    }
  }
  b[ii][0] = c[0];
  b[ii][1] = c[1];
}
void push(int i) {
  M mt = lazy[i];
  upd(i, mt);
  lazy[i] = eye;
  if (i >= N) return;
  lazy[i + i] = mul(lazy[i + i], mt);
  lazy[i + i + 1] = mul(lazy[i + i + 1], mt);
}
void pullup(int i) {
  for (int j = 0; j < 2; j++) {
    b[i][j] = b[i + i][j] + b[i + i + 1][j];
    if (b[i][j] >= mod) {
      b[i][j] -= mod;
    }
  }
}
void go(int l, int r, int L, int R, int p, M mt) {
  push(p);
  if (r <= L || R <= l) return;
  if (l <= L && R <= r) {
    lazy[p] = mt;
    push(p);
    return;
  }
  int mid = (L + R) / 2;
  go(l, r, L, mid, p + p, mt);
  go(l, r, mid, R, p + p + 1, mt);
  pullup(p);
}
int query(int l, int r, int L, int R, int p) {
  push(p);
  if (r <= L || R <= l) return 0;
  if (l <= L && R <= r) {
    return b[p][1];
  }
  int mid = (L + R) / 2;
  int res = query(l, r, L, mid, p + p) + query(l, r, mid, R, p + p + 1);
  if (res >= mod) res -= mod;
  return res;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  eye.a[0][0] = eye.a[1][1] = 1;
  eye.a[0][1] = eye.a[1][0] = 0;
  M a;
  a.a[0][0] = a.a[0][1] = a.a[1][0] = 1;
  a.a[1][1] = 0;
  mm[0] = a;
  for (int i = 1; i < 32; i++) {
    mm[i] = mul(mm[i - 1], mm[i - 1]);
  }
  for (int i = 0; i < N + N; i++) {
    lazy[i] = eye;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    M mt = pow(x);
    b[N + i][0] = mt.a[0][0];
    b[N + i][1] = mt.a[1][0];
  }
  for (int i = N - 1; i > 0; i--) {
    pullup(i);
  }
  while (m--) {
    int t, l, r, x;
    scanf("%d%d%d", &t, &l, &r);
    --l;
    if (t == 1) {
      scanf("%d", &x);
      go(l, r, 0, N, 1, pow(x));
    } else {
      printf("%d\n", query(l, r, 0, N, 1));
    }
  }
  return 0;
}
