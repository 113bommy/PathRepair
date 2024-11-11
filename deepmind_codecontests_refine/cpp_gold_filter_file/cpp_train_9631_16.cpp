#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
template <class T>
inline bool chkmin(T &a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool chkmax(T &a, T b) {
  return a < b ? a = b, true : false;
}
const int Mod = 1e9 + 7;
const int maxn = 2000, maxm = 2000;
int n, m;
char a[maxn + 5], b[maxn + 5], c[maxn + 5];
int g[2][maxn + 5];
int w[maxn + 5];
bool ok_left[2][maxn + 5][maxm + 5];
bool ok_right[2][maxn + 5][maxm + 5];
int Max[2][maxn + 5][maxm + 5];
int dp[2][maxn + 5][maxn + 5];
int ans = 0;
inline void update(int i, int j, int k, int val) {
  if (k == m || ok_right[i][j][k]) (ans += val) %= Mod;
}
inline void solve(bool ty) {
  memset(ok_left, 0, sizeof ok_left);
  memset(ok_right, 0, sizeof ok_right);
  memset(Max, 0, sizeof Max);
  for (int i = (0), _end = (2); i < _end; ++i) {
    for (int j = n - 1; j >= 0; --j)
      for (int k = m - 1; k >= 0; --k)
        if (g[i][j] == w[k]) Max[i][j][k] = Max[i][j + 1][k + 1] + 1;
  }
  for (int i = (0), _end = (2); i < _end; ++i) {
    for (int j = (0), _end = (n); j < _end; ++j) {
      int k = j;
      int cur = 0;
      while (k >= 0) {
        if (g[i][k] != w[cur++] || (cur << 1) > m) break;
        if (k != j) ok_left[!i][j + 1][cur << 1] = k + Max[!i][k][cur] > j;
        --k;
      }
    }
    for (int j = n - 1; j >= 0; --j) {
      int k = j;
      int cur = m;
      while (k < n) {
        if (g[i][k] != w[--cur] || (cur << 1) < m) break;
        if (j != k)
          ok_right[!i][j][(cur << 1) - m] = j + Max[!i][j][(cur << 1) - m] > k;
        ++k;
      }
    }
  }
  memset(dp, 0, sizeof dp);
  for (int j = (0), _end = (n + 1); j < _end; ++j) {
    for (int i = (0), _end = (2); i < _end; ++i)
      for (int k = (0), _end = (m + 1); k < _end; ++k) {
        if (!k || ok_left[i][j][k]) (++dp[i][j][k]) %= Mod;
        if (ty && k && k < m) update(i, j, k, dp[i][j][k]);
        if (dp[i][j][k]) {
          if (j < n) {
            if (k < m && g[i][j] == w[k]) {
              (dp[i][j + 1][k + 1] += dp[i][j][k]) %= Mod;
              if (ty && k && k + 1 == m) update(i, j + 1, k + 1, dp[i][j][k]);
            }
            if (k + 1 < m && g[i][j] == w[k] && g[!i][j] == w[k + 1]) {
              (dp[!i][j + 1][k + 2] += dp[i][j][k]) %= Mod;
              if (ty && k && k + 2 == m) update(!i, j + 1, k + 2, dp[i][j][k]);
            }
          }
          if (!ty) update(i, j, k, dp[i][j][k]);
        }
      }
  }
}
int main() {
  scanf("%s%s%s", a, b, c);
  n = strlen(a), m = strlen(c);
  for (int i = (0), _end = (n); i < _end; ++i)
    g[0][i] = a[i] - 'a', g[1][i] = b[i] - 'a';
  for (int i = (0), _end = (m); i < _end; ++i) w[i] = c[i] - 'a';
  ans = 0;
  solve(0);
  reverse(w, w + m);
  solve(1);
  (ans += Mod) %= Mod;
  printf("%d\n", ans);
  return 0;
}
