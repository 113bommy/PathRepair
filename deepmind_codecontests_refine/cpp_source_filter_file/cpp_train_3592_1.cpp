#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
char grid[1000][1000];
int n, m, xd[4] = {0, 1, 0, -1}, yd[4] = {1, 0, -1, 0};
long long d[3][1000][1000], d1, d2, d3;
queue<pair<pair<int, int>, int>> q;
bool ok(pair<int, int> a) {
  if (a.first < 0 || a.first > m - 1 || a.second < 0 || a.second > n - 1 ||
      grid[a.first][a.second] == '#')
    return false;
  return true;
}
void gendist() {
  for (int k = 0; k < 3; k++) {
    queue<pair<pair<int, int>, int>> empty;
    swap(q, empty);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (grid[j][i] == char('1' + k))
          d[k][j][i] = -1, q.push(make_pair(make_pair(j, i), 0));
        else
          d[k][j][i] = MOD;
    while (!q.empty()) {
      pair<pair<int, int>, int> x = q.front();
      q.pop();
      d[k][x.first.first][x.first.second] = x.second;
      for (int i = 0; i < 4; i++) {
        int x1 = x.first.first + xd[i], y1 = x.first.second + yd[i];
        if (ok(make_pair(x1, y1)) && x.second + 1 < d[k][x1][y1]) {
          d[k][x1][y1] = -1, q.push(make_pair(make_pair(x1, y1), x.second + 1));
        }
      }
    }
  }
  d1 = MOD, d2 = MOD, d3 = MOD;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (grid[j][i] == '2')
        d3 = min(d3, d[0][j][i] - 1), d1 = min(d1, d[2][j][i] - 1);
      else if (grid[j][i] == '3')
        d3 = min(d2, d[0][j][i] - 1);
    }
}
void findans() {
  long long ans = MOD;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (grid[j][i] == '.') {
        ans = min(ans, d[0][j][i] + d[1][j][i] + d[2][j][i] - 2);
      }
  ans = min(ans, d1 + d2 + d3 - max(max(d1, d2), d3));
  if (ans < MOD / 2)
    cout << ans;
  else
    cout << -1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> grid[j][i];
  gendist();
  findans();
  return 0;
}
