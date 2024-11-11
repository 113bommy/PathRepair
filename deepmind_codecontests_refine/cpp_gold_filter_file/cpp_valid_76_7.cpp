#include <bits/stdc++.h>
using namespace std;
long long dp[200010];
int main() {
  int n, m;
  cin >> n >> m;
  dp[1] = 1;
  long long sum = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] += sum;
    for (int l = 2, r = 0; l <= i; l = r + 1) {
      r = min(i, i / (i / l));
      dp[i] += 1ll * dp[i / l] * (r - l + 1);
      dp[i] %= m;
    }
    sum += dp[i];
    sum %= m;
  }
  cout << dp[n] << endl;
}
