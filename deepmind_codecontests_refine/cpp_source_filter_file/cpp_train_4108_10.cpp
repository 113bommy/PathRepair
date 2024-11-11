#include <bits/stdc++.h>
using namespace std;
int b[100001];
int c[100001][2];
long long dp[100001][2];
int main(int argc, char **argv) {
  int n;
  memset(b, 0, sizeof(b));
  memset(dp, 0, sizeof(dp));
  memset(c, 0, sizeof(c));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    b[ai]++;
  }
  int m = 0;
  for (int i = 0; i < 100001; i++) {
    if (b[i]) {
      c[m][0] = i;
      c[m][1] = b[i];
      m++;
    }
  }
  for (int i = 0; i < m; i++) {
    long long points = (long long)(c[i][0] * c[i][1]);
    if ((i != 0) && (c[i][0] == c[i - 1][0] + 1)) {
      dp[i][0] = dp[i - 1][1];
      if ((i > 2) && (c[i - 2][0] == c[i - 3][0] + 1) &&
          (c[i - 1][0] == c[i - 2][0] + 1)) {
        dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + points;
      } else {
        dp[i][1] = dp[i - 1][0] + points;
      }
    } else {
      if (i == 0) {
        dp[i][0] = 0;
        dp[i][1] = points;
      } else {
        long long last = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = last;
        dp[i][1] = last + points;
      }
    }
  }
  printf("%" PRId64 "\n", max(dp[m - 1][0], dp[m - 1][1]));
  return 0;
}
