#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
int n, m, sx, sy, fx, fy, ide[100005];
long long dist[100005], ans;
pair<int, int> x[100005], y[100005];
map<pair<int, int>, int> id;
vector<pair<int, long long> > edge[100005];
set<pair<long long, int> > q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> sx >> sy >> fx >> fy;
  ans = abs(sx - fx) + abs(sy - fy);
  for (int i = 1; i <= m; ++i) {
    cin >> x[i].first >> x[i].second;
    y[i] = x[i];
  }
  sort(x + 1, x + 1 + m);
  sort(y + 1, y + 1 + m, [](pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
  });
  for (int i = 1; i <= m; ++i) {
    id[x[i]] = i;
    dist[i] = min(abs((long long)sx - (long long)x[i].first),
                  abs((long long)sy - (long long)x[i].second));
    q.insert({dist[i], i});
  }
  for (int i = 1; i <= m; ++i) ide[i] = id[y[i]];
  for (int i = 1; i <= m; ++i) {
    int idNow = i, nxtId;
    long long ds;
    if (i > 1) {
      nxtId = i - 1;
      ds = x[i].first - x[nxtId].first;
      edge[idNow].push_back({nxtId, ds});
    }
    if (i < m) {
      nxtId = i + 1;
      ds = x[nxtId].first - x[i].first;
      edge[idNow].push_back({nxtId, ds});
    }
  }
  for (int i = 1; i <= m; ++i) {
    int idNow = ide[i], nxtId;
    long long ds;
    if (i > 1) {
      nxtId = ide[i - 1];
      ds = y[i].second - x[nxtId].second;
      edge[idNow].push_back({nxtId, ds});
    }
    if (i < m) {
      nxtId = ide[i + 1];
      ds = x[nxtId].second - y[i].second;
      edge[idNow].push_back({nxtId, ds});
    }
  }
  while (!q.empty()) {
    int node = q.begin()->second;
    long long cost = q.begin()->first;
    q.erase(q.begin());
    for (auto &nx : edge[node])
      if (dist[nx.first] > cost + nx.second) {
        auto it = q.find({dist[nx.first], nx.first});
        if (it != q.end()) q.erase(it);
        dist[nx.first] = cost + nx.second;
        q.insert({dist[nx.first], nx.first});
      }
  }
  for (int i = 1; i <= m; ++i)
    ans = min(ans, dist[i] + abs((long long)x[i].first - (long long)fx) +
                       abs((long long)x[i].second - (long long)fy));
  cout << ans;
  return 0;
}
