#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long f[30000 + 5], sum[30000 + 5], dou[30000 + 5], tri[30000 + 5];
int n, Q, w[30000 + 5], h[30000 + 5], rk[30000 + 5], Rk[30000 + 5],
    pos[30000 + 5], Pos[30000 + 5], ban[30000 + 5];
bool cmpw(int x, int y) { return w[x] < w[y]; }
bool cmph(int x, int y) { return h[x] < h[y]; }
inline void R(long long& x, long long y) { y > x ? x = y : 0; }
int main() {
  n = read();
  Q = read();
  for (int i = 1; i <= n; ++i) w[i] = read(), rk[i] = i;
  sort(rk + 1, rk + n + 1, cmpw);
  for (int i = 1; i <= n; ++i) h[i] = read(), Rk[i] = i;
  sort(Rk + 1, Rk + n + 1, cmph);
  for (int i = 1; i <= n; ++i) Pos[Rk[i]] = i, pos[rk[i]] = i;
  for (int i = 1; i <= n; ++i) ban[i] = Pos[rk[i]];
  sort(w + 1, w + n + 1);
  sort(h + 1, h + n + 1);
  for (int i = 1; i <= n; ++i) {
    sum[i] = 1LL * w[i] * h[i];
    if (i > 1) dou[i] = 1LL * w[i] * h[i - 1] + 1LL * w[i - 1] * h[i];
    if (i > 2)
      tri[i] = sum[i] + sum[i - 1] + sum[i - 2] -
               1LL * (w[i] - w[i - 1]) * (h[i] - h[i - 1]) -
               1LL * (w[i - 1] - w[i - 2]) * (h[i - 1] - h[i - 2]) -
               min(1LL * (w[i] - w[i - 1]) * (h[i - 1] - h[i - 2]),
                   1LL * (w[i - 1] - w[i - 2]) * (h[i] - h[i - 1]));
  }
  for (register int i = 1; i <= Q; ++i) {
    int x = read(), y = read();
    swap(ban[pos[x]], ban[pos[y]]);
    for (register int j = 1; j <= n; ++j) {
      f[j] = -1e18;
      if (ban[j] != j) R(f[j], f[j - 1] + sum[j]);
      if (j > 1) R(f[j], f[j - 2] + dou[j]);
      if (j > 2) R(f[j], f[j - 3] + tri[j]);
    }
    printf("%lld\n", f[n]);
  }
  return 0;
}
