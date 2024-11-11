#include <bits/stdc++.h>
using namespace std;
vector<int> tree[100010], res;
int n, a, b, init[100010], goal[100010], vis[100010];
void dfs(int node, int level, int flip) {
  vis[node] = 1;
  if (flip & (1 << (level & 1))) init[node] ^= 1;
  if (init[node] != goal[node]) {
    res.push_back(node);
    init[node] = goal[node];
    flip ^= (1 << (level & 1));
  }
  for (int i = 0; i < (int)tree[node].size(); i++) {
    int v = tree[node][i];
    if (!vis[v]) dfs(v, ++level, flip);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) cin >> init[i];
  for (int i = 1; i <= n; i++) cin >> goal[i];
  memset(vis, 0, sizeof(vis));
  dfs(1, 0, 0);
  cout << res.size() << endl;
  for (int i = 0; i < (int)res.size(); i++) cout << res[i] << endl;
}
