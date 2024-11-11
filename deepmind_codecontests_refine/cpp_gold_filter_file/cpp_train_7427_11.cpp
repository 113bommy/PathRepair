#include <bits/stdc++.h>
using namespace std;
const int maxN = 2000 + 10;
bool mark[maxN][maxN];
int n, m, que;
int up[maxN][maxN], bot[maxN][maxN];
int dist(const int &x, const int &y, const int &xx, const int &yy) {
  return (xx > 0 && xx <= n) ? labs(x - xx) + labs(y - yy) : n + m + 10;
}
pair<int, int> go(int x, int y) {
  pair<int, int> ret = pair<int, int>(n + 1, m + 1);
  int dis = n + m + 10;
  for (int i = y; i <= m && dis >= i - y; i++) {
    int tmp1 = dist(x, y, up[x][i], i);
    int tmp2 = dist(x, y, bot[x][i], i);
    if (tmp1 < dis || (tmp1 == dis && pair<int, int>(up[x][i], i) < ret)) {
      dis = tmp1;
      ret = pair<int, int>(up[x][i], i);
    }
    if (tmp2 < dis || (tmp2 == dis && pair<int, int>(bot[x][i], i) < ret)) {
      dis = tmp2;
      ret = pair<int, int>(bot[x][i], i);
    }
  }
  for (int i = y - 1; i > 0 && dis >= y - i; i--) {
    int tmp1 = dist(x, y, up[x][i], i);
    int tmp2 = dist(x, y, bot[x][i], i);
    if (tmp1 < dis || (tmp1 == dis && pair<int, int>(up[x][i], i) < ret)) {
      dis = tmp1;
      ret = pair<int, int>(up[x][i], i);
    }
    if (tmp2 < dis || (tmp2 == dis && pair<int, int>(bot[x][i], i) < ret)) {
      dis = tmp2;
      ret = pair<int, int>(bot[x][i], i);
    }
  }
  int rx = ret.first, ry = ret.second;
  mark[rx][ry] = true;
  up[rx][ry] = (!mark[rx - 1][ry]) ? rx - 1 : up[rx - 1][ry];
  bot[rx][ry] = (!mark[rx + 1][ry]) ? rx + 1 : bot[rx + 1][ry];
  for (int i = rx - 1; i > up[rx][ry]; i--) bot[i][ry] = bot[rx][ry];
  for (int i = rx + 1; i < bot[rx][ry]; i++) up[i][ry] = up[rx][ry];
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> que;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) up[i][j] = bot[i][j] = i;
  for (int i = 1; i <= que; i++) {
    int x, y;
    cin >> x >> y;
    pair<int, int> tmp = go(x, y);
    cout << tmp.first << ' ' << tmp.second << endl;
  }
  return 0;
}
