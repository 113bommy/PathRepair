#include <bits/stdc++.h>
using namespace std;
int const maxn = 405;
char a[maxn][maxn] = {};
int sumx[maxn][maxn] = {};
int sumy[maxn][maxn] = {};
int sumd1[maxn][maxn] = {};
int sumd2[maxn][maxn] = {};
inline bool test(int x1, int y1, int x2, int y2) {
  if (a[x1][y1] || a[x2][y2]) return false;
  if (x1 == x2) {
    return sumy[x1 + 1][y1 + 1] == sumy[x2 + 1][y2 + 1];
  }
  if (y1 == y2) {
    return sumx[x1 + 1][y1 + 1] == sumx[x2 + 1][y2 + 1];
  }
  if (y2 - y1 == x2 - x1) {
    return sumd1[x1 + 1][y1 + 1] == sumd1[x2 + 1][y2 + 1];
  }
  return sumd2[x1 + 1][y1 + 1] == sumd2[x2 + 1][y2 + 1];
}
inline bool test(int x1, int y1, int x2, int y2, int x3, int y3) {
  return test(x1, y1, x2, y2) && test(x1, y1, x3, y3) && test(x2, y2, x3, y3);
}
int n, m;
inline bool ok(int x1, int y1, int x2, int y2, int x3, int y3) {
  if (x1 < 0 || x1 >= n || x2 < 0 || x2 >= n || x3 < 0 || x3 >= n) return false;
  if (y1 < 0 || y1 >= m || y2 < 0 || y2 >= m || y3 < 0 || y3 >= m) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < (int)n; ++i)
    for (int j = 0; j < (int)m; ++j) {
      cin >> a[i][j];
      a[i][j] -= '0';
      sumx[i + 1][j + 1] = sumx[i][j + 1] + a[i][j];
      sumy[i + 1][j + 1] = sumy[i + 1][j] + a[i][j];
      sumd1[i + 1][j + 1] = sumd1[i][j] + a[i][j];
      sumd2[i + 1][j + 1] = sumd2[i][j + 2] + a[i][j];
    }
  int ans = 0;
  int da[] = {1, 1, 1, 1, 1, 1, 2, 1};
  int db[] = {-1, -1, 0, 0, 1, -1, 0, 1};
  int dc[] = {1, 1, 1, 0, 0, 2, 1, 0};
  int dd[] = {0, 1, 1, 1, 1, 0, 1, 2};
  for (int i = 0; i < (int)n; ++i)
    for (int j = 0; j < (int)m; ++j)
      for (int t = 0; t < (int)8; ++t)
        for (int k = 1; k < maxn; ++k)
          if (ok(i, j, i + da[t] * k, j + db[t] * k, i + dc[t] * k,
                 j + dd[t] * k)) {
            if (test(i, j, i + da[t] * k, j + db[t] * k, i + dc[t] * k,
                     j + dd[t] * k))
              ++ans;
          } else
            break;
  cout << ans << endl;
  return 0;
}
