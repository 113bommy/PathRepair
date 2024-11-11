#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5;
void solve() {
  long long int ans = 0, n, i, j, k;
  string s;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      vector<long long int> a(26, 0);
      long long int cnt = 0;
      for (k = i; k <= j; k++) {
        if (s[k] >= 'A' && s[k] <= 'Z') {
          cnt = 0;
          break;
        }
        if (a[s[k] - 'a'] == 0) {
          cnt++;
        }
        a[s[k] - 'a']++;
      }
      ans = max(ans, cnt);
    }
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
