#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &it : v) cin >> it;
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (i + 1 != n)
      if (v[i + 1] < v[i]) ans += v[i] - v[i + 1];
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
