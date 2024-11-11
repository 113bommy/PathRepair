#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const long long mod = 1e9 + 7;
long long dp[maxn][maxn];
long long a[maxn];
int n;
long long solve(int l, int r) {
  if (l >= r) return dp[l][r] = 1;
  if (dp[l][r] != -1) return dp[l][r];
  long long &ans = dp[l][r];
  ans = 0;
  for (int i = l + 1; i <= r; i++)
    if (i == r || a[l + 1] < a[i + 1]) {
      ans = (ans + solve(l + 1, i) * solve(i, r)) % mod;
    }
  return ans;
}
int main(int argc, const char *argv[]) {
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int res = solve(1, n);
  cout << res << endl;
  return 0;
}
