#include <bits/stdc++.h>
using namespace std;
struct Position {
  int p;
  int cost;
} pos, pre, now;
int cnt[200005];
int cost[200005];
int father[200005];
int n, m;
int x, y;
int k;
int path[200005];
vector<vector<int>> edge;
int s, e;
queue<Position> q;
int len;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n + 1; i++) {
    edge.push_back(vector<int>());
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    edge[y].push_back(x);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> path[i];
  }
  for (int i = 1; i <= n; i++) {
    cost[i] = INT_MAX;
    cnt[i] = 0;
    father[i] = i;
  }
  s = path[k - 1];
  e = path[0];
  cost[s] = 0;
  pos.p = s;
  pos.cost = 0;
  q.push(pos);
  while (!q.empty()) {
    pre = q.front();
    q.pop();
    len = edge[pre.p].size();
    now.cost = pre.cost + 1;
    for (int i = 0; i < len; i++) {
      now.p = edge[pre.p][i];
      if (now.cost > cost[now.p])
        continue;
      else if (now.cost == cost[now.p]) {
        cnt[now.p]++;
      } else if (now.cost < cost[now.p]) {
        cost[now.p] = now.cost;
        cnt[now.p] = 1;
        father[now.p] = pre.p;
        q.push(now);
      }
    }
  }
  int minans = 0;
  int maxans = 0;
  for (int i = 0; i < k - 1; i++) {
    if (cost[path[i]] < k - i - 1) {
      if (cost[path[i + 1]] == cost[path[i]] - 1) {
        if (cnt[path[i]] > 1) maxans++;
      } else {
        maxans++;
        minans++;
      }
    } else if (cnt[path[i]] > 1)
      maxans++;
  }
  cout << minans << " " << maxans << endl;
  return 0;
}
