#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<vector<char>>> a(
      5, vector<vector<char>>(n + 1, vector<char>(n + 1)));
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) cin >> a[i][j][k];
    }
  }
  int ans = 200;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      if (i == j) continue;
      for (int k = 1; k <= 4; k++) {
        if (i == k || j == k) continue;
        for (int p = 1; p <= 4; p++) {
          if (i == p || j == p || k == p) continue;
          vector<vector<int>> b(2 * n + 1, vector<int>(2 * n + 1));
          for (int m = 1; m <= n; m++) {
            for (int y = 1; y <= n; y++) {
              b[m][y] = (a[i][m][y] - '0');
              b[m + n][y] = (a[k][m][y] - '0');
              b[m][y + n] = (a[j][m][y] - '0');
              b[m + n][y + n] = (a[p][m][y] - '0');
            }
          }
          int t_ans = 0, st;
          for (int m = 1; m <= 2 * n; m++) {
            st = m % 2;
            for (int y = 1; y <= 2 * n; y++) {
              if (b[m][y] != st) {
                t_ans++;
              }
              st = !st;
            }
          }
          ans = min(ans, t_ans);
          for (int m = 1; m <= 2 * n; m++) {
            st = (m - 1) % 2;
            for (int y = 1; y <= 2 * n; y++) {
              if (b[m][y] != st) {
                t_ans++;
              }
              st = !st;
            }
          }
          ans = min(ans, t_ans);
        }
      }
    }
  }
  cout << ans;
  return 0;
}
