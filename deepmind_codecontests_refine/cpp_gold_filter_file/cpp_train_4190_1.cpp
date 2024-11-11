#include <bits/stdc++.h>
using namespace std;
long long int n, q, k;
vector<vector<long long int>> graph;
vector<long long int> visited, parent, tin, tout;
long long int timer = 0;
void scan_and_memset() {
  cin >> n;
  cin >> q;
  graph.resize(n + 1);
  visited.resize(n + 1);
  parent.resize(n + 1);
  tin.resize(n + 1);
  tout.resize(n + 1);
  for (long long int i = (1); i < (n); i += (1)) {
    long long int a, b;
    cin >> a;
    cin >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
}
void dfs(long long int node, long long int par) {
  visited[node] = 1;
  parent[node] = par;
  tin[node] = timer++;
  for (auto child : graph[node]) {
    if (!visited[child]) {
      dfs(child, node);
    }
  }
  tout[node] = timer++;
}
bool solve_query(long long int arr[]) {
  long long int deepest = -1, depth = -1;
  for (long long int i = (0); i < (k); i += (1)) {
    arr[i] = parent[arr[i]];
    if (tin[arr[i]] > depth) {
      depth = tin[arr[i]];
      deepest = arr[i];
    }
  }
  for (long long int i = (0); i < (k); i += (1)) {
    long long int x = arr[i];
    if (!(tin[x] <= tin[deepest] && tout[x] >= tout[deepest])) return false;
  }
  return true;
}
void preocess_queries() {
  for (long long int i = (0); i < (q); i += (1)) {
    cin >> k;
    long long int arr[k];
    for (long long int j = (0); j < (k); j += (1)) cin >> arr[j];
    if (solve_query(arr))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int32_t main() {
  scan_and_memset();
  dfs(1, 1);
  preocess_queries();
}
