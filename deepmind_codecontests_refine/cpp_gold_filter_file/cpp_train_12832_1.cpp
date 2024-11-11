#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double pi = acos(-1);
vector<long long> ft(1, 1LL);
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  sort(v.begin(), v.end());
  int ma = v[n - 1] + v[n - 2];
  int ans = 0;
  for (long long sum = 0; sum < ma + 1; sum++) {
    vector<int> taken(n, 0);
    int temp = 0;
    for (long long i = 0; i < n; i++) {
      if (taken[i]) continue;
      for (long long j = i + 1; j < n; j++) {
        if (taken[j]) continue;
        if (v[i] + v[j] == sum) {
          temp++;
          taken[j] = 1;
          break;
        }
      }
    }
    ans = max(ans, temp);
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
