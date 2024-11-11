#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solveCP311() {
  ll n;
  cin >> n;
  ld dp[n + 1];
  dp[0] = 0;
  dp[1] = 2;
  for (ll i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * 2;
  }
  cout << dp[n];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  while (t--) {
    solveCP311();
  }
  return 0;
}
