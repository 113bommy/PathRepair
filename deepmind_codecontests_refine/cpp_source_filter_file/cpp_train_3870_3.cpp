#include <bits/stdc++.h>
using namespace std;
const long long P = (1000 * 1000 * 1000) + 7;
const int sqr = 1000;
const int arrn = 200005;
int n;
long long k;
string in;
long long dp[102][102] = {};
void pre() {
  vector<int> last(300, -1);
  int n = in.length();
  for (int i = 0; i < n + 1; i++) dp[i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int l = 1; l <= n; l++) {
      dp[i][l] = dp[i - 1][l] + dp[i - 1][l - 1];
      if (last[in[i - 1]] != -1)
        dp[i][l] = dp[i][l] - dp[last[in[i - 1]]][l - 1];
    }
    last[in[i - 1]] = i - 1;
  }
}
void solve() {
  cin >> n >> k >> in;
  pre();
  int out = 0;
  for (int i = n; i >= 0 && k != 0; i--) {
    if (dp[n][i] >= k) {
      out += (k) * (n - i);
      k = 0;
    } else {
      k -= dp[n][i];
      out += dp[n][i] * (n - i);
    }
  }
  if (k == 0)
    cout << out;
  else
    cout << -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int T;
  T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
