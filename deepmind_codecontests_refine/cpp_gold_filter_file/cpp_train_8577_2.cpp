#include <bits/stdc++.h>
using namespace std;
template <class T>
inline int size(const T& c) {
  return c.size();
}
using namespace std;
int fastMax(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ y; }
int fastMin(int x, int y) { return (((y - x) >> (32 - 1)) & (x ^ y)) ^ x; }
struct rect {
  int x1, y1, x2, y2;
} r[110000];
const int maxn = 3000 + 10;
const int si = 3000;
int a[maxn][maxn];
int b[maxn][maxn], s[maxn][maxn];
int g[maxn][maxn][4];
vector<int> res;
int n, x, y, x2, y2;
int calc(int y1, int x1, int y2, int x2, int c) {
  return g[y2][x2][c] - g[y2][x1 - 1][c] - g[y1 - 1][x2][c] +
         g[y1 - 1][x1 - 1][c];
}
int main() {
  scanf("%d", &n);
  for (int i = (1), _b = (n); i <= _b; i++) {
    scanf("%d%d%d%d", &x, &y, &x2, &y2);
    r[i].x1 = x + 1;
    r[i].y1 = y + 1;
    r[i].x2 = x2;
    r[i].y2 = y2;
    for (int i = (y + 1), _b = (y2); i <= _b; i++) {
      a[i][x + 1]++;
      a[i][x2 + 1]--;
      g[i][x + 1][0]++;
      g[i][x2][2]++;
    }
    for (int i = (x + 1), _b = (x2); i <= _b; i++) {
      g[y2][i][1]++;
      g[y + 1][i][3]++;
    }
  }
  for (int i = (1), _b = (si); i <= _b; i++) {
    for (int j = (1), _b = (si); j <= _b; j++) {
      a[i][j] = a[i][j - 1] + a[i][j];
      s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
      for (int k = (0), _b = (3); k <= _b; k++) {
        g[i][j][k] =
            g[i - 1][j][k] + g[i][j - 1][k] - g[i - 1][j - 1][k] + g[i][j][k];
      }
    }
  }
  for (int i = (1), _b = (si); i <= _b; i++)
    for (int j = (1), _b = (si); j <= _b; j++) {
      int y = i;
      int x = j;
      while (y >= 1 && x >= 1) {
        if (s[i][j] - s[y - 1][j] - s[i][x - 1] + s[y - 1][x - 1] ==
                (i - y + 1) * (j - x + 1) &&
            calc(y, j, i, j, 2) == (i - y + 1) &&
            calc(i, x, i, j, 1) == (j - x + 1)) {
          if (calc(y, x, y, j, 3) == (j - x + 1) &&
              calc(y, x, i, x, 0) == (i - y + 1)) {
            cout << "YES ";
            res.clear();
            for (int k = (1), _b = (n); k <= _b; k++)
              if (r[k].y1 >= y && r[k].x1 >= x && r[k].y2 <= i && r[k].x2 <= j)
                res.push_back(k);
            cout << res.size() << endl;
            for (int i = (0), _b = (res.size() - 1); i <= _b; i++)
              cout << res[i] << ' ';
            return 0;
          }
          y--;
          x--;
        } else
          break;
      }
    }
  cout << "NO";
  fclose(stdin);
  fclose(stdout);
  return 0;
}
