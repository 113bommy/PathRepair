#include <bits/stdc++.h>
using namespace std;
const int Nmax = 250005;
struct edge {
  int to, c;
};
multiset<long long> s[Nmax];
vector<edge> v[Nmax];
vector<int> active[Nmax];
int grd[Nmax];
bool used[Nmax];
int n;
long long sum[Nmax], dp[Nmax][2];
void dfs(int node, int lim, int dad = 0, int up = 0) {
  used[node] = 1;
  while (v[node].size() && grd[v[node].back().to] <= lim) {
    sum[node] += v[node].back().c;
    s[node].insert(v[node].back().c);
    v[node].pop_back();
  }
  auto itt = s[node].end();
  int cntt = s[node].size();
  while (cntt > grd[node] - lim) {
    --cntt;
    --itt;
    sum[node] -= *itt;
  }
  s[node].erase(itt, s[node].end());
  long long sum0 = 0, sum2 = 0;
  for (auto it : v[node])
    if (it.to != dad) {
      dfs(it.to, lim, node, it.c);
      sum0 += dp[it.to][0];
      s[node].insert(dp[it.to][1] - dp[it.to][0]);
      sum2 += dp[it.to][1] - dp[it.to][0];
    }
  long long ans = sum0 + sum2 + sum[node];
  int cnt = s[node].size();
  assert(cnt);
  auto it = s[node].end();
  --it;
  while (cnt > grd[node] - lim) {
    ans -= *it;
    assert(it != s[node].begin());
    --it;
    --cnt;
  }
  dp[node][0] = ans;
  ans -= *it;
  if (dad) {
    dp[node][1] = ans + up;
    dp[node][0] = min(dp[node][0], dp[node][1]);
  } else
    dp[node][1] = -1;
  for (auto it : v[node])
    if (it.to != dad) s[node].erase(s[node].find(dp[it.to][1] - dp[it.to][0]));
}
int solve(int lim) {
  for (auto it : active[lim]) used[it] = 0;
  long long ans = 0;
  for (auto it : active[lim])
    if (!used[it]) {
      dfs(it, lim);
      ans += dp[it][0];
    }
  return ans;
}
int main() {
  cin.sync_with_stdio(false);
  int i, j, x, y, cost;
  long long ans0 = 0;
  cin >> n;
  for (i = 1; i < n; ++i) {
    cin >> x >> y >> cost;
    v[x].push_back({y, cost});
    v[y].push_back({x, cost});
    ans0 += cost;
  }
  cout << ans0 << ' ';
  for (i = 1; i <= n; ++i) {
    grd[i] = v[i].size();
    for (j = 1; j < grd[i]; ++j) active[j].push_back(i);
  }
  for (i = 1; i <= n; ++i)
    sort(v[i].begin(), v[i].end(),
         [](edge a, edge b) { return grd[a.to] > grd[b.to]; });
  for (i = 1; i < n; ++i) cout << solve(i) << ' ';
  return 0;
}
