#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) solve();
}
void solve() {
  int n, m;
  int ans = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char o;
      cin >> o;
      if (o == 'C') continue;
      if (i == n && o == 'D') ans++;
      if (j == m && o == 'R') ans++;
    }
  }
  cout << ans << "\n";
}
