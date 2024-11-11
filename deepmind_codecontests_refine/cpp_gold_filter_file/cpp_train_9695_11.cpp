#include <bits/stdc++.h>
const int N = 100001;
const long long mod = 1000000007;
using namespace std;
int T = 1;
int n, a[101], ans;
void solve() {
  ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i += 2) ans += a[i + 1] - a[i];
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  while (T--) {
    solve();
  }
  return 0;
}
