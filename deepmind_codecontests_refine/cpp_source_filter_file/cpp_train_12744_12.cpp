#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    int n, m;
    cin >> n >> m;
    string a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    int b[n][m];
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < m; j++) {
        if (a[i][j] == '1' && j > 0)
          b[i][j] = b[i - 1][j] + 1;
        else
          b[i][j] = a[i][j] - '0';
      }
    }
    int ans = 0;
    for (long long int i = 0; i < m; i++) {
      int c[n];
      for (long long int j = 0; j < n; j++) {
        c[j] = b[j][i];
      }
      sort(c, c + n);
      reverse(c, c + n);
      for (long long int j = 0; j < n; j++) {
        ans = max((long long)ans, c[j] * (j + 1));
      }
    }
    cout << ans;
  }
  return 0;
}
