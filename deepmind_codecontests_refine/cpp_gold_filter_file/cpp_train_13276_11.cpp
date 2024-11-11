#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
bool used[100001];
int ver = 0, edge = 0;
void read_graph(int m) {
  int v1, v2;
  for (int i = 0; i < m; i++) {
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }
}
void dfs(int v) {
  used[v] = true;
  ver++;
  for (auto to : graph[v]) {
    edge++;
    if (!used[to]) dfs(to);
  }
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, i, j, ans = 0, temp;
  cin >> n >> m;
  read_graph(m);
  for (i = 1; i <= n; i++) {
    ver = 0;
    edge = 0;
    if (!used[i]) dfs(i);
    if (edge / 2 == ver - 1) ans++;
  }
  cout << ans;
}
