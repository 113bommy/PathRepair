#include <bits/stdc++.h>
using namespace std;
long long visited[1500005] = {0};
vector<long long> adj[1500005];
long long n, m, edge, el;
void dfs(long long v) {
  visited[v] = 1;
  el++;
  edge += (adj[v].size());
  for (auto i : adj[v]) {
    if (!visited[i]) dfs(i);
  }
}
int main() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (long long i = 1; i <= n; i++) {
    if (!visited[i]) {
      edge = 0;
      el = 0;
      dfs(i);
      if (el > 2 && (edge != ((el) * (el - 1)))) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
}
