#include <bits/stdc++.h>
using namespace std;
int N, K, ans[200010] = {}, visited[200010] = {};
vector<vector<pair<int, int>>> v(200010);
vector<pair<int, int>> vertex;
set<int> penalty;
int main() {
  cin >> N >> K;
  int a, b;
  for (int i = 1; i <= N - 1; i++) {
    cin >> a >> b;
    v[a].push_back({b, i});
    v[b].push_back({a, i});
  }
  for (int i = 1; i <= N; i++) vertex.push_back({v[i].size(), i});
  sort(vertex.begin(), vertex.end(), greater<pair<int, int>>());
  int r = vertex[K].first;
  for (int i = 0; i < K; i++) penalty.insert(vertex[i].second);
  queue<pair<int, int>> Q;
  Q.push({vertex[0].second, -1});
  visited[vertex[0].second] = 1;
  while (!Q.empty()) {
    pair<int, int> p = Q.front();
    Q.pop();
    int n = p.first;
    int col = 1;
    for (auto x : v[n]) {
      if (visited[x.first] == 0) {
        if (col == p.second && penalty.count(x.first) == 0) col++;
        if (col > r) col = 1;
        ans[x.second] = col;
        Q.push({x.first, col});
        visited[x.first] = 1;
        col++;
        if (col > r) col = 1;
      }
    }
  }
  cout << r << endl;
  for (int i = 1; i <= N - 1; i++) {
    assert(ans[i] != 0);
    cout << ans[i] << (i != N - 1 ? " " : "\n");
  }
}
