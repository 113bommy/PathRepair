#include <bits/stdc++.h>
using namespace std;
const int N = 100005, P = 1000000007;
using ll = long long;
ll dp[N][2];
vector<int> e[N];
void dfs(int pos) {
  dp[pos][1] = 1;
  if (e[pos].empty()) return;
  for (auto &i : e[pos]) {
    dfs(i);
    ll t1 = (dp[pos][0] * dp[i][0] + dp[pos][1] * dp[i][1]) % P;
    ll t2 = (dp[pos][0] * dp[i][1] + dp[pos][1] * dp[i][0]) % P;
    dp[pos][0] = (dp[pos][0] + t1) % P;
    dp[pos][1] = (dp[pos][1] + t2) % P;
  }
  dp[pos][0] = dp[pos][0] * 2 % P;
  dp[pos][1] = dp[pos][1] * 2 % P;
  ll t1 = 1, t2 = 1, t3 = 0;
  for (auto &i : e[pos]) {
    t1 = (t1 + t1 * dp[i][0]) % P;
    ll tt2 = t2, tt3 = t3;
    t2 = (t2 + tt3 * dp[i][1]) % P;
    t3 = (t3 + tt2 * dp[i][1]) % P;
  }
  dp[pos][0] = (dp[pos][0] + P - t3) % P;
  dp[pos][1] = (dp[pos][1] + P - t1) % P;
}
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int t1;
  for (int i = 2; i <= n; i++) cin >> t1, e[t1].push_back(i);
  dfs(1);
  cout << (dp[1][0] + dp[1][1]) << endl;
  return 0;
}
