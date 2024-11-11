#include <bits/stdc++.h>
using namespace std;
int n, i, a[1001], m = 1000000000, b[1001][1001], used[1001][1001],
                   pr[1001][1001], j, x, y;
pair<int, int> p[1001][1001];
vector<int> path;
void dfs(int x, int y) {
  if (y + 2 <= n) {
    if (b[x][y + 2] != 0 && b[x][y + 2] > b[x][y] + max(a[y], a[y + 1]))
      b[x][y + 2] = b[x][y] + max(a[y], a[y + 1]), p[x][y + 2].first = y,
               p[x][y + 2].second = y + 1, pr[x][y + 2] = x;
    if (b[x][y + 2] == 0)
      b[x][y + 2] = b[x][y] + max(a[y], a[y + 1]), p[x][y + 2].first = y,
               p[x][y + 2].second = y + 1, pr[x][y + 2] = x;
    if (b[y + 1][y + 2] != 0 && b[y + 1][y + 2] > b[x][y] + max(a[x], a[y]))
      b[y + 1][y + 2] = b[x][y] + max(a[x], a[y]), p[y + 1][y + 2].first = x,
                   p[y + 1][y + 2].second = y, pr[y + 1][y + 2] = x;
    if (b[y + 1][y + 2] == 0)
      b[y + 1][y + 2] = b[x][y] + max(a[x], a[y]), p[y + 1][y + 2].first = x,
                   p[y + 1][y + 2].second = y, pr[y + 1][y + 2] = x;
    if (b[y][y + 2] != 0 && b[y][y + 2] > b[x][y] + max(a[x], a[y + 1]))
      b[y][y + 2] = b[x][y] + max(a[x], a[y + 1]), p[y][y + 2].first = x,
               p[y][y + 2].second = y + 1, pr[y][y + 2] = x;
    if (b[y][y + 2] == 0)
      b[y][y + 2] = b[x][y] + max(a[x], a[y + 1]), p[y][y + 2].first = x,
               p[y][y + 2].second = y + 1, pr[y][y + 2] = x;
    if (y + 2 == n) {
      if (m > b[x][y + 2] + max(a[x], a[y + 2]))
        m = b[x][y + 2] + max(a[x], a[y + 2]), p[y + 2][y + 2].first = x,
        p[y + 2][y + 2].second = y + 2;
      if (m > b[y + 1][y + 2] + max(a[y + 1], a[y + 2]))
        m = b[y + 1][y + 2] + max(a[y + 1], a[y + 2]),
        p[y + 2][y + 2].first = y + 1, p[y + 2][y + 2].second = y + 2;
      if (m > b[y][y + 2] + max(a[y], a[y + 2]))
        m = b[y][y + 2] + max(a[y], a[y + 2]), p[y + 2][y + 2].first = y,
        p[y + 2][y + 2].second = y + 2;
    }
  }
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  if (n == 1) {
    cout << a[1] << endl;
    cout << 1;
    return 0;
  }
  if (n == 2) {
    cout << max(a[1], a[2]) << endl;
    cout << 1 << " " << 2;
    return 0;
  }
  if (n % 2 == 1) {
    a[n + 1] = 0;
    n++;
  }
  dfs(1, 2);
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++)
      if (b[i][j] > 0) {
        if (j + 2 <= n) {
          x = i, y = j;
          if (b[x][y + 2] != 0 && b[x][y + 2] > b[x][y] + max(a[y], a[y + 1]))
            b[x][y + 2] = b[x][y] + max(a[y], a[y + 1]), p[x][y + 2].first = y,
                     p[x][y + 2].second = y + 1, pr[x][y + 2] = x;
          if (b[x][y + 2] == 0)
            b[x][y + 2] = b[x][y] + max(a[y], a[y + 1]), p[x][y + 2].first = y,
                     p[x][y + 2].second = y + 1, pr[x][y + 2] = x;
          if (b[y + 1][y + 2] != 0 &&
              b[y + 1][y + 2] > b[x][y] + max(a[x], a[y]))
            b[y + 1][y + 2] = b[x][y] + max(a[x], a[y]),
                         p[y + 1][y + 2].first = x, p[y + 1][y + 2].second = y,
                         pr[y + 1][y + 2] = x;
          if (b[y + 1][y + 2] == 0)
            b[y + 1][y + 2] = b[x][y] + max(a[x], a[y]),
                         p[y + 1][y + 2].first = x, p[y + 1][y + 2].second = y,
                         pr[y + 1][y + 2] = x;
          if (b[y][y + 2] != 0 && b[y][y + 2] > b[x][y] + max(a[x], a[y + 1]))
            b[y][y + 2] = b[x][y] + max(a[x], a[y + 1]), p[y][y + 2].first = x,
                     p[y][y + 2].second = y + 1, pr[y][y + 2] = x;
          if (b[y][y + 2] == 0)
            b[y][y + 2] = b[x][y] + max(a[x], a[y + 1]), p[y][y + 2].first = x,
                     p[y][y + 2].second = y + 1, pr[y][y + 2] = x;
          if (y + 2 == n) {
            if (m > b[x][y + 2] + max(a[x], a[y + 2]))
              m = b[x][y + 2] + max(a[x], a[y + 2]), p[y + 2][y + 2].first = x,
              p[y + 2][y + 2].second = y + 2;
            if (m > b[y + 1][y + 2] + max(a[y + 1], a[y + 2]))
              m = b[y + 1][y + 2] + max(a[y + 1], a[y + 2]),
              p[y + 2][y + 2].first = y + 1, p[y + 2][y + 2].second = y + 2;
            if (m > b[y][y + 2] + max(a[y], a[y + 2]))
              m = b[y][y + 2] + max(a[y], a[y + 2]), p[y + 2][y + 2].first = y,
              p[y + 2][y + 2].second = y + 2;
          }
        }
      }
  cout << m << endl;
  path.push_back(p[n][n].first);
  path.push_back(p[n][n].second);
  int l = p[n][n].first;
  int r = p[n][n].second;
  int ll = p[l][r].first;
  int rr = p[l][r].second;
  int lll = pr[l][r];
  for (i = 0; i < ((n - 1) / 2); i++) {
    path.push_back(ll);
    path.push_back(rr);
    l = lll;
    r = r - 2;
    ll = p[l][r].first;
    rr = p[l][r].second;
    lll = pr[l][r];
  }
  int j;
  for (i = path.size() - 1; i >= 0; i--) {
    if (a[path[i]] != 0) cout << path[i] << " ";
    i--;
    if (a[path[i]] != 0) cout << path[i];
    cout << endl;
  }
  return 0;
}
