#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  int f = 0;
  for (; c < '0' || c > '9'; f |= c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar())
    ;
  if (f) x = -x;
}
const int mo = 1e9 + 7;
inline int add(int x) { return x >= mo ? x - mo : x; }
inline int mul(int x, int y) { return (long long)x * y % mo; }
inline void U(int &x, int y) { x = add(x + y); }
const int N = 102;
int n, m, K, dp[2][N][N][N];
long double c[N][N];
inline void myAssert(int x) { assert(0 <= x && x < N); }
int main(void) {
  read(n);
  read(m);
  read(K);
  for (register int i = 0; i < (int)n + 1; i++) c[i][0] = 1;
  for (register int i = 1; i <= (n); i++)
    for (register int j = 1; j <= (i); j++)
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  int cur = 1;
  for (int em = 1; em + 1 <= n; em++) {
    dp[cur][em + 1][em][1] = 1;
  }
  int ans = 0;
  for (int val = 2; val <= m; val++) {
    int pre = cur;
    cur ^= 1;
    memset(dp[cur], 0, sizeof dp[cur]);
    for (int em = 1; em <= n; em++)
      for (int pl = 1; pl + em <= n; pl++)
        for (int pg = 1; pg <= K; pg++)
          if (dp[pre][pl][em][pg]) {
            for (int nc = em; nc + pl <= n; nc++) {
              long double good = pg * c[nc - 1][em - 1];
              if (good <= K) {
                U(dp[cur][pl + nc][nc - em][(int)good], dp[pre][pl][em][pg]);
              }
            }
          }
    for (int len = 1; len <= n; len++)
      for (int good = 1; good <= K; good++)
        U(ans, mul(m - val + 1, dp[cur][len][0][good]));
  }
  cout << ans << "\n";
}
