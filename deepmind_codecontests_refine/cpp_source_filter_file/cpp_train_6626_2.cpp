#include <bits/stdc++.h>
using namespace std;
long long dp[101][101][101];
char txt[101];
int sz;
long long MD = 1000000007;
long long norm(long long &x) { return x %= MD; }
void tran(int t) {
  int i, j, k;
  auto _0 = dp[t - 2];
  auto _1 = dp[t - 1];
  auto _2 = dp[t];
  for (i = 0; i <= sz; i++) {
    for (j = i; j <= sz; j++) {
      _2[i][j] = 0;
      for (k = i; k <= j; k++) {
        long long u;
        norm(u = _0[i][k] * _1[k][j]);
        norm(_2[i][j] += u);
      }
    }
  }
}
void init() {
  int i, j;
  for (i = 0; i <= sz; i++) {
    for (j = i; j <= sz; j++) {
      dp[0][i][j] = dp[1][i][j] = 0;
    }
  }
  for (i = 0; i <= sz; i++) {
    dp[0][i][i] = dp[1][i][i] = 1;
  }
  dp[0][0][0] = dp[1][0][0] = dp[0][sz][sz] = dp[1][sz][sz] = 2;
  for (i = 0; i < sz; i++) {
    dp[txt[i] - '0'][i][i + 1] = 1;
  }
}
int main() {
  int n, i;
  scanf("%d%d", &sz, &n);
  scanf("%s", txt);
  init();
  for (i = 2; i <= n; i++) {
    tran(i);
  }
  printf("%lld\n", dp[n][0][sz]);
  return 0;
}
