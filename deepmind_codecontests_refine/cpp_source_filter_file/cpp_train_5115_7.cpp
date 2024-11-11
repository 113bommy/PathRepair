#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
void level(vector<vector<int64_t>>& adj, vector<int64_t>& arr) {
  int64_t i, n;
  n = adj.size();
  vector<bool> visited(n, false);
  queue<int64_t> q;
  q.push(0);
  visited[0] = true;
  arr[0] = 1;
  while (q.size()) {
    i = q.front();
    for (auto v : adj[i]) {
      if (visited[v]) continue;
      arr[v] = arr[i] + 1;
      visited[v] = true;
      q.push(v);
    }
    q.pop();
  }
}
bool dfs(vector<vector<int64_t>>& adj, vector<bool>& visited,
         vector<int64_t>& arr, int64_t x, int64_t node) {
  visited[node] = true;
  if (arr[node] < x && arr[node] != -1) return false;
  int64_t j;
  if (arr[node] == -1)
    j = x;
  else
    j = arr[node];
  bool f;
  for (auto v : adj[node]) {
    if (visited[v]) continue;
    f = dfs(adj, visited, arr, j, v);
    if (!f) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t i, j, k, n;
  cin >> n;
  vector<int64_t> arr(n), depth(n);
  vector<vector<int64_t>> adj(n);
  for (i = 1; i < n; ++i) {
    cin >> j, --j;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }
  for (i = 0; i < n; ++i) cin >> arr[i];
  level(adj, depth);
  bool f = true;
  for (i = 0; i < n; ++i) {
    if (depth[i] & 1) {
      if (arr[i] == -1) {
        f = false;
        break;
      }
    } else {
      if (arr[i] != -1) {
        f = false;
        break;
      }
    }
  }
  if (!f) {
    cout << "-1\n";
    return 0;
  }
  vector<bool> visited(n, false);
  f = dfs(adj, visited, arr, 0, 0);
  if (!f) {
    cout << "-1\n";
    return 0;
  }
  int64_t ans = 0;
  vector<int64_t> ans1(n, 0);
  ans1[0] = arr[0];
  vector<int64_t> temp;
  for (i = 0; i < n; ++i)
    if (depth[i] % 2 == 0) temp.push_back(i);
  for (i = 0; i < temp.size(); ++i) {
    int64_t x = 100000000000;
    j = 0;
    for (auto v : adj[temp[i]]) {
      if (depth[v] > depth[temp[i]]) {
        j++;
        x = min(x, arr[v]);
      } else
        k = arr[v];
    }
    if (j >= 1) {
      ans1[temp[i]] = x - k;
      for (auto v : adj[temp[i]]) {
        if (depth[v] > depth[temp[i]]) ans1[v] = arr[v] - ans1[temp[i]];
      }
    } else
      ans1[temp[i]] = 0;
  }
  for (i = 0; i < n; ++i) ans += ans1[i];
  cout << ans << "\n";
  return 0;
}
