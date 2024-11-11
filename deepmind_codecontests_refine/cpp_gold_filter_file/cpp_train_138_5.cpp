#include <bits/stdc++.h>
using namespace std;
pair<int, int> operator+(pair<int, int> p1, pair<int, int> p2) {
  return make_pair(p1.first + p2.first, p1.second + p2.second);
}
int64_t bfs(pair<int32_t, int32_t> source, pair<int32_t, int32_t> dest,
            map<pair<int, int>, bool>& mp) {
  map<pair<int, int>, int64_t> dist;
  dist[source] = 0;
  queue<pair<int, int> > Q;
  Q.push(source);
  while (!Q.empty()) {
    pair<int, int> top = Q.front();
    Q.pop();
    if (mp[top] == true) {
      mp[top] = false;
      vector<pair<int, int> > vec = {{0, 1},  {0, -1}, {1, 0},  {1, 1},
                                     {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
      for (pair<int, int> p : vec) {
        if (dist.find(top + p) == dist.end() || dist[top + p] > dist[top] + 1)
          dist[top + p] = dist[top] + 1;
        Q.push(top + p);
      }
    }
  }
  if (dist.find(dest) == dist.end())
    return numeric_limits<int64_t>::max();
  else
    return dist[dest];
}
int main() {
  ios::sync_with_stdio(false);
  pair<int32_t, int32_t> source, dest;
  cin >> source.first >> source.second >> dest.first >> dest.second;
  int n;
  cin >> n;
  map<pair<int, int>, bool> mp;
  for (int i = 0; i < (n); i++) {
    int row, start, end;
    cin >> row >> start >> end;
    for (int j = (start); j < (end + 1); j++) mp[make_pair(row, j)] = true;
  }
  int64_t dist = bfs(source, dest, mp);
  cout << (dist == numeric_limits<int64_t>::max() ? -1 : dist) << "\n";
  return (0);
}
