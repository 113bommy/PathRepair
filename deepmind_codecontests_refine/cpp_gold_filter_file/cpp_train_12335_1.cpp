#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e3;
int v[maxN];
set<pair<int, int> > mySet;
bool ov[maxN];
vector<int> adj[maxN];
int n, m, paths[maxN][maxN], best = -1;
pair<int, pair<int, int> > vals[2];
void shp(int a) {
  queue<pair<int, int> > pq;
  pq.push(pair<int, int>(0, a));
  pair<int, int> cur;
  while (!pq.empty()) {
    cur = pq.front();
    paths[a][cur.second] = cur.first;
    pq.pop();
    for (int i = 0; i < adj[cur.second].size(); i++) {
      if (paths[a][adj[cur.second][i]] == INT_MAX) {
        paths[a][adj[cur.second][i]] = cur.first + 1;
        pq.push(pair<int, int>(cur.first + 1, adj[cur.second][i]));
      }
    }
  }
}
void opt() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int first = paths[vals[0].first][i] + paths[j][vals[0].second.first],
          second = paths[vals[1].first][i] + paths[j][vals[1].second.first];
      if (first + paths[i][j] <= vals[0].second.second &&
          second + paths[i][j] <= vals[1].second.second)
        best = max(m - (first + second + paths[i][j]), best);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0, from, to; i < m; i++) {
    cin >> from >> to;
    from--, to--;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      paths[i][j] = INT_MAX;
    }
    shp(i);
  }
  for (int i = 0; i < 2; i++) {
    cin >> vals[i].first >> vals[i].second.first >> vals[i].second.second;
    vals[i].first--, vals[i].second.first--;
  }
  opt();
  swap(vals[0].first, vals[0].second.first);
  opt();
  if (paths[vals[0].first][vals[0].second.first] <= vals[0].second.second &&
      paths[vals[1].first][vals[1].second.first] <= vals[1].second.second) {
    best = max(best, m - paths[vals[0].first][vals[0].second.first] -
                         paths[vals[1].first][vals[1].second.first]);
  }
  cout << best << '\n';
}
