#include <bits/stdc++.h>
using namespace std;
long long const MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n;
  string s;
  cin >> s;
  long long dp[26][26] = {0};
  long long ans[n], mi = 0;
  for (int i = 0; i < n; i++) {
    long long idx = s[i] - 'a';
    if (idx == 25) {
      ans[i] = 1;
      mi = max(mi, 1ll);
      dp[idx][0] = 1;
      for (int j = 0; j < 26; j++) dp[0][j] = 1;
      continue;
    }
    long long idx2 = 0;
    for (int j = 0; j < 26; j++) {
      if (dp[idx + 1][j] == 0) {
        dp[idx][j] = 1;
        for (int k = idx; k >= 0; k--) {
          dp[k][j] = 1;
        }
        idx2 = j + 1;
        break;
      }
    }
    ans[i] = idx2;
    mi = max(mi, ans[i]);
  }
  cout << mi << "\n";
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
