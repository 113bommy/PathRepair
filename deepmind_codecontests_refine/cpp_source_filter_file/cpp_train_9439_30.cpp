#include <bits/stdc++.h>
using namespace std;
long long n, k, x, ans;
bool dp[55][55];
vector<long long> a;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  a.push_back(0);
  cin >> n >> k;
  for (int i = 0; i < n && cin >> x; i++) a.push_back(a.back() + x);
  for (int bit = 54; bit >= 0; bit--) {
    memset(dp, 0, sizeof dp);
    long long target = (ans | (1LL << bit));
    for (int i = 1; i <= n; i++) dp[i][1] = (target & a[i]) == target;
    for (int i = 2; i <= n; i++)
      for (int j = 2; j <= k; j++)
        if (dp[i - 1][j - 1])
          for (int r = i; r <= n; r++)
            dp[r][j] |= (target & (a[r] - a[i - 1])) == target;
    if (dp[n][k]) ans = target;
  }
  cout << ans << endl;
  return 0;
}
