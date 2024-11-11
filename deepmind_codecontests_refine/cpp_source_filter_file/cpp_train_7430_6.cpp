#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
void add(int& a, int b) {
  a += b;
  if (a >= MOD) a %= MOD;
}
int dp[205][205][2][2];
int dp_new[205][205][2][2];
int S[205][205][2][2];
int SS(int l1, int r1, int l2, int r2, int a, int b) {
  if (l1 > r1) return 0;
  if (l2 > r2) return 0;
  int tmp = S[r1][r2][a][b];
  tmp -= S[l1 - 1][r2][a][b];
  if (tmp < 0) tmp += MOD;
  tmp -= S[r1][l2 - 1][a][b];
  if (tmp < 0) tmp += MOD;
  tmp += S[l1 - 1][l2 - 1][a][b];
  if (tmp >= MOD) tmp -= MOD;
  return tmp;
}
int main() {
  int n, m;
  ignore = scanf("%d %d", &n, &m);
  int ans = 0;
  for (int l = 1; l <= m; l++) {
    for (int r = l; r <= m; r++) {
      dp[l][r][0][0] = 1;
      ans++;
    }
  }
  for (int i = 2; i <= n; i++) {
    memset(dp_new, 0, sizeof dp_new);
    memset(S, 0, sizeof S);
    for (int l = 1; l <= m; l++) {
      for (int r = 1; r <= m; r++) {
        for (int a = 0; a < 2; a++)
          for (int b = 0; b < 2; b++) {
            int tmp = S[l - 1][r][a][b] + S[l][r - 1][a][b];
            if (tmp >= MOD) tmp -= MOD;
            tmp -= S[l - 1][r - 1][a][b];
            if (tmp < MOD) tmp += MOD;
            tmp += dp[l][r][a][b];
            if (tmp >= MOD) tmp -= MOD;
            S[l][r][a][b] = tmp;
          }
      }
    }
    for (int l = 1; l <= m; l++)
      for (int r = l; r <= m; r++) {
        add(dp_new[l][r][0][0], SS(l, r, l, r, 0, 0));
        add(dp_new[l][r][0][0], 1);
        add(dp_new[l][r][0][1], SS(l, r, r + 1, m, 0, 0));
        add(dp_new[l][r][0][1], SS(l, r, r + 1, m, 0, 1));
        add(dp_new[l][r][0][1], SS(l, r, r, r, 0, 1));
        add(dp_new[l][r][1][0], SS(1, l - 1, l, r, 0, 0));
        add(dp_new[l][r][1][0], SS(1, l - 1, l, r, 1, 0));
        add(dp_new[l][r][1][0], SS(l, l, l, r, 1, 0));
        add(dp_new[l][r][1][1], SS(1, l - 1, r + 1, m, 0, 0));
        add(dp_new[l][r][1][1], SS(1, l - 1, r + 1, m, 0, 1));
        add(dp_new[l][r][1][1], SS(1, l - 1, r + 1, m, 1, 0));
        add(dp_new[l][r][1][1], SS(1, l - 1, r + 1, m, 1, 1));
        add(dp_new[l][r][1][1], SS(l, l, r + 1, m, 1, 0));
        add(dp_new[l][r][1][1], SS(l, l, r + 1, m, 1, 1));
        add(dp_new[l][r][1][1], SS(1, l - 1, r, r, 0, 1));
        add(dp_new[l][r][1][1], SS(1, l - 1, r, r, 1, 1));
        add(dp_new[l][r][1][1], SS(l, l, r, r, 1, 1));
        add(ans, dp_new[l][r][0][0]);
        add(ans, dp_new[l][r][0][1]);
        add(ans, dp_new[l][r][1][0]);
        add(ans, dp_new[l][r][1][1]);
      }
    memcpy(dp, dp_new, sizeof dp);
  }
  printf("%d", ans);
}
