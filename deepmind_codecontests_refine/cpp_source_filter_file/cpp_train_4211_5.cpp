#include <bits/stdc++.h>
using namespace std;
int factors[2009][12];
int size[2009] = {0};
int dp[2009][2009];
int main() {
  for (int i = 1; i <= 2000; i++) {
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) {
        factors[i][size[i]] = j;
        size[i]++;
      }
    }
  }
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) dp[i][1] = 1;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= k; j++) {
      for (int k = 0; k < size[i]; k++)
        dp[i][j] = (dp[i][j] + dp[factors[i][k]][j - 1]) % 1000000007;
    }
    sum = (sum + dp[i][k]) % 1000000007;
  }
  cout << sum << "\n";
  return 0;
}
