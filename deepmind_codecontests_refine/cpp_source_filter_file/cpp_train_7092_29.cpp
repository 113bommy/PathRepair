#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
vector<int> g[N], comp;
int vis[N];
void dfs(int u) {
  vis[u] = true;
  for (auto v : g[u])
    if (!vis[v]) dfs(v);
  comp.push_back(u);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    bool flag = true;
    while (w) {
      if (w % 10 == 4 || w % 10 == 7) {
        w /= 10;
        continue;
      } else {
        flag = false;
        break;
      }
      w /= 10;
    }
    if (flag == false) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      comp.clear();
      dfs(i);
      ans += (comp.size()) * (n - comp.size()) * (n - comp.size() - 1);
    }
  cout << ans << "\n";
}
