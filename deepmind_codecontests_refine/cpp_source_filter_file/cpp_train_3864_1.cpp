#include <bits/stdc++.h>
using namespace std;
inline bool isvowel(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u')
    return 1;
  return 0;
}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;
const int M = 22;
const int pri = 997;
const int Magic = 2101;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int n, m, k;
int dp[2005][2005][2];
int ans;
void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int main() {
  cin >> n >> k;
  dp[1][1][1] = 2;
  dp[1][2][0] = 2;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      add(dp[i + 1][j][0], dp[i][j][0]);
      add(dp[i + 1][j][1], dp[i][j][1]);
      add(dp[i + 1][j][1], (dp[i][j][0] + dp[i][j][0]) % mod);
      add(dp[i + 1][j + 1][1], dp[i][j][1]);
      add(dp[i + 1][j + 1][0], (dp[i][j][1] + dp[i][j][1]) % mod);
      add(dp[i + 1][j + 2][0], dp[i][j][0]);
    }
  }
  add(ans, dp[n][k][0]);
  add(ans, dp[n][k][1]);
  cout << ans;
  return 0;
}
