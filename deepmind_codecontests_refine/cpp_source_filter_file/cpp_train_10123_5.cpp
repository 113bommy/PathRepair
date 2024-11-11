#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;
const long long mod = 998244353;
int a[509][509];
int main() {
  int n;
  scanf("%d", &n);
  if (n < 3) {
    cout << -1;
    return 0;
  }
  a[1][1] = 1;
  a[1][2] = 7;
  a[1][3] = 9;
  a[2][1] = 5;
  a[2][2] = 4;
  a[2][3] = 6;
  a[3][1] = 2;
  a[3][2] = 3;
  a[3][3] = 8;
  int tot = n * n - 9;
  for (int i = (1); i < (4); ++i)
    for (int j = (1); j < (4); ++j) a[i][j] += tot;
  queue<pair<int, int> > q;
  q.push({n, 1});
  int vis = 0;
  int cnt = 0;
  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();
    int x = u.first, y = u.second;
    if (a[x][y]) break;
    a[x][y] = ++cnt;
    if (vis == 0) {
      if (y + 1 <= n && !a[x][y + 1])
        q.push({x, y + 1});
      else if (x - 1 > 0 && !a[x - 1][y])
        q.push({x - 1, y}), vis = 1;
    } else if (vis == 1) {
      if (x - 1 > 0 && !a[x - 1][y])
        q.push({x - 1, y});
      else if (y - 1 > 0 && !a[x][y - 1])
        q.push({x, y - 1}), vis = 2;
    } else if (vis == 2) {
      if (x + 1 <= n && !a[x + 1][y])
        q.push({x + 1, y});
      else if (y - 1 > 0 && !a[x][y - 1])
        q.push({x, y - 1}), vis = 3;
    } else {
      if (y - 1 > 0 && !a[x][y - 1])
        q.push({x, y - 1});
      else if (x - 1 > 0 && !a[x - 1][y])
        q.push({x - 1, y}), vis = 0;
    }
  }
  for (int i = (1); i < (n + 1); ++i) {
    for (int j = (1); j < (n + 1); ++j) printf("%d ", a[i][j]);
    printf("\n");
  }
}
