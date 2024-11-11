#include <bits/stdc++.h>
using namespace std;
int k, n, dp[1000005], lcnt[1000005], h[1000005];
vector<int> ms[1000005];
void dfs(int x) {
  if (ms[x].empty()) {
    dp[x] = 1;
    lcnt[x] = 1;
    h[x] = 0;
    return;
  }
  int br = 0;
  h[x] = n;
  for (vector<int>::iterator i = ms[x].begin(); i != ms[x].end(); ++i) {
    int o = *i;
    dfs(o);
    h[n] = min(h[n], h[o] + 1);
    br += lcnt[o];
  }
  for (vector<int>::iterator i = ms[x].begin(); i != ms[x].end(); ++i) {
    int o = *i;
    dp[x] = max(dp[x], dp[o] + br - lcnt[o]);
  }
  if (h[x] < k) {
    lcnt[x] = br;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    ms[x].push_back(i);
  }
  dfs(1);
  cout << dp[1] << endl;
  return 0;
}
