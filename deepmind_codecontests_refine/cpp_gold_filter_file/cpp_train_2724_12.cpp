#include <bits/stdc++.h>
using namespace std;
long long int prime = 998244353;
long long int modulo = 1e9 + 7;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
void solve() {
  unordered_map<string, int> look_up;
  unordered_map<long long int, vector<int> > lp;
  long long int n, m = 0, k = 0, p = 0, l = 0, r = 0, tmp = 0, ans = 0,
                   count = 0;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int mod = 100000000;
  int dp[a + 1][b + 1][2];
  memset(dp, 0, sizeof(dp));
  dp[0][0][1] = 1;
  dp[0][0][0] = 1;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      for (int x = 1; x <= i && x <= c; x++) {
        dp[i][j][0] += dp[i - x][j][1];
        dp[i][j][0] %= mod;
      }
      for (int x = 1; x <= j && x <= d; x++) {
        dp[i][j][1] += dp[i][j - x][0];
        dp[i][j][1] %= mod;
      }
    }
  }
  cout << (dp[a][b][0] + dp[a][b][1]) % mod;
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  solve();
  return 0;
}
