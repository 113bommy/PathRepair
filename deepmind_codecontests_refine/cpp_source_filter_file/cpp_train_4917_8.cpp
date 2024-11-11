#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int> > dp;
vector<long long int> a;
long long int check(long long int l, long long int r) {
  if (l >= r) return 0;
  if (dp[l][r]) return dp[l][r];
  if (l + 1 == r) {
    dp[l][r] = a[r];
    return a[r];
  }
  dp[l][r] = -1;
  for (int m = l + 1; m < r; ++m) {
    long long int lf = check(l, m), rt = check(m, r);
    if (lf && lf == rt) {
      dp[l][r] = lf + 1;
      return lf + 1;
    }
  }
  return dp[l][r];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dp.assign(n + 1, vector<long long int>(n + 1, 0));
  vector<long long int> ans(n + 1, 1e9);
  ans[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (check(i, j) > 0) ans[j] = min(ans[j], ans[i] + 1);
    }
  }
  cout << ans[n];
}
