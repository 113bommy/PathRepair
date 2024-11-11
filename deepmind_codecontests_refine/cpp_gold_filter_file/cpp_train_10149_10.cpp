#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const long long INF = LLONG_MAX;
long long a[2][501][501];
long long arr[501];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long n, m, b, modu;
  cin >> n >> m >> b >> modu;
  for (long long i = 0; i <= 1; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= b; k++) a[i][j][k] = 0;
    }
  }
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  a[0][0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      for (long long k = 0; k <= b; k++) {
        if (k - arr[i] >= 0) {
          a[1][j][k] = (a[1][j][k] + a[0][j - 1][k - arr[i]]);
          a[1][j][k] = (a[1][j][k] + a[1][j - 1][k - arr[i]]) % modu;
        }
      }
    }
    for (long long j = 1; j <= m; j++) {
      for (long long k = 0; k <= b; k++) {
        a[0][j][k] = (a[1][j][k] + a[0][j][k]) % modu;
        a[1][j][k] = 0;
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i <= b; i++) {
    ans = (ans + a[0][m][i]) % modu;
  }
  cout << ans % modu << endl;
  return 0;
}
