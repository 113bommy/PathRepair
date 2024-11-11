#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long dp[100 + 1] = {};
  dp[1] = 1;
  dp[3] = 5;
  for (long long i = 5; i <= 100; i++) {
    if (i % 2 == 0) {
    } else {
      long long cnt = ((i / 2) * (i / 2) + 1) / 2;
      dp[i] = cnt * 4 + ((i / 2) / 2) * 4 + 1;
    }
  }
  if (n == 3) {
    cout << 5 << "\n";
    return 0;
  }
  for (long long i = 1; i <= 100; i++) {
    if (dp[i] >= n) {
      cout << i << "\n";
      return 0;
    }
  }
  return 0;
}
