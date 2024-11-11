#include <bits/stdc++.h>
template <typename A, typename B>
inline char smax(A &a, const B &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename A, typename B>
inline char smin(A &a, const B &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename I>
inline void read(I &x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) c == '-' ? f = 1 : 0;
  x = c & 15;
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  f ? x = -x : 0;
}
const int N = 15;
const int M = 2000 + 7;
const int NP = (1 << 12) + 7;
int n, m, S;
int a[N][M], dp[M][NP], f[M][NP], tt[NP];
std::pair<int, int> bb[M], b[N][M];
inline void work() {
  for (int j = 1; j <= m; ++j) {
    int mx = 0;
    for (int i = 1; i <= n; ++i) smax(mx, a[i][j]);
    bb[j] = std::pair<int, int>(-mx, j);
  }
  std::sort(bb + 1, bb + m + 1);
  smin(m, n);
  S = (1 << n) - 1;
  for (int jj = 1; jj <= m; ++jj) {
    int j = bb[jj].second;
    for (int s = 0; s <= S; ++s) tt[s] = 0, f[j][s] = 0;
    for (int s = 0; s <= S; ++s)
      for (int i = 1; i <= n; ++i)
        if ((s >> (i - 1)) & 1) tt[s] += a[i][j];
    for (int s = 0; s <= S; ++s)
      for (int i = 1; i <= n; ++i)
        smax(f[jj][s], tt[(s >> i) | ((s & ((1 << i) - 1)) << (n - i))]);
  }
  for (int j = 1; j <= m; ++j) {
    for (int s = 0; s <= S; ++s) dp[j][s] = f[j][s];
    for (int s = 0; s <= S; ++s)
      for (int sta = s; sta; sta = (sta - 1) & s)
        smax(dp[j][s], dp[j - 1][sta] + f[j][s ^ sta]);
  }
  printf("%d\n", dp[m][S]);
}
inline void init() {
  read(n), read(m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) read(a[i][j]);
}
int main() {
  int T;
  read(T);
  while (T--) {
    init();
    work();
  }
  fclose(stdin), fclose(stdout);
  return 0;
}
