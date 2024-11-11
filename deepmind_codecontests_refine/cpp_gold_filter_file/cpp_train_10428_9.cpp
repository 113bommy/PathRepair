#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int LOG = 20;
const int cntsz = 101;
const int INF = 1e9;
const int mod = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  long long ans = 0;
  for (int i = 0; i < int(n); i++) cin >> a[i];
  sort(a.begin(), a.end());
  vector<vector<int> > dp(n + 1, vector<int>(k + 1));
  for (int x = int(1); x < int(N / (k - 1) + 1); x++) {
    dp[0][0] = 1;
    int c = 0;
    for (int i = 0; i < int(n); i++) {
      while (a[i] - a[c] >= x) c++;
      for (int j = 0; j < int(k + 1); j++) dp[i + 1][j] = dp[i][j];
      for (int j = 0; j < int(k); j++) {
        dp[i + 1][j + 1] += dp[c][j];
        dp[i + 1][j + 1] %= mod;
      }
    }
    ans += dp[n][k];
    ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}
