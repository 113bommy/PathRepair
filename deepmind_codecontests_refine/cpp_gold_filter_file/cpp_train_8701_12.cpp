#include <bits/stdc++.h>
using namespace std;
const int MAX = 1003;
const int mult = 1000;
const int inf = 1e8;
int n, p, k;
int A[MAX];
int B[MAX];
int dp[2][53][53];
int opt[2][53][53];
int cur = 0;
int nxt = 1;
pair<int, int> check(int mid) {
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      dp[cur][i][j] = -inf;
      opt[cur][i][j] = 0;
    }
  }
  dp[cur][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < k; l++) {
        dp[nxt][j][l] = -inf;
        opt[nxt][j][l] = 0;
      }
    }
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < k; l++) {
        if (j == 0 && l == 0) {
          if (dp[nxt][k - 1][k - 1] <
              (dp[cur][j][l] + ((A[i] | B[i]) * mult) - mid - mid)) {
            dp[nxt][k - 1][k - 1] =
                (dp[cur][j][l] + ((A[i] | B[i]) * mult) - mid - mid);
            opt[nxt][k - 1][k - 1] = opt[cur][j][l] + 2;
          }
          if (dp[nxt][k - 1][l] < (dp[cur][j][l] + (A[i] * mult) - mid)) {
            dp[nxt][k - 1][l] = (dp[cur][j][l] + (A[i] * mult) - mid);
            opt[nxt][k - 1][l] = opt[cur][j][l] + 1;
          }
          if (dp[nxt][j][k - 1] < (dp[cur][j][l] + (B[i] * mult) - mid)) {
            dp[nxt][j][k - 1] = (dp[cur][j][l] + (B[i] * mult) - mid);
            opt[nxt][j][k - 1] = opt[cur][j][l] + 1;
          }
          if (dp[nxt][j][l] < dp[cur][j][l]) {
            dp[nxt][j][l] = dp[cur][j][l];
            opt[nxt][j][l] = opt[cur][j][l];
          }
        } else if (j > 0 && l == 0) {
          if (dp[nxt][j - 1][l] < (dp[cur][j][l] + (A[i] * mult))) {
            dp[nxt][j - 1][l] = (dp[cur][j][l] + (A[i] * mult));
            opt[nxt][j - 1][l] = opt[cur][j][l];
          }
          if (dp[nxt][j - 1][k - 1] <
              (dp[cur][j][l] + ((A[i] | B[i]) * mult) - mid)) {
            dp[nxt][j - 1][k - 1] =
                (dp[cur][j][l] + ((A[i] | B[i]) * mult) - mid);
            opt[nxt][j - 1][k - 1] = opt[cur][j][l] + 1;
          }
        } else if (j == 0 && l > 0) {
          if (dp[nxt][j][l - 1] < (dp[cur][j][l] + (B[i] * mult))) {
            dp[nxt][j][l - 1] = (dp[cur][j][l] + (B[i] * mult));
            opt[nxt][j][l - 1] = opt[cur][j][l];
          }
          if (dp[nxt][k - 1][l - 1] <
              (dp[cur][j][l] + ((A[i] | B[i]) * mult) - mid)) {
            dp[nxt][k - 1][l - 1] =
                (dp[cur][j][l] + ((A[i] | B[i]) * mult) - mid);
            opt[nxt][k - 1][l - 1] = opt[cur][j][l] + 1;
          }
        } else {
          if (dp[nxt][j - 1][l - 1] <
              (dp[cur][j][l] + ((A[i] | B[i]) * mult))) {
            dp[nxt][j - 1][l - 1] = dp[cur][j][l] + ((A[i] | B[i]) * mult);
            opt[nxt][j - 1][l - 1] = opt[cur][j][l];
          }
        }
      }
    }
    cur ^= 1;
    nxt ^= 1;
  }
  int mx = 0;
  int ret = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      if (dp[cur][i][j] > mx) {
        mx = dp[cur][i][j];
        ret = opt[cur][i][j];
      }
    }
  }
  return (make_pair(mx, ret));
}
int main() {
  scanf("%d %d %d", &n, &p, &k);
  int x;
  scanf("%d", &x);
  for (int i = 1; i <= x; i++) {
    int a;
    scanf("%d", &a);
    A[a] = 1;
  }
  scanf("%d", &x);
  for (int i = 1; i <= x; i++) {
    int a;
    scanf("%d", &a);
    B[a] = 1;
  }
  if (k == 0) {
    printf("0\n");
    return 0;
  }
  if ((2 * ((n + k - 1) / k)) <= p) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += (A[i] | B[i]);
    }
    printf("%d\n", ans);
    return 0;
  }
  int lo = 0;
  int hi = k * mult;
  int ans;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int x = (check(mid).second);
    if (x > p) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
      ans = mid;
    }
  }
  int val = check(ans).first;
  printf("%d\n", (val + (lo * p)) / mult);
  return 0;
}
