#include <bits/stdc++.h>
using namespace std;
long long int mod = pow(10, 9) + 7;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    vector<long long int> v[n];
    for (long long int i = 0; i < n; i++) {
      long long int ki;
      cin >> ki;
      for (long long int j = 0; j < ki; j++) {
        long long int x;
        cin >> x;
        v[i].push_back(x + 1 - j);
      }
    }
    map<long long int, long long int> mp;
    for (long long int i = 0; i < n; i++) {
      long long int x = *max_element(v[i].begin(), v[i].end());
      mp[x] += v[i].size();
    }
    auto it = mp.begin();
    long long int ans = it->first;
    long long int covered = 0;
    long long int sumcovered = ans;
    for (auto x : mp) {
      if (x.first < sumcovered) {
        ans = x.first - covered;
        sumcovered = x.first;
      }
      sumcovered += x.second;
      covered += x.second;
    }
    cout << ans << '\n';
  }
  return 0;
}
