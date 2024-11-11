#include <bits/stdc++.h>
using namespace std;
const int N = 3000 + 20, inf = 1e9;
int h[N][N], p[N], n, k, ans;
bool mark[N], mark2[N];
void bfs() {
  for (int i = 0; i <= n; i++)
    for (int j = i + 1; j <= n + 1; j++) h[i][j] = inf;
  h[0][1] = 0;
  queue<pair<int, int>> q;
  q.push({0, 1});
  while (q.size()) {
    pair<int, int> v = q.front();
    q.pop();
    if (v.second < n && mark[v.second] && p[v.first] &&
        h[v.second + 1][v.second + 2] == inf) {
      h[v.second + 1][v.second + 2] = h[v.first][v.second] + 1;
      q.push({v.second + 1, v.second + 2});
    }
    if (v.second < n && mark[v.second] && p[v.first] != 100 &&
        h[v.second][v.second + 1] == inf) {
      h[v.second][v.second + 1] = h[v.first][v.second] + 1;
      q.push({v.second, v.second + 1});
    }
    if (v.second < n && p[v.first] && mark2[v.second] &&
        h[v.first][v.second + 1] == inf) {
      h[v.first][v.second + 1] = h[v.first][v.second] + 1;
      q.push({v.first, v.second + 1});
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> p[i];
  mark[n - 1] = p[n - 1];
  for (int i = n - 2; ~i; i--) mark[i] = mark[i + 1] || p[i];
  mark2[n - 1] = p[n - 1] != 100;
  for (int i = n - 2; ~i; i--) mark2[i] = mark2[i + 1] || (p[i] != 100);
  bfs();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j <= n; j++)
      if (h[i][j] <= k) ans++;
  if (h[n][n + 1] <= k) ans++;
  return cout << ans << "\n", 0;
}
