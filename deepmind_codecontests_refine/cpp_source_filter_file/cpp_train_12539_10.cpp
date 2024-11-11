#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> a[1000 * 100 + 1000];
bool r[1000 * 100 + 1000];
bool h[1000 * 100 + 1000];
vector<int> ans;
bool mark[1000 * 100 + 1000];
void dfs(int v) {
  mark[v] = true;
  ans.push_back(v + 1);
  for (int i = 0; i < a[v].size(); i++) {
    if (!mark[a[v][i]]) {
      int u = a[v][i];
      h[u] = !h[u];
      dfs(u);
      ans.push_back(v + 1);
      h[v] = !h[v];
      if (h[u] != r[u]) {
        ans.push_back(u + 1);
        ans.push_back(v + 1);
        h[v] = !h[v];
      }
    }
  }
}
int main() {
  cin >> n >> m;
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    x--;
    y--;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  int st = -1;
  for (int i = 0; i < n; i++) {
    cin >> r[i];
    if (r[i] == 1) st = i;
  }
  if (st == -1) {
    cout << 0;
    return 0;
  }
  h[st] = 1;
  dfs(st);
  for (int i = 0; i < n; i++) {
    if (!mark[i] && r[i] != 0) return cout << -1, 0;
  }
  if (h[0] != r[0]) ans.pop_back();
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}
