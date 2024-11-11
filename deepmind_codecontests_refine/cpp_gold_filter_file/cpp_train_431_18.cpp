#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 5;
const long long mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    n *= 3;
    bool used[n];
    for (long long i = 0; i < n; i++) used[i] = 0;
    vector<pair<long long, long long> > edg;
    for (long long i = 0; i < m; i++) {
      long long u, v;
      cin >> u >> v;
      edg.push_back({v - 1, u - 1});
    }
    vector<long long> ans;
    for (long long i = 0; i < m; i++) {
      if (!used[edg[i].first] && !used[edg[i].second]) {
        used[edg[i].first] = 1;
        used[edg[i].second] = 1;
        ans.push_back(i);
      }
    }
    if (ans.size() >= n / 3) {
      cout << "Matching\n";
      for (long long i = 0; i < n / 3; i++) cout << ans[i] + 1 << ' ';
    } else {
      cout << "IndSet\n";
      long long kek = 0;
      for (long long i = 0; i < n; i++) {
        if (!used[i]) {
          cout << i + 1 << ' ';
          kek++;
        }
        if (kek == n / 3) break;
      }
    }
    cout << '\n';
  }
  return 0;
}
