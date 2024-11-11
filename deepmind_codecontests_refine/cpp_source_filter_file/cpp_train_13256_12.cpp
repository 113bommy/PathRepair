#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-10;
double EQ(double a, double b) { return abs(a - b) < EPS; }
void fast_stream() { std::ios_base::sync_with_stdio(0); }
int a[1001][2];
int dp[3001][201][2];
int n, l;
const int mod = 10000000007;
int dfs(int len, int prv, int flip) {
  if (dp[len][prv][flip] >= 0)
    return dp[len][prv][flip];
  else if (len == 0)
    return 1;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (i == prv) continue;
    int prvWidth = a[prv][flip ^ 1];
    for (int j = 0; j < 2; j++) {
      if (j == 1 && a[i][j] == a[i][j ^ 1]) continue;
      int width = a[i][j ^ 1];
      int curLen = a[i][j];
      if ((prv == 110 || prvWidth == curLen) && len - curLen >= 0)
        res = (res + dfs(len - curLen, i, j)) % mod;
    }
  }
  return dp[len][prv][flip] = res % mod;
}
void solve() {
  cin >> n >> l;
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
  memset(dp, -1, sizeof(dp));
  int res = dfs(l, 110, 0);
  cout << res << endl;
}
int main() {
  solve();
  return 0;
}
