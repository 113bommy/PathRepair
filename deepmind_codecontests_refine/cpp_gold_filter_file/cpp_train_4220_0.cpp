#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = 0;
  int sum = 0;
  while (c < '0' || c > '9') c = getchar();
  while ('0' <= c && c <= '9') sum = sum * 10 + c - '0', c = getchar();
  return sum;
}
long long n, m, A[200000 + 1][6], B[200000 + 1][6], rt[200000 + 1],
    dp[200000 + 1][1 << 5], dp2[200000 + 1][1 << 5], F[200000 + 1][1 << 5],
    F2[200000 + 1][1 << 5], ST[1 << 5][1 << 5];
bool vis[200000 + 1];
int find(int x) {
  if (rt[x] == x) return x;
  return rt[x] = find(rt[x]);
}
void unionn(int x, int y) {
  if (find(x) != find(y)) vis[find(y)] |= vis[find(x)], rt[find(x)] = find(y);
  return;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m - 1; ++i)
    for (int j = 1; j <= n; ++j) A[i][j] = read();
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) B[i][j] = read();
  for (int i = 1; i <= m; ++i)
    for (int j = 0; j < (1 << n); ++j) dp[i][j] = dp2[i][j] = 1e18;
  dp[1][(1 << n) - 1] = 0;
  for (int i = 1; i <= m - 1; ++i)
    for (int j = 0; j < (1 << n); ++j)
      for (int k = 1; k <= n; ++k)
        if ((1 << (k - 1)) & j) F[i][j] += A[i][k];
  for (int i = 1; i <= m - 1; ++i)
    for (int j = 0; j < (1 << n); ++j)
      for (int k = 1; k <= n; ++k)
        if ((1 << (k - 1)) & j) F2[i][j] += B[i + 1][k];
  for (int i = 0; i < (1 << n); ++i)
    for (int j = 0; j < (1 << n); ++j) {
      for (int k = 1; k <= n; ++k) vis[rt[k] = k] = ((i & (1 << (k - 1))) > 0);
      for (int k = 1; k <= n; ++k)
        if ((1 << (k - 1)) & (~j)) unionn(k, k + 1 - (k == n) * n);
      for (int k = 1; k <= n; ++k) ST[i][j] += (1 << (k - 1)) * vis[find(k)];
    }
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < (1 << n); ++j)
      for (int k = 0; k < (1 << n); ++k)
        dp2[i][j & (~k)] = min(dp2[i][j & (~k)], dp[i][j] + F[i][k]);
    for (int j = 0; j < (1 << n); ++j)
      for (int k = 0; k < (1 << n); ++k)
        dp[i + 1][ST[j][k]] = min(dp[i + 1][ST[j][k]], dp2[i][j] + F2[i][k]);
  }
  printf("%lld\n", dp[m][0]);
  return 0;
}
