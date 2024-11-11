#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  unordered_map<long long int, long long int> mp;
  cin >> n >> m;
  long long int a[n], b[n];
  unordered_set<long long int> s;
  long long int ans;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < n; i++) cin >> b[i], mp[b[i]]++;
  sort(a, a + n);
  sort(b, b + n);
  for (long long int i = 0; i < n; i++) s.insert((b[i] - a[0] + m) % m);
  for (auto it : s) {
    long long int cnt = 0;
    for (long long int i = 0; i < n; ++i) {
      if (mp[(a[i] + (long long int)it) % m] > 0)
        mp[(a[i] + (long long int)it) % m]--, cnt++;
      else
        break;
    }
    if (cnt == n) {
      ans = it;
      break;
    }
    mp.clear();
    for (long long int i = 0; i < n; i++) mp[b[i]]++;
  }
  cout << ans;
  return 0;
}
