#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, N = 5e5 + 10;
const long long LINF = LLONG_MAX;
long long ans[200][200];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, h;
  cin >> n >> m >> h;
  long long a[m];
  long long b[n];
  long long H[n][m];
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (long long j = 0; j < n; j++) {
    cin >> b[j];
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> H[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (H[i][j] != 0) {
        ans[i][j] = min({a[j], b[i]});
      }
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
