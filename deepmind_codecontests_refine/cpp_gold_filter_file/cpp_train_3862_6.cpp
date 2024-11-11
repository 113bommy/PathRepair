#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<long long int>>& edges, long long int n,
         vector<long long int>& no_of_child, vector<long long int>& dfslist,
         long long int u, vector<bool>& visited) {
  visited[u] = true;
  dfslist.push_back(u);
  no_of_child[u]++;
  for (long long int v : edges[u]) {
    if (visited[v] == false) {
      dfs(edges, n, no_of_child, dfslist, v, visited);
      no_of_child[u] += no_of_child[v];
    }
  }
}
int main() {
  long long int n, q;
  cin >> n >> q;
  vector<long long int> ar(n - 1);
  for (long long int x = 0; x < n - 1; x++) {
    cin >> ar[x];
    ar[x]--;
  }
  vector<vector<long long int>> edges(n);
  for (long long int x = 0; x < n - 1; x++) {
    edges[ar[x]].push_back(x + 1);
    edges[x + 1].push_back(ar[x]);
  }
  vector<long long int> dfslist;
  vector<long long int> no_of_child(n, 0);
  vector<bool> visited(n, false);
  dfs(edges, n, no_of_child, dfslist, 0, visited);
  vector<long long int> getindex(n);
  for (long long int x = 0; x < n; x++) {
    getindex[dfslist[x]] = x;
  }
  while (q--) {
    long long int u, k;
    cin >> u >> k;
    u--;
    if (no_of_child[u] >= k) {
      long long int i = getindex[u];
      cout << dfslist[i + k - 1] + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
