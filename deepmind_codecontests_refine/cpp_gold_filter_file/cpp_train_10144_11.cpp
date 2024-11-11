#include <bits/stdc++.h>
using namespace std;
const double eps = 1.0e-11;
const double pi = acos(-1.0);
const int N = 310;
int d[N][N];
short int sums[4][N][N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int tp, tu, td;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, t;
  scanf("%d%d%d", &n, &m, &t);
  scanf("%d%d%d", &tp, &tu, &td);
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) scanf("%d", &d[i][j]);
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      for (long long dir = 0; dir < 4; dir++) {
        int curr = 0, last = d[i][j];
        int x = i, y = j;
        for (long long shift = 0; shift < max(n, m); shift++) {
          x += dx[dir], y += dy[dir];
          if (x < 0 || x >= n || y < 0 || y >= m) break;
          if (d[x][y] > last) curr += tu;
          if (d[x][y] < last) curr += td;
          if (d[x][y] == last) curr += tp;
          sums[dir][i][j][shift + 1] = curr;
          last = d[x][y];
        }
      }
    }
  int best = 2000000000;
  int min_cost = min(tp, min(tu, td));
  int max_cost = max(tp, max(tu, td));
  int lx = 0, ly = 0, rx = 0, ry = 0;
  for (long long x1 = 0; x1 < n; x1++)
    for (long long x2 = x1 + 2; x2 <= n - 1; x2++) {
      set<pair<int, int> > s;
      for (long long y = 2; y <= m - 1; y++) {
        s.insert(make_pair(
            sums[1][x1][0][y] + sums[0][x1][y][x2 - x1] + sums[3][x2][y][y],
            y));
      }
      for (long long y = 0; y < m - 2; y++) {
        int have =
            sums[2][x2][y][x2 - x1] - sums[1][x1][0][y] - sums[3][x2][y][y];
        int need = t - have;
        auto it = s.lower_bound(make_pair(need, 0));
        if (it != s.end()) {
          if (abs(have + it->first - t) < abs(best - t)) {
            best = have + it->first;
            lx = x1, ly = y, rx = x2, ry = it->second;
          }
        }
        if (it != s.begin()) {
          --it;
          if (abs(have + it->first - t) < abs(best - t)) {
            best = have + it->first;
            lx = x1, ly = y, rx = x2, ry = it->second;
          }
        }
        s.erase(make_pair(sums[1][x1][0][y + 2] + sums[0][x1][y + 2][x2 - x1] +
                              sums[3][x2][y + 2][y + 2],
                          y + 2));
      }
    }
  printf("%d %d %d %d\n", lx + 1, ly + 1, rx + 1, ry + 1);
  return 0;
}
