#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> ans;
    vector<long long> a(n + 1, 0);
    for (int i = 0; i < m; i++) {
      int u, v;
      long long d;
      cin >> u >> v >> d;
      a[u] -= d;
      a[v] += d;
    }
    vector<int> pos, neg;
    for (int i = 1; i <= n; i++) {
      if (a[i] > 0)
        pos.push_back(i);
      else if (a[i] < 0)
        neg.push_back(i);
    }
    int j = 0;
    for (int i = 0; i < neg.size(); i++) {
      while (a[neg[i]] < 0) {
        long long mn = min(abs(a[neg[i]]), a[pos[j]]);
        ans.push_back({neg[i], pos[i], mn});
        a[neg[i]] += mn;
        a[pos[i]] -= mn;
        if (a[pos[i]] == 0) j++;
      }
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x[0] << " " << x[1] << " " << x[2] << endl;
  }
  return 0;
}
