#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> adj;
vector<int> depth;
void dfs(int v, int d) {
  if (visited[v]) {
    return;
  }
  visited[v] = true;
  depth[d]++;
  for (int i : adj[v]) {
    dfs(i, d + 1);
  }
}
int main() {
  int n;
  cin >> n;
  visited.resize(n);
  adj.resize(n + 1);
  for (int i = 2; i <= n; i++) {
    int to;
    cin >> to;
    adj[to].push_back(i);
  }
  depth.resize(n + 1);
  dfs(1, 0);
  int collected = 0;
  for (int i : depth) {
    collected += i % 2;
  }
  cout << collected << endl;
  return 0;
}
