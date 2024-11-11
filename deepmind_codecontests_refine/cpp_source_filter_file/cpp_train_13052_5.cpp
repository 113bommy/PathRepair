#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double PI = acos(-1);
template <class T, class S>
inline void add(T& a, S b) {
  a += b;
  if (a >= mod) a -= mod;
}
template <class T, class S>
inline void sub(T& a, S b) {
  a -= b;
  if (a < 0) a += mod;
}
template <class T, class S>
inline bool chkmax(T& a, S b) {
  return a < b ? a = b, true : false;
}
template <class T, class S>
inline bool chkmin(T& a, S b) {
  return a > b ? a = b, true : false;
}
int n, k;
int dp[N][N][2][2];
int way[N];
int F[N], Finv[N], inv[N];
int C(int n, int m) {
  if (n < m || n < 0) return 0;
  return 1LL * F[n] * Finv[m] % mod * Finv[n - m] % mod;
}
int main() {
  F[0] = Finv[0] = inv[1] = 1;
  for (int i = 2; i < N; i++)
    inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 1; i < N; i++) F[i] = 1LL * F[i - 1] * i % mod;
  for (int i = 1; i < N; i++) Finv[i] = 1LL * Finv[i - 1] * inv[i] % mod;
  scanf("%d%d", &n, &k);
  dp[0][0][1][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int u = 0; u < 2; u++) {
        for (int v = 0; v < 2; v++) {
          if (!dp[i][j][u][v]) continue;
          add(dp[i + 1][j][v][0], dp[i][j][u][v]);
          if (!u) {
            add(dp[i + 1][j + 1][v][0], dp[i][j][u][v]);
            if (i + 1 < n) add(dp[i + 1][j + 1][v][1], dp[i][j][u][v]);
          } else {
            if (i + 1 < n) add(dp[i + 1][j + 1][v][1], dp[i][j][u][v]);
          }
        }
      }
    }
  }
  for (int j = 1; j <= n; j++)
    for (int u = 0; u < 2; u++)
      for (int v = 0; v < 2; v++) add(way[j], dp[n][j][u][v]);
  int ans = 0;
  for (int i = k, op = 1; i <= n; i++, op = -op) {
    ans =
        (ans + 1LL * op * C(i, k) * way[i] % mod * F[n - i] % mod + mod) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
