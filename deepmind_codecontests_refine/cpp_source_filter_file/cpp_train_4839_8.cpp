#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
int a[4][maxn][maxn], s[4][maxn][maxn];
int sum(int id, int x1, int y1, int x2, int y2) {
  return s[id][x2][y2] - s[id][x1 - 1][y2] - s[id][x2][y1 - 1] +
         s[id][x1 - 1][y1 - 1];
}
long long cal0(int id, int n, int m) {
  long long ret = 0LL;
  for (int i = 2; i < m; i++)
    if (!sum(id, 1, i, n, i)) ret++;
  return ret;
}
long long cal1(int id, int n, int m) {
  long long ret = 0LL;
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++)
      if (!sum(id, i, 1, i, j) && !sum(id, 1, j, i, j)) ret++;
  return ret;
}
int num[4][2][maxn][maxn];
void getnum(int id, int n, int m) {
  for (int i = 2; i < n; i++)
    for (int j = 3; j < m; j++) {
      if (a[id][i][j]) {
        num[id][0][i][j] = 0;
        continue;
      }
      num[id][0][i][j] = num[id][0][i][j - 1];
      if (!sum(id, i, j - 2, i, j) && !sum(id, 1, j - 2, i, j - 2))
        num[id][0][i][j]++;
    }
  for (int i = 2; i < n; i++)
    for (int j = m - 2; j >= 2; j--) {
      if (a[id][i][j]) {
        num[id][1][i][j] = 0;
        continue;
      }
      num[id][1][i][j] = num[id][1][i][j + 1];
      if (!sum(id, i, j, i, j + 2) && !sum(id, 1, j + 2, i, j + 2))
        num[id][1][i][j]++;
    }
}
long long cal2(int id, int n, int m) {
  long long ret = 0LL;
  for (int i = 2; i < n; i++)
    for (int j = 3; j <= m; j++)
      if (!sum(id, 1, j, i, j)) ret += num[id][0][i][j];
  return ret;
}
long long cal3(int id, int n, int m) {
  long long ret = 0LL;
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++)
      if (!sum(id, i, j, n, j)) {
        ret += num[id][0][i][j], ret += num[id][1][i][j];
        if (j > 2 && !sum(id, 1, j - 1, i, j - 1)) ret++;
        if (j < m - 1 && !sum(id, 1, j + 1, i, j + 1)) ret++;
      }
  return ret;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char c = getchar();
      while (c != '#' && c != '.') c = getchar();
      int x = (c == '#');
      a[0][i][j] = a[1][j][n + 1 - i] = x;
      a[2][n + 1 - i][m + 1 - j] = a[3][m + 1 - j][i] = x;
    }
  for (int i = 0; i < 4; i++)
    for (int j = 1; j <= max(n, m); j++)
      for (int k = 1; k <= max(n, m); k++)
        s[i][j][k] =
            s[i][j][k - 1] + s[i][j - 1][k] - s[i][j - 1][k - 1] + a[i][j][k];
  long long ans = 0LL;
  ans += cal0(0, n, m) + cal0(1, m, n);
  ans += cal1(0, n, m) + cal1(1, m, n) + cal1(2, n, m) + cal1(3, m, n);
  getnum(0, n, m);
  getnum(1, m, n);
  getnum(2, n, m);
  getnum(3, m, n);
  ans += cal2(0, n, m) + cal2(1, m, n) + cal2(2, n, m) + cal2(3, m, n);
  ans += cal3(0, n, m) + cal3(1, m, n);
  printf("%I64d\n", ans);
}
