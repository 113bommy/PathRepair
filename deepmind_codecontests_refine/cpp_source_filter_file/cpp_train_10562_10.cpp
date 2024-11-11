#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<long double> > &graph, vector<long double> &vis,
         long long n) {
  for (long long i = 0; i < graph[n].size(); i++) {
    if (!vis[graph[n][i]]) {
      vis[graph[n][i]] = 1;
      dfs(graph, vis, graph[n][i]);
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  string na, ma;
  cin >> na >> ma;
  vector<vector<long double> > graph(n * m);
  for (long long i = 0; i < n * m; i++) {
    long long r = i / m, c = i % n;
    if (na[r] == '>') {
      if (c + 1 < m) graph[i].push_back(i + 1);
    } else {
      if (c > 0) graph[i].push_back(i - 1);
    }
    if (ma[c] == '^') {
      if (r > 0) graph[i].push_back(i - m);
    } else {
      if (r < n - 1) graph[i].push_back(i + m);
    }
  }
  for (long long i = 0; i < n * m; i++) {
    vector<long double> vis(n * m, 0);
    vis[i] = 1;
    dfs(graph, vis, i);
    for (long long j = 0; j < n * m; j++) {
      if (vis[j] == 0) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
