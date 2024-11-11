#include <bits/stdc++.h>
using namespace std;
int n, m;
int dp[200001];
int main() {
  cin >> n >> m;
  dp[1] = 1 % m;
  int sum = 1;
  for (int i = 2; i <= n; i++) {
    for (int l = 2, r; l <= i; l = r + 1) {
      r = i / (i / l);
      dp[i] = (dp[i] + (r - l + 1LL) * dp[i / l]) % m;
    }
    dp[i] = (dp[i] + sum) % m;
    sum = (sum + dp[i]) % m;
  }
  cout << dp[n] << endl;
}
