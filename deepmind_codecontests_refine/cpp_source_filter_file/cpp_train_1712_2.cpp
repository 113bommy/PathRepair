#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
set<long long> ch[100005];
vector<long long> adj[100005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j, k, l, m, n, t, r, cnt;
  long long flag = 0;
  long long ans = 0, an = 0;
  t = 1;
  while (t--) {
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
      cin >> a[i];
    }
    for (i = 2; i <= m; i++) {
      ans = ans + abs(a[i] - a[i - 1]);
    }
    if (m == 1) {
      cout << "0" << endl;
      continue;
    }
    if (a[2] != a[1]) {
      adj[a[1]].push_back(a[1]);
    }
    for (i = 2; i <= m - 1; i++) {
      if (a[i - 1] != a[i]) {
        adj[a[i]].push_back(a[i - 1]);
      }
      if (a[i + 1] != a[i]) {
        adj[a[i]].push_back(a[i + 1]);
      }
    }
    if (a[m - 1] != a[m]) {
      adj[a[m]].push_back(a[m - 1]);
    }
    long long ans1 = ans;
    for (i = 1; i <= n; i++) {
      if (!(long long)adj[i].size()) continue;
      an = 0;
      for (long long it : adj[i]) {
        an = an - abs(it - i);
      }
      sort(adj[i].begin(), adj[i].end());
      long long y, nn = adj[i].size();
      if (nn & 1) {
        y = adj[i][nn / 2];
      } else {
        y = (adj[i][nn / 2] + adj[i][nn / 2 - 1]) / 2;
      }
      for (long long it : adj[i]) {
        an = an + abs(y - it);
      }
      ans = min(ans, ans1 + an);
    }
    cout << ans << endl;
  }
}
