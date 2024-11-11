#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  vector<long long> v(n), t(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  for (long long i = 0; i < n; i++) cin >> t[i];
  vector<long long> prefT(n), prefV(n);
  partial_sum(t.begin(), t.end(), prefT.begin());
  partial_sum(v.begin(), v.end(), prefV.begin());
  vector<long long> dayX(n);
  vector<vector<long long>> del_snow(n + 1, vector<long long>());
  for (long long i = 0; i < n; i++) {
    dayX[i] = lower_bound(prefT.begin(), prefT.end(),
                          (i == 0 ? 0 : prefT[i - 1]) + v[i]) -
              prefT.begin();
    del_snow[dayX[i]].push_back(i);
  }
  set<long long> cur;
  for (long long i = 0; i < n; i++) {
    cur.insert(i);
    long long ans = 0;
    for (long long j = 0; j < del_snow[i].size(); j++) {
      long long k = del_snow[i][j];
      ans += v[k] - ((i == 0 ? 0 : prefT[i - 1]) - (k == 0 ? 0 : prefT[k - 1]));
      cur.erase(k);
    }
    ans += cur.size() * t[i];
    cout << ans << ' ';
  }
}
