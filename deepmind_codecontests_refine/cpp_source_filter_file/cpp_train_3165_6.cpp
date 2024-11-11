#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
vector<vector<int> > v(105);
pair<int, int> g[105];
int vis[105] = {0};
int z = 1;
void dfs(int k) {
  vis[k] = 1;
  for (int i = 1; i < z; i++) {
    if (vis[i])
      continue;
    else if (g[i].first < g[k].first && g[k].first < g[i].second)
      dfs(i);
    else if (g[i].first < g[k].second && g[k].first < g[i].second)
      dfs(i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int t, a, b;
  while (n--) {
    cin >> t >> a >> b;
    if (t == 1) {
      g[z].first = a;
      g[z].second = b;
      z++;
    } else {
      memset(vis, 0, sizeof vis);
      ;
      dfs(a);
      if (vis[b])
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
