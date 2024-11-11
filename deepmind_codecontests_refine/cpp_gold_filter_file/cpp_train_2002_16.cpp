#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
vector<vector<int>> grid(501, vector<int>(501));
vector<vector<int>> csg(501, vector<int>(501));
int n, m, k;
bool isStar(int i, int j) {
  if (i == 1 || j == 1 || i == n || j == m) return 0;
  return grid[i][j] && grid[i - 1][j] && grid[i + 1][j] && grid[i][j - 1] &&
         grid[i][j + 1];
}
int getCt(int i1, int j1, int i2, int j2) {
  if (i1 > i2 || j1 > j2 || i1 > n || j1 > m) return 0;
  return csg[i2][j2] - csg[i1 - 1][j2] - csg[i2][j1 - 1] + csg[i1 - 1][j1 - 1];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      grid[i][j] = s[j - 1] - '0';
    }
  }
  csg[1][1] = isStar(1, 1);
  for (int i = 2; i <= n; i++) {
    csg[i][1] = csg[i - 1][1] + isStar(i, 1);
  }
  for (int j = 1; j <= m; j++) {
    csg[1][j] = csg[1][j - 1] + isStar(1, j);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= m; j++) {
      csg[i][j] =
          csg[i - 1][j] + csg[i][j - 1] + isStar(i, j) - csg[i - 1][j - 1];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int pp = m + 1;
      for (int i2 = i + 2; i2 <= n; i2++) {
        while (getCt(i + 1, j + 1, i2 - 1, pp - 2) >= k) pp--;
        ans += m + 1 - pp;
      }
    }
  }
  cout << ans;
  return 0;
}
