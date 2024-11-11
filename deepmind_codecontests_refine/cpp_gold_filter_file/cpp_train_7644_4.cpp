#include <bits/stdc++.h>
using namespace std;
long long a[1003][1003], b[1003][1003], c[1003][1003], d[1003][1003],
    mat[1003][1003];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> mat[i][j];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      a[i][j] = max(a[i - 1][j], a[i][j - 1]) + mat[i][j];
    }
  }
  for (i = n; i >= 1; i--) {
    for (j = m; j >= 1; j--) {
      b[i][j] = max(b[i + 1][j], b[i][j + 1]) + mat[i][j];
    }
  }
  for (i = n; i >= 1; i--) {
    for (j = 1; j <= m; j++) {
      c[i][j] = max(c[i + 1][j], c[i][j - 1]) + mat[i][j];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = m; j >= 1; j--) {
      d[i][j] = max(d[i][j + 1], d[i - 1][j]) + mat[i][j];
    }
  }
  long long ans = 0;
  for (i = 2; i < n; i++) {
    for (j = 2; j < m; j++) {
      long long maxi = a[i - 1][j] + b[i + 1][j] + c[i][j - 1] + d[i][j + 1];
      long long maxi2 = a[i][j - 1] + b[i][j + 1] + c[i + 1][j] + d[i - 1][j];
      maxi = max(maxi, maxi2);
      ans = max(ans, maxi);
    }
  }
  cout << ans << '\n';
}
