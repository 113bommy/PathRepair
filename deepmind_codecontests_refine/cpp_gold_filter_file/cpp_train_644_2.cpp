#include <bits/stdc++.h>
using namespace std;
bool test_cases_exist = false;
void solve() {
  long long int i, j, n, m, pos, k, y, x, weigh, ans, sum, maxi, mini;
  long long int q;
  cin >> q >> x;
  vector<long long int> available(x, 0);
  ans = 0;
  while (q--) {
    cin >> k;
    k %= x;
    available[k]++;
    while (available[ans % x] > ans / x) ans++;
    cout << ans << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  if (test_cases_exist) cin >> t;
  while (t--) solve();
}
