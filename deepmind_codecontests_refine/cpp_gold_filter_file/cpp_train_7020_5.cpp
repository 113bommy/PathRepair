#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int init[N], goal[N];
bool vis[N];
vector<int> G[N], v;
void dfs(int node, int lvl, int odd, int even) {
  vis[node] = true;
  if (odd || even) {
    if (lvl & 1)
      if (odd & 1) goal[node] ^= 1;
    if (!(lvl & 1))
      if (even & 1) goal[node] ^= 1;
  }
  if (init[node] != goal[node]) {
    goal[node] ^= 1;
    if (lvl & 1)
      odd++;
    else
      even++;
    v.push_back(node);
  }
  for (auto x : G[node])
    if (!vis[x]) dfs(x, lvl + 1, odd, even);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n - 1); ++i) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  for (int i = 1; i < (int)(n + 1); ++i) cin >> init[i];
  for (int i = 1; i < (int)(n + 1); ++i) cin >> goal[i];
  dfs(1, 0, 0, 0);
  cout << (int)v.size() << endl;
  for (auto x : v) cout << x << " ";
}
