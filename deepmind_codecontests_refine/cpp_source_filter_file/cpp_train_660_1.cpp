#include <bits/stdc++.h>
using namespace std;
const int N = 1E6 + 7;
const int INF = 1E9;
vector<int> res;
vector<int> adj[N];
int parent[N];
int n, m, k;
int f[N];
void DFS(int u) {
  for (auto v : adj[u])
    if (parent[v] == 0) {
      f[v] = f[u] + 1;
      parent[v] = u;
      DFS(v);
    }
}
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  parent[1] = -1;
  DFS(1);
  for (int u = 2; u <= n; ++u) {
    for (auto v : adj[u])
      if (parent[u] != v && f[v] < f[u]) {
        int len = f[u] - f[v] + 1;
        if (len <= k + 1) {
          int v_2 = u;
          cout << len << "\n";
          while (v_2 != v) {
            cout << v_2 << " ";
            v_2 = parent[v_2];
          }
          return cout << v, 0;
        }
      }
  }
}
