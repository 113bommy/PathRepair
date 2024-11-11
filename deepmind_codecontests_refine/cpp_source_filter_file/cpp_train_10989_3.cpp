#include <bits/stdc++.h>
using namespace std;
unsigned long long dp[92];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  dp[1] = 2;
  dp[2] = 3;
  for (int i = 3; i < 90; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  int N;
  cin >> N;
  int i;
  for (i = 1; i < 90; i++) {
    if (N < dp[i]) {
      break;
    }
  }
  cout << i - 1;
  return 0;
}
