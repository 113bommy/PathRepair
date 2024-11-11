#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < m; i++)
    if (a[i] < 0) ans += abs(a[i]);
  cout << ans;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}
