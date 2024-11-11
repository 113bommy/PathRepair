#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 20000;
int n, m;
vector<vector<int>> capacity;
vector<vector<int>> adj;
int bfs(int s, int t, vector<int>& parent) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INF});
  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();
    for (int next : adj[cur]) {
      if (parent[next] == -1 && capacity[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if (next == t) return new_flow;
        q.push({next, new_flow});
      }
    }
  }
  return 0;
}
int maxflow(int s, int t) {
  int flow = 0;
  vector<int> parent(2 * n + 2);
  int new_flow;
  while (new_flow = bfs(s, t, parent)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return flow;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> n >> m;
  int arr[n + 1], brr[n + 1];
  int aa = 0, bb = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    aa += arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> brr[i];
    bb += brr[i];
  }
  if (aa != bb) {
    cout << "No\n";
    return 0;
  }
  vector<int> edge[n + 1];
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  adj.resize(2 * n + 2, vector<int>(0));
  capacity.resize(2 * n + 2, vector<int>(2 * n + 2, 0));
  for (int i = 1; i <= n; ++i) {
    adj[0].push_back(i);
    adj[i].push_back(0);
    capacity[0][i] = arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (auto ch : edge[i]) {
      adj[i].push_back(n + ch);
      adj[n + ch].push_back(i);
      capacity[i][n + ch] = arr[i];
    }
    adj[i].push_back(i + n);
    adj[i + n].push_back(i);
    capacity[i][n + i] = arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    adj[i + n].push_back(2 * n + 1);
    adj[2 * n + 1].push_back(n + i);
    capacity[n + i][2 * n + 1] = brr[i];
  }
  int ans[n + 1][2 * n + 1];
  for (int i = 1; i <= n; ++i) {
    for (int j = n + 1; j <= 2 * n; ++j) {
      ans[i][j] = capacity[i][j];
    }
  }
  int ff = maxflow(0, 2 * n + 1);
  if (ff != aa) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; ++i) {
    for (int j = n + 1; j <= 2 * n; ++j) {
      ans[i][j] -= capacity[i][j];
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}
