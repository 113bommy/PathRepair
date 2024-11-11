#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
long long a[MAXN];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = (1); i <= ((n)); ++i) cin >> a[i];
  long long ans = -0x3f3f3f3f3f3f;
  for (long long i = max(n - k - 1, 1); i <= n; ++i) {
    for (long long j = i + 1; j <= n; ++j) {
      ans = max(ans, i * j - k * (a[i] | a[j]));
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
