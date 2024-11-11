#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k, d;
  cin >> n >> k >> d;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = n;
  for (int i = 0; i <= n - d; i++) {
    set<int> s;
    for (int j = 0; j < d; j++) {
      s.emplace(a[i + j]);
    }
    ans = min(ans, (int)s.size());
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
