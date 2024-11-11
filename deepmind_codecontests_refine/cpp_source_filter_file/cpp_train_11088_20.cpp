#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long MX = 1e9;
const long long INF = 1e9;
void print_a(vector<int> v) {
  if (v.size()) cout << v[0];
  for (int i = 1; i < v.size(); ++i) cout << ' ' << v[i];
  cout << '\n';
}
vector<vector<int> > init_vvi(int n, int m, int val) {
  return vector<vector<int> >(n, vector<int>(m, val));
}
vector<vector<long long> > init_vvl(int n, int m, long long val) {
  return vector<vector<long long> >(n, vector<long long>(m, val));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int dp[n + 1][2][3], d;
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < n + 1; ++i) {
    d = s[i - 1] - '0';
    for (int j = 0; j < 2; ++j) {
      for (int f = 0; f < 3; ++f) {
        if (f == 0) {
          if (d == j)
            dp[i][j][f] = dp[i - 1][j ^ 1][f] + 1;
          else
            dp[i][j][f] = dp[i - 1][j][f];
        } else if (f == 1) {
          if (d != j)
            dp[i][j][f] = max(dp[i][d][0], dp[i][d][1]) + 1;
          else
            dp[i][j][f] = dp[i - 1][j][f];
        } else {
          if (d == j)
            dp[i][j][f] = max(dp[i - 1][j ^ 1][1], dp[i - 1][j ^ 1][2]) + 1;
          else
            dp[i][j][f] = dp[i - 1][j][2];
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 3; ++j) ans = max(ans, dp[n][i][j]);
  cout << ans << '\n';
  return 0;
}
