#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
int n, m;
vector<int> edge[N];
int vis[N];
long long cc, e;
void dfs(int u) {
  vis[u] = 1;
  e++;
  cc += edge[u].size();
  for (int j = 0; j < edge[u].size(); j++) {
    int v = edge[u][j];
    if (!vis[v]) {
      dfs(v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cc = 0;
      e = 0;
      dfs(i);
      cc /= 2;
      if (cc != e * (e - 1) / 2) {
        cout << "NO"
             << "\n";
        return 0;
      }
    }
  }
  cout << "YES"
       << "\n";
  return 0;
}
