#include <bits/stdc++.h>
using namespace std;
constexpr int LOG = 19;
constexpr int MOD = 998244353;
int powMOD(int a, int b) {
  if (b == 0) {
    return 1;
  } else if (b % 2 == 0) {
    int t = powMOD(a, b / 2);
    return 1LL * t * t % MOD;
  } else {
    return 1LL * a * powMOD(a, b - 1) % MOD;
  }
}
void dijkstra1(vector<long long>& dist,
               const vector<vector<pair<int, int>>>& gr) {
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      q;
  q.push({0, 0});
  dist[0] = 0;
  while (!q.empty()) {
    int curr = q.top().second;
    long long cd = q.top().first;
    q.pop();
    if (cd != dist[curr]) {
      continue;
    }
    for (const auto& next : gr[curr]) {
      if (dist[next.first] > cd + next.second) {
        dist[next.first] = cd + next.second;
        q.push({dist[next.first], next.first});
      }
    }
  }
}
pair<int, int> operator+(const pair<int, int>& left,
                         const pair<int, int>& right) {
  return make_pair(left.first + right.first, left.second + right.second);
}
void dijkstra2(vector<pair<int, int>>& dist,
               const vector<vector<pair<int, pair<int, int>>>>& gr) {
  priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>,
                 greater<pair<pair<int, int>, int>>>
      q;
  q.push({{0, 0}, 0});
  dist[0] = {0, 0};
  while (!q.empty()) {
    int curr = q.top().second;
    auto cd = q.top().first;
    q.pop();
    if (cd != dist[curr]) {
      continue;
    }
    for (const auto& next : gr[curr]) {
      if (dist[next.first] > cd + next.second) {
        dist[next.first] = cd + next.second;
        q.push({dist[next.first], next.first});
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> gr(LOG * n);
  vector<vector<pair<int, pair<int, int>>>> gr1(2 * n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    gr1[u].push_back({v, {0, 1}});
    gr1[n + v].push_back({n + u, {0, 1}});
    for (int j = 0; j < LOG; ++j) {
      if (j & 1) {
        gr[j * n + v].push_back({j * n + u, 1});
      } else {
        gr[j * n + u].push_back({j * n + v, 1});
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    gr1[i].push_back({n + i, {1, 0}});
    gr1[n + i].push_back({i, {1, 0}});
  }
  for (int j = 0; j + 1 < LOG; ++j) {
    for (int i = 0; i < n; ++i) {
      gr[j * n + i].push_back({(j + 1) * n + i, (1 << j)});
    }
  }
  vector<long long> dist(LOG * n, 1e18);
  dijkstra1(dist, gr);
  long long mm = 1e18;
  for (int j = 0; j < LOG; ++j) {
    mm = min(mm, dist[j * n + n - 1]);
  }
  if (mm != 1e18) {
    cout << mm;
    return 0;
  }
  vector<pair<int, int>> dist1(2 * n, {1e9, 1e9});
  dijkstra2(dist1, gr1);
  auto mmm = min(dist1[n - 1], dist1[2 * n - 1]);
  cout << (powMOD(2, mmm.first) - 1 + MOD + mmm.second) % MOD;
}
