#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> edge[N << 1];
bool vis[N];
int num = 0;
int cnt = 0;
void dfs(int u) {
  num++;
  vis[u] = true;
  cnt += edge[u].size();
  for (int i = 0; i < edge[u].size(); i++) {
    int v = edge[u][i];
    if (vis[v]) continue;
    dfs(v);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    num = 0;
    cnt = 0;
    dfs(i);
    cnt /= 2;
    if (cnt < num) ret++;
  }
  cout << ret << endl;
  return 0;
}
