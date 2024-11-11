#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, w[51], ans = 0, mx = INT_MIN, mp[51];
  cin >> n;
  for (long long int i = 0; i <= 50; i++) mp[i] = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> w[i];
    mp[w[i]]++;
  }
  for (long long int i = 1; i <= 50; i++) {
    ans = 0;
    for (long long int j = 1; j < i; j++) {
      if (j == (i - j)) {
        ans += (mp[j] / 2);
        break;
      } else if ((i - j) > j) {
        ans += min(mp[j], mp[i - j]);
      }
    }
    if (mx < ans) mx = ans;
  }
  cout << mx << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
