#include <bits/stdc++.h>
using namespace std;
int i, i0, n, m, s, t, dis[1005], dis0[1005];
bool dic[1005][1005];
vector<int> mp[1005];
queue<pair<int, int>> q;
int main() {
  scanf("%d %d %d %d", &n, &m, &s, &t);
  for (i = 1; i <= n; i++) dis0[i] = dis[i] = INT_MAX;
  dis[s] = 0, dis0[t] = 0;
  while (m--) {
    int x, y;
    scanf("%d %d", &x, &y);
    mp[x].push_back(y);
    mp[y].push_back(x);
    dic[x][y] = dic[y][x] = 1;
  }
  q.push({s, 0});
  while (!q.empty()) {
    for (auto i : mp[q.front().first]) {
      if (dis[i] > q.front().second + 1) {
        dis[i] = q.front().second + 1;
        q.push({i, q.front().second + 1});
      }
    }
    q.pop();
  }
  q.push({t, 0});
  while (!q.empty()) {
    for (auto i : mp[q.front().first]) {
      if (dis0[i] > q.front().second + 1) {
        dis0[i] = q.front().second + 1;
        q.push({i, q.front().second + 1});
      }
    }
    q.pop();
  }
  int ans = 0;
  for (i = 1; i <= n; i++)
    for (i0 = 1; i0 < i; i0++)
      if (!dic[i][i0] && dis0[i] + dis[i0] + 1 >= dis[t] &&
          dis[i] + dis0[i0] + 1 >= dis[t])
        ans++;
  printf("%d\n", ans);
  return 0;
}
