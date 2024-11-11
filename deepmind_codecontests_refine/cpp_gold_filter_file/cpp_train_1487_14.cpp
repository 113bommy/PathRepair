#include <bits/stdc++.h>
using namespace std;
int const MAXN = 2e6 + 9;
int ans[MAXN];
vector<int> g[MAXN];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
      g[i].clear();
      ans[i] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      g[x].push_back(i);
    }
    for (int i = 0; i <= n; i++) {
      g[i].push_back(n + 1);
    }
    for (int i = 1; i <= n; i++) {
      if ((int)g[i].size() == 1) continue;
      int d = g[i][0];
      for (int j = 1; j < (int)g[i].size(); j++) {
        d = max(d, g[i][j] - g[i][j - 1]);
      }
      ans[d] = min(ans[d], i);
    }
    for (int i = 1; i <= n; i++) {
      ans[i] = min(ans[i], ans[i - 1]);
      if (ans[i] == 1e9)
        cout << -1 << " ";
      else
        cout << ans[i] << " ";
    }
    cout << '\n';
  }
}
