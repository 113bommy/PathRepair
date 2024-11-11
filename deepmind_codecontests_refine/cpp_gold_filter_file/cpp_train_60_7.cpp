#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long a[100005], b[100005], p[100005], n;
vector<pair<long long, long long> > v[100005];
void dfs(long long x) {
  for (auto u : v[x]) {
    dfs(u.first);
    if (p[u.first] >= 0)
      p[x] += p[u.first];
    else {
      if (p[u.first] < -1e18 / u.second) {
        cout << "NO";
        exit(0);
      }
      p[x] += p[u.first] * u.second;
    }
    if (p[x] < -1e18) {
      cout << "NO";
      exit(0);
    }
  }
  p[x] += b[x] - a[x];
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> b[i];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long x, y;
  for (long long i = 2; i <= n; i++) {
    cin >> x >> y;
    v[x].emplace_back(make_pair(i, y));
  }
  dfs(1);
  if (p[1] >= 0) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
