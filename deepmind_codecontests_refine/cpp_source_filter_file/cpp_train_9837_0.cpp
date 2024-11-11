#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[110][110] = {}, ans = 0, v;
  string s[110] = {};
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  memset(a, 0, sizeof(a));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (s[i][j] == 'W' && a[i][j] != 1 || s[i][j] == 'B' && a[i][j] != 0) {
        if (s[i][j] == 'W')
          v = 1 - a[i][j];
        else
          v = -a[i][j];
        for (int k = 0; k <= i; k++) {
          for (int l = 0; l <= j; l++) {
            a[k][l] += v;
          }
        }
        ans++;
      }
    }
  }
  cout << ans;
}
