#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[150001], cost[150001];
void dfs(long long int i, vector<long long int> &visited,
         vector<pair<long long int, long long int>> &v) {
  visited[i] = 1;
  for (long long int j = 0; j < v.size(); j++) {
    if (visited[j] == 1)
      continue;
    else if (v[i].first > v[j].first && v[i].first < v[j].second)
      dfs(j, visited, v);
    else if (v[i].second > v[j].first && v[i].second < v[j].second)
      dfs(j, visited, v);
  }
}
void solve() {
  long long int t, n, m, x, y, z, p = 0, b = 0, l = INT_MAX, k, mini = 0;
  cin >> n;
  vector<pair<long long int, long long int>> v;
  for (long long int i = 1; i <= n; i++) {
    cin >> z >> x >> y;
    if (z == 1) {
      v.push_back(make_pair(x, y));
    } else {
      vector<long long int> visited(v.size(), 0);
      dfs(x - 1, visited, v);
      if (visited[y] == 1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
