#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
long long mod = 998244353;
const int MAXN = 200005;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int d = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (d * a[i] > d * a[i - 1] && d * a[i] > d * a[i + 1]) {
        ans += d * a[i];
        d = -d;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
