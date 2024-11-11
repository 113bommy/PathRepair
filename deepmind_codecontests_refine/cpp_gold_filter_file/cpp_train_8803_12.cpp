#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 7;
const int M = 1007;
const int inf = 1e9 + 7;
const long long linf = 1e18 + 7;
const double pi = acos(-1);
const double eps = 1e-7;
const bool multipleTest = 0;
int dp[N][26];
int C[N][N];
int sum[N];
string s;
int n;
void solve() {
  cin >> n >> s;
  sum[0] = 1;
  for (int i = 0; i < s.size(); ++i) {
    int u = s[i] - 'a';
    for (int len = i + 1; len > 0; --len) {
      sum[len] -= dp[len][u];
      if (sum[len] < 0) sum[len] += inf;
      dp[len][u] = sum[len - 1] - dp[len - 1][u];
      if (dp[len][u] < 0) dp[len][u] += inf;
      sum[len] += dp[len][u];
      if (sum[len] >= inf) sum[len] -= inf;
    }
  }
  C[0][0] = 1;
  for (int i = (1); i < (N); i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = (1); j < (i); j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      if (C[i][j] >= inf) C[i][j] -= inf;
    }
  }
  long long ans = 0;
  for (int len = (1); len < (n + 1); len++) {
    ans = (ans + 1ll * C[n - 1][len - 1] * sum[len]) % inf;
  }
  cout << ans;
}
int main() {
  int Test = 1;
  if (multipleTest) {
    cin >> Test;
  }
  for (int i = 0; i < Test; ++i) {
    solve();
  }
}
