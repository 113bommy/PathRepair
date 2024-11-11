#include <bits/stdc++.h>
using namespace std;
const int MAX_N = -1;
const int inf = 2e9 + 19;
long long n, k, dp[5];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  dp[1] = 1;
  dp[2] = (n * (n - 1) / 2) + dp[1];
  dp[3] = (((n * (n - 1) * (n - 2)) / 6) * 2) + dp[2];
  dp[4] = (((n * (n - 1) * (n - 2) * (n - 3)) / 24) * 9) + dp[3];
  cout << dp[k];
  return (0);
}
