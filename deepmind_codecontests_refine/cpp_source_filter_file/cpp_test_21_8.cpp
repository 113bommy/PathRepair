#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
void CMax(T1 &x, T2 y) {
  if (y > x) x = y;
}
template <typename T1, typename T2>
void CMin(T1 &x, T2 y) {
  if (y < x) x = y;
}
template <typename T>
void read(T &x) {
  x = 0;
  int op = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') op = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  x *= op;
}
inline void swap(int &x, int &y) { x ^= y ^= x ^= y; }
inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }
const int MN = 105;
int n, m, k, P;
int dp[MN][MN][MN];
inline int Pls(int x, int y) {
  x += y;
  return x >= P ? x - P : x;
}
int C[MN][MN], fac[MN];
void process(int n = 100) {
  fac[0] = 1;
  for (int i = (1); i <= (n); ++i) fac[i] = 1ll * fac[i - 1] * i % P;
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = (1); j <= (i); ++j)
      C[i][j] = Pls(C[i - 1][j], C[i - 1][j - 1]);
  }
}
int main() {
  read(n);
  read(m);
  read(k);
  read(P);
  process();
  for (int i = (0); i <= (n); ++i) dp[0][i][0] = 1;
  for (int i = (1); i <= (n); ++i) dp[i][1][1] = dp[i][0][0] = fac[i];
  for (int i = (1); i <= (n); ++i)
    for (int j = (i + 1); j <= (n); ++j) dp[i][j][0] = fac[i];
  if (n < m + k) {
    puts("0");
    return 0;
  }
  for (int i = 2; i <= n; ++i)
    for (int j = 2; j <= i; ++j) {
      int upx = min(k, i - j + 1);
      for (int x = 0; x <= upx; ++x) {
        for (int l = 0; l < i; ++l) {
          int res = 0;
          for (int y = 0; y <= x; ++y)
            res = Pls(res,
                      1ll * dp[l][j - 1][y] * dp[i - l - 1][j - 1][x - y] % P);
          dp[i][j][x] = Pls(dp[i][j][x], 1ll * res * C[i - 1][l] % P);
        }
      }
    }
  printf("%d\n", dp[n][m][k]);
  return 0;
}
