#include <bits/stdc++.h>
using namespace std;
long long mod = 1e18;
int n, k, a[300300], sum, ans, hold;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans++;
    sum += min(a[i] + hold, 8);
    hold += max(0, a[i] + hold - 8);
    if (sum >= k) {
      cout << ans << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
