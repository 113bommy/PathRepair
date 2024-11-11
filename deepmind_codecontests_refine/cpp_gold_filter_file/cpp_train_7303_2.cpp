#include <bits/stdc++.h>
using namespace std;
int mx = -1;
bool vis[200000];
vector<int> edge[200000];
void dfs(int n, int cnt) {
  vis[n] = 1;
  for (int i = 0; i < edge[n].size(); i++) {
    if (!vis[edge[n][i]]) {
      dfs(edge[n][i], 1 + cnt);
    }
  }
  mx = max(mx, cnt);
}
int main() {
  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (arr[i] == -1) continue;
    edge[i].push_back(arr[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i] == -1) continue;
    memset(vis, 0, sizeof vis);
    dfs(i, 1);
  }
  cout << max(mx, 1) << endl;
  return 0;
}
