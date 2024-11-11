#include <bits/stdc++.h>
using namespace std;
void flash() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  flash();
  long long int n, m;
  cin >> n >> m;
  vector<long long int> a(n), b(m);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < m; i++) cin >> b[i];
  vector<long long int> ans;
  for (long long int i = 0; i < n; i++) {
    long long int cur = -1000000000000000000 - 179;
    for (long long int j = 0; j < n; j++) {
      if (i != j) {
        for (long long int k = 0; k < m; k++) {
          cur = max(cur, a[j] * b[k]);
        }
      }
    }
    ans.push_back(cur);
  }
  sort(ans.begin(), ans.end());
  cout << ans[0] << '\n';
  return 0;
}
