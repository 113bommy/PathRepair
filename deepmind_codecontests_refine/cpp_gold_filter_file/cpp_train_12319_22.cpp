#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 100000007;
const ll uwu = 22;
const ll si = (1 << uwu);
int dp[si], def = si - 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int ar[n];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    dp[ar[i]] = ar[i];
  }
  for (int i = 0; i < uwu; i++) {
    for (int mask = 1; mask < si; mask++) {
      if (mask & (1 << i)) dp[mask] = max(dp[mask ^ (1 << i)], dp[mask]);
    }
  }
  for (int i = 0; i < n; i++) {
    dp[(def ^ ar[i])] ? cout << dp[(def ^ ar[i])] << " " : cout << -1 << " ";
  }
  return 0;
}
