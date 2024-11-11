#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1, *p2;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int rd() {
  int x = 0;
  char ch = nc();
  while (ch < '0' || ch > '9') ch = nc();
  while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = nc();
  return x;
}
const int MAX_N = 5e1 + 5, MAX_M = 5e1 + 5, MAX_W = 1e2 + 2, MAX_S = 26e2 + 52,
          inf = 1e9 + 7, MOD = 998244353;
int n, m;
int dv[MAX_W];
int w[MAX_N];
int love[MAX_N];
int ans[MAX_N];
int sum[2];
int dp[2][MAX_N][MAX_W][MAX_S];
int _sum(int a, int b) {
  int c = a + b;
  if (MOD <= c) c -= MOD;
  if (c < 0) c += MOD;
  return c;
}
int _sub(int a, int b) {
  int c = a - b;
  if (c < 0) c += MOD;
  return c;
}
int _mul(int a, int b) {
  int c = 1LL * a * b % MOD;
  return c;
}
int _pow(int a, int b) {
  if (!b) return 1;
  int res = _pow(a, b >> 1);
  res = _mul(res, res);
  if (b & 1) res = _mul(res, a);
  return res;
}
int calc(int a, int b) {
  int dis = sum[0] - b;
  a -= dis;
  return sum[1] + a;
}
void preProcess() {
  for (int i = 0; i < MAX_W; i++) dv[i] = _pow(i, MOD - 2);
}
int main() {
  preProcess();
  ios::sync_with_stdio(false), cin.tie(0);
  n = rd();
  m = rd();
  for (int i = 0; i < n; i++) love[i] = rd();
  for (int i = 0; i < n; i++) {
    w[i] = rd();
    sum[love[i]] += w[i];
  }
  for (int i = 0; i < n; i++) dp[0][i][w[i]][sum[0]] = 1;
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < n; j++)
      for (int k = max(0, w[j] - i); k <= w[j] + i; k++)
        for (int s = max(0, sum[0] - i); s <= sum[0] + i; s++) {
          if (love[j]) {
            if (k)
              dp[i & 1][j][k][s] = _mul(dp[(i - 1) & 1][j][k - 1][s],
                                        _mul(k - 1, dv[s + calc(i - 1, s)]));
            dp[i & 1][j][k][s] =
                _sum(dp[i & 1][j][k][s],
                     _mul(dp[(i - 1) & 1][j][k][s + 1],
                          _mul(s + 1, dv[s + 1 + calc(i - 1, s + 1)])));
            dp[i & 1][j][k][s] =
                _sum(dp[i & 1][j][k][s],
                     _mul(dp[(i - 1) & 1][j][k][s],
                          _mul(calc(i - 1, s) - k, dv[s + calc(i - 1, s)])));
          }
          if (!love[j]) {
            dp[i & 1][j][k][s] =
                _mul(dp[(i - 1) & 1][j][k + 1][s + 1],
                     _mul(k + 1, dv[s + 1 + calc(i - 1, s + 1)]));
            dp[i & 1][j][k][s] =
                _sum(dp[i & 1][j][k][s],
                     _mul(dp[(i - 1) & 1][j][k][s + 1],
                          _mul(s + 1 - k, dv[s + 1 + calc(i - 1, s + 1)])));
            dp[i & 1][j][k][s] =
                _sum(dp[i & 1][j][k][s],
                     _mul(dp[(i - 1) & 1][j][k][s],
                          _mul(calc(i - 1, s), dv[s + calc(i - 1, s)])));
          }
        }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < MAX_S; j++)
      for (int k = 0; k < MAX_W; k++)
        ans[i] = _sum(ans[i], _mul(dp[m & 1][i][k][j], k));
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
