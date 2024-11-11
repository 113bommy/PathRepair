#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char c[1005][1005];
pair<int, int> s, t;
int n, m;
bool vis[1005][1005];
int sp[1005][1005];
int ar[] = {-1, 1, 0, 0}, ac[] = {0, 0, 1, -1};
bool valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && c[i][j] != '*';
}
bool dfs(int i, int j, int tu = 0, int st = -1) {
  if (tu > 2) return 0;
  if (i == t.first && j == t.second) return 1;
  vis[i][j] = 1;
  bool ret = 0;
  for (int a = 0; a < 4; a++) {
    int ni = i + ar[a];
    int nj = j + ac[a];
    if (valid(ni, nj)) ret |= dfs(ni, nj, st != -1 && st != a ? tu + 1 : tu, a);
  }
  return ret;
}
int main() {
  scanf("%d %d", &n, &m);
  memset(sp, -1, sizeof sp);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &c[i][j]);
      if (c[i][j] == 'S') s = {i, j};
      if (c[i][j] == 'T') t = {i, j};
    }
  }
  priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
  pq.push({{0, -1}, s});
  bool ans = 0;
  while (!pq.empty()) {
    auto a = pq.top();
    pq.pop();
    if (vis[a.second.first][a.second.second]) continue;
    vis[a.second.first][a.second.second] = 1;
    for (int k = 0; k < 4; k++) {
      int ni = a.second.first + ar[k];
      int nj = a.second.second + ac[k];
      if (valid(ni, nj)) {
        if (sp[ni][nj] == -1 ||
            sp[ni][nj] >
                -a.first.first +
                    (a.first.second != k && a.first.second != -1 ? 1 : 0)) {
          sp[ni][nj] = -a.first.first +
                       (a.first.second != k && a.first.second != -1 ? 1 : 0);
          pq.push({{-sp[ni][nj], k}, {ni, nj}});
        }
      }
    }
    if (a.second.first == t.first && a.second.second == t.second) {
      if (-a.first.first <= 2) ans = 1;
      break;
    }
  }
  if (ans)
    puts("YES");
  else
    puts("NO");
  return 0;
}
