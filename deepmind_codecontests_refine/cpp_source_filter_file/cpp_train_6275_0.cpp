#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, ans = INT_MAX;
    cin >> n;
    for (int x = 1; x * x <= n; ++x) {
      ans = min(ans, x - 1 + ((n - x) / x));
    }
    cout << ans << "\n";
  }
}
