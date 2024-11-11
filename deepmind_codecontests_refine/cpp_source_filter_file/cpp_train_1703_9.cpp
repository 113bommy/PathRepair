#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
const int inf = 1e9 + 7;
const long long mod = 1e9 + 7;
int dp[maxn][30];
int prv[maxn][30];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < 30; i++) {
    fill(dp[i], dp[i] + maxn, inf);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (i == 0) {
        dp[i][j] = (s[0] != 'A' + j);
        continue;
      }
      for (int m = 0; m < k; m++) {
        if (m != j) {
          int ans = dp[i - 1][m] + (s[i] != 'A' + j);
          if (ans < dp[i][j]) {
            prv[i][j] = m;
          }
          dp[i][j] = min(dp[i][j], ans);
        }
      }
    }
  }
  int ans = inf;
  int lastc = inf;
  for (int j = 0; j < k; j++) {
    if (dp[n - 1][j] < ans) {
      lastc = j;
    }
    ans = min(ans, dp[n - 1][j]);
  }
  cout << ans << endl;
  vector<char> ns;
  for (int i = n - 1; i >= 0; i--) {
    ns.push_back('A' + lastc);
    lastc = prv[i][lastc];
  }
  for (int i = ns.size() - 1; i >= 0; i--) {
    cout << ns[i];
  }
  cout << endl;
}
