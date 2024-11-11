#include <bits/stdc++.h>
using namespace std;
const double PI =
    3.141592653589793238462643383279502884197169399375105820974944;
long long n;
vector<long long> adj[200005];
long long dp[200005][2], a[200005];
void dfs(long long s) {
  long long tot = 0, cnt = 0, maxi = -1000000000;
  for (auto x : adj[s]) {
    dfs(x);
    if (dp[x][0] > dp[x][1]) {
      tot += dp[x][0];
    } else {
      cnt = 1 - cnt;
      tot += dp[x][1];
    }
    (maxi) = max((maxi), (-abs(dp[x][0] - dp[x][1])));
  }
  if (cnt) {
    dp[s][0] = tot + maxi;
    dp[s][1] = tot;
  } else {
    dp[s][0] = tot;
    dp[s][1] = tot + maxi;
  }
  (dp[s][1]) = max((dp[s][1]), (dp[s][0] + a[s]));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = (1); i < (n + 1); i++) {
    long long p;
    cin >> p >> a[i];
    if (a[i] != 1) adj[p].push_back(i);
  }
  dfs(1);
  cout << max(dp[1][0], dp[1][1]) << endl;
}
