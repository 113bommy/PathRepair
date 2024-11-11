#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, p, dp[1005], res;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p;
    dp[i] = 1;
    for (int j = p; j < i; j++) dp[i] = (dp[i] + dp[j] + 1) % MOD;
  }
  for (int i = 1; i <= n; i++) res = (res + dp[i] + 1) % MOD;
  cout << res << endl;
  return 0;
}
