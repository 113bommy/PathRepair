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
const int N = 15;
pair<int, int> dis[N][N][N][N][3][3], dp[N][N], hh[N * N];
int n, a[N][N];
int dx[] = {2, 1, 2, 1, -1, -2, -1, -2};
int dy[] = {1, 2, -1, -2, 2, 1, -2, -1};
priority_queue<pair<pair<int, int>, pair<int, int> > > pq;
pair<int, int> operator+(pair<int, int> x, pair<int, int> y) {
  return make_pair(x.first + y.first, x.second + y.second);
}
bool isvalid(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= n) return false;
  return true;
}
void doit(int x, int y, int xx, int yy, int i, int j, int len, int len2) {
  if (j == 0) {
    for (int(ii) = 0; (ii) < (8); (ii)++) {
      int fx = xx + dx[ii], fy = yy + dy[ii];
      if (isvalid(fx, fy) && dis[x][y][fx][fy][i][j] > make_pair(len, len2)) {
        pq.push(make_pair(make_pair(len, len2), make_pair(fx * n + fy, 0)));
        dis[x][y][fx][fy][i][j] = make_pair(len, len2);
      }
    }
  }
  if (j == 1) {
    int tmp = xx - yy;
    for (int fx = -2 * N; fx <= 2 * N; fx++) {
      int fy = fx - tmp;
      if (isvalid(fx, fy) && dis[x][y][fx][fy][i][j] > make_pair(len, len2)) {
        pq.push(make_pair(make_pair(len, len2), make_pair(fx * n + fy, 1)));
        dis[x][y][fx][fy][i][j] = make_pair(len, len2);
      }
    }
    tmp = xx + yy;
    for (int fx = -2 * N; fx <= 2 * N; fx++) {
      int fy = tmp - fx;
      if (isvalid(fx, fy) && dis[x][y][fx][fy][i][j] > make_pair(len, len2)) {
        pq.push(make_pair(make_pair(len, len2), make_pair(fx * n + fy, 1)));
        dis[x][y][fx][fy][i][j] = make_pair(len, len2);
      }
    }
  }
  if (j == 2) {
    for (int fx = -2 * N; fx <= 2 * N; fx++) {
      int fy = yy;
      if (isvalid(fx, fy) && dis[x][y][fx][fy][i][j] > make_pair(len, len2)) {
        pq.push(make_pair(make_pair(len, len2), make_pair(fx * n + fy, 2)));
        dis[x][y][fx][fy][i][j] = make_pair(len, len2);
      }
    }
    for (int fy = -2 * N; fy <= 2 * N; fy++) {
      int fx = xx;
      if (isvalid(fx, fy) && dis[x][y][fx][fy][i][j] > make_pair(len, len2)) {
        pq.push(make_pair(make_pair(len, len2), make_pair(fx * n + fy, 2)));
        dis[x][y][fx][fy][i][j] = make_pair(len, len2);
      }
    }
  }
}
void init(int x, int y) {
  for (int(i) = 0; (i) < (3); (i)++) {
    dis[x][y][x][y][i][i] = make_pair(0, 0);
    pq.push(make_pair(make_pair(0, 0), make_pair(x * n + y, i)));
    while (!pq.empty()) {
      pair<pair<int, int>, pair<int, int> > u = pq.top();
      pq.pop();
      if (dis[x][y][u.second.first / n][u.second.first % n][i]
             [u.second.second] < u.first)
        continue;
      for (int(j) = 0; (j) < (3); (j)++)
        if (j != u.second.second &&
            dis[x][y][u.second.first / n][u.second.first % n][i][j] >
                make_pair(u.first.first + 1, u.first.second + 1)) {
          dis[x][y][u.second.first / n][u.second.first % n][i][j] =
              make_pair(u.first.first + 1, u.first.second + 1);
          pq.push(make_pair(make_pair(u.first.first + 1, u.first.second + 1),
                            make_pair(u.second.first, j)));
        }
      doit(x, y, u.second.first / n, u.second.first % n, i, u.second.second,
           u.first.first + 1, u.first.second);
    }
  }
}
int main() {
  n = getint();
  for (int(i) = 0; (i) < (N); (i)++)
    for (int(j) = 0; (j) < (N); (j)++)
      for (int(k) = 0; (k) < (N); (k)++)
        for (int(l) = 0; (l) < (N); (l)++)
          for (int(ok0) = 0; (ok0) < (3); (ok0)++)
            for (int(ok1) = 0; (ok1) < (3); (ok1)++)
              dis[i][j][k][l][ok0][ok1] = make_pair(1000000000, 1000000000);
  for (int(i) = 0; (i) < (n); (i)++)
    for (int(j) = 0; (j) < (n); (j)++) {
      a[i][j] = getint();
      hh[a[i][j]] = make_pair(i, j);
      init(i, j);
    }
  for (int(i) = 0; (i) < (3); (i)++) dp[1][i] = make_pair(0, 0);
  for (int i = 2; i <= n * n; i++)
    for (int(j) = 0; (j) < (3); (j)++) {
      pair<int, int> tmp = make_pair(1000000000, 1000000000);
      for (int(k) = 0; (k) < (3); (k)++)
        tmp = min(tmp, dis[hh[i - 1].first][hh[i - 1].second][hh[i].first]
                          [hh[i].second][k][j] +
                           dp[i - 1][k]);
      dp[i][j] = tmp;
    }
  pair<int, int> res = min(dp[n * n][0], min(dp[n * n][1], dp[n * n][2]));
  printf("%d %d\n", res.first, res.second);
  return 0;
}
