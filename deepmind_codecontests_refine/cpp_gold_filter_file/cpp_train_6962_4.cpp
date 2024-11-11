#include <iostream>
#include <algorithm>

using namespace std;

long long dp[33];

int main() {
  int n;
  
  while( cin >> n, n ) {
    fill(dp, dp+32, 0);
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for(int i=3; i<=n; i++) {
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    cout << dp[n]/3650+1 << endl;
  }
  
  return 0;
}