#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 5;
vector<int> g[N];
vector<int> visited(N, 0);
bool isCycle;
bool unary;
void dfs(int v, int p) {
  if (visited[v]) {
    isCycle = true;
    return;
  }
  visited[v] = 1;
  int cnt = 0;
  for (auto u : g[v]) {
    if (u != p) {
      cnt++;
      dfs(u, v);
    }
  }
  if (p != -1 && cnt > 1) {
    unary = false;
  }
  if (p == -1 && cnt > 2) {
    unary = false;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      isCycle = false;
      unary = true;
      dfs(i, -1);
      if (isCycle && unary) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}
