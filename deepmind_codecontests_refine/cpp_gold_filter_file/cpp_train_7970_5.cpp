#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int dp[n + 1];
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = i * 5 + dp[i - 1];
  }
  for (int i = n; i >= 0; i--) {
    if (dp[i] + k > 240) {
    } else {
      cout << i;
      break;
    }
  }
}
