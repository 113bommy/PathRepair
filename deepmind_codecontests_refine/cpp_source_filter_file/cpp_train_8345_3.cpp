#include <bits/stdc++.h>
using namespace std;
char sf[1000005];
int len;
double dp[1000005][2], eps = 1e-8;
bool check(int d) {
  double lmt = d / 100000000.0;
  dp[1][1] = -lmt, dp[1][0] = 0;
  for (int i = 1; i <= len; i++) {
    if (sf[i] == 'L') dp[i][0] += 1;
    if (sf[i] == 'R') dp[i][1] += 1;
    dp[i][0] -= lmt, dp[i][1] -= lmt;
    dp[i + 1][0] = dp[i][0] - lmt;
    dp[i + 1][1] = dp[i][1] - lmt;
    if (sf[i] == 'X' || sf[i] != sf[i + 1]) {
      dp[i + 1][0] = max(dp[i + 1][0], dp[i][1]);
      dp[i + 1][1] = max(dp[i + 1][1], dp[i][0]);
    }
  }
  return max(dp[len][0] - lmt, dp[len][1]) >= -eps;
}
int main() {
  scanf("%s", sf + 1);
  len = strlen(sf + 1);
  if (sf[1] != 'X' && sf[1] == sf[len]) {
    if (sf[1] == 'L')
      sf[++len] = 'X';
    else {
      len++;
      for (int i = 2; i <= len; i++) sf[i] = sf[i - 1];
      sf[1] = 'X';
    }
  }
  int l = 0, r = 100000000, ans;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%0.6lf", ans / 1000000.0);
}
