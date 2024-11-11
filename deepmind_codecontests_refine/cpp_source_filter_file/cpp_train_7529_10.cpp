#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int j = 0; j < n; j++)
    for (int i = 0; i < n; i++) cin >> a[i][j];
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    ans += a[x][y];
    x++;
    y++;
  }
  x = n;
  y = n;
  for (int i = 0; i < n; i++) {
    x--;
    y--;
    ans += a[x][y];
  }
  for (int i = 0; i < n; i++) {
    ans += a[i][(n - 1) / 2];
    ans += a[(n - 1) / 2][i];
  }
  ans -= 3 * a[(n - 1) / 2][(n - 1) / 2];
  cout << ans << endl;
}
