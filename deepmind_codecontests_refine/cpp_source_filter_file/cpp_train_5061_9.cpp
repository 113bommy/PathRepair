#include <bits/stdc++.h>
using namespace std;
int dist[600 + 15][600 + 15];
int start[200 + 15];
int MAX_ = INT_MAX / 2 - 5;
vector<pair<int, int> > sas[1000];
int cap[250000 + 15];
int v, e, n, k;
int pop_w[1000];
int pop_kr[1000];
int group[1000];
int last_checked[1000];
int dead[1000];
int res;
int num = 0;
bool b = 0;
int to_add;
bool DFS(int w, int bneck) {
  if (w == n + v + 2) {
    to_add = bneck;
    res += to_add;
    return 1;
  }
  for (int i = last_checked[w] + 1; i < sas[w].size(); i++) {
    int do_ = sas[w][i].first;
    int neck = min(bneck, cap[sas[w][i].second]);
    last_checked[w] = i;
    if (neck && !dead[do_])
      if (DFS(do_, neck)) {
        cap[sas[w][i].second] -= to_add;
        cap[sas[w][i].second ^ 1] += to_add;
        return 1;
      }
  }
  return 0;
}
int DINIC() {
  for (int i = 0; i <= n + v + 3; i++) {
    group[i] = -1;
    dead[i] = 0;
    last_checked[i] = -1;
  }
  queue<pair<int, int> > q;
  q.push({0, 0});
  group[0] = 0;
  while (!q.empty()) {
    int top_w = q.front().first;
    int top_g = q.front().second;
    q.pop();
    for (int i = 0; i < sas[top_w].size(); i++)
      if (group[sas[top_w][i].first] == -1) {
        group[sas[top_w][i].first] = top_g + 1;
        q.push({sas[top_w][i].first, top_g + 1});
      }
  }
  int ile = 0;
  while (DFS(0, INT_MAX)) ile++;
  return ile;
}
bool CHECK(int t) {
  for (int i = 0; i <= n + v + 3; i++) sas[i].clear();
  int place;
  num = 0;
  for (int i = 1; i <= n; i++) {
    place = start[i];
    for (int j = 1; j <= v; j++) {
      if (dist[place][j] <= t) {
        sas[i].push_back({j + n, num});
        sas[j + n].push_back({i, num + 1});
        cap[num] = 1;
        cap[num + 1] = 0;
        num += 2;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    sas[0].push_back({i, num});
    sas[i].push_back({0, num + 1});
    cap[num] = 1;
    cap[num + 1] = 0;
    num += 2;
  }
  for (int i = n + 1; i <= n + v; i++) {
    sas[i].push_back({n + v + 2, num});
    sas[n + v + 2].push_back({i, num + 1});
    cap[num] = 1;
    cap[num + 1] = 0;
    num += 2;
  }
  res = 0;
  while (DINIC()) {
  };
  if (res >= k) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> v >> e >> n >> k;
  for (int i = 1; i <= n; i++) cin >> start[i];
  for (int i = 1; i <= v; i++)
    for (int j = 1; j <= v; j++) dist[i][j] = MAX_;
  for (int i = 1; i <= n; i++) dist[i][i] = 0;
  int h, j, r;
  for (int i = 1; i <= e; i++) {
    cin >> h >> j >> r;
    dist[h][j] = min(dist[h][j], r);
    dist[j][h] = min(dist[j][h], r);
  }
  for (int mid = 1; mid <= v; mid++)
    for (int x = 1; x <= v; x++)
      for (int y = 1; y <= v; y++)
        dist[x][y] = min(dist[x][y], dist[x][mid] + dist[mid][y]);
  if (!CHECK(1731311)) {
    cout << -1;
    return 0;
  }
  int b = 0;
  int e = 1731311;
  while (b <= e) {
    int mid = (b + e) / 2;
    if (CHECK(mid))
      e = mid - 1;
    else
      b = mid + 1;
  }
  cout << b;
}
