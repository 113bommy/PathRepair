#include <bits/stdc++.h>
using namespace std;
const long long hell = 1000000007;
const long long mod = 1000000007;
long long solve() {
  vector<long long> v[100001];
  vector<pair<long long, long long> > ans;
  long long n;
  cin >> n;
  long long mx = INT_MIN;
  for (long long i = 1; i < n + 1; i++) {
    long long tmp;
    cin >> tmp;
    v[tmp].push_back(i);
    mx = max(tmp, mx);
  }
  bool ok = 0;
  long long xxx, cnt = 0;
  for (long long i = 1; i < mx + 1; i++) {
    ok = 0;
    if ((long long)v[i].size() == 1) {
      ans.push_back({i, 0});
      cnt++;
    } else if (!v[i].empty()) {
      for (long long k = 0; k < (long long)v[i].size(); k++) {
        if (k == 0) {
          xxx = v[i][k + 1] - v[i][k];
        } else {
          if (v[i][k] - v[i][k - 1] != xxx) {
            ok = 1;
            break;
          }
        }
      }
      if (!ok) {
        ans.push_back({i, xxx});
        cnt++;
      }
    }
  }
  cout << cnt << '\n';
  for (auto it : ans) cout << it.first << " " << it.second << '\n';
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
