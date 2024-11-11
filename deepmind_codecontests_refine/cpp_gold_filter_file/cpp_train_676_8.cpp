#include <bits/stdc++.h>
using namespace std;
int n, m, l, a[101][101][101];
int valid(int i, int j, int k) {
  return (i >= 1 && i <= n && j >= 1 && j <= m && k >= 1 && k <= l &&
          a[i][j][k] == 1);
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  int i, j, k, ans = 0;
  string s;
  cin >> n >> m >> l;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> s;
      s = " " + s;
      for (k = 1; k <= l; k++) a[i][j][k] = s[k] - '0';
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      for (k = 1; k <= l; k++) {
        if (!a[i][j][k]) continue;
        if (valid(i - 1, j, k) && valid(i + 1, j, k))
          ans++;
        else if (valid(i, j - 1, k) && valid(i, j + 1, k))
          ans++;
        else if (valid(i, j, k - 1) && valid(i, j, k + 1))
          ans++;
        else if (valid(i - 1, j, k) && valid(i, j + 1, k) &&
                 !valid(i - 1, j + 1, k))
          ans++;
        else if (valid(i - 1, j, k) && valid(i, j, k + 1) &&
                 !valid(i - 1, j, k + 1))
          ans++;
        else if (valid(i, j - 1, k) && valid(i + 1, j, k) &&
                 !valid(i + 1, j - 1, k))
          ans++;
        else if (valid(i, j - 1, k) && valid(i, j, k + 1) &&
                 !valid(i, j - 1, k + 1))
          ans++;
        else if (valid(i, j, k - 1) && valid(i + 1, j, k) &&
                 !valid(i + 1, j, k - 1))
          ans++;
        else if (valid(i, j, k - 1) && valid(i, j + 1, k) &&
                 !valid(i, j + 1, k - 1))
          ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
