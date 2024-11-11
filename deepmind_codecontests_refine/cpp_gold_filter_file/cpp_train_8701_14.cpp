#include <bits/stdc++.h>
using namespace std;
int N, P, K, dp[1003][103], n[1003][103], sz[2], v[2][1100], cum[3][1100], ans;
int q(int i, int l, int r) { return cum[i][r] - (l ? cum[i][l - 1] : 0); }
int main() {
  scanf("%d %d %d", &N, &P, &K);
  for (int i = (0); i < (2); i++) {
    scanf("%d", &sz[i]);
    for (int j = (0); j < (sz[i]); j++) {
      int a;
      scanf("%d", &a), a--;
      v[i][a] = 1;
    }
  }
  for (int i = (0); i < (1100); i++) {
    cum[0][i] = v[0][i];
    cum[1][i] = v[1][i];
    cum[2][i] = v[0][i] & v[1][i];
    if (i > 0) {
      for (int j = (0); j < (3); j++) cum[j][i] += cum[j][i - 1];
    }
  }
  for (int u = (1); u < (P + 1); u++) {
    for (int i = (0); i < (N + 1); i++)
      for (int d = max(0, 51 - i); i + d - 51 <= N && d < 103; d++) {
        if (i > 0 && d < 102) n[i][d] = max(n[i][d], n[i - 1][d + 1]);
        if (d > 0) n[i][d] = max(n[i][d], n[i][d - 1]);
        int j = i + d - 51;
        if (i < N) {
          int ni = min(i + K, N), nj = j, nd = nj - ni + 51;
          if (nd >= 0 && nd < 103) {
            int c = q(0, i, ni - 1);
            if (j > i) c -= q(2, i, j - 1);
            n[ni][nd] = max(n[ni][nd], dp[i][d] + c);
          }
        }
        if (j < N) {
          int ni = i, nj = min(j + K, N), nd = nj - ni + 51;
          if (nd >= 0 && nd < 103) {
            int c = q(1, j, nj - 1);
            if (i > j) c -= q(2, j, i - 1);
            n[ni][nd] = max(n[ni][nd], dp[i][d] + c);
          }
        }
      }
    for (int i = (0); i < (1003); i++)
      for (int d = (0); d < (103); d++) {
        dp[i][d] = n[i][d];
        ans = max(ans, dp[i][d]);
      }
  }
  printf("%d\n", ans);
  return 0;
}
