#include <bits/stdc++.h>
using namespace std;
int lim = 1000000 + 100;
int mod = 1000000000 + 7;
int inf = 1000000000;
long long int M = 1000000000000000000 + 10000000;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    if (k >= m - 1) {
      for (int i = 0; i < m; i++) {
        ans = max(ans, a[i + 1]);
        ans = max(ans, a[n - i]);
      }
    } else {
      for (int i = 0; i <= k; i++) {
        int res = lim;
        for (int j = 0; j < m - k; j++) {
          int x = max(a[i + j + 1], a[n - m + i + j + 1]);
          res = min(res, x);
        }
        ans = max(ans, res);
      }
    }
    cout << ans << "\n";
  }
}
