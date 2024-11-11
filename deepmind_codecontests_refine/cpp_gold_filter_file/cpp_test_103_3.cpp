#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, m, cnt;
int dist[N][N];
bool st[N][N];
char g[N][N];
pair<int, int> p[N * N];
int dfs(int first, int second) {
  p[++cnt] = {first, second};
  if (first < 1 || first > n || second < 1 || second > m || st[first][second])
    return dist[first][second];
  st[first][second] = true;
  auto &k = dist[first][second];
  if (g[first][second] == 'U') k = dfs(first - 1, second) + 1;
  if (g[first][second] == 'D') k = dfs(first + 1, second) + 1;
  if (g[first][second] == 'L') k = dfs(first, second - 1) + 1;
  if (g[first][second] == 'R') k = dfs(first, second + 1) + 1;
  return dist[first][second];
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> g[i][j];
  for (int i = 0; i <= n + 5; i++)
    for (int j = 0; j <= m + 5; j++) st[i][j] = false, dist[i][j] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (!st[i][j]) {
        cnt = 0;
        dfs(i, j);
        pair<int, int> t = p[cnt];
        for (int k = 1; k <= cnt; k++)
          if (t == p[k]) {
            for (int h = k; h < cnt; h++)
              dist[p[h].first][p[h].second] = cnt - k;
          }
      }
    }
  int first = 0, second = 0, res = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (dist[i][j] > res) first = i, second = j, res = dist[i][j];
  cout << first << " " << second << " " << res << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}
