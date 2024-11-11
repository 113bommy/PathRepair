#include <bits/stdc++.h>
using namespace std;
const long long N = 300010, M = 1005;
long long t, n, p[N], s[N], m, a[3][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> m;
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    s[n + 1] = 0;
    for (int i = 1; i <= m; i++) {
      p[i] = p[i - 1] + a[2][i];
    }
    for (int i = m; i >= 1; i--) {
      s[i] = s[i + 1] + a[1][i];
    }
    long long res = 2e18;
    for (int i = 1; i <= m; i++) {
      long long x = max(p[i - 1], s[i + 1]);
      res = min(res, x);
    }
    if (m == 1) res = 0;
    cout << res << "\n";
  }
  return 0;
}
