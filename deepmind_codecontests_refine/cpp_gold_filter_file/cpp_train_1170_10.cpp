#include <bits/stdc++.h>
using namespace std;
using namespace std;
void solve() {
  long long n, m, a, b;
  cin >> n >> m >> a >> b;
  char ar[n][m];
  long long countk = 0, countf = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> ar[i][j];
      if (ar[i][j] == '.')
        countk++;
      else
        countf++;
    }
  }
  if (m == 1) {
    cout << countk * a << '\n';
    return;
  }
  if (2 * a < b) {
    cout << countk * a << '\n';
    return;
  } else {
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (ar[i][j] == '.') {
          long long count = 0;
          while (j < m && ar[i][j] == '.') {
            count++;
            j++;
          }
          long long tn = count / 2;
          long long rem = count % 2;
          ans += tn * b;
          ans += rem * a;
        }
      }
    }
    cout << ans << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
