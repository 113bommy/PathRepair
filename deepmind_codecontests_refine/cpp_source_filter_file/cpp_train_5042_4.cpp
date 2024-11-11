#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, p, dp[1005], res;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p;
    dp[p] = 2;
    for (int j = p; j < i; j++) dp[i] = (dp[i] + dp[j]) % MOD;
  }
  for (int i = 1; i <= n; i++) res = (res + dp[i]) % MOD;
  cout << res << endl;
  return 0;
}
