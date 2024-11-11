#include <bits/stdc++.h>
using namespace std;
int n, k, dp[4096][1024], opt[4096][1024];
int m[4096][4096], sum[4096][4096];
int getSum(int l, int r) {
  l--;
  if (l == -1) {
    return sum[r][r] / 2;
  }
  return (sum[r][r] - sum[l][r] - sum[r][l] + sum[l][l]) / 2;
}
void getAns(int d, int m, int optL, int optR) {
  dp[m][d] = getSum(0, m);
  for (int i = max(optL, 1); i <= optR; i++) {
    if (dp[m][d] > dp[i - 1][d - 1] + getSum(i, m)) {
      dp[m][d] = dp[i - 1][d - 1] + getSum(i, m);
      opt[m][d] = i;
    }
  }
}
void solve(int d, int optL, int optR, int l, int r) {
  int m = (l + r) / 2;
  getAns(d, m, optL, optR);
  if (l + 1 >= r) {
    return;
  }
  solve(d, optL, opt[m][d], l, m);
  solve(d, opt[m][d], optR, m + 1, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  char arr[8096];
  cin.ignore();
  for (int i = 0; i < n; i++) {
    cin.getline(arr, 8096);
    for (int j = 0; j < n; j++) {
      m[i][j] = arr[j * 2] - '0';
      dp[i][j] = (1 << 30);
    }
  }
  sum[0][0] = m[0][0];
  for (int i = 1; i < n; i++) {
    sum[i][0] = m[i][0] + sum[i - 1][0];
  }
  for (int i = 1; i < n; i++) {
    sum[0][i] = m[0][i] + sum[0][i - 1];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      sum[i][j] = m[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= k; i++) {
    solve(i, 0, n - 1, 0, n);
  }
  cout << dp[n - 1][k] << "\n";
  return 0;
}
