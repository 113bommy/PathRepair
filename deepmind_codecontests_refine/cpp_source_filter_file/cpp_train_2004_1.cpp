#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 7;
long long t, n, m, a, b;
long long ans[N][N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m >> a >> b;
    if ((n * a) != (m * b))
      cout << "NO\n";
    else {
      for (long long i = 0; i < n; i++)
        for (long long j = 0; j < m; j++) ans[i][j] = 0;
      long long j = 0;
      long long tcnt = 0;
      while (tcnt < (n * a)) {
        for (long long i = 0; i < n; i++) {
          long long cnt = 0;
          while (cnt < b) {
            ans[i][j] = 1;
            j = (j + 1) % m;
            cnt++;
            tcnt++;
          }
        }
      }
      cout << "YES\n";
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) cout << ans[i][j];
        cout << "\n";
      }
    }
  }
  return 0;
}
