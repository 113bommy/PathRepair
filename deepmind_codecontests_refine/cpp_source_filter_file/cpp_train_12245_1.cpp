#include <bits/stdc++.h>
using namespace std;
int vis[100010], n, ans1, ans2, x, y;
vector<int> adj[100010];
void dfs(int i, int last = 1) {
  vis[i] = last;
  if (vis[i] == 1)
    ans1++;
  else
    ans2++;
  for (int j = 0; j < adj[i].size(); j++) {
    if (!vis[adj[i][j]]) dfs(adj[i][j], 3 - last);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  dfs(1);
  cout << (n * (n - 1) / 2 - (n - 1) - (ans1 * (ans1 - 1) / 2) -
           (ans2 * (ans2 - 1) / 2));
  return 0;
}
