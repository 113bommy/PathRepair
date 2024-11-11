#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a, b[1000006];
  for (int i = 0; i < 1000006; i++) {
    b[i] = 0;
  }
  long long int mx = 0;
  long long int c;
  for (int i = 0; i < n; i++) {
    cin >> a >> c;
    b[a] = c;
    mx = max(a, mx);
  }
  long long int dp[mx];
  for (int i = 0; i < mx; i++) {
    dp[i] = 0;
  }
  if (b[0] > 0) {
    dp[0] = 1;
  }
  long long int ans = dp[0];
  for (int i = 1; i < mx + 1; i++) {
    if (b[i] > 0) {
      if (b[i] >= i) {
        dp[i] = 1;
      } else {
        dp[i] = dp[i - b[i] - 1] + 1;
      }
    } else {
      dp[i] = dp[i - 1];
    }
    ans = max(ans, dp[i]);
  }
  cout << n - ans << endl;
}
