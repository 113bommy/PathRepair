#include <bits/stdc++.h>
using namespace std;
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int n, m, k, id, cnt;
pair<int, int> c[int(60) * int(60)];
bool f[int(60)][int(60)], t, e[int(60) * int(60)];
int dem, num[int(60)][int(60)];
char a[int(60)][int(60)];
int check(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m || a[x][y] == '*') return 0;
  if (x == 1 || x == n || y == 1 || y == m) return 2;
  return 1;
}
void dfs(int x, int y, int id) {
  if (check(x, y) == 2) t = false;
  dem++;
  num[x][y] = id;
  f[x][y] = false;
  for (int i = (0), _b = (3); i <= _b; i++) {
    int x2 = x + xx[i];
    int y2 = y + yy[i];
    if (check(x2, y2) && f[x2][y2]) dfs(x2, y2, id);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (1), _b = (n); i <= _b; i++) scanf("%s", a[i] + 1);
  memset(f, true, sizeof(f));
  for (int i = (1), _b = (n); i <= _b; i++)
    for (int j = (1), _b = (m); j <= _b; j++)
      if (f[i][j] && a[i][j] == '.') {
        dem = 0;
        t = true;
        id++;
        dfs(i, j, id);
        if (t) {
          cnt++;
          c[cnt].first = dem;
          c[cnt].second = id;
        }
      }
  sort(c + 1, c + 1 + cnt);
  int res = 0;
  for (int i = (1), _b = (cnt - k); i <= _b; i++) {
    e[c[i].second] = true;
    res += c[i].first;
  }
  for (int i = (1), _b = (n); i <= _b; i++)
    for (int j = (1), _b = (n); j <= _b; j++)
      if (e[num[i][j]]) a[i][j] = '*';
  printf("%d\n", res);
  for (int i = (1), _b = (n); i <= _b; i++) printf("%s\n", a[i] + 1);
}
