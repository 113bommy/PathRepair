#include <bits/stdc++.h>
using namespace std;
long long Inf = 1000000000000000001LL;
int g[105][105], ax[210], n, m, N, r[210], ans[210];
long long K, dp[205][205];
bool cmp(int p1, int p2) { return ax[p1] < ax[p2]; }
void Add(long long &a, long long b) {
  if (a == Inf || b == Inf) {
    a = Inf;
    return;
  }
  if (a >= Inf - b) {
    a = Inf;
    return;
  }
  a += b;
}
long long sol() {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    int f1 = 1, f2 = 1;
    if (ans[i] == 1) f1 = 1, f2 = 0;
    if (ans[i] == -1) f1 = 0, f2 = 1;
    for (int j = 0; j <= N; j++)
      if (dp[i][j]) {
        if (f1) Add(dp[i + 1][j + 1], dp[i][j]);
        if (f2 && j) Add(dp[i + 1][j - 1], dp[i][j]);
      }
  }
  return dp[N][0];
}
int main() {
  scanf("%d%d%I64d", &n, &m, &K);
  Inf = K + 1;
  for (int i = 0; i < n + m; i++) ax[i] = 5000000;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%d", &g[i][j]);
      ax[i + j] = min(ax[i + j], g[i][j]);
    }
  N = n + m - 1;
  for (int i = 0; i < N; i++) r[i] = i;
  sort(r, r + N, cmp);
  memset(ans, 0, sizeof(ans));
  for (int i = 0; i < N; i++) {
    ans[r[i]] = 1;
    long long ret = sol();
    if (ret >= K)
      continue;
    else {
      K -= ret;
      ans[r[i]] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%c", ans[i + j] == 1 ? '(' : ')');
    puts("");
  }
  return 0;
}
