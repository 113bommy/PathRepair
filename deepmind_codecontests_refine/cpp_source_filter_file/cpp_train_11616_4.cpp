#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, z, flag = 0;
vector<long long> sum(200005), mx(200005, INT_MIN);
vector<int> adj[200005 + 1];
vector<int> pl(200005 + 1);
map<int, int> vis;
void dfs(int a) {
  vis[a] = 1;
  for (int i = 0; i < adj[a].size(); i++) {
    if (vis[adj[a][i]] == 0) {
      dfs(adj[a][i]);
      sum[a] += sum[adj[a][i]];
      mx[a] = max(mx[a], mx[adj[a][i]]);
    }
  }
  sum[a] += pl[a];
  mx[a] = max(mx[a], sum[a]);
  return;
}
map<int, int> mp;
long long ans = INT_MIN;
void dfs2(int x) {
  mp[x] = 1;
  long long k = 0;
  priority_queue<int> q;
  for (int i = 0; i < adj[x].size(); i++) {
    if (mp[adj[x][i]] == 0) q.push(mx[adj[x][i]]);
  }
  long long s = q.size();
  int j = 2;
  while (j > 0 && q.size()) {
    k += q.top();
    q.pop();
    j--;
  }
  if (s > 1) ans = max(ans, k);
  for (int i = 0; i < adj[x].size(); i++) {
    if (mp[adj[x][i]] == 0) dfs2(adj[x][i]);
  }
}
int main() {
  int t;
  t = 1;
  for (int r = 0; r < t; r++) {
    cin >> n;
    long long i;
    for (i = 1; i <= n; i++) cin >> pl[i];
    for (i = 0; i < n - 1; i++) {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    dfs(1);
    dfs2(1);
    if (ans == INT_MIN)
      cout << "Impossible\n";
    else
      cout << ans;
  }
  return 0;
}
