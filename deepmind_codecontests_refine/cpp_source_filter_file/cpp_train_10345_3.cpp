#include <bits/stdc++.h>
using namespace std;
char cell[109][10009];
int d[2], w[2];
int main() {
  int n, m;
  cin >> n >> m;
  getchar();
  for (int(i) = (int)(0); (i) < (int)(n); ++(i)) {
    for (int(j) = (int)(0); (j) < (int)(m); ++(j))
      cell[i + 1][j + 1] = getchar();
    getchar();
  }
  int ans = 0;
  int x, y, now = 0;
  d[0] = 1, d[1] = -1;
  x = y = w[0] = w[1] = 1;
  for (int T = 10000000; T; --T) {
    if (x == n) {
      cout << ans << endl;
      return 0;
    }
    if (cell[x + 1][y] == '.')
      ++x, w[0] = w[1] = y;
    else if (y == w[now]) {
      if (1 <= y + d[now] && y + d[now] <= m && cell[x][y + d[now]] != '#') {
        w[now] += d[now];
        if (cell[x][y + d[now]] == '.')
          y += d[now];
        else
          now ^= 1;
      } else
        now ^= 1;
    } else {
      ans += (long long)abs(w[now] - y) - 1;
      y = w[now];
    }
    ++ans;
  }
  cout << "Never" << endl;
  return 0;
}
