#include <bits/stdc++.h>
using namespace std;
int n, m, a[55][55], b[55][55], x, y;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
      if (a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!(a[i][j] > a[i - 1][j] && a[i][j] > a[i][j - 1] &&
            b[i][j] > b[i - 1][j] && b[i][j] > b[i][j - 1])) {
        cout << "Impossible";
        return 0;
      }
    }
  }
  cout << "Possible";
  return 0;
}
