#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const int MAX = (int)1e5 + 5;
int store[MAX];
int dp[MAX][2];
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = (1); i < (n + 1); ++i) scanf("%d", store + i);
  for (int i = (1); i < (n + 1); ++i) {
    if (store[i] > store[i - 1])
      dp[i][0] = dp[i - 1][0] + 1;
    else
      dp[i][0] = 1;
  }
  for (int i = n; i >= 1; --i) {
    if (store[i] < store[i + 1])
      dp[i][1] = dp[i + 1][1] + 1;
    else
      dp[i][1] = 1;
  }
  int res = 0;
  for (int i = (1); i < (n + 1); ++i) {
    res = max(res, dp[i - 1][0] + 1);
    res = max(res, dp[i + 1][1] + 1);
    if (store[i - 1] <= store[i + 1] + 2)
      res = max(res, dp[i - 1][0] + dp[i + 1][1] + 1);
  }
  printf("%d", res);
  return 0;
}
