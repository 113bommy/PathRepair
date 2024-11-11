#include <bits/stdc++.h>
using namespace std;
long long a[300009], b[300009], dp[300009][5];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, i, n, j, k, ans;
  cin >> t;
  a[0] = -10;
  while (t--) {
    cin >> n;
    i = 1;
    while (i <= n) {
      cin >> a[i] >> b[i];
      i++;
    }
    i = 1;
    while (i <= n) {
      j = 0;
      while (j < 5) {
        ans = LLONG_MAX;
        k = 0;
        while (k < 5) {
          if (a[i] + j != a[i - 1] + k) ans = min(ans, dp[i - 1][k] + j * b[i]);
          k++;
        }
        dp[i][j] = ans;
        j++;
      }
      i++;
    }
    i = 0;
    ans = LLONG_MAX;
    while (i < 5) {
      ans = min(ans, dp[n][i]);
      i++;
    }
    cout << ans << "\n";
  }
}
