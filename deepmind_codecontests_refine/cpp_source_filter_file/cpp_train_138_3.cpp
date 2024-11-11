#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, 1, 1, -1, 1, -1};
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  map<pair<int, int>, bool> Allowed;
  int n;
  cin >> n;
  while (n--) {
    int r, a, b;
    cin >> r >> a >> b;
    for (int i = a; i <= b; i++) Allowed[{r, i}] = true;
  }
  Allowed[{x1, y1}] = true;
  Allowed[{x2, y2}] = true;
  map<pair<int, int>, int> ans;
  queue<pair<int, int>> que;
  que.push({x1, y1});
  ans[{x1, y1}] = 0;
  while (!que.empty()) {
    int x = que.front().first, y = que.front().second;
    que.pop();
    for (int i = 0; i < 8; i++) {
      int newX = x + dx[i], newY = y + dy[i];
      if (Allowed[{newX, newY}] && !ans[{newX, newY}]) {
        que.push({newX, newY});
        ans[{newX, newY}] = ans[{x, y}] + 1;
      }
    }
  }
  if (!ans[{x2, y2}])
    cout << -1;
  else
    cout << ans[{x2, y2}];
  return 0;
}
