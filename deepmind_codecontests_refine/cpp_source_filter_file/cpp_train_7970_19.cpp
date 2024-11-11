#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int dp[n + 1];
  dp[1] = 5;
  for (int i = 2; i <= n; i++) {
    dp[i] = i * 5 + dp[i - 1];
  }
  for (int i = n; i >= 1; i--) {
    if (dp[i] + k > 240) {
    } else {
      cout << i;
      break;
    }
  }
}
