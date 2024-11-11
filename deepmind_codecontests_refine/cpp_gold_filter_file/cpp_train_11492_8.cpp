#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 22;
int n, m, par[maxn];
vector<int> G[maxn];
bool vis[maxn];
inline void DFS(int st) {
  vis[st] = true;
  for (int i = 0; i < G[st].size(); i++)
    if (!vis[G[st][i]]) DFS(G[st][i]);
}
int main() {
  int ans = 0, f = 0;
  cin >> n >> m;
  for (int i = 0; i < 322; i++) par[i] = i;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    f += k;
    for (int j = 0; j < k; j++) {
      int t;
      cin >> t;
      G[i].push_back(t + 100);
      G[t + 100].push_back(i);
    }
  }
  if (f == 0) {
    cout << n << endl;
    return 0;
  }
  DFS(1);
  for (int i = 1; i <= n; i++)
    if (!vis[i]) {
      DFS(i);
      ans++;
    }
  cout << ans << endl;
  return 0;
}
