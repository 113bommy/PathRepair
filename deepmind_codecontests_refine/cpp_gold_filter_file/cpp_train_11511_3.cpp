#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e18;
const long long int N = 1e6 + 20;
vector<long long int> g[N];
long long int vis[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tc = 1;
  while (tc--) {
    long long int n, curr, W;
    cin >> n >> curr >> W;
    vector<pair<long long int, long long int>> v;
    for (long long int i = 1; i < n; i++) {
      long long int t, w;
      cin >> t >> w;
      v.push_back({t, w});
    }
    multiset<long long int> ms;
    sort(v.begin(), v.end(), greater<pair<long long int, long long int>>());
    long long int ans = n;
    long long int idx = 0;
    while (1) {
      long long int i;
      for (i = idx; i < n - 1; i++) {
        if (v[i].first > curr) {
          ms.insert(v[i].second - v[i].first + 1);
        } else {
          break;
        }
      }
      idx = i;
      ans = min(ans, (long long int)ms.size() + 1);
      curr -= *ms.begin();
      if (curr < 0 || ms.empty()) {
        break;
      }
      ms.erase(ms.begin());
    }
    cout << ans << '\n';
  }
}
