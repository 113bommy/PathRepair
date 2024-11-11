#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adia[1100];
int costsg;
int n, m;
int S, T, l;
int dist[1100];
vector<pair<pair<int, int>, pair<int, int>>> alone;
int cbin();
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> l >> S >> T;
  int a, b, c;
  while (m--) {
    cin >> a >> b >> c;
    if (c == 0) alone.push_back({{a, adia[a].size()}, {b, adia[b].size()}});
    adia[a].push_back({b, c});
    adia[b].push_back({a, c});
  }
  costsg = 100;
  int p(0), q(1 << 30);
  while (q) {
    if (p + q <= 1000 * 1000 * 1000) {
      costsg = p + q;
      int x(cbin());
      if (x <= l) p += q;
    }
    q >>= 1;
  }
  costsg = p;
  if (cbin() > l || p == 0) {
    cout << "NO";
    return 0;
  }
  costsg = p + 1;
  if (cbin() < l) {
    cout << "NO";
    return 0;
  }
  for (auto i : alone) {
    adia[i.first.first][i.first.second].second =
        adia[i.second.first][i.second.second].second = p;
  }
  int punere(p);
  p = 0, q = 1 << 20;
  while (q) {
    if (p + q <= alone.size()) {
      for (int i(0); i < p + q; i++)
        adia[alone[i].first.first][alone[i].first.second].second++,
            adia[alone[i].second.first][alone[i].second.second].second++;
      int x(cbin());
      for (int i(0); i < p + q; i++)
        adia[alone[i].first.first][alone[i].first.second].second--,
            adia[alone[i].second.first][alone[i].second.second].second--;
      if (x <= l) p += q;
    }
    q >>= 1;
  }
  for (int i(0); i < p; i++)
    adia[alone[i].first.first][alone[i].first.second].second++,
        adia[alone[i].second.first][alone[i].second.second].second++;
  cout << "YES\n";
  for (int i(0); i < n; i++) {
    for (auto j : adia[i]) {
      if (j.first > i) cout << i << ' ' << j.first << ' ' << j.second << '\n';
    }
  }
  return 0;
}
int cbin() {
  for (int i(0); i <= n; i++) dist[i] = 1e9;
  priority_queue<pair<int, int>> q;
  q.push({0, S});
  while (!q.empty()) {
    int t(q.top().first), x(q.top().second);
    t *= -1;
    q.pop();
    if (dist[x] < t) continue;
    if (x == T) return dist[x];
    for (auto i : adia[x]) {
      if (!i.second) i.second = costsg;
      if (dist[i.first] > t + i.second) {
        dist[i.first] = t + i.second;
        q.push({-dist[i.first], i.first});
      }
    }
  }
  return 2 * 1000 * 1000 * 1000;
}
