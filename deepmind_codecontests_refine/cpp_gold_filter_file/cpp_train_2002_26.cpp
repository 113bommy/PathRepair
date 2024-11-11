#include <bits/stdc++.h>
using namespace std;
int q[555][555], a[555][555];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (long long i = (1); i < (n + 1); i++) {
    string w;
    cin >> w;
    for (long long j = (1); j < (m + 1); j++) q[i][j] = w[j - 1] - '0';
  }
  for (long long i = (1); i < (n + 1); i++)
    for (long long j = (1); j < (m + 1); j++)
      a[i][j] = q[i][j] & q[i - 1][j] & q[i + 1][j] & q[i][j + 1] & q[i][j - 1];
  for (long long i = (1); i < (m + 1); i++)
    for (long long j = (1); j < (n); j++) a[j][i] += a[j - 1][i];
  long long ans = 0;
  for (long long i = (1); i < (n + 1); i++) {
    for (long long j = (i + 2); j < (n + 1); j++) {
      int l = 1, r = 2, s = 0;
      while (r < m) {
        while (r < m && s < k) s += a[j - 1][r] - a[i][r++];
        while (l < r && s >= k) {
          s -= a[j - 1][++l] - a[i][l];
          ans += m - r + 1;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
