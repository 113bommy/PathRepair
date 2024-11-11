#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int get(char x) { return 'z' - x; }
int rget(char x) { return x - 'a'; }
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<int>> dp(n, vector<int>(k + 1));
  for (int i = 0; i < n; ++i) {
    int c = (i + 1) * (n - i);
    if (c <= k) add(dp[i][c], get(s[i]));
    add(dp[i][0], rget(s[i]));
  }
  vector<int> sum(k + 1);
  for (int i = 0; i < n; ++i)
    for (int j = 0, l, r; j <= k; ++j) {
      dp[i][j] = (dp[i][j] + (long long)rget(s[i]) * sum[j]) % mod;
      for (l = i + 1; l < n; ++l) {
        int c = j + (l - i) * (n - l);
        if (c > k) break;
        dp[l][c] = (dp[l][c] + (long long)get(s[l]) * dp[i][j]) % mod;
      }
      for (r = n - 1; r > l; --r) {
        int c = j + (r - i) * (n - r);
        if (c > k) break;
        dp[r][c] = (dp[r][c] + (long long)get(s[r]) * dp[i][j]) % mod;
      }
      add(sum[j], dp[i][j]);
    }
  int ans = 0;
  for (int i = 0; i < n; ++i) add(ans, dp[i][k]);
  cout << ans << "\n";
  return 0;
}
