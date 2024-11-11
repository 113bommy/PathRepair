#include <bits/stdc++.h>
using namespace std;
long long int dp[10000];
int main() {
  dp[1] = 1;
  int n;
  cin >> n;
  dp[2] = 2;
  dp[3] = 4;
  for (int i = 4; i <= n; i++) dp[i] = dp[i - 2] + i;
  cout << dp[n] << endl;
  return 0;
}
