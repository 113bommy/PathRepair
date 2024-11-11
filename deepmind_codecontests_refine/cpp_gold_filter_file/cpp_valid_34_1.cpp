#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  long long int ans = -1e7, m1 = 0, m2 = INT_MAX;
  m1 = v[0];
  m2 = 1;
  for (long long int i = 1; i < n; i++) {
    long long int c = m2 * (i + 1) - k * (m1 | v[i]);
    ans = max(ans, c);
    long long int mm = (ans + (k) * (v[i])) / (i + 1);
    for (long long int j = i - 1; j >= mm - 1; j--) {
      if (j < 0) break;
      long long int c2 = (i + 1) * (j + 1) - k * (v[i] | v[j]);
      ans = max(ans, c2);
    }
    if (v[i] < m1) {
      m2 = i, m1 = v[i];
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
}
