#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<long long, pair<long long, long long> > mp;
signed main() {
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> b(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  for (long long i = 0; i < n; ++i) cin >> b[i];
  for (long long i = 0; i < n; ++i) {
    mp[a[i]].second++;
    mp[a[i]].first += b[i];
  }
  vector<long long> v1;
  vector<pair<long long, long long> > v2;
  long long res = 0;
  for (auto i : mp) {
    if (i.second.second > 1) {
      v1.push_back(i.first);
      res += i.second.first;
    } else {
      v2.push_back({i.first, i.second.first});
    }
  }
  for (long long i = 0; i < v2.size(); ++i) {
    bool good = false;
    for (long long j = 0; j < v1.size(); ++j) {
      if ((v1[j] | v2[i].first) == v1[j]) {
        good = true;
        break;
      }
    }
    if (good) res += v2[i].second;
  }
  cout << res;
  return 0;
}
