#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int MAX = (int)5e3 + 5;
int inf = (int)1e10;
int mod = (int)998244353;
int ans[MAX][MAX], val[MAX];
int main() {
  ios::sync_with_stdio(0);
  string s;
  int g = 0;
  int n;
  cin >> n;
  if (n == 3) {
    cout << 7 << " " << 8 << " " << 6 << "\n";
    cout << 2 << " " << 3 << " " << 5 << "\n";
    cout << 1 << " " << 4 << " " << 9 << "\n";
  } else if (n < 3) {
    cout << -1;
  } else {
    int cur = 1;
    for (int i = 1; i <= n - 2; i++) {
      if (i % 2 == 1) {
        for (int j = 1; j <= n; j++) {
          ans[i][j] = cur;
          cur++;
        }
      } else {
        for (int j = n; j > 0; j--) {
          ans[i][j] = cur;
          cur++;
        }
      }
    }
    if (n % 2 == 0) {
      int x = 1, y = n;
      ans[y][x] = cur++;
      x++;
      while (x != n) {
        ans[y][x] = cur++;
        if (x % 2 == 0 && y % 2 == 0)
          y--;
        else if (x % 2 == 0 && y % 2 == 1)
          x++;
        else if (x % 2 == 1 && y % 2 == 1)
          y++;
        else
          x++;
      }
      ans[n][n] = n * n;
      ans[n - 1][n] = n * n - 1;
      ans[n - 1][1] = n * n - 2;
    } else {
      ans[n - 1][n] = cur++;
      ans[n][n] = cur++;
      ans[n][n - 1] = cur++;
      int x = n - 2, y = n;
      while (x != 1) {
        ans[y][x] = cur++;
        if (x % 2 == 1 && y % 2 == 1)
          y--;
        else if (x % 2 == 1 && y % 2 == 0)
          x--;
        else if (x % 2 == 0 && y % 2 == 0)
          y++;
        else
          x--;
      }
      ans[n][1] = n * n;
      ans[n - 1][1] = n * n - 2;
      ans[n - 1][n - 1] = n * n - 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) cout << ans[i][j] << " ";
      cout << "\n";
    }
  }
  return 0;
}
