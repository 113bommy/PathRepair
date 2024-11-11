#include <bits/stdc++.h>
inline int getint() {
  int x = 0, p = 1;
  char c = getchar();
  while (c <= 32) c = getchar();
  if (c == 45) p = -p, c = getchar();
  while (c > 32) x = x * 10 + c - 48, c = getchar();
  return x * p;
}
using namespace std;
const int N = 2010;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int sx, sy, n, m, L, R;
string s[N];
queue<pair<int, int> > qu;
pair<int, int> dis[N][N];
bool isvalid(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '*') return false;
  return true;
}
int main() {
  n = getint();
  m = getint();
  sx = getint() - 1;
  sy = getint() - 1;
  L = getint(), R = getint();
  for (int(i) = 0; (i) < (n); (i)++) cin >> s[i];
  for (int(i) = 0; (i) < (n); (i)++)
    for (int(j) = 0; (j) < (n); (j)++)
      dis[i][j] = make_pair(1000000000 + 2, 1000000000 + 2);
  dis[sx][sy] = make_pair(0, 0);
  qu.push(make_pair(sx, sy));
  while (!qu.empty()) {
    pair<int, int> u = qu.front();
    qu.pop();
    for (int(i) = 0; (i) < (4); (i)++) {
      int fx = u.first + dx[i], fy = u.second + dy[i];
      pair<int, int> len = dis[u.first][u.second];
      if (i == 1) len.first++;
      if (i == 3) len.second++;
      if (isvalid(fx, fy) && dis[fx][fy] > len) {
        dis[fx][fy] = len;
        if (dis[fx][fy].first <= R && dis[fx][fy].second <= L)
          qu.push(make_pair(fx, fy));
      }
    }
  }
  int res = 0;
  for (int(i) = 0; (i) < (n); (i)++)
    for (int(j) = 0; (j) < (m); (j)++)
      if (dis[i][j].first <= R && dis[i][j].second <= L) res++;
  printf("%d\n", res);
  return 0;
}
