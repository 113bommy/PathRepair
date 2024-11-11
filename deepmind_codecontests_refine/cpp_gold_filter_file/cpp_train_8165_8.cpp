#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long ar[n];
  long long f[100001] = {0};
  for (long long i = 0; i < n; i++) {
    cin >> ar[i];
    f[ar[i]]++;
  }
  long long dp[100001];
  dp[0] = 0, dp[1] = f[1];
  for (long long i = 2; i < 100001; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + f[i] * i);
  }
  cout << dp[100000];
}
