#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
int n;
int a[200005];
int u[200005];
int v[200005];
vector<int> edges[200005];
long long int dp[200005][2];
bool visited[200005];
long long int ans;
bool good;
pair<long long int, long long int> dfs(int node, int par) {
  if (visited[node]) return make_pair(dp[node][0], dp[node][1]);
  dp[node][0] = a[node];
  dp[node][1] = -inf;
  pair<long long int, long long int> tmp;
  int cnt = 0;
  for (int i = 0; i < edges[node].size(); ++i) {
    if (edges[node][i] == par) continue;
    ++cnt;
    tmp = dfs(edges[node][i], node);
    dp[node][0] += tmp.first;
    dp[node][1] = max(dp[node][1], tmp.second);
  }
  if (cnt > 1) good = 1;
  dp[node][1] = max(dp[node][1], dp[node][0]);
  long long int first = -(long long int)inf * 1000000;
  long long int second = -(long long int)inf * 1000000;
  long long int t;
  for (int i = 0; i < edges[node].size(); ++i) {
    if (edges[node][i] == par) continue;
    t = dp[edges[node][i]][1];
    if (t > first) {
      second = first;
      first = t;
    } else if (t > second) {
      second = t;
    }
  }
  ans = max(ans, first + second);
  visited[node] = 1;
  return make_pair(dp[node][0], dp[node][1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i < n; ++i) {
      cin >> u[i] >> v[i];
      edges[u[i]].push_back(v[i]);
      edges[v[i]].push_back(u[i]);
    }
    ans = -(long long int)inf * 1000000;
    good = 0;
    dfs(1, -1);
    if (!good) {
      cout << "Impossible\n";
    } else {
      cout << ans << "\n";
    }
    for (int i = 1; i <= n; ++i) edges[i].clear();
  }
  return 0;
}
