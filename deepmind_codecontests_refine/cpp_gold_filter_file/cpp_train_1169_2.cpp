#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 20) + 100, LOG = 19, inf = 1e9, mod = 998244353;
const long long INF = 1e18;
int n, m, k, ex;
long long p[N], base[N];
int a[N], b[N], c[N], A[LOG][N], B[N], ans[N];
bool was[N];
long long first(long long x) {
  long long res = 0;
  for (int i = 0; i < m; i++) {
    if (was[i]) continue;
    res = ((res << 1) | ((x >> i) & 1));
  }
  return res;
}
int sum(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
void add(long long x) {
  for (int i = 0; i < k; i++)
    if ((x >> p[i]) & 1) x ^= base[i];
  if (x == 0) {
    ex++;
    return;
  }
  for (int i = 0; i < m; i++)
    if ((x >> i) & 1) {
      p[k] = i;
      base[k] = x;
      k++;
      break;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    add(x);
  }
  if (k <= 20) {
    for (int i = 0; i < (1 << k); i++) {
      long long x = 0;
      for (int j = 0; j < k; j++)
        if ((i >> j) & 1) x ^= base[j];
      ans[__builtin_popcountll(x)]++;
    }
  } else {
    for (int i = 0; i < min(m / 2, k); i++) was[p[i]] = 1;
    for (int i = 0; i < (1 << min(m / 2, k)); i++) {
      long long x = 0, cnt = 0;
      for (int j = 0; j < min(m / 2, k); j++)
        if ((i >> j) & 1) x ^= base[j];
      for (int j = 0; j < min(m / 2, k); j++)
        if ((x >> p[j]) & 1) cnt++, x ^= (1ll << p[j]);
      A[cnt][first(x)]++;
    }
    for (int i = 0; i < (1 << (k - min(m / 2, k))); i++) {
      long long x = 0;
      for (int j = 0; j < k - min(m / 2, k); j++)
        if ((i >> j) & 1) x ^= base[j + min(m / 2, k)];
      B[first(x)]++;
    }
    long long inv = 1;
    for (int i = 0; i < LOG; i++) {
      if (inv & 1) inv += mod;
      inv >>= 1;
    }
    for (int i = 0; i < LOG; i++) {
      for (int j = 0; j < (1 << LOG); j++) a[j] = A[i][j], b[j] = B[j];
      for (int j = 0; j < LOG; j++)
        for (int q = 0; q < (1 << LOG); q++)
          if ((q >> j) & 1) {
            {
              int x = a[q ^ (1 << j)];
              int y = a[q];
              a[q ^ (1 << j)] = sum(x, y);
              a[q] = sub(x, y);
            }
            {
              int x = b[q ^ (1 << j)];
              int y = b[q];
              b[q ^ (1 << j)] = sum(x, y);
              b[q] = sub(x, y);
            }
          }
      for (int j = 0; j < (1 << LOG); j++) c[j] = 1ll * a[j] * b[j] % mod;
      for (int j = 0; j < LOG; j++)
        for (int q = 0; q < (1 << LOG); q++)
          if ((q >> j) & 1) {
            int x = c[q ^ (1 << j)];
            int y = c[q];
            c[q ^ (1 << j)] = sum(x, y);
            c[q] = sub(x, y);
          }
      for (int j = 0; j < (1 << LOG); j++) {
        c[j] = c[j] * inv % mod;
        ans[i + __builtin_popcountll(j)] =
            sum(ans[i + __builtin_popcountll(j)], c[j]);
      }
    }
  }
  long long x = 1;
  while (ex--) {
    x = x + x;
    if (x >= mod) x -= mod;
  }
  for (int i = 0; i <= m; i++) printf("%lld ", 1ll * ans[i] * x % mod);
}
