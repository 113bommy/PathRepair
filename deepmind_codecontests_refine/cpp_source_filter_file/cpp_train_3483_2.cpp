#include <bits/stdc++.h>
using namespace std;
int ans[100005];
int dp[100005];
int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  int q, k;
  cin >> q >> k;
  dp[0] = 1;
  for (int i = 1; i <= 10; i++) {
    if (i < k)
      dp[i] = dp[i - 1];
    else
      dp[i] = dp[i - 1] + dp[i - k];
    dp[i] %= mod;
  }
  for (int i = 1; i <= 100000; i++) {
    ans[i] = ans[i - 1] + dp[i];
    ans[i] %= mod;
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << (ans[b] - ans[a - 1] + mod) % mod << endl;
  }
}
