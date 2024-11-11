#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
const int INF = 0x3f3f3f3f, N = 10;
constexpr int M = N * N * 3;
const ll LINF = 1e18 + 5;
int n, a[N][N], id[N][N][3], t;
pii dis[M][M], dp[N * N][3];
pii ord[N * N];
const int dir[8][2] = {{2, 1}, {2, -1}, {-2, -1}, {-2, 1},
                       {1, 2}, {1, -2}, {-1, -2}, {-1, 2}};
pii operator+(const pii &a, const pii &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      --a[i][j];
      ord[a[i][j]] = make_pair(i, j);
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < 3; k++) id[i][j][k] = t++;
  for (int i = 0; i < n * n * 3; i++)
    for (int j = 0; j < n * n * 3; j++) dis[i][j] = make_pair(INF, INF);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int ti, tj;
      dis[id[i][j][0]][id[i][j][0]] = make_pair(0, 0);
      for (int k = 0; k < 8; k++) {
        ti = i + dir[k][0], tj = j + dir[k][1];
        if (ti < 0 || tj < 0 || ti >= n || tj >= n) continue;
        dis[id[i][j][0]][id[ti][tj][0]] = make_pair(1, 0);
      }
      dis[id[i][j][0]][id[i][j][1]] = dis[id[i][j][0]][id[i][j][2]] =
          make_pair(1, 1);
      dis[id[i][j][1]][id[i][j][1]] = make_pair(0, 0);
      for (int k = 0; k < n; k++) {
        ti = i + k, tj = j + k;
        if (!(ti < 0 || tj < 0 || ti >= n || tj >= n))
          dis[id[i][j][1]][id[ti][tj][1]] = make_pair(1, 0);
        ti = i + k, tj = j - k;
        if (!(ti < 0 || tj < 0 || ti >= n || tj >= n))
          dis[id[i][j][1]][id[ti][tj][1]] = make_pair(1, 0);
        ti = i - k, tj = j + k;
        if (!(ti < 0 || tj < 0 || ti >= n || tj >= n))
          dis[id[i][j][1]][id[ti][tj][1]] = make_pair(1, 0);
        ti = i - k, tj = j - k;
        if (!(ti < 0 || tj < 0 || ti >= n || tj >= n))
          dis[id[i][j][1]][id[ti][tj][1]] = make_pair(1, 0);
      }
      dis[id[i][j][1]][id[i][j][0]] = dis[id[i][j][1]][id[i][j][2]] =
          make_pair(1, 1);
      dis[id[i][j][2]][id[i][j][2]] = make_pair(0, 0);
      for (int k = 0; k < n; k++) {
        ti = i + k, tj = j;
        if (!(ti < 0 || tj < 0 || ti >= n || tj >= n))
          dis[id[i][j][2]][id[ti][tj][2]] = make_pair(1, 0);
        ti = i, tj = j + k;
        if (!(ti < 0 || tj < 0 || ti >= n || tj >= n))
          dis[id[i][j][2]][id[ti][tj][2]] = make_pair(1, 0);
        ti = i - k, tj = j;
        if (!(ti < 0 || tj < 0 || ti >= n || tj >= n))
          dis[id[i][j][2]][id[ti][tj][2]] = make_pair(1, 0);
        ti = i, tj = j - k;
        if (!(ti < 0 || tj < 0 || ti >= n || tj >= n))
          dis[id[i][j][2]][id[ti][tj][2]] = make_pair(1, 0);
      }
      dis[id[i][j][2]][id[i][j][0]] = dis[id[i][j][2]][id[i][j][1]] =
          make_pair(1, 1);
    }
  }
  for (int k = 0; k < n * n * 3; k++)
    for (int i = 0; i < n * n * 3; i++)
      for (int j = 0; j < n * n * 3; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  for (int i = 0; i < n * n * 3; i++)
    for (int j = 0; j < 3; j++) dp[i][j] = make_pair(INF, INF);
  dp[id[ord[0].first][ord[0].second][0]][0] =
      dp[id[ord[0].first][ord[0].second][1]][1] =
          dp[id[ord[0].first][ord[0].second][2]][2] = make_pair(0, 0);
  for (int i = 1; i < n * n; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        dp[id[ord[i].first][ord[i].second][j]][j] =
            min(dp[id[ord[i].first][ord[i].second][j]][j],
                dp[id[ord[i - 1].first][ord[i - 1].second][k]][k] +
                    dis[id[ord[i - 1].first][ord[i - 1].second][k]]
                       [id[ord[i].first][ord[i].second][j]]);
  pii ans = min(dp[id[ord[n * n - 1].first][ord[n * n - 1].second][0]][0],
                min(dp[id[ord[n * n - 1].first][ord[n * n - 1].second][1]][1],
                    dp[id[ord[n * n - 1].first][ord[n * n - 1].second][2]][2]));
  cout << ans.first << ' ' << ans.second;
  return 0;
}
