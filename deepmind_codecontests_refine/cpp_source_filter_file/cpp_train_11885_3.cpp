#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long r, n;
  while (cin >> r >> n) {
    vector<long long> v;
    map<pair<long long, long long>, long long> mp;
    map<long long, long long> cnt;
    for (long long i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      if (x > y) swap(x, y);
      mp[make_pair(x, y)]++;
      if (!cnt[x]) v.push_back(x);
      if (!cnt[y]) v.push_back(y);
      cnt[x]++;
      cnt[y]++;
    }
    long long l = v.size();
    long long ok = 0;
    for (long long i = 0; i < 2; i++) {
      for (long long j = 2; j < l; j++) {
        long long x = v[i];
        long long y = v[j];
        if (x > y) swap(x, y);
        if (cnt[v[i]] + cnt[v[j]] - mp[make_pair(x, y)] == n) {
          ok = 1;
          break;
        }
      }
    }
    if (ok || l == 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
