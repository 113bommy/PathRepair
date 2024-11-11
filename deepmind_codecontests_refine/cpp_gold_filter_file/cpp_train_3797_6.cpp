#include <bits/stdc++.h>
using namespace std;
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < 48) c = getchar();
  while (c > 47) x = x * 10 + (c ^ 48), c = getchar();
  return x;
}
char A[55], B[55];
vector<int> fuck[26], shit[26 * 26];
int dp[55][55];
bool F[55][55][26], G[55][55][26];
void solve() {
  int qcnt;
  scanf("%s %s %d", A + 1, B + 1, &qcnt);
  while (qcnt--) {
    char str[10];
    scanf("%s", str);
    char c = *str, c1 = str[3], c2 = str[4];
    fuck[c - 'a'].push_back(26 * (c1 - 'a') + c2 - 'a');
    shit[26 * (c1 - 'a') + c2 - 'a'].push_back(c - 'a');
  }
  int N = strlen(A + 1);
  for (int i = (1), iend = (N); i <= iend; ++i) F[i][i][A[i] - 'a'] = 1;
  for (int sz = (2), szend = (N); sz <= szend; ++sz) {
    for (int i = (1), iend = (N - sz + 1); i <= iend; ++i) {
      int j = i + sz - 1;
      for (int k = (i), kend = (j - 1); k <= kend; ++k) {
        for (int c1 = (0), c1end = (25); c1 <= c1end; ++c1)
          if (F[i][k][c1]) {
            for (int c2 = (0), c2end = (25); c2 <= c2end; ++c2)
              if (F[k + 1][j][c2]) {
                for (int x : shit[c1 * 26 + c2]) F[i][j][x] = 1;
              }
          }
      }
    }
  }
  int M = strlen(B + 1);
  for (int i = (1), iend = (M); i <= iend; ++i) G[i][i][B[i] - 'a'] = 1;
  for (int sz = (2), szend = (M); sz <= szend; ++sz) {
    for (int i = (1), iend = (M - sz + 1); i <= iend; ++i) {
      int j = i + sz - 1;
      for (int k = (i), kend = (j - 1); k <= kend; ++k) {
        for (int c1 = (0), c1end = (25); c1 <= c1end; ++c1)
          if (G[i][k][c1]) {
            for (int c2 = (0), c2end = (25); c2 <= c2end; ++c2)
              if (G[k + 1][j][c2]) {
                for (int x : shit[c1 * 26 + c2]) G[i][j][x] = 1;
              }
          }
      }
    }
  }
  memset(dp, -1, sizeof dp);
  dp[0][0] = 0;
  for (int i = (1), iend = (N); i <= iend; ++i) {
    for (int j = (1), jend = (M); j <= jend; ++j) {
      dp[i][j] = 1e9;
      for (int p = (0), pend = (i - 1); p <= pend; ++p)
        for (int q = (0), qend = (j - 1); q <= qend; ++q)
          if (dp[p][q] != -1) {
            for (int ch = (0), chend = (25); ch <= chend; ++ch)
              if (F[p + 1][i][ch] && G[q + 1][j][ch]) {
                chkmin(dp[i][j], dp[p][q] + 1);
              }
          }
      if (dp[i][j] > 1e8) dp[i][j] = -1;
    }
  }
  printf("%d\n", dp[N][M]);
}
int main() {
  solve();
  return 0;
}
