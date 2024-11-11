#include <bits/stdc++.h>
using namespace std;
typedef struct fair {
  int p[101] = {};
  int c = 0;
} node;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vector<int> z(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> z[i];
  }
  vector<int> adj[n + 1];
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> ans(n + 1);
  vector<node> ok(n + 1);
  for (int i = 1; i <= n; i++) {
    ok[i].p[z[i]] = 1;
    ok[i].c++;
  }
  for (int _ = 1; _ <= k + 1; _++) {
    for (int i = 1; i <= n; i++) {
      for (int &it : adj[i]) {
        if (ok[i].c >= s) {
          break;
        }
        for (int j = 1; j <= k; j++) {
          if (ok[i].c >= s) {
            break;
          }
          if (ok[i].p[j] == 0 && ok[it].p[j] == _) {
            ok[i].c++;
            ok[i].p[j] = _ + 1;
            ans[i] += _;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
