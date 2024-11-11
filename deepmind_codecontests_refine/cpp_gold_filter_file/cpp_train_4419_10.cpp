#include <bits/stdc++.h>
using namespace std;
long long vis[1005];
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<pair<long long, pair<long long, long long> > > g;
  for (long long i = 1; i <= n; i++) {
    long long a, b;
    cin >> a >> b;
    g.push_back({b, {a, i}});
  }
  sort(g.rbegin(), g.rend());
  long long k;
  cin >> k;
  long long ans = 0;
  vector<pair<long long, long long> > arr, pos;
  for (long long i = 1; i <= k; i++) {
    long long c;
    cin >> c;
    arr.push_back({c, i});
  }
  sort(arr.begin(), arr.end());
  for (auto u : g) {
    long long a = u.first;
    long long b = u.second.first;
    long long c = u.second.second;
    for (auto G : arr) {
      long long e = G.first;
      long long f = G.second;
      if (vis[f] == 0 && b <= e) {
        ans += a;
        pos.push_back({c, f});
        vis[f] = 1;
        break;
      }
    }
  }
  cout << pos.size() << " " << ans << endl;
  for (auto u : pos) {
    cout << u.first << " " << u.second << endl;
  }
  return 0;
}
