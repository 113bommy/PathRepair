#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
int x1[400000], x2[400000], x3[400000], x4[400000], x5[400000];
int W[400000][2], R[400000];
int u, v, w;
inline int power(int x, int y) {
  int s = 1;
  for (int i = 30; i >= 0; i--) {
    s = 1LL * s * s % p;
    if (y & (1 << i)) s = 1LL * s * x % p;
  }
  return s;
}
inline void preNTT(int n) {
  for (w = 1; w <= n; w = w << 1)
    ;
  w = w << 1, u = power(3, (p - 1) / w), v = power(u, p - 2);
  W[0][0] = 1, W[0][1] = 1;
  for (int i = 1; i < w; i++) {
    W[i][0] = 1LL * W[i - 1][0] * u % p;
    W[i][1] = 1LL * W[i - 1][1] * v % p;
  }
  for (int i = 0, l; l = 0, i < w; i++) {
    for (int j = i, k = 1; k < w;
         l = (l << 1) | (j & 1), j = j >> 1, k = k << 1)
      ;
    R[i] = l;
  }
  return;
}
inline void NTT(int *T, int t) {
  for (int i = 0; i < w; i++)
    if (i < R[i]) swap(T[i], T[R[i]]);
  for (int i = 1; i < w; i = i << 1)
    for (int j = 0; j < w; j = j + (i << 1))
      for (int k = 0; k < i; k++)
        u = T[j + k], v = 1LL * W[w / (i << 1) * k][t] * T[i + j + k] % p,
        T[j + k] = (u + v) % p, T[i + j + k] = (u - v + p) % p;
  if (t) {
    u = power(w, p - 2);
    for (int i = 0; i < w; i++) T[i] = 1LL * T[i] * u % p;
  }
  return;
}
int f[120000], g[120000];
int i, m, n, t;
inline void calc(int l, int r) {
  int mid = (l + r) >> 1;
  preNTT(r - l);
  for (int i = 0; i < w; i++) x1[i] = 0;
  for (int i = l; i <= mid; i++) {
    x1[i - l] = f[i];
    if (l) x1[i - l] = (x1[i - l] + f[i]) % p;
  }
  for (int i = 0; i < w; i++) x2[i] = 0;
  for (int i = 0; i <= r - l; i++)
    if (i <= mid) x2[i] = f[i];
  for (int i = 0; i < w; i++) x4[i] = 0;
  for (int i = 0; i <= r - l; i++) x4[i] = g[i];
  NTT(x1, 0), NTT(x2, 0), NTT(x4, 0);
  for (int i = 0; i < w; i++) x5[i] = 1LL * x1[i] * x2[i] % p * x4[i] % p;
  NTT(x5, 1);
  for (int i = mid + 1; i <= r; i++) f[i] = (f[i] + x5[i - l]) % p;
  return;
}
inline void merge(int l, int r) {
  if (l == r) {
    if (!l) f[l] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  merge(l, mid);
  calc(l, r);
  merge(mid + 1, r);
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &t), g[t]++;
  merge(0, m);
  for (i = 1; i <= m; i++) printf("%d\n", f[i]);
  return 0;
}
