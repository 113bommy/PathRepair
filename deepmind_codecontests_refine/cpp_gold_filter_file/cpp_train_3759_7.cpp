#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, m, y;
  cin >> n >> y;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m >> y;
  vector<int> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  map<int, int> mp;
  int res = 2;
  for (long long len = 1ll; len <= 2000000000ll; len <<= 1ll) {
    mp.clear();
    for (int i = 0; i < n; i++) {
      mp[a[i] % (2ll * len)]++;
    }
    for (int i = 0; i < m; i++) {
      mp[(b[i] + len) % (2ll * len)]++;
    }
    int mx = 0;
    for (auto p : mp) {
      mx = max(mx, p.second);
    }
    res = max(res, mx);
  }
  cout << res;
  return 0;
}
