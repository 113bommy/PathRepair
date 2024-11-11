#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, lv[200], idx[200], tmp;
  long long s, dp[200][200];
  scanf("%d%d%I64d", &n, &m, &s);
  memset(lv, 63, sizeof(lv));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%d", &tmp);
      lv[i + j] = min(tmp, lv[i + j]);
    }
  for (int i = 0; i < n + m - 1; i++) idx[i] = i;
  sort(idx, idx + n + m - 1, [&](int x, int y) { return lv[x] < lv[y]; });
  char ans[200] = {};
  for (int t = 0; t < n + m - 1; t++) {
    ans[idx[t]] = '(';
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < n + m - 1; i++)
      for (int c = i & 1; c <= i && c <= n + m - 1 - i; c += 2) {
        if (c && ans[i] != '(') dp[i + 1][c - 1] += min(dp[i][c], s);
        if (ans[i] != ')') dp[i + 1][c + 1] += min(dp[i][c], s);
      }
    if (s > dp[n + m - 1][0]) {
      s -= dp[n + m - 1][0];
      ans[idx[t]] = ')';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) putchar(ans[i + j]);
    puts("");
  }
}
