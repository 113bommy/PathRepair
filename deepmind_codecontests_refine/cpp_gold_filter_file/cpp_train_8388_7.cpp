#include <bits/stdc++.h>
using namespace std;
int vis[200005];
vector<int> v[200005];
long long nodes;
long long edges;
void DFS(int s) {
  vis[s] = 1;
  nodes++;
  edges += v[s].size();
  for (auto x : v[s]) {
    if (!vis[x]) DFS(x);
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    nodes = 0;
    edges = 0;
    if (!vis[i]) {
      DFS(i);
      edges /= 2;
      long long cur = nodes * (nodes - 1) / 2;
      if (edges != cur) return cout << "NO", 0;
    }
  }
  cout << "YES";
  return 0;
}
