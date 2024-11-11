#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const long long mod = 1e9 + 7;
long long val[N], n;
vector<pair<long long, long long> > edge[N];
long long ans;
long long dp[N];
void dfs(int x, int fa) {
  dp[x] = val[x];
  long long max1 = 0, max2 = 0;
  for (auto v : edge[x])
    if (v.first != fa) {
      int to = v.first, vv = v.second;
      dfs(to, x);
      if (dp[to] - vv >= max1)
        max2 = max1, max1 = dp[to] - vv;
      else if (dp[to] - vv > max2)
        max2 = dp[to] - vv;
    }
  ans = max(ans, dp[x] + max1 + max2);
  dp[x] += max1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
  long long a, b, c;
  for (int i = 1; i < n; i++) {
    scanf("%lld%lld%lld", &a, &b, &c);
    edge[a].push_back({b, c});
    edge[b].push_back({a, c});
  }
  dfs(1, 0);
  cout << ans;
}
