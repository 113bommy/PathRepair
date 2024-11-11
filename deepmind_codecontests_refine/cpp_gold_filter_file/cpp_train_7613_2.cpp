#include <bits/stdc++.h>
using namespace std;
string s;
long long int dp[510][501];
long long int solve(long long int l, long long int r) {
  if (dp[l][r] != -1) {
    return dp[l][r];
  }
  if (l > r) return 0;
  long long int a = 1 + solve(l + 1, r);
  for (long long int i = l + 1; i <= r; i++) {
    if (s[i] != s[l]) continue;
    a = min(a, solve(l + 1, i - 1) + solve(i, r));
  }
  dp[l][r] = a;
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, i;
  cin >> n;
  cin >> s;
  memset(dp, -1, sizeof dp);
  cout << solve(0, s.size() - 1);
}
