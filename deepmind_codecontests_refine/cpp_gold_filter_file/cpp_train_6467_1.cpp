#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7;
int parent[maxn], n, depth[maxn];
long long maxi;
vector<int> adjlist[maxn], children[maxn];
long long val[maxn], dp[maxn];
set<pair<long long, pair<int, int> > > s;
set<pair<long long, pair<int, int> > >::iterator it;
int anscount;
void dfs(int cur) {
  depth[cur] = depth[parent[cur]] + 1;
  dp[cur] = val[cur];
  for (auto u : adjlist[cur]) {
    if (parent[cur] == u) continue;
    children[cur].push_back(u);
    parent[u] = cur;
    dfs(u);
    dp[cur] += max(0LL, dp[u]);
  }
  s.insert({dp[cur], {depth[cur], cur}});
}
void process(int cur) {
  if (cur <= 1 || dp[cur] <= 0) return;
  int p = parent[cur];
  if (s.find({dp[p], {depth[p], p}}) != s.end()) {
    process(p);
    s.erase({dp[p], {depth[p], p}});
    dp[p] -= dp[cur];
    s.insert({dp[p], {depth[p], p}});
  }
}
void rem(int cur) {
  if (s.find({dp[cur], {depth[cur], cur}}) != s.end())
    s.erase({dp[cur], {depth[cur], cur}});
  for (auto u : children[cur]) {
    if (dp[u] > 0) rem(u);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> val[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adjlist[u].push_back(v);
    adjlist[v].push_back(u);
  }
  dfs(1);
  it = s.end();
  it--;
  maxi = it->first;
  while (true) {
    it = s.end();
    it--;
    process(it->second.second);
    rem(it->second.second);
    anscount++;
    if (s.empty()) break;
    it = s.end();
    it--;
    if (it->first != maxi) break;
  }
  cout << maxi * anscount << ' ' << anscount;
  return 0;
}
