#include <bits/stdc++.h>
inline int read() {
  int data = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && !std::isdigit(ch)) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (std::isdigit(ch)) data = data * 10 + (ch ^ 48), ch = getchar();
  return data * w;
}
const int N(1e6 + 10), M(20);
struct node {
  int x, y;
} a[N];
char sS[M + 5], sT[M + 5];
int n, m, K, S, T, lim, P[M], f[1 << M], g[1 << M], cnt[1 << M];
void swap(int &S, int x, int y) {
  int v = (S >> x & 1) ^ (S >> y & 1);
  S ^= (v << x) | (v << y);
}
inline void chkmin(int &x, const int &y) {
  if (y < x) x = y;
}
inline void chkmax(int &x, const int &y) {
  if (x < y) x = y;
}
int main() {
  n = read(), m = read(), K = read(), lim = 1 << K, std::scanf("%s%s", sS, sT);
  for (int i = 0; i < K; i++) S |= (sS[i] - '0') << i;
  for (int i = 0; i < K; i++) T |= (sT[i] - '0') << i;
  for (int i = 1; i <= n; i++) a[i] = (node){read() - 1, read() - 1};
  for (int i = 0; i < lim; i++) f[i] = n + 1;
  g[T] = n + 1;
  for (int i = 0; i < K; i++) P[i] = i;
  for (int i = 1; i < lim; i++) cnt[i] = cnt[i >> 1] + (i & 1);
  for (int i = n, X = S, Y = T; i; i--) {
    int x = a[i].x, y = a[i].y, p = 0, q = 0;
    for (int j = 0; j < K; j++)
      if (P[j] == x) {
        p = j;
        break;
      }
    for (int j = 0; j < K; j++)
      if (P[j] == y) {
        q = j;
        break;
      }
    std::swap(P[p], P[q]), swap(X, p, q), swap(Y, p, q), f[X] = i;
    if (!g[Y]) g[Y] = i;
  }
  for (int i = lim - 1; i; i--)
    for (int j = 0; j < K; j++)
      if (i >> j & 1) chkmin(f[i ^ (1 << j)], f[i]);
  for (int i = lim - 1; i; i--)
    for (int j = 0; j < K; j++)
      if (i >> j & 1) chkmax(g[i ^ (1 << j)], g[i]);
  int ans = -1, l = 0, r = 0;
  for (int i = 0; i < lim; i++)
    if (g[i] - f[i] >= m) {
      int c = 2 * cnt[i] + K - cnt[S] - cnt[T];
      if (ans < c) ans = c, l = f[i], r = g[i] - 1;
    }
  printf("%d\n%d %d\n", ans, l, r);
  return 0;
}
