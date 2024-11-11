#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int mx = 1e5 + 5;
int n, m;
vector<pair<int, int>> edge[mx];
set<int> bad[mx];
int dist[mx];
priority_queue<pair<int, int>> q;
bool used[mx];
void add(int x, int d) {
  if (d < dist[x]) {
    dist[x] = d;
    q.push(make_pair(-d, x));
  }
}
int next(int x, int t) {
  if (bad[x].find(t) != bad[x].end()) t++;
  return t;
}
int main() {
  ios::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed;
  cin >> n >> m;
  int t, x;
  for (int i = 0; i < m; i++) {
    int x, y, d;
    cin >> x >> y >> d;
    x--, y--;
    edge[x].push_back(make_pair(y, d));
    edge[y].push_back(make_pair(x, d));
  }
  for (int i = 0; i < n; i++) {
    int cnt;
    cin >> cnt;
    for (int j = 0; j < cnt; j++) {
      cin >> t;
      bad[i].insert(t);
    }
  }
  for (int i = 0; i < n; i++) dist[i] = 2000000000;
  add(0, 0);
  while (!q.empty()) {
    x = q.top().second;
    t = -q.top().first;
    q.pop();
    if (used[x]) continue;
    used[x] = 1;
    t = next(x, t);
    for (int i = 0; i < edge[x].size(); i++) {
      int y = edge[x][i].first;
      int t2 = t + edge[x][i].second;
      add(y, t2);
    }
  }
  if (dist[n - 1] == 2000000000)
    cout << -1 << "\n";
  else
    cout << dist[n - 1] << "\n";
  return 0;
}
