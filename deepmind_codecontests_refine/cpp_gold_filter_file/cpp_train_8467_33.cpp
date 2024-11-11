#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  if (n == 0)
    cout << "0 0 0";
  else if (n == 1)
    cout << "1 0 0";
  else if (n == 2)
    cout << "1 1 0";
  else {
    vector<long long int> dp(1000000);
    dp[0] = 0;
    dp[1] = 1;
    long long int i = 2;
    for (i = 2; true; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
      if (dp[i] == n) break;
    }
    cout << dp[i - 1] << " " << dp[i - 3] << " " << dp[i - 4];
  }
}
