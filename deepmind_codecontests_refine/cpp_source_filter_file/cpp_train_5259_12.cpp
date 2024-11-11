#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int ar[n];
  for (long long int i = 0; i < n; i++) cin >> ar[i];
  long long int dp[n];
  memset(dp, 0, sizeof(dp));
  for (long long int i = 0; i < n; i++) dp[ar[i]] = dp[ar[i] - 1] + 1;
  long long int maxi = -1;
  for (long long int i = 0; i < n; i++) maxi = max(maxi, dp[i]);
  cout << n - maxi;
  return 0;
}
