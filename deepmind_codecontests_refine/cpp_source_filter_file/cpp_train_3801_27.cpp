#include <bits/stdc++.h>
using namespace std;
const long long M = 3e5 + 7, mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  {
    long long x;
    cin >> x;
    vector<pair<long long, long long>> v;
    for (long long i = 1;; i++) {
      long long y = (i * (i + 1) * (2 * i + 1)) / 6;
      if (x < y) break;
      long long temp = x - y;
      long long t1 = i, t2 = (i + 1);
      if (t1 % 2 == 0)
        t1 /= 2;
      else
        t2 /= 2;
      if (temp % t1 != 0 && temp % t2 != 0) continue;
      temp /= t1;
      temp /= t2;
      long long j = i + temp;
      v.push_back({i, j});
      if (i != j) v.push_back({j, i});
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (auto u : v) cout << u.first << " " << u.second << "\n";
  }
  return 0;
}
