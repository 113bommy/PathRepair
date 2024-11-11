#include <bits/stdc++.h>
using namespace std;
int n, m, k, r, level, sum, d[55][55];
bool vis[55][55];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  queue<pair<int, int> > q;
  q.push({1, 1});
  d[1][1] = 1;
  vector<pair<int, int> > v;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    v.push_back({d[x][y], x * 100 + y});
    if (x + 1 <= n && !vis[x + 1][y]) {
      vis[x + 1][y] = true;
      d[x + 1][y] = d[x][y] + 1;
      q.push({x + 1, y});
    }
    if (y + 1 <= m && !vis[x][y + 1]) {
      vis[x][y + 1] = true;
      d[x][y + 1] = d[x][y] + 1;
      q.push({x, y + 1});
    }
  }
  int ans = 0;
  for (int i = 0; i < k; i++) ans += v[i].first;
  printf("%d\n", ans);
  for (int i = k - 1; i >= 0; i--) {
    int x = v[i].second / 100, y = v[i].second % 100;
    printf("(1 1)");
    for (int j = 2; j <= x; j++) printf(" (%d %d)", j, 1);
    for (int j = 2; j <= y; j++) printf(" (%d %d)", x, j);
    printf("\n");
  }
  return 0;
}
