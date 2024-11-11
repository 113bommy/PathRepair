#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
int a[1105][1105], n, m, b[1105][1105];
int dp[1105][1105], used[1105][1105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
string second;
bool OK(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void dfs(int x, int y) {
  used[x][y] = 1;
  for (int d = 0; d < 4; d++) {
    int i = x + dx[d];
    int j = y + dy[d];
    if (OK(i, j) && !used[i][j]) dfs(i, j);
  }
}
int calc(int n, int m) {
  if (n < 0 || m < 0) return 0;
  return dp[n][m];
}
int calc(int x1, int stupid_cmath, int x2, int y2) {
  return calc(x2, y2) - calc(x2, stupid_cmath - 1) - calc(x1 - 1, y2) +
         calc(x1 - 1, stupid_cmath - 1);
}
void isRectangle() {
  int x1 = inf, stupid_cmath = inf, x2 = -1, y2 = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (!a[i][j]) continue;
      x1 = min(x1, i);
      stupid_cmath = min(stupid_cmath, j);
      x2 = max(x2, i);
      y2 = max(y2, j);
    }
  if (x1 == inf) {
    cout << 0 << endl;
    exit(0);
  }
  int cnt = calc(x1, stupid_cmath, x2, y2);
  if (cnt == (x2 - x1 + 1) * (y2 - stupid_cmath + 1)) {
    cout << min(x2 - x1 + 1, y2 - stupid_cmath + 1) << endl;
    exit(0);
  }
}
void init() {
  memset(b, 0, sizeof b);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) b[i][j] = a[i][j];
}
void print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << b[i][j];
    cout << endl;
  }
  cout << endl;
}
bool ok(int h, int w) {
  if (h <= 0 || w <= 0) return false;
  init();
  int curi = -1, curj = -1;
  for (int i = 0; i < n && curi == -1; i++) {
    for (int j = 0; j < m && curj == -1; j++) {
      if (b[i][j]) {
        curi = i;
        curj = j;
      }
    }
  }
  if (curi + h > n || curj + w > m) return false;
  int cnt = calc(curi, curj, curi + h - 1, curj + w - 1);
  if (cnt != h * w) return false;
  for (int i = curi; i < curi + h; i++)
    for (int j = curj; j < curj + w; j++) b[i][j] = 0;
  while (true) {
    if (b[curi + h][curj] == 0 && b[curi][curj + w] == 0) break;
    if (b[curi + h][curj] && b[curi][curj + w]) return false;
    if (b[curi + h][curj]) {
      for (int i = curj; i < curj + w; i++) {
        if (!b[curi + h][i]) return false;
        b[curi + h][i] = 0;
      }
      curi++;
    } else {
      for (int i = curi; i < curi + h; i++) {
        if (!b[i][curj + w]) return false;
        b[i][curj + w] = 0;
      }
      curj++;
    }
  }
  int k = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) k += b[i][j];
  return k == 0;
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; i++) {
    getline(cin, second);
    for (int j = 0; j < m; j++)
      if (second[j] == 'X') a[i][j] = 1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      dp[i][j] = a[i][j] + calc(i, j - 1) + calc(i - 1, j) - calc(i - 1, j - 1);
  }
  isRectangle();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j]) {
        dfs(i, j);
        for (int i1 = 0; i1 < n; i1++)
          for (int j1 = 0; j1 < m; j1++)
            if (a[i1][j1] && !used[i1][j1]) {
              cout << -1 << endl;
              return 0;
            }
        int h = 0, w = 0;
        int t = i;
        while (t < n && a[t][i]) {
          t++;
          h++;
        }
        t = j;
        while (t < m && a[i][t]) {
          t++;
          w++;
        }
        int ans = inf;
        if (ok(h, w)) ans = min(ans, h * w);
        if (ok(1, w)) ans = min(ans, w);
        if (ok(h, 1)) ans = min(ans, h);
        if (ok(1, 1)) ans = min(ans, 1);
        if (i + h < n) {
          t = j;
          while (t < m && !a[i + h][t]) t++;
          if (t < j + w) {
            for (int d = -5; d <= 5; d++)
              if (ok(h, j + w - t + d)) ans = min(ans, h * (j + w - t + d));
          }
        }
        if (j + w < m) {
          t = i;
          while (t < n && !a[t][j + w]) t++;
          if (t < i + h) {
            for (int d = -5; d <= 5; d++)
              if (ok(i + h - t + d, w)) ans = min(ans, w * (d + i + h - t));
          }
        }
        if (ans == inf) ans = -1;
        cout << ans << endl;
        return 0;
      }
    }
  }
  return 0;
}
