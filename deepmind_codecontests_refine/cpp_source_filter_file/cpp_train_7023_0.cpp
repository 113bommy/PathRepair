#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  char c[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> c[i][j];
  int i;
  for (i = 0; i + 1 < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] < c[i + 1][j])
        break;
      else if (c[i][j] > c[i + 1][j]) {
        for (int k = 0; k < n; k++) c[k][j] = '0';
        i = 0;
        break;
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < m; j++)
    if (c[n - 1][j] == '0') {
      ans++;
    }
  cout << ans;
}
