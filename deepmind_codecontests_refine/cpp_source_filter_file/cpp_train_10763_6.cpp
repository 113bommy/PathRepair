#include <bits/stdc++.h>
const long long mod = 1000000000;
class V {
 public:
  long long a[2];
  V(long long a0 = 0, long long a1 = 0) {
    a[0] = a0 % mod;
    a[1] = a1 % mod;
  }
  V operator+(const V &v) { return V(a[0] + v.a[0], a[1] + v.a[1]); }
};
class M {
 public:
  long long a[2][2];
  M(long long a00 = 1, long long a01 = 0, long long a10 = 0,
    long long a11 = 1) {
    a[0][0] = a00 % mod;
    a[0][1] = a01 % mod;
    a[1][0] = a10 % mod;
    a[1][1] = a11 % mod;
  }
  M operator+(const M &m) {
    return M(a[0][0] + m.a[0][0], a[0][1] + m.a[0][1], a[1][0] + m.a[1][0],
             a[1][1] + m.a[1][1]);
  }
  M operator*(const M &m) {
    M r(0, 0, 0, 0);
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) r.a[i][j] += a[i][k] * m.a[k][j];
        r.a[i][j] %= mod;
      }
    return r;
  }
  V operator*(const V &v) {
    return V(a[0][0] * v.a[0] + a[0][1] * v.a[1],
             a[1][0] * v.a[0] + a[1][1] * v.a[1]);
  }
};
const int maxn = 200010;
const int maxit = (1 << 19) + 5;
M pow_m[maxn], sum_m[maxn], m0;
long long it_a[maxit], it_b[maxit];
V it_v[maxit];
V it_vr(int u, int L, int R, int bonus = 0) {
  return it_v[u] + sum_m[R - L + 1] * V(it_b[u] + bonus, it_b[u] + bonus);
}
void it_update(int u, int L, int R, int x, int v) {
  if (x < L || x > R) return;
  if (L == R) {
    it_a[u] = v;
    it_b[u] = 0;
    it_v[u] = V(v, v);
    return;
  }
  it_b[2 * u] += it_b[u];
  it_b[2 * u + 1] += it_b[u];
  it_b[u] = 0;
  int M = (L + R) / 2;
  it_update(2 * u, L, M, x, v);
  it_update(2 * u + 1, M + 1, R, x, v);
  it_v[u] = it_vr(2 * u, L, M) + pow_m[M - L + 1] * it_vr(2 * u + 1, M + 1, R);
}
void it_add(int u, int L, int R, int l, int r, int v) {
  if (r < L || l > R) return;
  if (l <= L && r >= R) {
    it_b[u] += v;
    return;
  }
  int M = (L + R) / 2;
  it_add(2 * u, L, M, l, r, v);
  it_add(2 * u + 1, M + 1, R, l, r, v);
  it_v[u] = it_vr(2 * u, L, M) + pow_m[M - L + 1] * it_vr(2 * u + 1, M + 1, R);
}
V it_get(int u, int L, int R, int l, int r, long long bonus = 0) {
  if (r < L || l > R) return V(0, 0);
  if (l <= L && r >= R) {
    return pow_m[L - l] * it_vr(u, L, R, bonus);
  }
  int M = (L + R) / 2;
  return it_get(2 * u, L, M, l, r, bonus + it_b[u]) +
         it_get(2 * u + 1, M + 1, R, l, r, bonus + it_b[u]);
}
int main() {
  m0 = M(0, 1, 1, 1);
  pow_m[0] = M(1, 0, 0, 1);
  sum_m[0] = M(0, 0, 0, 0);
  for (int i = 0; i + 1 < maxn; i++) {
    pow_m[i + 1] = pow_m[i] * m0;
    sum_m[i + 1] = sum_m[i] + pow_m[i];
  }
  memset(it_b, 0, sizeof(it_b));
  int n, m, x, l, r, a, t;
  assert(scanf("%d%d", &n, &m) == 2);
  for (int i = 0; i < n; i++) {
    assert(scanf("%d", &a) == 1);
    it_update(1, 0, n - 1, i, a);
  }
  for (int i = 0; i < m; i++) {
    assert(scanf("%d", &t) == 1);
    if (t == 1) {
      assert(scanf("%d%d", &x, &a) == 2);
      it_update(1, 0, n - 1, x - 1, a);
    } else if (t == 2) {
      assert(scanf("%d%d", &l, &r) == 2);
      V v = it_get(1, 0, n - 1, l - 1, r - 1);
      printf("%d\n", (int)v.a[0]);
    } else if (t == 3) {
      assert(scanf("%d%d%d", &l, &r, &a) == 3);
      it_add(1, 0, n - 1, l - 1, r - 1, a);
    } else
      assert(t == 1);
  }
  return 0;
}
