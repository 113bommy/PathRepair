#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
const long long md = (long long)1e9 + 7;
int us[N][N];
long long dp[N][N];
vector<long long> ans;
int main() {
  int n;
  long long k;
  cin >> n >> k;
  dp[n][1] = 1;
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= 2; j++) {
      dp[i][j + 1] += dp[i + 1][j];
      dp[i][1] += dp[i + 1][j];
    }
  }
  int i = 1;
  while (i < n + 1) {
    int j;
    for (j = 1; j <= n - i + 1; j++) {
      if (k <= dp[i][j]) break;
      k -= dp[i][j];
    }
    for (int h = i + j - 1; h >= i; h--) {
      ans.push_back(h);
    }
    i += j;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
