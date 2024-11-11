#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, ans = 0;
  string second;
  char prev = 'A';
  cin >> n >> k >> second;
  sort(second.begin(), second.end());
  for (auto& i : second) {
    if (i > prev + 1) {
      ans += i - 'a' + 1, prev = i;
      k--;
    }
    if (k == 0) break;
  }
  if (k)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
