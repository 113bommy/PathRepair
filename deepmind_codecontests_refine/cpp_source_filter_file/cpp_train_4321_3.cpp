#include <bits/stdc++.h>
using namespace std;
struct matrixType {
  int r, c;
  long long matrix[2][2];
};
long long k;
int n, m, mod;
long long s[50005];
long long a[50005];
long long v[50005];
int rk[50005];
matrixType qhy;
matrixType e[64];
matrixType st[50005 << 2];
long long f[50005];
matrixType d;
matrixType operator*(matrixType a, matrixType b) {
  int i, j, k;
  d.r = a.r;
  d.c = b.c;
  for (i = 0; i < d.r; i++)
    for (j = 0; j < d.c; j++) {
      d.matrix[i][j] = 0;
      for (k = 0; k < a.c; k++)
        d.matrix[i][j] =
            (d.matrix[i][j] + a.matrix[i][k] * b.matrix[k][j] % mod) % mod;
    }
  return d;
}
bool cmp(int x, int y) { return a[x] < a[y]; }
void build_st(int x, int l, int r) {
  if (l == r) {
    st[x].c = st[x].r = 2;
    st[x].matrix[0][0] = 0;
    st[x].matrix[1][0] = 1;
    st[x].matrix[0][1] = s[l];
    st[x].matrix[1][1] = s[l + 1];
  } else {
    build_st((x << 1), l, ((l + r) >> 1));
    build_st((x << 1 | 1), ((l + r) >> 1) + 1, r);
    st[x] = st[(x << 1)] * st[(x << 1 | 1)];
  }
}
void change_st(int x, int l, int r, int p, int v, bool flag) {
  if (l == r) {
    st[x].matrix[flag][1] = v;
  } else {
    if (p <= ((l + r) >> 1))
      change_st((x << 1), l, ((l + r) >> 1), p, v, flag);
    else
      change_st((x << 1 | 1), ((l + r) >> 1) + 1, r, p, v, flag);
    st[x] = st[(x << 1)] * st[(x << 1 | 1)];
  }
}
void standing_by() {
  int i;
  scanf("%lld%d", &k, &mod);
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%lld", &s[i]);
  s[n] = s[0];
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%lld%lld", &a[i], &v[i]);
    rk[i] = i;
  }
  sort(rk + 1, rk + 1 + m, cmp);
  qhy.r = 1;
  qhy.c = 2;
  qhy.matrix[0][0] = 0;
  qhy.matrix[0][1] = 1;
  build_st(1, 0, n - 1);
  e[0] = st[1];
  for (i = 1; i < 64; i++) e[i] = e[i - 1] * e[i - 1];
}
matrixType qp;
void qpow(long long y) {
  int i;
  for (i = 0; y; y >>= 1, i++)
    if (y & 1) qhy = qhy * e[i];
}
void complete() {
  long long l, r;
  int i, j;
  for (l = 0, i = 1; l < k - k % n; l = r) {
    if (i <= m && a[rk[i]] <= k - k % n) {
      r = a[rk[i]] / n * n;
      if (a[rk[i]] % n == 0) r -= n;
      if (r > l) {
        qpow((r - l) / n);
        l = r;
        r += n;
      } else
        r = l + n;
    } else {
      r = k - k % n;
      qpow((r - l) / n);
      break;
    }
    for (j = i; j <= m && a[rk[j]] >= l && a[rk[j]] <= r; j++) {
      if (a[rk[j]] < r) change_st(1, 0, n - 1, a[rk[j]] % n, v[rk[j]], 0);
      if (a[rk[j]] > l)
        change_st(1, 0, n - 1, (a[rk[j]] + n - 1) % n, v[rk[j]], 1);
    }
    qhy = qhy * st[1];
    for (; i < j; i++) {
      if (a[rk[i]] < r)
        change_st(1, 0, n - 1, a[rk[i]] % n, s[a[rk[i]] % n], 0);
      if (a[rk[i]] > l)
        change_st(1, 0, n - 1, (a[rk[i]] + n - 1) % n, s[a[rk[i]] % n], 1);
      if (a[rk[i]] == r) break;
    }
  }
  f[0] = qhy.matrix[0][0];
  f[1] = qhy.matrix[0][1];
  for (j = 0; j <= k % n; j++)
    if (i <= m && a[rk[i]] == k - k % n + j) {
      s[j] = v[rk[i]];
      i++;
    }
  for (j = 2; j <= k % n; j++)
    f[j] = (f[j - 1] * s[j - 1] % mod + f[j - 1] * s[j - 1] % mod) % mod;
  printf("%lld\n", f[k % n]);
}
int main() {
  standing_by();
  complete();
  return 0;
}
