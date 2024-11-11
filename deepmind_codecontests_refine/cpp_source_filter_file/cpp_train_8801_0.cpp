#include <bits/stdc++.h>
using namespace std;
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
int A[200][200], Color[200];
long long dp[200][200][200];
long long solve(int n, int k, int p, int m) {
  if (n == 0 && k == 0) return 0;
  if (k == 0 || n == 0) return LLONG_MAX / 4;
  if (dp[n][k][p] != -1) return dp[n][k][p];
  dp[n][k][p] = LLONG_MAX / 4;
  if (Color[n]) {
    if (p == Color[n])
      dp[n][k][p] = solve(n - 1, k, Color[n], m);
    else
      dp[n][k][p] = solve(n - 1, k - 1, Color[n], m);
  } else {
    for (int i = 1; i <= m; i++) {
      if (p == i)
        dp[n][k][p] = min(dp[n][k][p], solve(n - 1, k, i, m) + A[n][i]);
      else
        dp[n][k][p] = min(dp[n][k][p], solve(n - 1, k - 1, i, m) + A[n][i]);
    }
  }
  return dp[n][k][p];
}
int main() {
  for (int i = 0; i <= 150; i++)
    for (int j = 0; j <= 150; j++)
      for (int k = 0; k <= 150; k++) dp[i][j][k] = -1;
  int n = getnum(), m = getnum(), k = getnum();
  for (int i = 1; i <= n; i++) Color[i] = getnum();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) A[i][j] = getnum();
  }
  long long x = solve(n, k, 0, m);
  if (x >= LLONG_MAX / 8)
    cout << "-1";
  else
    cout << x;
}
